#include "inc/body/BodyMetrics.inc"

/* Bel start at 0*y and goes above y plane / diameter is around  N_Shoulder_Len / 2.25 */

#declare O_Belt_Just_Bad = cylinder {
	<0, 0, 0>
	<0, N_Torso_Len / 8, 0>
	N_Shoulder_Len / 2.25
	scale V_BodyPart_Torso_Scale
	texture {
		pigment {
			color rgb <0.1, 0.2, 0.1>
		}
	}
}

#declare P_BodyPart_ArmorPart_Belt = O_Belt_Just_Bad;
