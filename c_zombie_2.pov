/*
                    _     _        ____
 _______  _ __ ___ | |__ (_) ___  |___ \
|_  / _ \| '_ ` _ \| '_ \| |/ _ \   __) |
 / / (_) | | | | | | |_) | |  __/  / __/
/___\___/|_| |_| |_|_.__/|_|\___| |_____|

	Same zombie as c_zombie_1.pov: green skin, very dark grey trousers,
	pale grey shirt, sparse grey hair.
*/

#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"
#declare C_Skin = color rgb <0.2, 0.3, 0.14>;

#declare T_Skin_Blood = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 color rgb <0.15, 0, 0>]
			[0.25 C_Skin * 0.3]
			[0.6 C_Skin * 0.6]
			[0.95 C_Skin]
		}
	}
}

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/zombie_face_balding.png"
			map_type 1
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

#declare T_BodyPart_Skin = T_Skin_Blood

#include "inc/armors/Short_Trousers_Ripped_Dark"
#include "inc/armors/Belt_Thick_Dark_Leather_Iron_Round_Buckle"
#include "inc/armors/Boot_Leather_Brown_Dirty"
#include "inc/armors/MaleShirt_Ripped_Dirty_Gray"
#include "inc/hair/Zombie_Black"

// sparse grey hair: thin strands, the scalp shows between them
#declare T_Hair_Gray_Sparse = texture {
	pigment {
		radial
		color_map {
			[0 color rgbt <0.5, 0.5, 0.5, 0>]
			[0.3 color rgbt <0.5, 0.5, 0.5, 0>]
			[0.35 color rgbt <0.5, 0.5, 0.5, 1>]
			[1 color rgbt <0.5, 0.5, 0.5, 1>]
		}
		frequency 40
	}
}

#declare P_BodyPart_ArmorPart_Helm = object {
	P_Hair_Zombie_Black
	texture {
		T_Hair_Gray_Sparse
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
