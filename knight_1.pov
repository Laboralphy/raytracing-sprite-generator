/**
 * @description Knight with dull armor, shield, and a sword
 * 2 frames per attack, shield always on, except when attacking
 * @frames 4
 */

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/RunFrames.inc"

#declare B_FIST_INSTEAD_OF_HAND = 1;

#declare C_Skin = color rgb <0.3, 0.3, 0.3>;
#declare T_Skin = texture {
	pigment {
		C_Skin
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;

#include "inc/Clothes.inc"

#declare P_Boot = Clothe_Boot_Soleret;
#declare P_Wrist = Clothe_Wrist_Gauntlet;

#declare T_Head = T_Skin;
#declare T_Face = texture {
	pigment {
		image_map {
			png "png/k_face.png"
			map_type 1
		}
	}
}

#declare T_Torso = texture {
	pigment {
		cylindrical
		color_map {
			[0.5 Blue]
			[0.5 C_Skin]
		}
	}
	rotate <90, 0, 0>
	scale 3
	translate <0, 5.75, 0>
}

#include "inc/Body.inc";


union {
	object {
		BodyM
	}
	rotate AnimationAngle * y
	scale 0.85
	translate OffsetBody * y
}
