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

#local Digger1 = box {
	<0, 0, -10>
	<10, -10, 10>
	rotate 45 * z
}

#local Digger2 = union {
	object {
		Digger1
	}
	object {
		Digger1
		rotate 180 * z
		translate <-0.2, 0, 0>
	}
	translate <0.1, 0, 0>
} 

#local Digger3 = union {
	object {
		Digger2
	}
	object {
		Digger2
		rotate 90 * z
	}
	cylinder {
		<0, 0, -10>
		<0, 0, 10>
		0.1
	}
} 

#local Harnais_Ring = torus {
	0.11
	0.025
	rotate 90 * x
	texture {
		T_Brass_1A
	}
}

#local Hanais1 = difference {
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
		Hanais1
	}
	object {
		Harnais_Ring
		translate <0, 0.81, -0.3>
	}
	object {
		Harnais_Ring
		translate <0, 0.81, 0.3>
	}
}

#declare P_BodyPart_ArmorPart_Chest = Harnais2;
