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
#declare C_Skin = color rgb 0.1;
#declare T_BodyPart_Skin = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 color rgb <0.15, 0, 0>]
			[0.1 C_Skin * 0.1]
			[0.5 C_Skin]
		}
	}
	translate <0, 0, -0.2>
}

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/k_face.png"
			map_type 1
		}
		rotate <10, 0, 0>
	}
}
#include "inc/body/BodyParts.inc"

#declare O_Character = object {
	O_BodyPart_Body_M
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
