#include "inc/body/BodyMetrics.inc"

/* for a boot, use N_BodyMetrics_Leg_Thickness and N_Thigh_Len */

#declare O_Thigh_Lame_Pink_Pant = union {
	cylinder {
		<0, 0, 0>
		<0, N_Thigh_Len, 0>
		N_BodyMetrics_Leg_Thickness * 1.1
	}
	sphere {
		<0, N_Thigh_Len, 0>
		N_BodyMetrics_Leg_Thickness * 1.1
	}
	texture {
		pigment {
			color rgb <1, 0.5, 1>
		}
	}
}

#declare P_BodyPart_ArmorPart_Thigh = O_Thigh_Lame_Pink_Pant;
