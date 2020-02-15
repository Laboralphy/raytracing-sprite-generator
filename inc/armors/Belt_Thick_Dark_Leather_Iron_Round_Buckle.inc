#include "inc/body/BodyMetrics.inc"
#include "metals"

#declare O_Belt_Leather = cylinder {
	<0, 0, 0>
	<0, N_Torso_Len / 4, 0>
	N_Shoulder_Len * 0.5
	scale V_BodyPart_Torso_Scale * 0.85
	texture {
		pigment {
			color rgb <0.08, 0.08, 0.08>
		}
	}
}

#declare O_Belt_Buckle = torus {
	0.9
	0.3
	rotate <90, 0, 0>
	scale 0.1
	texture {
		T_Chrome_1B
	}
}

#declare P_BodyPart_ArmorPart_Belt = union {
	object {
		O_Belt_Leather
	}
	object {
		O_Belt_Buckle
		translate <0, N_Torso_Len / 8, -V_BodyPart_Torso_Scale.z * N_Shoulder_Len * 0.5>
	}
}
