#include "inc/body/BodyMetrics.inc"

/* Armor goes from 0 to TorsoLen */

#declare O_MaleArmor_Example = sor {
	5
	<0.9 * N_Shoulder_Len / 2, -1>
	<0.9 * N_Shoulder_Len / 2, 0>
	<1.4 * N_Shoulder_Len / 2, N_Torso_Len>
	<1.0 * N_Shoulder_Len / 2, 1.25 * N_Torso_Len>
	<1.0 * N_Shoulder_Len / 2, 1.25 * N_Torso_Len + 1>
	sturm
	scale V_BodyPart_Torso_Scale * <0.85, 1, 1>
	texture {
		pigment {
			color rgb <0.5, 0.1, 0.1>
		}
	}
}

#declare P_BodyPart_ArmorPart_Chest = O_MaleArmor_Example;
