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
- `inc/frames/` : poses par personnage (`#switch (N_Animation_Frame)`), `inc/Camera.inc` : décodage de `clock`, caméra, lumière.
- `inc/armors/`, `inc/hair/`, `inc/weapons/` : pièces `P_*` et textures interchangeables.
- `inc/wizard/`, `inc/jack/`, `inc/skeleton/` : modèles hors corps de base (mage, Jack-o'-lantern) et pièces du squelette.
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

// 4. Pose
#declare AV_Arm_Left = <0, 0, 10>;

// 5. Corps de base, puis placement dans la scène
#include "inc/body/BodyParts.inc"
object { O_BodyPart_Armored_Body_M }
```

## Géométrie et repères

- Axe Y vers le haut. Les pieds sont à peu près à `y = 0` : le torse est translaté de `N_Shin_Len + N_Thigh_Len + N_Leg_Thickness`.
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

- L'animation passe par la variable `clock` et par les `AV_*`.

### Cible : moteur raycaster-386 (`../raycaster-386`)

- **Planche** : une seule bande PNG horizontale (le moteur découpe par `sx / largeur_tuile`), cadres 64×96 par défaut, réglables dans la spec (`frame.width/height`). Le moteur limite un canvas à ~32 000 px de large.
- **Échelle** : fixe pour tous les personnages (`frame.units_height` = 6 unités POV pour 96 px), pieds sur la ligne de base (`frame.baseline`). Un humain fait ~72 px, le troll ~91 px.
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
- Pas de pose pour le tronc, le cou ni la tête (pas d'`AV_Torso`, `AV_Head`, `AV_Neck`).
- Bloc `#ifdef (T_BodyPart_Skin) #end` vide dans `O_BodyPart_Wrist` : code mort.

## À ne pas faire

- Ne pas renommer les variables publiques existantes (`N_*`, `AV_*`, `T_*`, `P_*`) : d'autres fichiers en dépendent.
- Ne pas committer de gros fichiers générés.
- Ne pas utiliser de fonctionnalité propre à la 3.8 ni remplacer `ovus` sans me demander.
