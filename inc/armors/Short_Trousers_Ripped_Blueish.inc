#include "inc/body/BodyMetrics.inc"

/* Skirt start at 0*y and goes bellow y plane */

#declare C_Jeans = color rgb <0.05, 0.09, 0.25>;

#declare T_Jeans = texture {
	pigment {
		tiling 1
		color_map {
			[0, C_Jeans]
			[0.5 C_Jeans * 0.5]
			[1 C_Jeans]
		}
		rotate <90, 0, 45>
		scale 0.06
	}
}

#declare O_Short_Trousers_Ripped_Blueish = union {
	cone {
		<0, 0, 0>
		0.425 * N_Shoulder_Len
		<0, -N_Thigh_Len / 3, 0>
		0.5 * N_Shoulder_Len
	}
	sphere {
		0
		0.5 * N_Shoulder_Len
		scale <1, 0.5, 1>
		translate <0, -N_Thigh_Len / 3, 0>
	}
	scale V_BodyPart_Torso_Scale
}

#declare O_Short_Trousers_Ripped_Blueish_Leg = cylinder {
	<0, 0, 0>
	<0, N_Thigh_Len, 0>
	N_BodyMetrics_Leg_Thickness * 1.3
}


#declare P_BodyPart_ArmorPart_Skirt = object {
	O_Short_Trousers_Ripped_Blueish
	texture {
		T_Jeans
	}
}

#declare P_BodyPart_ArmorPart_Thigh = object {
	O_Short_Trousers_Ripped_Blueish_Leg
	texture {
		T_Jeans
	}
}


#declare O_Shin_Trousers_Ripped_Blueish_Cutter_0 = box {
	<-10, 0, 0>
	<10, -20, 20>
	rotate x * 45
	scale <1, 1, 0.5>
}

#declare O_Shin_Trousers_Ripped_Blueish_Cutter_1 = union {
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_0
		translate <0, N_Shin_Len * 0.8, 0>
	}
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_0
		rotate y * 30
		translate <0, N_Shin_Len * 0.9, 0>
	}
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_0
		rotate y * 75
		translate <0, N_Shin_Len * 0.8, 0>
	}
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_0
		rotate y * 100
		translate <0, N_Shin_Len * 0.9, 0>
	}
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_0
		rotate y * 133
		translate <0, N_Shin_Len * 0.8, 0>
	}
}


#declare O_Kneel_Trousers_Ripped_Blueish_Leg = sphere {
	<0, 0, 0>
	N_BodyMetrics_Leg_Thickness * 1.3
	texture {
		T_Jeans
	}
}


#declare O_Shin_Trouser = difference {
	cone {
		<0, 0, 0>
		N_Leg_Thickness * 1.3
		<0, -N_Shin_Len * 0.4, 0>
		N_Leg_Thickness * 1.1
	}
	object {
		O_Shin_Trousers_Ripped_Blueish_Cutter_1
		translate <0, -N_Shin_Len, 0>
	}
	texture {
		T_Jeans
	}
}



#declare P_BodyPart_ArmorPart_Kneel = union {
	object {
		O_Kneel_Trousers_Ripped_Blueish_Leg
	}
	object {
		O_Shin_Trouser
	}
}


