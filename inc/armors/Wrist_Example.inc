#include "colors.inc"
#include "inc/body/BodyMetrics"

/*
A wrist should be thick as N_Arm_Thickness
and should be long as N_Wrist_Len
*/

#declare P_BodyPart_ArmorPart_Wrist = cylinder {
	<0, 0, 0>
	<0, N_Wrist_Len, 0>
	N_Arm_Thickness * 1.1
	texture {
		pigment {
			color Red
		}
	}
}
