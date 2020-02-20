/*

   _            _                     _             _                  
  (_) __ _  ___| | __      ___       | | __ _ _ __ | |_ ___ _ __ _ __  
  | |/ _` |/ __| |/ /____ / _ \ _____| |/ _` | '_ \| __/ _ \ '__| '_ \ 
  | | (_| | (__|   <_____| (_) |_____| | (_| | | | | ||  __/ |  | | | |
 _/ |\__,_|\___|_|\_\     \___/      |_|\__,_|_| |_|\__\___|_|  |_| |_|
|__/                                                                   

@frames 6

*/
#include "inc/Camera.inc"
#include "inc/jack/Jack"

#declare TheJack = O_JackOLantern_2;

#switch (N_Animation_Frame)
	#case (0)
		#declare TheJack = O_JackOLantern_2;
	#break

	#case (1)
		#declare TheJack = O_JackOLantern_15;
	#break
	
	#case (2)
		#declare TheJack = O_JackOLantern;
	#break
#end

object {
	TheJack
	rotate y * N_Animation_Angle
}
