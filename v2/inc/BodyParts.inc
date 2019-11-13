#declare N_Shoulder_Len = 2; // distance between two shoulders
#declare N_Torso_Len = 3; // size of torso from shoulder to legs
#declare N_Arm_Len = 2; // arm length from shoulder to elbow
#declare N_ForeArm_Len = 2; // distance from elbow to hand
#declare N_Leg_Len = 2; // distance from torso to kneel
#declare N_Shin_Len = 2; // distance from kneel to foot

#declare T_Default = texture {
	pigment {
		color rgb 0.1
	}
}


#declare O_BodyPart_Boob = sphere_sweep {
	cubic_spline
	5
	<0, 0, 0>, 1
	<0, 0.2, 0>, 0.95
	<0, 1, 0>, 0.4
	<0, 2, 0>, 0.01
	<0, 2.5, 0>, 0
	tolerance 1.0e-4
}

#declare N_BodyPart_Boobs_Size = 1.6;
#declare N_BodyPart_Boobs_Distance = 1.9;
#declare N_BodyPart_Boobs_Z = -0.0;
#declare N_BodyPart_Boobs_Strength = 0.5;
#declare N_BodyPart_Boobs_Threshold = 0.25;
#declare O_BodyPart_Boobs = blob {
	threshold N_BodyPart_Boobs_Threshold
	sphere {
		<-N_BodyPart_Boobs_Distance / 2, 0, 0>
		N_BodyPart_Boobs_Size
		N_BodyPart_Boobs_Strength
		translate z * N_BodyPart_Boobs_Z
	}
	sphere {
		<N_BodyPart_Boobs_Distance / 2, 0, 0>
		N_BodyPart_Boobs_Size
		N_BodyPart_Boobs_Strength
		translate z * N_BodyPart_Boobs_Z
	}
	sphere {
		<-N_BodyPart_Boobs_Distance / 2, N_BodyPart_Boobs_Distance / 6, 0>
		N_BodyPart_Boobs_Size / 2
		N_BodyPart_Boobs_Strength
		translate z * N_BodyPart_Boobs_Z
	}
	sphere {
		<N_BodyPart_Boobs_Distance / 2, N_BodyPart_Boobs_Distance / 6, 0>
		N_BodyPart_Boobs_Size / 2
		N_BodyPart_Boobs_Strength
		translate z * N_BodyPart_Boobs_Z
	}
}

#declare O_BodyPart_Torso_Mid_M = cylinder {
	0
	N_Torso_Len * y
	N_Shoulder_Len / 2
	scale <1, 1, 0.5>
}

#declare O_BodyPart_Torso_Mid_F = lathe {
	cubic_spline
	6
	<10 * N_Shoulder_Len / 20, (-1) * N_Torso_Len / 3>
	<10 * N_Shoulder_Len / 20, 0 * N_Torso_Len / 3>
	<8 * N_Shoulder_Len / 20, 1 * N_Torso_Len / 3>
	<8 * N_Shoulder_Len / 20, 2 * N_Torso_Len / 3>
	<10 * N_Shoulder_Len / 20, 3 * N_Torso_Len / 3>
	<10 * N_Shoulder_Len / 20, 4 * N_Torso_Len / 3>
	sturm
	scale <1, 1, 0.5>
}

#declare O_BodyPart_Torso_M = union {
	object {
		O_BodyPart_Torso_Mid_M
	} 
	torus {
		N_Shoulder_Len / 2 - N_Shoulder_Len / 4
		N_Shoulder_Len / 4
		scale <1, 1, 0.5>
		translate N_Torso_Len * y
	}
	torus {
		N_Shoulder_Len / 2 - N_Shoulder_Len / 4
		N_Shoulder_Len / 4
		scale <1, 1, 0.5>
	}
}

#declare O_BodyPart_Torso_F = union {
	object {
		O_BodyPart_Torso_Mid_F
	} 
	torus {
		N_Shoulder_Len / 2 - N_Shoulder_Len / 4
		N_Shoulder_Len / 4
		scale <1, 1, 0.5>
		translate N_Torso_Len * y
	}
	torus {
		N_Shoulder_Len / 2 - N_Shoulder_Len / 4
		N_Shoulder_Len / 4
		scale <1, 1, 0.5>
	}
	object {
		O_BodyPart_Boobs
		scale N_Shoulder_Len * 0.25
		translate <0, N_Torso_Len * 0.8, -N_Torso_Len * 0.05>
	}
}
