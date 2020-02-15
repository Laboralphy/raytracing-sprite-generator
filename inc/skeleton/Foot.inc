#local O_Skel_Foot_Finger = sphere_sweep {
	linear_spline
	4
	0, N_Finger_Thickness
	<0, 0, -N_Finger_Len>, N_Finger_Thickness
	<0, 0, -N_Finger_Len>, N_Finger_Thickness / 2
	<0, 0, -N_Finger_Len * 2>, N_Finger_Thickness / 2
}

#declare O_Skel_Foot = union {
	object {
		O_Skel_Foot_Finger
	}
	object {
		O_Skel_Foot_Finger
		rotate <0, 20, 0>
	}
	object {
		O_Skel_Foot_Finger
		rotate <0, -20, 0>
	}
	object {
		O_Skel_Foot_Finger
		rotate <0, -10, 0>
	}
	object {
		O_Skel_Foot_Finger
		rotate <0, 10, 0>
	}
	scale 1.5
	texture {
		T_BodyPart_Skin
	}
}
