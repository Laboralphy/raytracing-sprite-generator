# Scène d'Halloween

## La demande

Tester jusqu'où va la créativité avec POV-Ray : créer une scène entière sur le thème d'Halloween, avec toute liberté de mise en scène, d'assets et de composition, dans le dossier `halloween/`, puis en faire un rendu en haute résolution.

## Ce qui a été fait

### Mise en scène

Une composition de carte postale, en profondeur :

- **Fond** : une énorme pleine lune, avec un halo et des « mers » plus sombres, dans un ciel de nuit étoilé qui vire au violet sombre à l'horizon. Devant elle, sur une colline, une maison victorienne hantée en contre-jour : tour à toit pointu, pignons, cheminée de travers, quelques fenêtres éclairées en jaune. Deux arbres morts l'encadrent.
- **Plan moyen** : un cimetière derrière une grille en fer forgé à pointes. Les deux piliers du portail laissent passer un chemin de terre vers la colline. Les pierres tombales moussues, gravées « R.I.P. » ou « 1666 », et les croix de pierre penchent de travers.
- **Premier plan** : quatre citrouilles sculptées, éclairées de l'intérieur par une bougie. Il y a trois expressions : yeux triangulaires et sourire en dents de scie, regard furieux, air surpris. Leur lumière orangée sort par les découpes et éclaire le sol.
- **Encadrement** : un grand arbre mort tortueux à gauche, dont les branches s'étalent dans le ciel.
- **Ambiance** : des chauves-souris, dont trois en silhouette devant la lune, et une brume basse au ras du sol. La lumière de la lune, froide et bleutée, arrive par l'arrière, ce qui crée un contraste avec le orange des citrouilles.

### Fichiers

| Fichier | Contenu |
|---|---|
| `halloween.pov` | la scène : caméra, ciel et étoiles, lune et halo, lumières, brume, sol, colline, chemin, cimetière, grille, placement des assets |
| `inc/Pumpkin.inc` | citrouille côtelée (10 lobes), creusée, couvercle découpé et pédoncule, trois visages ; une lampe intérieure (bougie) éclaire à travers les découpes |
| `inc/Tombstone.inc` | pierre tombale à sommet arrondi avec texte gravé (police `timrom.ttf`) et coin ébréché, croix de pierre ; pierre granitique avec de la mousse |
| `inc/DeadTree.inc` | arbre mort récursif : branches tortueuses en `sphere_sweep`, ramifiées au hasard (graine fixe), racines |
| `inc/House.inc` | maison hantée pour silhouette lointaine : corps, aile, tour, toits, cheminée, fenêtres éclairées ou sombres |
| `inc/Bat.inc` | chauve-souris aux ailes festonnées, battement réglable |

### Rendu

Depuis le dossier `halloween/` :

```
povray +Ihalloween.pov +O../output/halloween.png +W1920 +H1080 +A0.1 +AM2 +R3 -D
```

Il donne `output/halloween.png` (1920×1080, environ 10 s). L'image est générée : elle reste dans `output/`, hors de git.

### Itérations

Chaque version a été rendue en basse résolution et regardée avant de passer à la suivante :

1. Premier jet : la brume, trop épaisse et trop claire, délavait toute la scène ; les étoiles faisaient un bruit blanc ; le halo dessinait un anneau sombre autour de la lune ; les citrouilles étaient coupées par le bas du cadre.
2. Ciel plus sombre, brume plus légère et plus basse, halo placé derrière la lune, caméra reculée.
3. Les visages des citrouilles étaient découpés à l'arrière : le sens d'extrusion des prismes était inversé. Après correction, elles brillent par l'avant.
4. Arbre au premier plan refait (tronc plus épais, branches plus tortueuses et étalées), texture du sol sans effet de dalles, chauves-souris plus grandes devant la lune.
5. En haute résolution, les étoiles devenaient de petits tortillons (lignes de contour du motif) : elles ne gardent plus que les pics du motif, ce qui donne des points.

### Limites

- Éclairage direct, sans radiosité ni lumière volumétrique : la brume est un `fog` au sol, pas un `media`, pour garder un rendu rapide.
- La maison est une silhouette lointaine, peu détaillée de près.
- Les poteaux de la grille projettent vers la caméra de longues ombres rectilignes. C'est cohérent avec une lune derrière la scène, mais ça se voit beaucoup sur le sol.
