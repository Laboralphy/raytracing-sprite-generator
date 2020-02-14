#include "inc/body/BodyMetrics.inc"

/* for a boot, use N_BodyMetrics_Leg_Thickness and N_Thigh_Len */

#declare O_Skel_Thigh_Bone = object {
	sphere_sweep {
		linear_spline
		5
		<N_BodyMetrics_Leg_Thickness, N_Thigh_Len, 0>, N_BodyMetrics_Leg_Thickness
		<0, N_Thigh_Len - 1.5 * N_BodyMetrics_Leg_Thickness, 0>, N_BodyMetrics_Leg_Thickness
		<0, 1.5 * N_BodyMetrics_Leg_Thickness, 0>, N_BodyMetrics_Leg_Thickness
		<-N_BodyMetrics_Leg_Thickness / 2, 0, 0>, N_BodyMetrics_Leg_Thickness
		<N_BodyMetrics_Leg_Thickness / 2, 0, 0>, N_BodyMetrics_Leg_Thickness
	}
	texture {
		T_BodyPart_Skin
	}
}

#declare P_BodyPart_ArmorPart_Thigh = O_Skel_Thigh_Bone;
