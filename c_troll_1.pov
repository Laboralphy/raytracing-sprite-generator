/*

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/troll.inc"
#declare C_Skin = color rgb <0.25, 0.1, 0.15>;

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


#declare N_BodyMetrics_Member_Factor = 1.1;
#declare N_BodyMetrics_Leg_Thickness = 0.2;
#declare N_BodyMetrics_Arm_Thickness = 0.14;

#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
