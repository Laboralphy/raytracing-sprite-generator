#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/frames/succubus.inc"
#include "inc/hair/Egg_Long_Curl"
#include "inc/armors/Horns_Demon.inc"

// dark hair, nearly black, with a purple sheen
#declare T_Hair_Succubus = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0.015, 0.01, 0.02>]
			[0.4 color rgb <0.08, 0.04, 0.1>]
			[0.6 color rgb <0.04, 0.02, 0.05>]
			[1 color rgb <0.015, 0.01, 0.02>]
		}
		frequency 24
	}
	finish { specular 0.15 roughness 0.1 }
}

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
			png "png/witch_face.png"
			map_type 1
		}
	}
}
#include "inc/armors/Succubus_Costume.inc"
#include "inc/armors/Wand_Ruby_Sphere"
#include "inc/armors/Wrist_Golden_Bracers"
#include "inc/armors/Boot_High_Red_Pointed.inc"
#include "inc/armors/Belt_Brown_Leather_Gold_Round_Buckle"
#include "inc/armors/Choker_Black"

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		P_Hair_Egg_Long_Curl
		texture {
			T_Hair_Succubus
		}
	}
	object {
		O_Horns_Demon
	}
}


#include "inc/body/BodyParts.inc"

#declare O_Character = object {
	O_BodyPart_Armored_Body_F
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
}
