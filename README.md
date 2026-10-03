# raytracing-sprite-generator

Personnages animés décrits en POV-Ray (SDL), rendus en planches de sprites pour
le moteur [raycaster-386](../raycaster-386) : 8 directions, animations idle,
marche, attaque, douleur et mort.

## Prérequis

- POV-Ray 3.7 (`sudo apt install povray`), testé avec 3.7.0.10.
- Python 3 et ImageMagick (`convert`, `compare`).
- Pour contrôler dans le moteur : Node.js, puis une fois `cd viewer && npm install`.
  Le dossier `viewer/` est lié à `../raycaster-386` ; si le moteur change, y relancer `npm run build`.

## Générer une planche

Toutes les commandes se lancent depuis la racine du dépôt.

```bash
tools/sprites.py sprites/witch.json            # planche seule
tools/sprites.py sprites/witch.json --preview  # + grille de contrôle
```

Résultat dans `output/` (ignoré par git, régénérable à tout moment) :

| Fichier | Usage |
|---|---|
| `output/witch.png` | **la planche** : une bande horizontale de cadres, à copier dans le jeu |
| `output/witch.json` | **le tileset** RCE-100 (`width`, `height`, `animations`), à reprendre dans le niveau ou les blueprints du jeu (y ajouter `id` et `src`) |
| `output/witch.preview.png` | contrôle : une ligne par animation et par direction |

Toutes les planches d'un coup :

```bash
for f in sprites/*.json; do tools/sprites.py "$f"; done
```

Personnages disponibles : `zombie`, `ghoul`, `skeleton`, `knight`, `mummy`, `troll`, `witch`, `jack`, `wizard_blue`, `wizard_red`.
Décors disponibles : `barrel`, `chain`, `lantern`.

## Contrôler le résultat

```bash
cd viewer
node snapshot.mjs witch death   # output/witch.engine.png : 8 vues dans le moteur, sans navigateur
npx vite                        # visionneuse interactive : http://localhost:5173/?sheet=witch&anim=walk
```

Dans les deux cas, le personnage regarde vers la bande sombre du sol : s'il lui
tourne le dos, l'ordre des directions est faux.

## Comment c'est organisé

Un personnage, c'est trois fichiers :

| Fichier | Contenu |
|---|---|
| `c_<perso>.pov` | la scène : mensurations, textures, pièces d'armure, puis le corps de base |
| `inc/frames/<fichier>.inc` | les poses, numérotées (`Pose_Define`) ; un même fichier peut servir à plusieurs personnages (`zombie.inc` sert aussi à la goule et au squelette) |
| `sprites/<nom>.json` | la recette de la planche : quelle scène, quel cadre, quelles poses pour chaque animation |

### La recette (`sprites/<nom>.json`)

```json
{
	"scene": "c_witch_blue.pov",
	"frame": { "width": 64, "height": 96, "units_height": 6.0, "baseline": 0.1 },
	"animations": [
		{ "id": "idle", "poses": [0, 7], "duration": 400, "loop": "@LOOP_YOYO" },
		{ "id": "walk", "poses": [2, 3, 4, [4, 2, 0.5]], "duration": 150, "loop": "@LOOP_FORWARD" },
		{ "id": "death", "poses": [9, 10, 11, 12, 13], "directions": 1, "duration": 120, "loop": "@LOOP_NONE" }
	]
}
```

- Le nom de la planche est celui du fichier : `sprites/witch.json` donne `output/witch.png`.
- `frame` : taille du cadre en pixels. `units_height` fixe l'échelle (6 unités POV pour 96 px) : à garder identique pour tous les personnages pour qu'ils restent à la même échelle en jeu. Un grand monstre peut avoir un cadre plus large (`troll.json` : 96×96).
- `poses` : numéros de pose du fichier `inc/frames/`, ou `[de, vers, mélange]` pour une pose intermédiaire (`[4, 2, 0.5]` = à mi-chemin entre 4 et 2).
- `directions` : 8 (par défaut) ou 1 (rendue de face, répétée pour les 8 directions : pour la mort).
- `duration` en millisecondes par image ; `loop` : `@LOOP_NONE`, `@LOOP_FORWARD`, `@LOOP_YOYO`.
- Options : `shift_x` (unités POV) décale le personnage dans le cadre, par exemple un cadavre qui déborde (`ghoul.json`) ; `camera_elevation` (degrés) fait plonger la caméra.

La numérotation des poses est décrite en tête de chaque fichier `inc/frames/*.inc`.

## Exemple : une sorcière à jupe grise, en gardant la bleue

La couleur de la jupe est écrite dans la pièce `inc/armors/Witch_Costume_Blue_Skirt.inc`.
Comme pour les autres variantes du dépôt (`Short_Trousers_Ripped_Blueish` / `_Dark`),
on duplique la pièce, la scène et la recette ; les poses sont partagées.

**1. La pièce** : copier le costume.

```bash
cp inc/armors/Witch_Costume_Blue_Skirt.inc inc/armors/Witch_Costume_Gray_Skirt.inc
```

Dans la copie, ajouter une texture grise à côté de `T_Pleaded_Blue` :

```pov
#declare T_Pleaded_Gray = texture {
	pigment {
		radial
		color_map {
			[0, Gray50]
			[0.5 Gray50 * 0.5]
			[1 Gray50]
		}
		frequency 16
	}
}
```

