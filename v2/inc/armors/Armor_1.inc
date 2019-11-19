#include "colors.inc"
#include "metals.inc"
#include "inc/BodyMetrics.inc"

#declare O_Armor_Spike = cone {
	<0, 0, 0>
	N_Arm_Thickness * 0.75
	<0, 2 * N_Arm_Thickness, 0>
	0
}

#declare T_Armor = texture {
	T_Chrome_1A
	normal {
		dents 1
		scale 0.2
	}
}

#declare P_BodyPart_ArmorPart_Skirt = cone {
	<0, 0, 0>
	0.4 * N_Shoulder_Len
	<0, -N_Thigh_Len / 1.5, 0>
	0.6 * N_Shoulder_Len
	open
	scale V_BodyPart_Torso_Scale
	texture {
		pigment {
			hexagon
			pigment { Gray50 },
			pigment { Gray30 },
			pigment { Gray20 }
		}
		scale 0.05
		rotate 90 * x
		normal {
			bumps 1
			scale 0.1
		}
	}
}

#declare P_BodyPart_ArmorPart_Chest = sor {
	5
	<0.9 * N_Shoulder_Len / 2, -1>
	<0.9 * N_Shoulder_Len / 2, 0>
	<1.4 * N_Shoulder_Len / 2, N_Torso_Len>
	<1.0 * N_Shoulder_Len / 2, 1.25 * N_Torso_Len>
	<1.0 * N_Shoulder_Len / 2, 1.25 * N_Torso_Len + 1>
	sturm
	scale V_BodyPart_Torso_Scale * <0.85, 1, 1>
	texture {
		T_Armor
		scale 0.25
	}
}


#declare O_Soleret_Top = union {
	cone {
		<0, -N_Leg_Thickness, 0>
		N_Leg_Thickness * 1
		<0, N_Shin_Len * 0.5, 0>
		N_Leg_Thickness * 1.3
	}
	torus {
		N_Leg_Thickness * 1
		N_Leg_Thickness * 0.3
		translate <0, N_Shin_Len * 0.5, 0>
	}
	texture {
		T_Armor
	}
}

#declare O_Boot_Heel = intersection {
	sphere {
		<0, 0, 0>
		N_Leg_Thickness
		scale <1, 1, 2>
	}
	box {
		<-N_Leg_Thickness * 2, 0, 0>
		<N_Leg_Thickness * 2, N_Leg_Thickness * 2, -N_Leg_Thickness * 2>
	}
	translate -N_Leg_Thickness * y
}



#declare P_BodyPart_ArmorPart_Shin = union {
	object {
		O_Soleret_Top
	}
	object {
		O_Boot_Heel
		texture {
			T_Armor
		}
	}
	cylinder {
		<0, -N_Leg_Thickness, 0>
		<0, N_Shin_Len, 0>
		N_Leg_Thickness * 1.05
		texture {
			T_Armor
		}
	}
	sphere {
		<0, N_Shin_Len, 0>
		N_Leg_Thickness * 1.15
		texture {
			T_Armor
		}
	}
	object {
		O_Armor_Spike
		rotate x * (-90)
		translate <0, N_Shin_Len, -N_Leg_Thickness>
		texture {
			T_Armor
		}
	}
}


#declare P_BodyPart_ArmorPart_Thigh = union {
	cylinder {
		0
		<0, N_Thigh_Len, 0>
		N_Leg_Thickness * 1.1
	}
	cone {
		0
		N_Leg_Thickness
		<0, N_Thigh_Len / 2, 0>
		N_Leg_Thickness * 1.2
	}
	texture {
		T_Armor
	}
}
