/*

   _            _                     _             _                  
  (_) __ _  ___| | __      ___       | | __ _ _ __ | |_ ___ _ __ _ __  
  | |/ _` |/ __| |/ /____ / _ \ _____| |/ _` | '_ \| __/ _ \ '__| '_ \ 
  | | (_| | (__|   <_____| (_) |_____| | (_| | | | | ||  __/ |  | | | |
 _/ |\__,_|\___|_|\_\     \___/      |_|\__,_|_| |_|\__\___|_|  |_| |_|
|__/                                                                   


	OLD VERSION, kept for comparison: the torus pumpkin (inc/jack/Jack_old.inc).
	The current Jack is c_jack.pov.
*/
#include "inc/Camera.inc"
#include "inc/frames/jack.inc"
#include "inc/jack/Jack_old"

object {
	O_JackOLantern_Posed
	rotate y * N_Animation_Angle
}