puis, dans le bloc de la jupe, renommer `O_Skirt_Blue` en `O_Skirt_Gray` et
remplacer `texture { T_Pleaded_Blue }` par `texture { T_Pleaded_Gray }` (seulement
dans `O_Skirt_Gray` : le haut et les épaules restent bleus), et finir par
`#declare P_BodyPart_ArmorPart_Skirt = O_Skirt_Gray;`.
Pour tout le costume en gris, remplacer `Blue` par `Gray50` partout dans la copie.

**2. La scène** : copier le personnage et changer l'include du costume.

```bash
cp c_witch_blue.pov c_witch_gray.pov
```

```pov
#include "inc/armors/Witch_Costume_Gray_Skirt"   // au lieu de Witch_Costume_Blue_Skirt
```

**3. La recette** : copier et changer la scène.

```bash
cp sprites/witch.json sprites/witch_gray.json
```

```json
"scene": "c_witch_gray.pov",
```

**4. Générer et vérifier.**

```bash
tools/sprites.py sprites/witch_gray.json --preview
cd viewer && node snapshot.mjs witch_gray idle
```

On obtient `output/witch_gray.png` et `output/witch_gray.json`, à côté de
`output/witch.png` (bleue), inchangée.

Pour une variante qui ne change que des couleurs de peau, de cheveux ou des
pièces déjà disponibles dans `inc/armors/`, `inc/hair/` ou `inc/weapons/`, seules
les étapes 2 à 4 sont nécessaires : on change les `#declare T_*` ou les `#include`
dans la copie de la scène.

## Décors (objets sans animation)

Les décors suivent le même principe que les personnages, avec le préfixe `p_`
(les créatures ont `c_`) :

| Fichier | Contenu |
|---|---|
| `p_<objet>.pov` | la scène : inclut `inc/Camera.inc` (lumière) et place l'objet |
| `inc/props/<Objet>.inc` | l'objet réutilisable (`Barrel.inc`, `Chain.inc`, `Lantern.inc`…) |
| `sprites/<objet>.json` | la recette : une seule image, une seule direction |

```json
{
	"scene": "p_barrel.pov",
	"frame": { "width": 64, "height": 96, "units_height": 6.0, "baseline": 0.1 },
	"animations": [
		{ "id": "default", "poses": [0], "directions": 1, "duration": 1000, "loop": "@LOOP_NONE" }
	]
}
```

- **Échelle** : la même que les personnages (un humain fait 4,5 unités, le tonneau 2).
- **Objet au sol** : sa base est en `y = 0`.
- **Objet suspendu** : le haut du cadre correspond au plafond du moteur. On
  l'accroche à `N_Prop_Ceiling` (`inc/props/Props.inc`), comme `p_chain.pov` et
  `p_lantern.pov`. La macro `Chain(N_Maillons, N_Echelle)` de `inc/props/Chain.inc`
  fabrique une chaîne de la longueur voulue.
- **Objet asymétrique** (charrette, chaise) : `"directions": 8` et
  `rotate y * N_Animation_Angle` sur l'objet dans la scène.
- **Objet animé** (flamme) : plusieurs poses, lues dans la scène avec `N_Pose_From`
  (voir `inc/Animation.inc`).
- **Objet lumineux** (lanterne, torche) : dans le jeu, marquer le blueprint
  `FX_LIGHT_SOURCE` pour qu'il ne soit pas assombri par la distance.

## Modifier ou ajouter des poses

1. Ajouter un `#case (N)` dans le fichier `inc/frames/` du personnage ; il ne déclare
   que ce qui diffère de la pose de repos (`Pose_Reset()` dans `inc/Pose.inc`).
2. L'utiliser dans `poses` de la recette, puis régénérer.
3. Vérifier qu'aucune image ne déborde du cadre (`--preview`) et le rendu dans le moteur.

Articulations : `AV_Thigh_*`, `AV_Shin_*`, `AV_Arm_*`, `AV_Wrist_*` (membres, `x > 0` =
vers l'avant), `AV_Torso` (haut du corps, autour des hanches), `AV_Head`, `AV_Body`
(corps entier, autour du sol), `V_Body_Offset` (déplacement). Pour le torse, la tête
et le corps, `x < 0` penche en avant.

## Modifier les fichiers de base (`inc/body/`, `inc/Pose.inc`, `inc/Animation.inc`)

Ils servent à tous les personnages. Avant de les toucher :

```bash
tools/regress.py save    # rendus de référence : tous les personnages, toutes les poses, 8 directions
# ... modifications ...
tools/regress.py check   # comparaison pixel à pixel
```

Quelques pixels d'écart sur des textures procédurales (bouclier du chevalier)
viennent d'arrondis ; au-delà, regarder les images dans `output/regress/`.

## Rendre une image isolée

```bash
povray +Ic_witch_blue.pov +Otest.png +W256 +H192 +UA +A +K7 -D
```

`+K` vaut `100 × direction + pose` (direction POV : 0 = face, 2 = profil nez à
gauche…), ici la pose 7 vue de face. C'est la caméra de prévisualisation de
`inc/Camera.inc`, pas celle des planches. L'ancien script `render` fonctionne
encore mais n'est plus utilisé : ses en-têtes `@frames` dans les `.pov` ne sont
plus à jour.
