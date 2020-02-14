#include "metals"
#include "inc/body/BodyMetrics"

/*
A wrist should be thick as N_Arm_Thickness
and should be long as N_Wrist_Len
*/

#local Spike = cone {
}

#declare P_BodyPart_ArmorPart_Wrist = cylinder {
	<0, N_Wrist_Len * 0.2, 0>
	<0, N_Wrist_Len, 0>
	N_Arm_Thickness * 2.1
	texture {
		T_Brass_1A
	}
}
