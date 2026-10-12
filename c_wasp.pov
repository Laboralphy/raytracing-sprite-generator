/*
 __      __
 \ \    / /_ _ ____ __
  \ \/\/ / _` (_-< '_ \
   \_/\_/\__,_/__/ .__/
                 |_|

	Giant wasp, flying. See inc/wasp/Wasp.inc.
*/
#include "inc/Camera.inc"
#include "inc/frames/wasp.inc"
#include "inc/wasp/Wasp.inc"

object {
	O_Wasp_Posed
	rotate y * N_Animation_Angle
}
