#include "inc/skeleton/Foot"

#local O_Skel_Shin = union {
	cone {
		<0, 0, 0>
		N_Leg_Thickness * 2
		<0, N_Shin_Len * 0.75, 0>
		N_Leg_Thickness * 2.5
	}
	torus {
		N_Leg_Thickness * 2.5 - 0.1
		0.1
		translate <0, N_Shin_Len * 0.75, 0>
	}
	texture {
		pigment {
			color rgb <0.05, 0.025, 0>
		}
	}
}

#declare P_BodyPart_ArmorPart_Shin = union {
	object { O_Skel_Foot }
	object { O_Skel_Shin }
}
