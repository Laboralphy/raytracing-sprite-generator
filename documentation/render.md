# Rendu : commandes disponibles

Toutes les commandes se lancent **depuis la racine du dépôt**. Les fichiers
générés vont dans `output/` (ignoré par git, régénérable à tout moment).

Voir aussi : [npc.md](npc.md) (créatures), [things.md](things.md) (décors),
`sprites/CATALOG.md` (détail des animations de chaque planche).

## En bref

| Je veux… | Commande |
|---|---|
| la planche d'une créature ou d'un décor | `tools/sprites.py sprites/goblin.json` |
| la planche + une grille de contrôle | `tools/sprites.py sprites/goblin.json --preview` |
| toutes les planches | `for f in sprites/*.json; do tools/sprites.py "$f" --preview; done` |
| des bords plus lisses | `tools/sprites.py sprites/goblin.json --supersample 2` |
| les GIF animés d'une planche | `tools/gifs.py goblin` |
| la vue dans le moteur (8 directions) | `cd viewer && node snapshot.mjs goblin walk` |
| la visionneuse interactive | `cd viewer && npx vite` puis `http://localhost:5173/?sheet=goblin&anim=walk` |
| une image isolée (une pose, une direction) | `povray +Ic_goblin.pov +Oout.png +W256 +H192 +UA -A +K103 -D -GA` |
| les vignettes de la documentation | `tools/thumbnails.py` |
| le catalogue des animations | `tools/catalog.py` |
| vérifier qu'un fichier de base ne casse rien | `tools/regress.py save`, modifier, puis `tools/regress.py check` |

Prérequis : POV-Ray 3.7, Python 3, ImageMagick (`convert`, `compare`) ; Node.js
pour `viewer/` (une fois : `cd viewer && npm install`).

## `tools/sprites.py` : planches de sprites

```bash
tools/sprites.py sprites/<nom>.json [--preview] [--supersample N] [--jobs N] [--out DOSSIER]
```

| Option | Effet |
|---|---|
| `--preview` | écrit aussi `<nom>.preview.png` : une ligne par animation et par direction, fond vert, agrandi ×2 |
| `--supersample N` | rend N fois plus grand puis réduit (filtre box) : bords plus lisses, ~N² fois plus lent. Remplace la clé `"supersample"` de la spec |
| `--jobs N` | nombre de rendus POV-Ray en parallèle (défaut : nombre de cœurs) |
| `--out DOSSIER` | dossier de sortie (défaut : `output/`). Attention : le fichier `<nom>.json` de sortie a le même nom que la spec, ne pas sortir dans le dossier de la spec |

Sorties dans `output/` :

| Fichier | Usage |
|---|---|
| `<nom>.png` | **la planche** : une bande horizontale de cadres (ordre : animation, puis direction, puis image) |
| `<nom>.json` | **le tileset** RCE-100 (`width`, `height`, `animations[{id, start[8], length, duration, loop}]`) à reprendre dans le jeu |
| `<nom>.preview.png` | (avec `--preview`) la grille de contrôle |

Chaque appel régénère aussi `sprites/CATALOG.md`.

### La spec `sprites/<nom>.json`

```json
{
	"scene": "c_goblin.pov",
	"frame": { "width": 64, "height": 96, "units_height": 6.0, "baseline": 0.1 },
	"shadow": { "radius": 0.6, "opacity": 0.45 },
	"supersample": 1,
	"animations": [
		{ "id": "idle", "poses": [0, 7], "duration": 400, "loop": "@LOOP_YOYO" },
		{ "id": "walk", "poses": [3, 4, 5, 6], "duration": 110, "loop": "@LOOP_FORWARD" },
		{ "id": "death", "poses": [9, 10, 11, 12, [12, 13, 0.5], 13], "directions": 1, "view": 3, "duration": 120, "loop": "@LOOP_NONE" }
	]
}
```

| Clé | Sens |
|---|---|
| `scene` | la scène POV-Ray (`c_*.pov` créature, `p_*.pov` décor) |
| `frame.width` / `height` | taille d'un cadre en pixels (64×96 ; 96×96 pour les grands monstres) |
| `frame.units_height` | unités POV couvertes par la hauteur du cadre : **6 partout**, sinon les échelles diffèrent en jeu |
| `frame.baseline` | unités POV entre le bas du cadre et le sol (0,1 ; 0,35 pour les décors posés avec ombre) |
| `shadow` | ombre au sol : `radius`, `opacity`, `height` (facultatif) |
| `supersample` | voir `--supersample` |
| `poses` | numéros de pose (`inc/frames/<fichier>.inc`) ou `[de, vers, mélange]` |
| `directions` | 8 (défaut) ou 1 (rendue une fois, répétée pour les 8 directions : mort, décor) |
| `view` | direction moteur utilisée quand `directions` vaut 1 (4 = face ; 3 = trois quarts, pour les morts) |
| `camera_elevation` | angle de plongée de la caméra, en degrés (15 pour les décors posés au sol) |
| `shift_x` | décale le personnage dans le cadre (unités POV), par exemple un cadavre qui déborde |
| `duration` | ms par image |
| `loop` | `@LOOP_NONE`, `@LOOP_FORWARD`, `@LOOP_YOYO` |

