#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/BodyHair.inc"


#declare C_Skin = color rgb <0.8, 0.6, 0.4>;
#declare T_Skin = texture {
	pigment {
		C_Skin
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;

#include "inc/Clothes.inc"

#declare P_Boot = Clothe_Boot_Type1;
#declare P_Hair = P_Hair_2;
#declare P_ArmWear = Clothe_ArmWear_Type1;
#declare P_Glove = Clothe_Bracer_Type1;
#declare P_Belt = Clothe_Belt_Type1;
#declare T_Head = T_Skin;
#declare T_Face = texture {
	pigment {
		image_map {
			png "png/w_face.png"
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
		Body
	}
	object {
		Clothe_Skirt_Pleaded_Blue
	}
	rotate AnimationAngle * y
	scale 0.7
}

