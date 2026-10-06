/*
   ____      _
  / ___|   _| |__   ___
 | |  | | | | '_ \ / _ \
 | |__| |_| | |_) |  __/
  \____\__,_|_.__/ \___|

	Evil cube of dark metal, rolling face by face. See inc/cube/Cube.inc.
*/
#include "inc/Camera.inc"
#include "inc/frames/cube.inc"
#include "inc/cube/Cube.inc"

object {
	O_Cube_Posed
	rotate y * N_Animation_Angle
}
