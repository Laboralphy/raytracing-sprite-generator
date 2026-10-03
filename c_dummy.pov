/*

     _                                 
  __| |_   _ _ __ ___  _ __ ___  _   _ 
 / _` | | | | '_ ` _ \| '_ ` _ \| | | |
| (_| | |_| | | | | | | | | | | | |_| |
 \__,_|\__,_|_| |_| |_|_| |_| |_|\__, |
                                 |___/ 

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/dummy.inc"
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

#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
}
