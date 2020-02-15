#include "metals"
#include "finish"
#include "inc/body/BodyMetrics"

/*
A wrist should be thick as N_Arm_Thickness
and should be long as N_Wrist_Len
*/

#local Spike = cone {
	0, N_Wrist_Len / 8
	<N_Wrist_Len / 2, 0, 0>, 0
	texture {
		T_Brass_1E
	}
}

#declare P_BodyPart_ArmorPart_Wrist = union {
	cylinder {
		<0, N_Wrist_Len * 0.2, 0>
		<0, N_Wrist_Len, 0>
		N_Arm_Thickness * 1.1
		texture {
			pigment {
				color rgb <0.02, 0.015, 0>
			}
			finish {
				Shiny
			}
		}
	}
	object {
		Spike
		translate y * N_Wrist_Len * 0.25
	}
	object {
		Spike
		translate y * N_Wrist_Len * 0.5
	}
	object {
		Spike
		translate y * N_Wrist_Len * 0.75
	}
}
