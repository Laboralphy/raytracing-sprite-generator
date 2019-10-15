#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/BodyHair.inc"

#declare T_Skin = texture {
	pigment {
		color rgb <1, 0.86, 0.67>
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;

#include "inc/Clothes.inc"

#declare P_Boot = Boot_Type1;
#declare P_Hair = P_Hair_2;
#declare P_ArmWear = ArmWear_Type1;
#declare P_Glove = Bracer_Type1;

#include "inc/Body.inc";


union {
	object {
		Body
	}
	object {
		Skirt_Pleaded_Blue
	}
	rotate AnimationAngle * y
	scale 0.7
}

