/*
     _            _          _       _     _   
  __| | __ _ _ __| | ___ __ (_) __ _| |__ | |_ 
 / _` |/ _` | '__| |/ / '_ \| |/ _` | '_ \| __|
| (_| | (_| | |  |   <| | | | | (_| | | | | |_ 
 \__,_|\__,_|_|  |_|\_\_| |_|_|\__, |_| |_|\__|
                               |___/           

	Dark knight: the knight (c_knight_mace.pov, same poses), taller and
	sturdier, blackened armor with reddish rust, big horns, crimson cape,
	shield with a demon skull, broad sword.

*/

// taller and sturdier (before any include: the armor reads them)
#declare N_BodyMetrics_Value = 1.12;
#declare N_BodyMetrics_Leg_Thickness = 0.22;
#declare N_BodyMetrics_Arm_Thickness = 0.14;
#declare N_Hip_Spacing = 0.38;

#include "inc/Camera.inc"
#include "inc/frames/knight.inc"
#include "inc/armors/DarkArmor.inc"
#include "inc/weapons/Weapon_Demon_Skull_Shield.inc"
#include "inc/weapons/Weapon_Broad_Sword.inc"

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
}
