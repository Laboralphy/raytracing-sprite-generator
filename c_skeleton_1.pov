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
			png "png/skull_face_blue_eyes.png"
			map_type 2
		}
		scale <1, 2, 1>
		translate <0, -0.6, -0.25>
	}
}

#declare T_BodyPart_Skin = T_Skin_Bones

#include "inc/skeleton/Body.inc"
#include "inc/skeleton/Waist"
#include "inc/skeleton/Skull"
#include "inc/skeleton/Shin_1"

#declare P_BodyPart_Torso_Replace = union {
	object {
		O_Skel_Spine
	}
	object {
		P_Skel_Waist
		scale 0.25
	}
	texture { T_BodyPart_Skin }
}

#declare P_BodyPart_Head_Replace = object {
	object {
		O_Skel_Skull
	}
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
	#ifdef (T_BodyPart_Face) 
		texture {
			T_BodyPart_Face
		}
	#end
	scale N_Head_Size
}

#include "inc/armors/MaleShirt_Ripped_Dirty_Brownish"
#include "inc/skeleton/Leg"
#include "inc/skeleton/Wrist_1"
#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}

object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
