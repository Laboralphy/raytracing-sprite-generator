#include "inc/BodyParts.inc"
#include "inc/Camera.inc"

#declare O_Character = object {
	O_BodyPart_Torso_F
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
}
