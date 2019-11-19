#include "inc/BodyMetrics.inc"

#declare O_FemaleShirt_Base = blob {
	threshold 0.3
	/* bottom */
	sphere {
		0
		N_Shoulder_Len / 2
		2
		scale <1, 0.8, 0.55>
	}
	
	/* bottom l */
	sphere {
		<N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	/* bottom r */
	sphere {
		<-N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	
	/* main torso parts */

	cylinder {
		0
		<0, N_Torso_Len / 4, 0>
		N_Shoulder_Len / 2
		1
		scale V_BodyPart_Torso_Scale
	}

	cylinder {
		<0, N_Torso_Len / 4, 0>
		<0, 3 * N_Torso_Len / 4, 0>
		N_Shoulder_Len / 2
		1
		scale V_BodyPart_Torso_Scale
	}

	cylinder {
		<0, 3 * N_Torso_Len / 4, 0>
		<0, N_Torso_Len, 0>
		N_Shoulder_Len / 2
		3
		scale V_BodyPart_Torso_Scale
	}

	/* left shoulder */
	sphere {
		<N_Shoulder_Len / 2, N_Torso_Len, 0>
		N_Shoulder_Len / 3
		1
	}
	/* right shoulder */
	sphere {
		<-N_Shoulder_Len / 2, N_Torso_Len, 0>
		N_Shoulder_Len / 3
		1
	}
	/* left boob */
	sphere {
		<N_BodyPart_Boobs_Spacing, N_Torso_Len - (N_Torso_Len / 6), -N_Shoulder_Len / 6>
		N_BodyPart_Boobs_Size 
		2
	}
	/* right boob */
	sphere {
		<-N_BodyPart_Boobs_Spacing, N_Torso_Len - (N_Torso_Len / 6), -N_Shoulder_Len / 6>
		N_BodyPart_Boobs_Size 
		2
	}
	translate <0, -N_Torso_Len / 2 0>
	scale 1.05
	translate <0, N_Torso_Len / 2 0>
	pigment {
		color rgb <1, 0, 0>
	}
}

#declare P_BodyPart_ArmorPart_Chest = O_FemaleShirt_Base;
