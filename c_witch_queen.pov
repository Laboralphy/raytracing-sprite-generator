/*

           _ _       _                                    
__      __(_) |_ ___| |__     __ _ _   _  ___  ___ _ __  
\ \ /\ / /| | __/ __| '_ \   / _` | | | |/ _ \/ _ \ '_ \ 
 \ V  V / | | || (__| | | | | (_| | |_| |  __/  __/ | | |
  \_/\_/  |_|\__\___|_| |_|  \__, |\__,_|\___|\___|_| |_|
                                |_|                       

	The blue witch (same size, same poses) crowned: golden crown with gems
	instead of the hat, blond hair, dress fading from blue to dark gray with a
	gold lattice on the bodice and a skirt cut at the front.

*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/frames/witch.inc"
#include "inc/hair/Egg_Long_Curl"
#declare N_Crown_Gems = 0;
#include "inc/armors/Crown_Gold_Gems.inc"

// pale blond (less yellow than the gold of the crown), brighter than inc/hair/Texture_Blond
#declare T_Hair_Queen = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0.72, 0.62, 0.42>]
			[0.4 color rgb <1, 0.94, 0.72>]
			[0.6 color rgb <0.9, 0.82, 0.58>]
			[1 color rgb <0.72, 0.62, 0.42>]
		}
		frequency 24
	}
	finish { specular 0.3 roughness 0.05 }
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
#include "inc/armors/Witch_Queen_Costume.inc"
#include "inc/armors/Wand_Ruby_Sphere"
#include "inc/armors/Wrist_Golden_Bracers"
#include "inc/armors/Boot_Leather_Gray_Glossy"
#include "inc/armors/Belt_Brown_Leather_Gold_Round_Buckle"
#include "inc/armors/Choker_Black"

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		P_Hair_Egg_Long_Curl
		texture {
			T_Hair_Queen
		}
	}
	object {
		O_Crown_Gold_Gems
		// narrow and tall, sitting on the top of the head
		scale <0.36, 0.68, 0.36>
		rotate x * -8
		translate <0, 1.04, 0>
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
