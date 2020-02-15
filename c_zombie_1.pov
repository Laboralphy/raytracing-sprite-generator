/*
                    _     _      
 _______  _ __ ___ | |__ (_) ___ 
|_  / _ \| '_ ` _ \| '_ \| |/ _ \
 / / (_) | | | | | | |_) | |  __/
/___\___/|_| |_| |_|_.__/|_|\___|
                                 

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"
#declare C_Skin = color rgb <0.15, 0.15, 0.15>;

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

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/zombie_face.png"
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

#include "inc/armors/Short_Trousers_Ripped_Blueish"
#include "inc/armors/Belt_Thick_Dark_Leather_Iron_Round_Buckle"
#include "inc/armors/Boot_Leather_Brown_Dirty"
#include "inc/armors/MaleShirt_Ripped_Dirty"
#include "inc/hair/Zombie_Black"
#include "inc/hair/Texture_Black_Gray"

#declare P_BodyPart_ArmorPart_Helm = object {
	P_Hair_Zombie_Black
	texture {
		T_Hair_Black_Gray
	}
}

#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
