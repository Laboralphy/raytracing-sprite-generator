#include "inc/BodyMetrics.inc"
#include "golds"
#include "finish.inc"

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
}

#declare O_FemaleShirt_Extruded = difference {
	object {
		O_FemaleShirt_Base
	}
	cylinder {
		<0, 1.2 * N_Torso_Len, 10>
		<0, 1.2 * N_Torso_Len, -10>
		N_Shoulder_Len / 2.75
	}
	texture {
		pigment {
			tiling 11
			color_map {
				[0, Blue]
				[0.5 Blue * 0.5]
				[1 Blue]
			}
			rotate <90, 0, 45>
			scale 0.1
		}
	}
}

#declare O_Belt_Leather = cylinder {
	<0, 0, 0>
	<0, N_Torso_Len / 4, 0>
	N_Shoulder_Len / 2
	scale V_BodyPart_Torso_Scale * 0.85
	texture {
		pigment {
			color rgb <0.2, 0.08, 0.01>
		}
	}
}

#declare O_Belt_Buckle = torus {
	0.9
	0.3
	rotate <90, 0, 0>
	scale 0.1
	texture {
		T_Gold_1B
	}
}

#declare P_BodyPart_ArmorPart_Belt = union {
	object {
		O_Belt_Leather
	}
	object {
		O_Belt_Buckle
		translate <0, N_Torso_Len / 8, -V_BodyPart_Torso_Scale.z * N_Shoulder_Len / 2>
	}
}


#declare P_BodyPart_ArmorPart_Chest = O_FemaleShirt_Extruded;


#declare O_Skirt_Blue = sor {
	6
	<1, -1>
	<0.7, -0.9>
	<0.65, -0.8>
	<0.6, -0.5>
	<0.4, -0.1>
	<0, 0>
	sturm
	scale <1, 0.9, 1.2>
	scale V_BodyPart_Torso_Scale
	translate 0.1 * y
	texture {
		pigment {
			radial
			color_map {
				[0, Blue]
				[0.5 Blue * 0.5]
				[1 Blue]
			}
			frequency 16
		}
	}
}

#declare P_BodyPart_ArmorPart_Skirt = O_Skirt_Blue;

/*
 _                 _   
| |__   ___   ___ | |_ 
| '_ \ / _ \ / _ \| __|
| |_) | (_) | (_) | |_ 
|_.__/ \___/ \___/ \__|
                       
*/

#declare O_Boot_Leather_Top = difference {
	cylinder {
		<0, 0, 0>
		<0, N_Shin_Len * 0.7, 0>
		N_Leg_Thickness * 0.9
	}
	box {
		<0, 0, N_Leg_Thickness>
		<N_Leg_Thickness, N_Leg_Thickness, -N_Leg_Thickness>
		rotate z * 45
		translate <0, (N_Shin_Len - N_Leg_Thickness) * 0.7, 0>
	}
}

#declare O_Boot_Leather_Heel = intersection {
	sphere {
		<0, 0, 0>
		N_Leg_Thickness
		scale <1, 1, 2>
	}
	box {
		<-N_Leg_Thickness * 2, 0, 0>
		<N_Leg_Thickness * 2, N_Leg_Thickness * 2, -N_Leg_Thickness * 2>
	}
	translate -N_Leg_Thickness * y
}

// mauvais orthographe (majuscule errante)
#declare P_BodyPart_ArmorPart_Shin = union {
	object {
		O_Boot_Leather_Top
	}
	object {
		O_Boot_Leather_Heel
	}
	
	texture {
		pigment {
			Gray05
		}
		finish {
			Phong_Glossy
		}
	}
}

