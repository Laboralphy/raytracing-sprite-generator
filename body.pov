#include "colors.inc"
#include "inc/Camera.inc"


#declare T_Skin = texture {
	pigment {
		color rgb <0, 0.6, 0.7>
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;

#include "inc/Clothes.inc"

#declare P_Boot = Boot_Type1;

#include "inc/Body.inc";



union {
	object {
		Body
	}
	/*
	object {
		Skirt_Pleaded_Blue
	}*/
	rotate AnimationAngle * y
}

