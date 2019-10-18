/**
 * @description Knight with dull armor, shield, and a sword
 * 2 frames per attack, shield always on, except when attacking
 * @frames 4
 */

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/RunFramesKnight.inc"

#declare B_FIST_INSTEAD_OF_HAND = 1;

#declare C_Skin = color rgb <0.1, 0.1, 0.1>;
#declare T_Skin = texture {
	pigment {
		C_Skin
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;
#declare T_Torso = T_Skin;

#include "inc/Clothes.inc"

#declare P_Boot = Clothe_Boot_Soleret;
#declare P_Wrist = Clothe_Wrist_Gauntlet;
#declare P_Shoulder = Clothe_Shoulder_Armor_Pad;
#declare P_Legging = Clothe_Legging_Armor;
#declare P_Belt = Clothe_Belt_Type1;
#declare P_Hair = Clothe_Helm_Type2;
#declare P_Shield = Clothe_Shield_Type1;

#declare T_Head = T_Skin;
#declare T_Face = texture {
	pigment {
		image_map {
			png "png/k_face.png"
			map_type 1
		}
	}
}

#include "inc/Body.inc";

union {
	object {
		BodyM
	}
	object {
		Clothe_Mail_Skirt
		translate 2.55 * y
	}
	object {
		Clothes_Shirt_Armor
		translate 2.55 * y
	}
	rotate AnimationAngle * y
	scale 0.85
	translate OffsetBody * y
}

object {
	Weapon_Sword_Type1
	translate <2, 1, -3>
}
