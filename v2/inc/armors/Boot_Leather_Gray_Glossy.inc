#include "inc/body/BodyMetrics.inc"

/*
 _                 _   
| |__   ___   ___ | |_ 
| '_ \ / _ \ / _ \| __|
| |_) | (_) | (_) | |_ 
|_.__/ \___/ \___/ \__|
                       
*/

#declare O_Boot_Leather_Top = difference {
	cylinder {
		<0, -N_Leg_Thickness, 0>
		<0, N_Shin_Len * 0.7, 0>
		N_Leg_Thickness * 1.1
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
		N_Leg_Thickness * 1.1
		scale <1, 1, 2>
	}
	box {
		<-N_Leg_Thickness * 2, 0, N_Leg_Thickness>
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
