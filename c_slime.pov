/*
  ____  _ _
 / ___|| (_)_ __ ___   ___
 \___ \| | | '_ ` _ \ / _ \
  ___) | | | | | | | |  __/
 |____/|_|_|_| |_| |_|\___|

	Greenish translucent slime. See inc/slime/Slime.inc.
*/
#include "inc/Camera.inc"
#include "inc/frames/slime.inc"
#include "inc/slime/Slime.inc"

object {
	O_Slime_Posed
	rotate y * N_Animation_Angle
}
