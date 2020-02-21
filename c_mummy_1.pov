/*
 _ __ ___  _   _ _ __ ___  _ __ ___  _   _ 
| '_ ` _ \| | | | '_ ` _ \| '_ ` _ \| | | |
| | | | | | |_| | | | | | | | | | | | |_| |
|_| |_| |_|\__,_|_| |_| |_|_| |_| |_|\__, |
                                     |___/ 

@frames 6

*/

#include "inc/Camera.inc"
#include "inc/frames/mummy.inc"
#declare C_Skin = color rgb <0.15, 0.15, 0.15>;

#declare T_Skin_Blood = texture {
	pigment {
		image_map {
			png "png/mummy_skin.png"
			map_type 2
		}
	}
}


#declare T_BodyPart_Face = texture {
  pigment {
    image_map {
			png "png/mummy_face.png"
			map_type 2
    }
  }
  translate -0.2 * y
}

#declare T_BodyPart_Skin = T_Skin_Blood

#declare N_BodyMetrics_Member_Factor = 1.1;
#declare N_BodyMetrics_Leg_Thickness = 0.15;
#declare N_BodyMetrics_Arm_Thickness = 0.11;
#include "inc/armors/MaleShirt_Big_Amulet"
#include "inc/weapons/Weapon_Ornate_Mace"
#include "inc/armors/Boot_Mummy_Ragged"
#include "inc/body/BodyParts.inc"


#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
