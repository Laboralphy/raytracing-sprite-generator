#include "inc/body/BodyMetrics.inc"

#declare C_Shirt_Dirty = color rgb <0.15, 0.35, 0.15>;

#declare T_Shirt_Dirty = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 color rgb <0.2, 0, 0>]
			[0.3 C_Shirt_Dirty * 0.2]
			[0.5 C_Shirt_Dirty]
			[1 C_Shirt_Dirty * 0.7]
		}
	}
	scale 0.5
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

// ne garder que la partie au dessus de y 0
#declare O_MaleShirt_Trunc = intersection {
	object {
		O_MaleShirt_Base
	}
	box {
		<-10, 0, -10>
		<10, 10, 10>
	}
}


#declare O_Shirt_Razor_0 = box {
	<-10, 0, 0>
	<10, -20, 20>
	rotate x * 45
	scale <1, 1, 0.5>
}

#declare O_Shirt_Razor_1 = union {
	object {
		O_Shirt_Razor_0
		translate <0, 0.8, 0>
	}
	object {
		O_Shirt_Razor_0
		rotate y * 30
		translate <0, 0.9, 0>
	}
	object {
		O_Shirt_Razor_0
		rotate y * 75
		translate <0, 0.8, 0>
	}
	object {
		O_Shirt_Razor_0
		rotate y * 100
		translate <0, 0.9, 0>
	}
	object {
		O_Shirt_Razor_0
		rotate y * 133
		translate <0, 0.8, 0>
	}
}


// dechirer la base du t-shirt
#declare P_BodyPart_ArmorPart_Chest = difference {
	object {
		O_MaleShirt_Trunc
	}
	object {
		O_Shirt_Razor_1
		translate <0, -N_Torso_Len * 0.2, 0>
	}
	object {
		O_Shirt_Razor_1
		scale <1, -1, 1>
		rotate <0, 75, 0>
		translate <0, N_Torso_Len * 2, 0>
	}
}
