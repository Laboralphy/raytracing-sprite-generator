/*


@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"
#declare C_Skin = color rgb <0.8, 0.8, 0.6>;

#declare T_Skin_Bones = texture {
	pigment {
		C_Skin
	}
}

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/face_zombie.png"
			map_type 1
		}
	}
}

#declare T_BodyPart_Skin = T_Skin_Bones

//#include "inc/armors/Short_Trousers_Ripped_Blueish"
//#include "inc/armors/Belt_Thick_Dark_Leather_Iron_Round_Buckle"
//#include "inc/armors/Boot_Leather_Brown_Dirty"
//#include "inc/armors/MaleShirt_Ripped_Dirty"
//#include "inc/hair/Zombie_Black"
//#include "inc/hair/Texture_Black_Gray"

#declare N_BodyMetrics_Arm_Thickness = 0.08;
#declare N_BodyMetrics_Leg_Thickness = 0.10;
#declare N_BodyMetrics_Blob_Threshold = 0.95;

#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
