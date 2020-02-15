#include "golds.inc"
#include "inc/body/BodyMetrics"

#declare P_BodyPart_ArmorPart_Wrist = torus {
	N_Arm_Thickness
	N_Arm_Thickness * 0.3
	translate <0, N_Wrist_Len * 0.333, 0>
	texture {
		T_Gold_3C
	}
}
