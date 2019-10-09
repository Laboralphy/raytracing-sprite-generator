#include "colors.inc"
#include "inc/Camera.inc"


#declare T_Skin = texture {
	pigment {
		color rgb <1, 0.6, 0.7>
	}
}

#declare T_Legs = T_Skin;
#declare T_Arms = T_Skin;

#include "inc/Body.inc";

#declare Skirt_1 = sor {
	6
	<0, 0>
	<0.5, 0.1>
	<0.75, 0.5>
	<0.9, 0.9>
	<1, 1>
	<1, 2>
	scale <1, -1, 0.6>
	texture {
		pigment {
			radial
			color_map {
				[0, Blue]
				[0.5 Blue * 0.5]
				[1 Blue]
			}
			frequency 16
		}
	}
	translate <0, 2.7, 0>
}

union {
	object {
		Body
	}
	object {
		Skirt_1
	}
	rotate AnimationAngle * y
}

