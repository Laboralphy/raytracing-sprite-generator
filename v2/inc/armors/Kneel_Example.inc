#include "inc/BodyMetrics.inc"

/* for a kneel, use N_BodyMetrics_Leg_Thickness */

#declare O_Kneel_Ugly_Green_Sphere = sphere {
	<0, 0, 0>
	N_BodyMetrics_Leg_Thickness * 1.3
	texture {
		pigment {
			color rgb <0, 1, 0>
		}
	}
}

#declare P_BodyPart_ArmorPart_Kneel = O_Kneel_Ugly_Green_Sphere;
