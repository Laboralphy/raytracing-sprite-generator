#include "inc/Camera.inc"
#include "inc/jack/Jack"

#switch (N_Animation_Frame)
	#case (0)
		#declare TheJack = O_JackOLantern;
	#break
	
	#case (1)
		#declare TheJack = O_JackOLantern_2;
	#break
#end

object {
	TheJack
	rotate y * N_Animation_Angle
}
