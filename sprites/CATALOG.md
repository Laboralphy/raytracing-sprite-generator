# Catalogue des sprites

> Généré par `tools/catalog.py` (et à chaque `tools/sprites.py`) depuis `sprites/*.json`
> et les commentaires des `#case` de `inc/frames/*.inc`. Ne pas éditer à la main.

- **Directions** (moteur) : `d` = 0 dos, 2 nez vers la droite de l'écran, 4 face, 6 nez vers la gauche.
  Une animation à 8 directions a sa première tuile en `début + longueur·d` ; une animation à 1 direction
  est rendue sous la vue indiquée et sert pour les 8.
- **Tuile** : index dans la bande `output/<sprite>.png` (x = index × largeur du cadre).
- **Poses** : `n NOM` = pose n de `inc/frames/` ; `a→b (x %)` = pose a mélangée vers b.

| Sprite | Cadre | Images | Animations |
|---|---|---|---|
| [barrel](#barrel) | 64×96 | 1 | `default` |
| [chain](#chain) | 64×96 | 1 | `default` |
| [cube](#cube) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [dummy_archer](#dummy_archer) | 64×96 | 102 | `idle`, `walk`, `attack`, `pain`, `death` |
| [dummy_small](#dummy_small) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [ghoul](#ghoul) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [goblin](#goblin) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [goblin_warrior](#goblin_warrior) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [jack](#jack) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [knight](#knight) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [lantern](#lantern) | 64×96 | 1 | `default` |
| [mummy](#mummy) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [skeleton](#skeleton) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [skeleton_archer](#skeleton_archer) | 64×96 | 102 | `idle`, `walk`, `attack`, `pain`, `death` |
| [slime](#slime) | 96×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [troll](#troll) | 96×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |
| [witch](#witch) | 64×96 | 86 | `idle`, `walk`, `attack`, `pain`, `death` |
| [wizard_blue](#wizard_blue) | 64×96 | 86 | `idle`, `walk`, `attack`, `pain`, `death` |
| [wizard_red](#wizard_red) | 64×96 | 86 | `idle`, `walk`, `attack`, `pain`, `death` |
| [zombie](#zombie) | 64×96 | 94 | `idle`, `walk`, `attack`, `pain`, `death` |

## barrel

Scène `p_barrel.pov`. Cadre 64×96, 1 image (64 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `default` | 1 | 1 | 0 (vue 4) | 1000 ms | NONE | 0 |

## chain

Scène `p_chain.pov`. Cadre 64×96, 1 image (64 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `default` | 1 | 1 | 0 (vue 4) | 1000 ms | NONE | 0 |

## cube

Scène `c_cube.pov`, poses `inc/frames/cube.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 IDLE 1 · 1 IDLE 2 |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 2 WALK 1 · 3 WALK 2 · 4 WALK 3 · 5 WALK 4 |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 6 ATTACK 1 · 7 ATTACK 2 · 7→0 (50%) |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 8 PAIN · 8→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 9 DEATH 1 · 10 DEATH 2 · 11 DEATH 3 · 12 DEATH 4 · 13 DEATH 5 · 14 DEATH 6 |

<details><summary>Poses</summary>

- **0** : IDLE 1: glowing red
- **1** : IDLE 2: the glow breathes, darker
- **2** : WALK 1: rest
- **3** : WALK 2: lifts its back on the front edge, heating up with the effort
- **4** : WALK 3: on the edge
- **5** : WALK 4: falls on the next face
- **6** : ATTACK 1: rocks back on its back edge, heating up
- **7** : ATTACK 2: lunges on its front edge, white hot
- **8** : PAIN: knocked back on its back edge, the glow sputters
- **9** : DEATH 1: overheats and shudders
- **10** : DEATH 2: topples forward
- **11** : DEATH 3: on its edge, cooling
- **12** : DEATH 4: falling face down
- **13** : DEATH 5: face down, the face on top now looks forward, embers
- **14** : DEATH 6: cold

</details>

## dummy_archer

Scène `c_dummy_archer.pov`, poses `inc/frames/archer.inc`. Cadre 64×96, 102 images (6528 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 8 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 5 WALK 1 · 6 WALK 2 · 7 WALK 3 · 7→5 (50%) |
| `attack` | 4 | 8 | 48 + 4·d | 150 ms | NONE | 1 ATTACK 1 · 2 ATTACK 2 · 3 ATTACK 3 · 4 ATTACK 4 |
| `pain` | 2 | 8 | 80 + 2·d | 150 ms | NONE | 9 PAIN · 9→0 (50%) |
| `death` | 6 | 1 | 96 (vue 3) | 120 ms | NONE | 10 DEATH 1 · 11 DEATH 2 · 12 DEATH 3 · 13 DEATH 4 · 13→14 (50%) · 14 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1: aim, bow raised, arrow nocked, string at rest
- **2** : ATTACK 2: half draw
- **3** : ATTACK 3: full draw, string at the cheek
- **4** : ATTACK 4: release, the arrow is gone, the hand flies back
- **5** : WALK 1: left leg forward, right arm forward
- **6** : WALK 2: passing
- **7** : WALK 3: right leg forward, left arm forward
- **8** : IDLE: weight on one leg, head turned
- **9** : PAIN: thrown backward, arms flung out
- **10** : DEATH 1: hit, head snapping back, arms flung forward
- **11** : DEATH 2: tipping backward, knees giving way
- **12** : DEATH 3: falling on the back
- **13** : DEATH 4: hitting the ground, knees up
- **14** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## dummy_small

Scène `c_dummy_small.pov`, poses `inc/frames/small.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 7 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 110 ms | FORWARD | 3 TROT 1 · 4 TROT 2 · 5 TROT 3 · 6 TROT 4 |
| `attack` | 3 | 8 | 48 + 3·d | 130 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 8 PAIN · 8→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 9 DEATH 1 · 10 DEATH 2 · 11 DEATH 3 · 12 DEATH 4 · 12→13 (50%) · 13 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND: knees slightly bent, sword ready
- **1** : ATTACK 1: sword raised over the shoulder, crouching
- **2** : ATTACK 2: slash, lunging
- **3** : TROT 1: left foot reaching forward, right foot kicked back, in the air
- **4** : TROT 2: on the left foot, right leg tucked, lowest point
- **5** : TROT 3: right foot reaching forward, left foot kicked back, in the air
- **6** : TROT 4: on the right foot, left leg tucked, lowest point
- **7** : IDLE: shifting weight, shoulders up, head nearly still
- **8** : PAIN: thrown backward
- **9** : DEATH 1: hit, head snapping back, arms flung forward
- **10** : DEATH 2: tipping backward, knees giving way
- **11** : DEATH 3: falling on the back
- **12** : DEATH 4: hitting the ground, knees up
- **13** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## ghoul

Scène `c_ghoul_1.pov`, poses `inc/frames/zombie.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 3 WALK 1 · 4 WALK 2 · 5 WALK 3 · 5→3 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 (shift_x 0.1) | 88 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1
- **2** : ATTACK 2
- **3** : WALK 1
- **4** : WALK 2
- **5** : WALK 3
- **6** : IDLE: swaying, head hanging
- **7** : PAIN: thrown backward
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## goblin

Scène `c_goblin.pov`, poses `inc/frames/small.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 7 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 110 ms | FORWARD | 3 TROT 1 · 4 TROT 2 · 5 TROT 3 · 6 TROT 4 |
| `attack` | 3 | 8 | 48 + 3·d | 130 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 8 PAIN · 8→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 9 DEATH 1 · 10 DEATH 2 · 11 DEATH 3 · 12 DEATH 4 · 12→13 (50%) · 13 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND: knees slightly bent, sword ready
- **1** : ATTACK 1: sword raised over the shoulder, crouching
- **2** : ATTACK 2: slash, lunging
- **3** : TROT 1: left foot reaching forward, right foot kicked back, in the air
- **4** : TROT 2: on the left foot, right leg tucked, lowest point
- **5** : TROT 3: right foot reaching forward, left foot kicked back, in the air
- **6** : TROT 4: on the right foot, left leg tucked, lowest point
- **7** : IDLE: shifting weight, shoulders up, head nearly still
- **8** : PAIN: thrown backward
- **9** : DEATH 1: hit, head snapping back, arms flung forward
- **10** : DEATH 2: tipping backward, knees giving way
- **11** : DEATH 3: falling on the back
- **12** : DEATH 4: hitting the ground, knees up
- **13** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## goblin_warrior

Scène `c_goblin_warrior.pov`, poses `inc/frames/small.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 7 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 110 ms | FORWARD | 3 TROT 1 · 4 TROT 2 · 5 TROT 3 · 6 TROT 4 |
| `attack` | 3 | 8 | 48 + 3·d | 130 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 8 PAIN · 8→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 9 DEATH 1 · 10 DEATH 2 · 11 DEATH 3 · 12 DEATH 4 · 12→13 (50%) · 13 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND: knees slightly bent, sword ready
- **1** : ATTACK 1: sword raised over the shoulder, crouching
- **2** : ATTACK 2: slash, lunging
- **3** : TROT 1: left foot reaching forward, right foot kicked back, in the air
- **4** : TROT 2: on the left foot, right leg tucked, lowest point
- **5** : TROT 3: right foot reaching forward, left foot kicked back, in the air
- **6** : TROT 4: on the right foot, left leg tucked, lowest point
- **7** : IDLE: shifting weight, shoulders up, head nearly still
- **8** : PAIN: thrown backward
- **9** : DEATH 1: hit, head snapping back, arms flung forward
- **10** : DEATH 2: tipping backward, knees giving way
- **11** : DEATH 3: falling on the back
- **12** : DEATH 4: hitting the ground, knees up
- **13** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## jack

Scène `c_jack.pov`, poses `inc/frames/jack.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 3 | 8 | 0 + 3·d | 250 ms | YOYO | 0 FLOAT 1 · 1 FLOAT 2 · 2 FLOAT 3 |
| `walk` | 4 | 8 | 24 + 4·d | 150 ms | FORWARD | 3 MOVE 1 · 4 MOVE 2 · 5 MOVE 3 · 4 MOVE 2 |
| `attack` | 2 | 8 | 56 + 2·d | 150 ms | NONE | 6 ATTACK · 6→0 (75%) |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 | 88 (vue 4) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 10→11 (50%) · 11 DEATH 4 · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : FLOAT 1
- **1** : FLOAT 2
- **2** : FLOAT 3
- **3** : MOVE 1: gliding, leaning forward
- **4** : MOVE 2
- **5** : MOVE 3
- **6** : ATTACK: fire, lantern held out and kicking up a little (recoil), blazing
- **7** : PAIN: thrown backward, flame flickering
- **8** : DEATH 1: shudder, flame dying
- **9** : DEATH 2: the robe starts to empty
- **10** : DEATH 3: collapsing, the pumpkin falls
- **11** : DEATH 4: on the ground
- **12** : DEATH 5: empty robe, pumpkin rolled over, lantern out

</details>

## knight

Scène `c_knight_mace.pov`, poses `inc/frames/knight.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 3 WALK 1 · 4 WALK 2 · 5 WALK 3 · 5→3 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 (shift_x 0.2) | 88 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1: weapon raised
- **2** : ATTACK 2: strike
- **3** : WALK 1
- **4** : WALK 2
- **5** : WALK 3
- **6** : IDLE: guard relaxed, shield a little lower
- **7** : PAIN: thrown backward, shield knocked aside
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## lantern

Scène `p_lantern.pov`. Cadre 64×96, 1 image (64 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `default` | 1 | 1 | 0 (vue 4) | 1000 ms | NONE | 0 |

## mummy

Scène `c_mummy_1.pov`, poses `inc/frames/mummy.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 500 ms | YOYO | 0 STAND · 7 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 200 ms | FORWARD | 4 WALK 1 · 5 WALK 2 · 6 WALK 3 · 6→4 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 1 ATTACK 1 · 2 ATTACK 2 · 3 ATTACK 3 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 8 PAIN · 8→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 9 DEATH 1 · 10 DEATH 2 · 11 DEATH 3 · 12 DEATH 4 · 12→13 (50%) · 13 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1: mace raised
- **2** : ATTACK 2: strike
- **3** : ATTACK 3: left hand forward
- **4** : WALK 1
- **5** : WALK 2
- **6** : WALK 3
- **7** : IDLE: slumped, head hanging on the side
- **8** : PAIN: thrown backward
- **9** : DEATH 1: hit, head snapping back, arms flung forward
- **10** : DEATH 2: tipping backward, knees giving way
- **11** : DEATH 3: falling on the back
- **12** : DEATH 4: hitting the ground, knees up
- **13** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## skeleton

Scène `c_skeleton_1.pov`, poses `inc/frames/skeleton.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 3 WALK 1 · 4 WALK 2 · 5 WALK 3 · 5→3 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND: sword held low, pointing forward
- **1** : ATTACK 1: sword raised over the shoulder
- **2** : ATTACK 2: slash
- **3** : WALK 1: left leg forward, right arm forward
- **4** : WALK 2: passing
- **5** : WALK 3: right leg forward, left arm forward
- **6** : IDLE: head tilted, sword lowered
- **7** : PAIN: thrown backward, arms flung out
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, skull turned aside

</details>

## skeleton_archer

Scène `c_skeleton_archer.pov`, poses `inc/frames/archer.inc`. Cadre 64×96, 102 images (6528 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 8 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 5 WALK 1 · 6 WALK 2 · 7 WALK 3 · 7→5 (50%) |
| `attack` | 4 | 8 | 48 + 4·d | 150 ms | NONE | 1 ATTACK 1 · 2 ATTACK 2 · 3 ATTACK 3 · 4 ATTACK 4 |
| `pain` | 2 | 8 | 80 + 2·d | 150 ms | NONE | 9 PAIN · 9→0 (50%) |
| `death` | 6 | 1 (shift_x 0.1) | 96 (vue 3) | 120 ms | NONE | 10 DEATH 1 · 11 DEATH 2 · 12 DEATH 3 · 13 DEATH 4 · 13→14 (50%) · 14 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1: aim, bow raised, arrow nocked, string at rest
- **2** : ATTACK 2: half draw
- **3** : ATTACK 3: full draw, string at the cheek
- **4** : ATTACK 4: release, the arrow is gone, the hand flies back
- **5** : WALK 1: left leg forward, right arm forward
- **6** : WALK 2: passing
- **7** : WALK 3: right leg forward, left arm forward
- **8** : IDLE: weight on one leg, head turned
- **9** : PAIN: thrown backward, arms flung out
- **10** : DEATH 1: hit, head snapping back, arms flung forward
- **11** : DEATH 2: tipping backward, knees giving way
- **12** : DEATH 3: falling on the back
- **13** : DEATH 4: hitting the ground, knees up
- **14** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## slime

Scène `c_slime.pov`, poses `inc/frames/slime.inc`. Cadre 96×96, 94 images (9024 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 IDLE 1 · 1 IDLE 2 |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 2 WALK 1 · 3 WALK 2 · 4 WALK 3 · 5 WALK 4 |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 6 ATTACK 1 · 7 ATTACK 2 · 8 ATTACK 3 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 9 PAIN · 9→0 (50%) |
| `death` | 6 | 1 (caméra 20°) | 88 (vue 3) | 120 ms | NONE | 10 DEATH 1 · 11 DEATH 2 · 12 DEATH 3 · 13 DEATH 4 · 14 DEATH 5 · 15 DEATH 6 |

<details><summary>Poses</summary>

- **0** : IDLE 1
- **1** : IDLE 2: swells a little
- **2** : WALK 1
- **3** : WALK 2
- **4** : WALK 3
- **5** : WALK 4
- **6** : ATTACK 1: rears up, leaning back
- **7** : ATTACK 2: spits, thrown forward
- **8** : ATTACK 3: settles back
- **9** : PAIN: squashed and knocked aside
- **10** : DEATH 1: shudders and stretches up
- **11** : DEATH 2: sags
- **12** : DEATH 3: crushed flat
- **13** : DEATH 4: wobbles back up
- **14** : DEATH 5: settles
- **15** : DEATH 6: puddle

</details>

## troll

Scène `c_troll_1.pov`, poses `inc/frames/troll.inc`. Cadre 96×96, 94 images (9024 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 3 WALK 1 · 4 WALK 2 · 5 WALK 3 · 5→3 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1: right claw drawn back
- **2** : ATTACK 2: strike
- **3** : WALK 1
- **4** : WALK 2
- **5** : WALK 3
- **6** : IDLE: hunched, swaying, arms hanging
- **7** : PAIN: thrown backward, arms flung up
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## witch

Scène `c_witch_blue.pov`, poses `inc/frames/witch.inc`. Cadre 64×96, 86 images (5504 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 2 WALK 1 · 3 WALK 2 · 4 WALK 3 · 4→2 (50%) |
| `attack` | 2 | 8 | 48 + 2·d | 150 ms | NONE | 5 ATTACK · 5→0 (75%) |
| `pain` | 2 | 8 | 64 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 (shift_x 0.2) | 80 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK: wand forward *(inutilisée)*
- **2** : WALK 1
- **3** : WALK 2
- **4** : WALK 3
- **5** : ATTACK: fire, wand held out, kicking up a little (recoil), flash at the tip
- **6** : IDLE: hand on the hip, head tilted
- **7** : PAIN: thrown backward
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>

## wizard_blue

Scène `c_wizard_blue.pov`, poses `inc/frames/wizard.inc`. Cadre 64×96, 86 images (5504 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 600 ms | YOYO | 0 ROBE SHAPE 1 · 0→1 (30%) |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 0 ROBE SHAPE 1 · 0→1 (50%) · 1 ROBE SHAPE 2 · 1→0 (50%) |
| `attack` | 2 | 8 | 48 + 2·d | 150 ms | NONE | 2 ATTACK · 2→0 (75%) |
| `pain` | 2 | 8 | 64 + 2·d | 150 ms | NONE | 3 PAIN · 3→0 (50%) |
| `death` | 6 | 1 | 80 (vue 4) | 120 ms | NONE | 4 DEATH 1 · 5 DEATH 2 · 6 DEATH 3 · 6→7 (50%) · 7 DEATH 4 · 8 DEATH 5 |

<details><summary>Poses</summary>

- **0** : ROBE SHAPE 1
- **1** : ROBE SHAPE 2
- **2** : ATTACK: fire, the wand kicks up a little (recoil), flash at the tip
- **3** : PAIN: thrown backward
- **4** : DEATH 1: shudder
- **5** : DEATH 2: the robe starts to sink, the head and the hands fade
- **6** : DEATH 3: collapsing, the head and the hands fading out
- **7** : DEATH 4: on the ground
- **8** : DEATH 5: empty robe, the hat lying on it

</details>

## wizard_red

Scène `c_wizard_red.pov`, poses `inc/frames/wizard.inc`. Cadre 64×96, 86 images (5504 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 600 ms | YOYO | 0 ROBE SHAPE 1 · 0→1 (30%) |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 0 ROBE SHAPE 1 · 0→1 (50%) · 1 ROBE SHAPE 2 · 1→0 (50%) |
| `attack` | 2 | 8 | 48 + 2·d | 150 ms | NONE | 2 ATTACK · 2→0 (75%) |
| `pain` | 2 | 8 | 64 + 2·d | 150 ms | NONE | 3 PAIN · 3→0 (50%) |
| `death` | 6 | 1 | 80 (vue 4) | 120 ms | NONE | 4 DEATH 1 · 5 DEATH 2 · 6 DEATH 3 · 6→7 (50%) · 7 DEATH 4 · 8 DEATH 5 |

<details><summary>Poses</summary>

- **0** : ROBE SHAPE 1
- **1** : ROBE SHAPE 2
- **2** : ATTACK: fire, the wand kicks up a little (recoil), flash at the tip
- **3** : PAIN: thrown backward
- **4** : DEATH 1: shudder
- **5** : DEATH 2: the robe starts to sink, the head and the hands fade
- **6** : DEATH 3: collapsing, the head and the hands fading out
- **7** : DEATH 4: on the ground
- **8** : DEATH 5: empty robe, the hat lying on it

</details>

## zombie

Scène `c_zombie_1.pov`, poses `inc/frames/zombie.inc`. Cadre 64×96, 94 images (6016 px de large).

| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |
|---|---|---|---|---|---|---|
| `idle` | 2 | 8 | 0 + 2·d | 400 ms | YOYO | 0 STAND · 6 IDLE |
| `walk` | 4 | 8 | 16 + 4·d | 150 ms | FORWARD | 3 WALK 1 · 4 WALK 2 · 5 WALK 3 · 5→3 (50%) |
| `attack` | 3 | 8 | 48 + 3·d | 150 ms | NONE | 0→1 (50%) · 1 ATTACK 1 · 2 ATTACK 2 |
| `pain` | 2 | 8 | 72 + 2·d | 150 ms | NONE | 7 PAIN · 7→0 (50%) |
| `death` | 6 | 1 | 88 (vue 3) | 120 ms | NONE | 8 DEATH 1 · 9 DEATH 2 · 10 DEATH 3 · 11 DEATH 4 · 11→12 (50%) · 12 DEATH 5 |

<details><summary>Poses</summary>

- **0** : STAND
- **1** : ATTACK 1
- **2** : ATTACK 2
- **3** : WALK 1
- **4** : WALK 2
- **5** : WALK 3
- **6** : IDLE: swaying, head hanging
- **7** : PAIN: thrown backward
- **8** : DEATH 1: hit, head snapping back, arms flung forward
- **9** : DEATH 2: tipping backward, knees giving way
- **10** : DEATH 3: falling on the back
- **11** : DEATH 4: hitting the ground, knees up
- **12** : DEATH 5: lying on the back, arms and legs fallen flat, head turned aside

</details>
