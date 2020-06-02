#include "inc/body/BodyMetrics.inc"
#include "golds"
#include "finish.inc"

#declare T_Pleaded_Blue = texture {
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
		<N_BodyPart_Boobs_Spacing, N_Torso_Len - 0.1 * N_Torso_Len, -N_Shoulder_Len / 5>
		N_BodyPart_Boobs_Size 
		3.2
	}
	/* right boob */
	sphere {
		<-N_BodyPart_Boobs_Spacing, N_Torso_Len - 0.1 * N_Torso_Len, -N_Shoulder_Len / 5>
		N_BodyPart_Boobs_Size 
		3.2
	}
	translate <0, -N_Torso_Len / 2 0>
	scale 1.05
	translate <0, N_Torso_Len / 2 0>
}

#declare O_FemaleShirt_Croped = difference {
	object {
		O_FemaleShirt_Base
	}
	cylinder {
		<0, 1.5 * N_Torso_Len, 2>
		<0, 1.2 * N_Torso_Len,  -10>
		N_Shoulder_Len / 2.5
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



#declare P_BodyPart_ArmorPart_Chest = O_FemaleShirt_Croped;


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
	texture { T_Pleaded_Blue }
}

#declare P_BodyPart_ArmorPart_Skirt = O_Skirt_Blue;



/*
     _                 _     _               
 ___| |__   ___  _   _| | __| | ___ _ __ ___ 
/ __| '_ \ / _ \| | | | |/ _` |/ _ \ '__/ __|
\__ \ | | | (_) | |_| | | (_| |  __/ |  \__ \
|___/_| |_|\___/ \__,_|_|\__,_|\___|_|  |___/

*/

#declare P_BodyPart_ArmorPart_Shoulder = union {
	sphere {
		<0, N_Arm_Len, 0>
		N_Arm_Thickness * 2.1
		texture { T_Pleaded_Blue }
	}
	cylinder {
		<0, N_Arm_Len, 0>
		<0, N_Arm_Len * 0.5, 0>
		N_Arm_Thickness * 1.5
		texture { T_Pleaded_Blue }
	}
}
