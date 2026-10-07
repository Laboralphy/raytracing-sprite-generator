/*

     _                                                       _ _ 
  __| |_   _ _ __ ___  _ __ ___  _   _     ___ _ __ ___   __ _| | |
 / _` | | | | '_ ` _ \| '_ ` _ \| | | |   / __| '_ ` _ \ / _` | | |
| (_| | |_| | | | | | | | | | | | |_| |   \__ \ | | | | | (_| | | |
 \__,_|\__,_|_| |_| |_|_| |_| |_|\__, |   |___/_| |_| |_|\__,_|_|_|
                                 |___/                             

Small dummy: base for small creatures (goblins, imps...): short body, short
legs, long arms, big head; small trotting steps (inc/frames/small.inc), short
sword in the right hand.

*/

#declare N_BodyMetrics_Value = 0.65;
#declare N_BodyMetrics_Leg_Factor = 0.65;
#declare N_BodyMetrics_Arm_Factor = 0.95;
#declare N_BodyMetrics_Head_Factor = 1.35;
#declare N_BodyMetrics_Leg_Thickness = 0.12;
#declare N_BodyMetrics_Arm_Thickness = 0.095;

#include "inc/Camera.inc"
#include "inc/frames/small.inc"

#declare T_BodyPart_Skin = texture {
	pigment {
		color rgb <0.5, 0.5, 0.5>
	}
}

#declare T_BodyPart_Face = texture {
	pigment {
		color rgb <0.5, 0.5, 0.5>
	}
}

#include "inc/weapons/Weapon_Sword.inc"
#include "inc/body/BodyParts.inc"

object {
	O_BodyPart_Armored_Body_M
	rotate y * N_Animation_Angle
}