Directions (convention du moteur, `src/render/spriteFacing.ts`) : 0 = dos,
2 = nez vers la droite de l'écran, 4 = face, 6 = nez vers la gauche.

## `tools/gifs.py` : animations en GIF

Lit `output/<nom>.png` et `output/<nom>.json` : lancer `tools/sprites.py` avant.

```bash
tools/gifs.py goblin witch                 # output/gif/goblin_idle.gif, goblin_walk.gif, ...
tools/gifs.py --all                        # toutes les planches de output/
tools/gifs.py goblin --anim attack death   # seulement ces animations
tools/gifs.py goblin --view face side      # + output/gif/goblin_<anim>_side.gif (profil)
```

| Option | Effet |
|---|---|
| `--anim A [B ...]` | seulement ces animations |
| `--view face side` | `face` : vue de face (défaut) ; `side` : de profil, fichiers `_side.gif` |
| `--scale 3` | agrandissement, sans lissage (défaut 3) |
| `--background '#3a3632'` | fond uni (un GIF ne gère pas la semi-transparence) |
| `--hold 100` | pause sur la dernière image d'une animation qui ne boucle pas (attaque, mort), en 1/100 s |

Vitesse : la `duration` de la spec ; `@LOOP_YOYO` joue l'aller-retour.

## Contrôle dans le moteur (`viewer/`)

`viewer/` est lié à `../raycaster-386` (`file:`). Après un changement du moteur,
y relancer `npm run build`.

```bash
cd viewer
node snapshot.mjs goblin            # output/goblin.engine.png : 8 vues, sans navigateur
node snapshot.mjs goblin attack     # une animation précise
npx vite                            # http://localhost:5173/?sheet=goblin&anim=walk
```

Le personnage regarde vers +x : il doit toujours regarder vers la bande sombre
du sol. Sinon, l'ordre des directions est faux.

## Image isolée avec POV-Ray

Pour essayer une pose ou une pièce sans refaire toute la planche :

```bash
povray +Ic_goblin.pov +Ooutput/test.png +W256 +H192 +UA -A +K<clock> -D -GA
```

- `clock = 100 × direction POV + pose`, décodé dans `inc/Camera.inc` /
  `inc/Animation.inc`. Direction POV 0 = face (`direction POV = (direction moteur + 4) mod 8`).
  Exemple : `+K203` = pose 3, de profil.
- `+1000` = mode dev : caméra orthographique de face, avec un sol blanc et un fond
  en damier (utile pour voir les pieds et la silhouette, mais le personnage y est petit).
- Pose intermédiaire : `Declare=N_Pose_From=3 Declare=N_Pose_To=4 Declare=N_Pose_Blend=0.5`.
- `+UA` : fond transparent ; `-A` : sans antialiasing (plus rapide pour itérer).

Cette caméra n'est pas celle des planches. Pour voir exactement le cadrage du jeu
en plus grand, faire une spec temporaire avec un cadre agrandi (par exemple
`"width": 256, "height": 384, "units_height": 6.0`) et la rendre avec
`--out` vers un **autre** dossier que celui de la spec.

## Outils annexes

| Outil | Rôle |
|---|---|
| `tools/thumbnails.py [noms…]` | vignettes `documentation/img/<nom>.png` depuis `output/` (créature : face, trois quarts, profil, dos ; décor : son image). Options `--scale`, `--background` |
| `tools/catalog.py` | régénère `sprites/CATALOG.md` (animations, première tuile, libellé des poses tiré des `#case` de `inc/frames/`) |
| `tools/regress.py save` / `check [scènes…]` | non-régression des fichiers de base : toutes poses × 8 directions, comparaison pixel à pixel (`output/regress/`) |
| `tools/goblin_face.py` | régénère la texture de visage `png/goblin_face.png` |
| `render -r <scene>` / `render -p <scene> <clock>` | ancien script bash (512×384), remplacé par `tools/sprites.py` |

## Scène d'Halloween (hors jeu)

Depuis `halloween/` (voir `halloween/scene.md`) :

```bash
cd halloween
povray +Ihalloween.pov +O../output/halloween.png +W1920 +H1080 +A0.1 +AM2 +R3 -D
```
