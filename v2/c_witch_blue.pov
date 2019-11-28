/*

 _     _                       _ _       _     
| |__ | |_   _  ___  __      _(_) |_ ___| |__  
| '_ \| | | | |/ _ \ \ \ /\ / / | __/ __| '_ \ 
| |_) | | |_| |  __/  \ V  V /| | || (__| | | |
|_.__/|_|\__,_|\___|   \_/\_/ |_|\__\___|_| |_|
                                               

@frames 4

*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/frames/witch.inc"
#include "inc/HairRepository.inc"
#include "inc/armors/Wizard_Hat.inc"

// human skin color
#declare C_Skin = color rgb <0.8, 0.6, 0.4>;
#declare T_BodyPart_Skin = texture {
	pigment {
		C_Skin
	}
}
#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/w_face.png"
			map_type 1
		}
	}
}
#include "inc/armors/Witch_Costume_Blue_Skirt"
#include "inc/armors/Wand_Ruby_Sphere"
#include "inc/armors/Wrist_Golden_Bracers"

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		P_HairRepository_Egg_Long_Curl
		texture {
			T_HairRepository_Red
		}
	}
	object {
		O_WizardHat
	}
}


#include "inc/body/BodyParts.inc"

#declare O_Character = object {
	O_BodyPart_Body_F
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
