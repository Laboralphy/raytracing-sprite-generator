/*

     _            _      _          _       _     _                              
  __| | __ _ _ __| | __ | | ___ __ (_) __ _| |__ | |_   _ __ ___   __ _  ___ ___ 
 / _` |/ _` | '__| |/ / | |/ / '_ \| |/ _` | '_ \| __| | '_ ` _ \ / _` |/ __/ _ \
| (_| | (_| | |  |   <  |   <| | | | | (_| | | | | |_  | | | | | | (_| | (_|  __/
 \__,_|\__,_|_|  |_|\_\ |_|\_\_| |_|_|\__, |_| |_|\__| |_| |_| |_|\__,_|\___\___|
                                      |___/                                      

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/knight.inc"
#include "inc/armors/ChromedArmor_1"
#include "inc/weapons/Weapon_Crossed_Shield"
#include "inc/weapons/Weapon_Spiked_Mace"

#declare C_Skin = color rgb 0.1;
#declare T_BodyPart_Skin = texture {
	pigment {
		C_Skin
	}
}
#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/knight_face.png"
			map_type 1
		}
	}
}
#include "inc/body/BodyParts.inc"

#declare O_Character = object {
	O_BodyPart_Armored_Body_M
	texture {
		T_Default
	}
}

object {
	O_Character
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}