#include "inc/body/BodyMetrics.inc"

/* for a boot, use N_BodyMetrics_Leg_Thickness and N_Shin_Len */

#declare O_Boot_Horrible_Yellow_Cylinder = cylinder {
	<0, 0, 0>
	<0, N_Shin_Len, 0>
	N_BodyMetrics_Leg_Thickness * 1.1
	texture {
		pigment {
			color rgb <1, 0.5, 0>
		}
	}
}

#declare P_BodyPart_ArmorPart_Shin = O_Boot_Horrible_Yellow_Cylinder;
