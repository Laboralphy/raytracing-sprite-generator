/*
	Bow, held in the LEFT hand.

	The body has no left hand weapon slot: the bow is plugged into the shield
	slot (P_BodyPart_ArmorPart_Shield), whose fixed placement in the wrist
	is undone here. So a bow and a shield cannot be worn together.

	Bow frame, origin at the grip (in the fist), before V_Pose_Extra.z:
		x   along the limbs (up when the left arm points at the target, see
		    inc/frames/archer.inc)
		-y  towards the target (the arrow flies along -y)
		+y  towards the archer: the string side
	Driven by the pose (inc/frames/archer.inc):
		V_Pose_Extra.x  draw, 0 (string at rest) to 1 (full draw)
		V_Pose_Extra.y  arrow nocked when > 0.5
		V_Pose_Extra.z  bow turned around the fist (degrees, z axis): 0 to
		                shoot, 90 to carry it limbs along the forearm

	Textures overridable: T_Bow_Wood, T_Bow_String, T_Arrow_Shaft, T_Arrow_Head,
	T_Arrow_Fletching.
*/

#include "inc/body/BodyMetrics.inc"

#ifndef (T_Bow_Wood)
	#declare T_Bow_Wood = texture {
		pigment {
			gradient x
			color_map {
				[0 color rgb <0.4, 0.22, 0.08>]
				[0.5 color rgb <0.3, 0.15, 0.05>]
				[1 color rgb <0.4, 0.22, 0.08>]
			}
			scale 0.1
		}
		finish {
			specular 0.3
			roughness 0.05
		}
	}
#end

#ifndef (T_Bow_String)
	#declare T_Bow_String = texture {
		pigment {
			color rgb <0.85, 0.82, 0.7>
		}
	}
#end

#ifndef (T_Arrow_Shaft)
	#declare T_Arrow_Shaft = texture {
		pigment {
			color rgb <0.6, 0.45, 0.25>
		}
	}
#end

#ifndef (T_Arrow_Head)
	#declare T_Arrow_Head = texture {
		pigment {
			color rgb 0.35
		}
		finish {
			specular 0.6
			metallic
		}
	}
#end

#ifndef (T_Arrow_Fletching)
	#declare T_Arrow_Fletching = texture {
		pigment {
			color rgb <0.7, 0.1, 0.05>
		}
	}
#end

// half length of the bow, and full draw (grip to nock)
#ifndef (N_Bow_Half_Len)
	#declare N_Bow_Half_Len = 1.1 * N_Torso_Len;
#end
#ifndef (N_Bow_Draw_Len)
	#declare N_Bow_Draw_Len = 1.6 * N_Torso_Len;
#end
// bow turned in the fist around its limbs (degrees): the arrow then points
// from the bow hand to the cheek rather than along the forearm (set for the
// stance of inc/frames/archer.inc)
#ifndef (N_Bow_Tilt)
	#declare N_Bow_Tilt = -16;
#end

#local N_Draw = V_Pose_Extra.x;
#local N_L = N_Bow_Half_Len;
// how far the tips are bent back towards the archer (y)
#local N_Bend = (0.14 + 0.22 * N_Draw) * N_L;
#local N_Tip_X = N_L * (1 - 0.1 * N_Draw);
#local V_Tip = <N_Tip_X, N_Bend, 0>;
#local V_Nock = <0, N_Bend + N_Draw * N_Bow_Draw_Len, 0>;

#local N_BOW_STEPS = 10;

#local O_Bow_Limbs = sphere_sweep {
	linear_spline
	2 * N_BOW_STEPS + 1
	#local I = -N_BOW_STEPS;
	#while (I <= N_BOW_STEPS)
		#local N_T = I / N_BOW_STEPS;
		<N_T * N_Tip_X, N_Bend * N_T * N_T, 0>, 0.045 - 0.022 * abs(N_T)
		#local I = I + 1;
	#end
	texture {
		T_Bow_Wood
	}
}

#local O_Bow_String = union {
	cylinder {
		V_Tip, V_Nock, 0.012
	}
	cylinder {
		V_Tip * <-1, 1, 1>, V_Nock, 0.012
	}
	sphere {
		V_Nock, 0.012
	}
	texture {
		T_Bow_String
	}
}

#local O_Bow_Arrow = union {
	cylinder {
		V_Nock, <0, -0.25 * N_L, 0>, 0.02
		texture {
			T_Arrow_Shaft
		}
	}
	cone {
		<0, -0.25 * N_L, 0>, 0.045, <0, -0.25 * N_L - 0.14, 0>, 0
		texture {
			T_Arrow_Head
		}
	}
	// fletching: two vanes near the nock
	box {
		<-0.05, 0.03, -0.004>, <0.05, 0.2, 0.004>
		translate V_Nock - y * 0.05
		texture {
			T_Arrow_Fletching
		}
	}
	box {
		<-0.004, 0.03, -0.05>, <0.004, 0.2, 0.05>
		translate V_Nock - y * 0.05
		texture {
			T_Arrow_Fletching
		}
	}
}

// the bow in the fist (origin at the grip)
#declare O_Bow = union {
	object {
		O_Bow_Limbs
	}
	// grip
	cylinder {
		<-0.12, 0, 0>, <0.12, 0, 0>, 0.055
		texture {
			T_Bow_Wood
		}
	}
	object {
		O_Bow_String
	}
	#if (V_Pose_Extra.y > 0.5)
		object {
			O_Bow_Arrow
		}
	#end
	rotate x * N_Bow_Tilt
	rotate z * V_Pose_Extra.z
}

// undo the placement of the shield in the left wrist (inc/body/BodyParts.inc):
// there, the shield is turned <0, -90, 0>, then <-90, 0, 0>, then moved
// to <N_Arm_Thickness, -N_Wrist_Len, -0.25 * N_Wrist_Len>
#declare P_BodyPart_ArmorPart_Shield = object {
	O_Bow
	translate <0, -N_Wrist_Len, 0>
	translate -<N_Arm_Thickness, -N_Wrist_Len, -0.25 * N_Wrist_Len>
	rotate <90, 0, 0>
	rotate <0, 90, 0>
}
