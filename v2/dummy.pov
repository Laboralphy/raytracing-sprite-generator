#include "inc/armors/Armor_1"

#declare AV_Arm_Left = <90, 0, 10>;
#declare AV_Arm_Right = <90, 0, -10>;

#include "inc/BodyParts.inc"
#include "inc/Camera.inc"

#declare O_Character = object {
	O_BodyPart_Body_M
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
}
