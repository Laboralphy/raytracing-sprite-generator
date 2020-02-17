/*
       _                 _ 
  __ _| |__   ___  _   _| |
 / _` | '_ \ / _ \| | | | |
| (_| | | | | (_) | |_| | |
 \__, |_| |_|\___/ \__,_|_|
 |___/                     

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"
#declare C_Skin = color rgb 0.8;

#declare N_BodyMetrics_Member_Factor = 1;

#declare T_Skin_Blood = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 color rgb <0.15, 0, 0>]
			[0.25 C_Skin * 0.1]
			[0.95 C_Skin]
		}
	}
}

#declare T_BodyPart_Torso = texture {
	pigment {
		image_map {
			png "png/zombie_torso.png"
			map_type 2
		}
		scale <1, 1.25, 1>
		translate y * 0.25
	}
}

#declare C_Skin = color rgb 0.4;
#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/ghoul_face_red_eyes.png"
			map_type 2
		}
		scale <1, 2, 1>
		translate <0, -0.6, -0.25>
	}
}

#declare T_BodyPart_Skin = T_Skin_Blood

#include "inc/armors/Short_Trousers_Ripped_Dark"
#include "inc/armors/Belt_Thick_Dark_Leather_Iron_Round_Buckle"
#include "inc/armors/Boot_Leather_Brown_Dirty"
#include "inc/hair/Texture_Black_Gray"
#include "inc/skeleton/Skull"
#include "inc/skeleton/Tongue"
#include "inc/armors/Wrist_Spiked"

#declare P_BodyPart_Head_Replace = union {
	object {
		O_Skel_Skull
		texture {
			T_BodyPart_Skin
		}
		texture {
			T_BodyPart_Face
		}
		translate <0, 0, 0.25>
		scale 0.5
	}
	object {
		O_Tongue_Red
	}
}

#include "inc/armors/Helm_Chaos_Horns"
#include "inc/armors/MaleShirt_Harnais"
#include "inc/body/BodyParts"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
