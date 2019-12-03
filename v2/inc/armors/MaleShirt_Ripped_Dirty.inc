#include "inc/body/BodyMetrics.inc"

#declare T_Shirt_Dirty = texture {
	pigment {
		color rgb <1, 0, 0>
	}
}

#declare O_MaleShirt_Base = blob {
	threshold 0.3
	/* bottom */
	sphere {
		0
		N_Shoulder_Len / 2
		2
		scale <1, 0.8, 0.55>
	}
	
	/* bottom left */
	sphere {
		<N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	/* bottom right */
	sphere {
		<-N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	/* bottom center */
	sphere {
		<0, -N_Torso_Len * 0.1, -N_Shoulder_Len / 20>
		N_Shoulder_Len / 5
		3
		scale <1, 1.5, 1>
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
	translate <0, -N_Torso_Len / 2 0>
	scale 1.05
	translate <0, N_Torso_Len / 2 0>
	texture {
		T_Shirt_Dirty
	}
}

//#declare P_BodyPart_ArmorPart_Chest = O_MaleShirt_Base;
