# CLAUDE.md

Projet POV-Ray qui génère des personnages animés. Les rendus servent de sprites pour mon raycaster engine (vue 2.5D, personnages vus sous plusieurs angles).

> Les passages marqués **TODO** sont à compléter par moi. Ne les invente pas : si une information manque, demande-la.

## Objectif

- Décrire les personnages **entièrement en code POV-Ray** (SDL), de façon paramétrique.
- Un personnage = un petit fichier qui surcharge des paramètres (mensurations, textures, pièces d'armure, pose), puis inclut le corps de base.
- Produire des variantes variées (nain, géant, elfe, guerrière, mage…) sans toucher aux fichiers de base, sauf pour les rendre plus paramétrables.

## Environnement

- POV-Ray **3.7** (testé avec 3.7.0.10, paquet Ubuntu). La primitive `ovus` utilisée par le projet existe depuis la 3.7. La 3.8 n'est jamais sortie en version stable (dernière bêta : août 2021).
- Planche de sprites : `tools/sprites.py sprites/<perso>.json [--preview]` (Python 3 + ImageMagick `convert`, rendu en parallèle).
- Image isolée : `povray +Ic_zombie_1.pov +O<sortie>.png +W256 +H192 +UA -A +K<clock> -D -GA`, avec `clock = 100 × direction POV + pose` (décodé dans `inc/Camera.inc`, +1000 = mode dev).
- Ancien script `render` (`-r` / `-p`) : conservé, mais remplacé par `tools/sprites.py` pour le jeu.
- Contrôle dans le moteur (`viewer/`, lié à `../raycaster-386` par `file:` ; après un changement du moteur, y relancer `npm run build`) :
	- `cd viewer && node snapshot.mjs <perso> [animation]` → `output/<perso>.engine.png`, 8 vues sans navigateur.
	- `cd viewer && npx vite` → visionneuse interactive (`?sheet=<perso>&anim=<id>`).
	- Le personnage regarde vers +x : il doit toujours regarder vers la bande sombre du sol.
- Le canal alpha (`+UA`) est nécessaire pour les sprites : fond transparent.
- Sorties dans : `output/` (ignoré par git ; ne pas committer les PNG générés, sauf demande explicite).

## Structure du dépôt

- `inc/body/BodyMetrics.inc` : mensurations et poses par défaut (variables `N_*`, `AV_*`).
- `inc/body/` : parties du corps (torse M/F, jambes, bras, main, tête, casque).
- `c_*.pov` (racine) : fichiers de personnage (une scène par personnage).
- `p_*.pov` (racine) : décors (props) ; objets réutilisables dans `inc/props/` (`Props.inc` : hauteur du plafond `N_Prop_Ceiling` pour les objets suspendus).
- `inc/frames/` : poses par personnage (`#switch (N_Animation_Frame)`), `inc/Camera.inc` : décodage de `clock`, caméra, lumière.
- `inc/armors/`, `inc/hair/`, `inc/weapons/` : pièces `P_*` et textures interchangeables.
- `inc/wizard/`, `inc/jack/`, `inc/skeleton/` : modèles hors corps de base (mage, Jack-o'-lantern) et pièces du squelette. Jack (`inc/jack/Jack.inc`, `O_JackOLantern_Posed`) est piloté par les mêmes variables de pose (`inc/frames/jack.inc`) : bras de la lanterne, citrouille, corps, et `V_Pose_Extra` (effondrement de la robe, flamme, forme de la robe). Sa lanterne (`inc/jack/Lantern.inc`) est distincte de celle des décors (`inc/props/Lantern.inc`). Le mage (`inc/wizard/Wizard.inc`, `O_Wizard_Posed`, poses dans `inc/frames/wizard.inc`, variantes `c_wizard_blue` / `c_wizard_red` par `WizardRobeTint`) suit le même principe ; `V_Pose_Extra.y` règle le flash du tir au bout de la baguette (porté par `inc/armors/Wand_Ruby_Sphere.inc`, donc partagé avec la sorcière). Sa marche vient de la robe seule : `V_Pose_Extra.z` (0 à 1) transforme point par point l'une en l'autre les 2 surfaces de révolution de la robe (`P_WizardRobeGarb`, `P_WizardRobeGarb_2`), et la tête, les mains et les manches suivent sa hauteur ; pas de dandinement. `inc/wizard/frames.inc` est du code mort (variables `AnimationFrame` jamais définies, inclus nulle part).
- `png/` : textures de visage et de torse (sources, à garder). `xcf/` : sources GIMP. `materials/` : essais de textures bois.
- `sprites/<perso>.json` : spécification d'une planche (scène, cadre, animations). `tools/sprites.py` : générateur de planches.

## Conventions de nommage

Les préfixes indiquent le type de la variable. Respecte-les pour toute nouvelle déclaration.

| Préfixe | Signification | Exemple |
|---|---|---|
| `N_` | nombre (mesure, taille, épaisseur) | `N_Torso_Len` |
| `V_` | vecteur (échelle, position) | `V_BodyPart_Torso_Scale` |
| `AV_` | vecteur d'angles de rotation, en degrés (pose) | `AV_Arm_Left` |
| `T_` | texture | `T_BodyPart_Skin` |
| `O_` | objet fini | `O_BodyPart_Armored_Body_F` |
| `P_` | pièce optionnelle à brancher (armure, arme) | `P_BodyPart_ArmorPart_Helm` |

- Les noms de pièces de corps suivent `O_BodyPart_<Partie>` ; la version armée s'appelle `O_BodyPart_Armored_<Partie>`.
- Les variantes homme / femme se terminent par `_M` / `_F`.
- Indentation par tabulations, comme dans les fichiers existants.

## Mécanisme de surcharge (important)

Les paramètres optionnels fonctionnent avec `#ifndef` / `#ifdef` :

- Pour **surcharger** une valeur, on la déclare **avant** l'`#include` du fichier de base.
- Les pièces optionnelles (`P_*`, `T_BodyPart_*`) sont testées avec `#ifdef`. Si elles ne sont pas définies, la partie est simplement absente.
- `NULL_OBJECT` (`sphere { 0, 0 }`) sert d'objet vide quand une pièce n'existe pas.
- Toute nouvelle mesure doit être protégée par `#ifndef`, sinon elle ne peut plus être surchargée par un personnage.

Gabarit d'un fichier de personnage :

```pov
// 1. Mensurations (avant l'include)
#declare N_BodyMetrics_Value = 0.8;
#declare N_BodyMetrics_Member_Factor = 0.6;

// 2. Textures
#declare T_BodyPart_Skin = texture { pigment { color rgb <0.8, 0.6, 0.5> } }

// 3. Pièces d'armure (optionnelles)
#declare P_BodyPart_ArmorPart_Helm = union { /* ... */ }

// 4. Poses : pas de AV_* ici (Pose_Reset() les écraserait), mais un fichier de poses
#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"

// 5. Corps de base, puis placement dans la scène
#include "inc/body/BodyParts.inc"
object { O_BodyPart_Armored_Body_M rotate y * N_Animation_Angle }
```

## Géométrie et repères

- Axe Y vers le haut. Les pieds sont à peu près à `y = 0` : le torse est translaté de `N_Hip_Height` (`N_Shin_Len + N_Thigh_Len + N_Leg_Thickness`). Le personnage regarde vers `-z`.
- Assemblage (`BodyPart_Body` dans `BodyParts.inc`) : le haut du corps (torse, tête, bras, collier) est construit autour des hanches et pivote avec `AV_Torso` ; la tête pivote avec `AV_Head` autour du haut du cou ; `AV_Body` puis `V_Body_Offset` déplacent tout le corps autour du point au sol entre les pieds.
- Le côté **gauche** du personnage est en `+x`, le droit en `-x`. Le côté droit est obtenu par miroir (`scale <-1, 1, 1>`) de la pièce gauche : écris les pièces d'armure pour le côté gauche seulement.
- Les membres pendent vers `-y` depuis leur articulation. Les `AV_*` sont appliqués autour de cette articulation (épaule, coude, hanche, genou).
- Le torse est un `blob` : attention au `threshold` et aux rayons d'influence (3e valeur de chaque sphère). Change-les par petites touches et regarde le rendu.

## Façon de travailler

1. **Rends toujours après une modification** et regarde l'image (basse résolution pour itérer, par exemple 128×128, sans antialiasing). Ne déclare jamais qu'une modification fonctionne sans l'avoir vue.
2. Vérifie systématiquement : pièces qui flottent ou traversent le corps, proportions, symétrie gauche/droite, silhouette lisible en petit (les sprites seront affichés petits).
3. Fais des changements petits et isolés, un personnage ou une pièce à la fois.
4. Pour un nouveau personnage : crée un fichier de personnage qui surcharge les paramètres. Ne modifie pas les fichiers de base pour un cas particulier.
5. Si une modification des fichiers de base est utile (par exemple rendre une mesure surchargeable), propose-la et explique l'impact sur les personnages existants avant de l'appliquer. Re-rends les personnages existants pour vérifier l'absence de régression.
6. Garde les commentaires existants (blocs ASCII art de section) et le style général.

## Animation

- `clock = 100 × direction POV + pose` (`inc/Animation.inc`). La pose peut aussi être donnée en ligne de commande : `Declare=N_Pose_From=3 Declare=N_Pose_To=4 Declare=N_Pose_Blend=0.5` (interpolation linéaire de tous les `AV_*` et de `V_Body_Offset`).
- **`V_Pose_Extra`** : vecteur libre, interpolé comme les autres, ignoré par le corps de base ; un modèle hors corps l'utilise pour ses propres réglages (Jack).
- **Poses** : `inc/frames/<perso>.inc` définit `#macro Pose_Define(N_Pose)` (un `#switch` qui ne déclare que ce qui diffère de `Pose_Reset()`), puis inclut `inc/Pose.inc`. `zombie.inc` sert aussi à la goule et au squelette ; c'est le modèle du format (`AV_*` déclarés directement).
- **Attaques à distance (style Heretic)** : 2 images, le tir (arme légèrement relevée par le recul, flash) puis une récupération interpolée vers le repos (`[tir, 0, 0.75]`). Mage, sorcière et Jack suivent ce modèle.
- **Signes des angles** : membres (pendent vers le bas) : `x > 0` = vers l'avant. `AV_Torso`, `AV_Head`, `AV_Body` (pointent vers le haut) : `x < 0` = penché en avant, `x > 0` = en arrière. `z` : sur le côté.
- **Poses du zombie, du chevalier et du troll** (même numérotation ; la momie et la sorcière ont leur propre numérotation, voir l'en-tête de `mummy.inc` et `witch.inc`) : 0 STAND, 1-2 ATTACK, 3-5 WALK, 6 IDLE, 7 PAIN, 8-12 DEATH (chute sur le côté droit, genoux pliés, pour tenir en largeur vue de face).
- **Spec `sprites/<perso>.json`** : une pose = un numéro, ou `[de, vers, mélange]`. Par animation : `directions` (8 ou 1), `duration` (ms), `loop`, et si besoin `camera_elevation` (degrés) et `shift_x` (unités POV, décale le personnage dans le cadre, ex. un cadavre qui déborde).
- **Mort sur une seule direction** : rendue de face. Un corps tombé en arrière est vu par la tranche (invisible) ; une caméra plongeante le fait ressembler à un personnage tassé : d'où la chute sur le côté.
- **Non-régression des fichiers de base** : `tools/regress.py save` avant, `tools/regress.py check` après (comparaison pixel à pixel, toutes poses × 8 directions). Quelques pixels d'écart sur des textures procédurales (bouclier du chevalier) viennent d'arrondis et sont normaux.

### Cible : moteur raycaster-386 (`../raycaster-386`)

- **Planche** : une seule bande PNG horizontale (le moteur découpe par `sx / largeur_tuile`), cadres 64×96 par défaut, réglables dans la spec (`frame.width/height`). Le moteur limite un canvas à ~32 000 px de large.
- **Échelle** : fixe pour tous les personnages (`frame.units_height` = 6 unités POV pour 96 px), pieds sur la ligne de base (`frame.baseline`). Un humain fait ~72 px, le troll ~91 px. Un grand monstre peut avoir un cadre plus large (le troll : 96×96, bras trop longs pour 64 px ; ~6,9 Mo dans le moteur).
- **Sortie** : `output/<perso>.png` + `output/<perso>.json` (fragment de tileset RCE-100 : `width`, `height`, `animations[{id, start[8], length, duration, loop}]`). Ordre dans la bande : animation, puis direction, puis image.
- **8 directions, pas de miroir.** Convention du moteur (`src/render/spriteFacing.ts`) : 0 = dos, 2 = nez vers la droite de l'écran, 4 = face, 6 = nez vers la gauche. Côté POV, 0 = face : `direction POV = (direction moteur + 4) mod 8`.
- **Animations visées** : idle 2 (yoyo), marche 4, attaque 3, douleur 2, mort 6 (une seule direction, `start` répété 8 fois). Environ 94 images, ~4,6 Mo résidents par type dans le moteur ; viser 8 à 10 types de personnages par niveau.
- Le moteur assombrit les sprites à la volée (shading paresseux + cache partagé de 4 Mo). Les projectiles et explosions marqués `FX_LIGHT_SOURCE` ne sont pas assombris.

## Points d'attention connus

À vérifier ou corriger quand l'occasion se présente (ne pas corriger sans me prévenir) :

- `O_BodyPart_Torso_F` : le cou monte jusqu'à `2 * N_Torso_Len`, alors que la version M utilise `N_Torso_Len + N_Neck_Len`. Probablement une coquille.
- Jupe et ceinture ne sont pas positionnées de la même façon en M (`N_Belt_Height`) et en F (`N_Torso_Len / 4`).
- Dans `BodyMetrics.inc`, les mesures dérivées (`N_Shoulder_Len`, `N_Neck_Len`, `N_Head_Size`, `N_Leg_Thickness`, etc.) ne sont pas protégées par `#ifndef`, donc non surchargeables. C'est le principal frein à la variété des personnages.
- Les épaisseurs (bras, jambes) ne suivent pas `N_BodyMetrics_Value` : un grand personnage paraît filiforme.
- Pas d'`AV_Neck` : le cou fait partie du `blob` du torse et ne peut pas plier séparément (`AV_Head` suffit pour l'instant).
- `c_dummy.pov` est un mannequin de test, absent du jeu (pas de planche). `inc/frames/dummy.inc` est encore à l'ancien format et n'applique aucune pose : le dummy reste au repos.
- Bloc `#ifdef (T_BodyPart_Skin) #end` vide dans `O_BodyPart_Wrist` : code mort.

## À ne pas faire

- Ne pas renommer les variables publiques existantes (`N_*`, `AV_*`, `T_*`, `P_*`) : d'autres fichiers en dépendent.
- Ne pas committer de gros fichiers générés.
- Ne pas utiliser de fonctionnalité propre à la 3.8 ni remplacer `ovus` sans me demander.
