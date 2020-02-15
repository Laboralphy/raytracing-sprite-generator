#include "inc/body/BodyMetrics.inc"

/* Skirt start at 0*y and goes bellow y plane */

#declare O_Skirt_Risible_And_Shaby = cone {
	<0, 0, 0>
	0.5 * N_Shoulder_Len
	<0, -N_Thigh_Len / 1.75, 0>
	0.7 * N_Shoulder_Len
	open
	scale V_BodyPart_Torso_Scale
	texture {
		pigment {
			color rgb <0.5, 0.5, 0.75>
		}
	}
}


#declare P_BodyPart_ArmorPart_Skirt = O_Skirt_Risible_And_Shaby;
