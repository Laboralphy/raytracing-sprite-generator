#include "inc/body/BodyMetrics.inc"
#include "metals"
#include "finish"

#local Harnais_Base = blob {
	threshold 0.3
	
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
	translate <0, -N_Torso_Len / 2, 0>
	scale 1.05
	translate <0, N_Torso_Len / 2, 0>
	texture {
		pigment {
			color rgb 0.05
		}
	}
}

#local Digger1 = sphere {
	<0, 0.45, -0.18>
	0.45
}

#local Digger2 = sphere {
	<0, 0.45, -0.18>
	0.3
}

#local Digger3 = difference {
	object {
		Digger1
	}
	object {
		Digger2
	}
}

#local Harnais1 = intersection {
	object {
		Harnais_Base
	}
	object {
		Digger3
		translate y * 0.8
	}
}

#local Harnais2 = union {
	object {
		Harnais1
	}
}

#declare P_BodyPart_ArmorPart_Chest = Harnais1;
