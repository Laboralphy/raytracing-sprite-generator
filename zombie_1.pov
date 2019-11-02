/**
 * @description Zombie with no armor and no weapon
 * @frames 6
 */

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/RunFramesZombie.inc"
#include "inc/BodyHair.inc"

#declare B_Fist_Instead_Of_Hand = 1;
#declare B_Equip_Shield = 0;
#declare B_Raise_Shield = 0;

#declare C_Skin = color rgb <0.1, 0.1, 0.1>;
#declare T_Skin = texture {
	pigment {
		C_Skin
	}
}

#declare P_Null = sphere { 0, 0 }

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;
#declare T_Torso = T_Skin;

#include "inc/Clothes.inc"

#declare T_Head = T_Skin;
#declare T_Face = texture {
	pigment {
		image_map {
			png "png/k_face.png"
			map_type 1
		}
	}
}

#declare P_Legging = Clothe_Legging_Zombie_Pant;
#declare P_Boot = Clothe_Boot_Zombie_Bare_Foot;
#declare P_Belt = Clothe_Belt_Type2;
#declare P_Hair = P_Hair_7;
#declare P_Wrist = P_Null;
#declare P_Shoulder = P_Null;

#include "inc/Body.inc";

union {
	object {
		BodyM
	}
	object {
		Clothe_Zombie_Pant_Upper
		translate 2.57 * y
	}
	rotate AnimationAngle * y
	scale 0.85
	translate OffsetBody * y
}
