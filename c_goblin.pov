/*
             _     _ _
  __ _  ___ | |__ | (_)_ __
 / _` |/ _ \| '_ \| | | '_ \
| (_| | (_) | |_) | | | | | |
 \__, |\___/|_.__/|_|_|_| |_|
 |___/

Goblin with a short sword and leather armor: see inc/goblin/Goblin.inc.

*/

#include "inc/Camera.inc"
#include "inc/frames/small.inc"
#include "inc/goblin/Goblin.inc"
#include "inc/body/BodyParts.inc"

object {
	O_BodyPart_Armored_Body_M
	rotate y * N_Animation_Angle
}
