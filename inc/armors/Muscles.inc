#include "inc/body/BodyMetrics.inc"

/*
	Muscles: skin-coloured bulges to plug on the limbs (left side, the right
	side is mirrored by the body). Each piece is a blob: a core cylinder
	inside the limb, plus one component per muscle, so that the muscles merge
	smoothly with each other and with the limb.

	Declares (not plugged, the character chooses the slots):
		O_Muscles_Arm     -> P_BodyPart_ArmorPart_Arm   (origin at the elbow, up to the shoulder)
		O_Muscles_Forearm -> P_BodyPart_ArmorPart_Elbow (origin at the elbow, down to the hand)
		O_Muscles_Thigh   -> P_BodyPart_ArmorPart_Thigh (origin at the knee, up to the hip)
		O_Muscles_Calf    -> P_BodyPart_ArmorPart_Kneel (origin at the knee, down to the foot)

	Front is -z, outside of the left limb is +x.
	N_Muscles_Bulk scales the bulges (1 = default).
*/

#ifndef (N_Muscles_Bulk)
	#declare N_Muscles_Bulk = 1;
#end

#local N_MUSCLES_THRESHOLD = 0.25;
// a lone component of radius R has its surface at R * sqrt(1 - sqrt(threshold))
#local N_MUSCLES_SURFACE = 1 / sqrt(1 - sqrt(N_MUSCLES_THRESHOLD));

// one muscle: ellipsoid of half-axes V_Radii (approximately, before merging).
// N_Muscles_Bulk thickens it and pushes it outward, but keeps its length.
#macro Muscle(V_Center, V_Radii)
	sphere {
		0, N_MUSCLES_SURFACE, 1
		scale <V_Radii.x * N_Muscles_Bulk, V_Radii.y, V_Radii.z * N_Muscles_Bulk>
		translate <V_Center.x * N_Muscles_Bulk, V_Center.y, V_Center.z * N_Muscles_Bulk>
	}
#end

// core along the limb axis, surface at radius N_Radius
#macro Muscle_Core(V_From, V_To, N_Radius)
	cylinder {
		V_From, V_To, N_Radius * N_MUSCLES_SURFACE, 1
	}
#end



//      _
//     / \   _ __ _ __ ___
//    / _ \ | '__| '_ ` _ \
//   / ___ \| |  | | | | | |
//  /_/   \_\_|  |_| |_| |_|


#local N_T = N_Arm_Thickness;
#local N_L = N_Arm_Len;

#declare O_Muscles_Arm = blob {
	threshold N_MUSCLES_THRESHOLD
	Muscle_Core(<0, 0.15 * N_L, 0>, <0, 0.8 * N_L, 0>, 0.8 * N_T)
	// biceps
	Muscle(<0.05 * N_T, 0.5 * N_L, -0.55 * N_T>, <0.8 * N_T, 0.22 * N_L, 0.8 * N_T>)
	// triceps
	Muscle(<0, 0.62 * N_L, 0.5 * N_T>, <0.75 * N_T, 0.25 * N_L, 0.75 * N_T>)
	// deltoid
	Muscle(<0.4 * N_T, 0.92 * N_L, 0>, <1 * N_T, 0.16 * N_L, 1 * N_T>)
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#local N_L = N_Wrist_Len;

#declare O_Muscles_Forearm = blob {
	threshold N_MUSCLES_THRESHOLD
	Muscle_Core(<0, -0.1 * N_L, 0>, <0, -0.85 * N_L, 0>, 0.8 * N_T)
	// flexors (thick below the elbow, thin at the wrist)
	Muscle(<0.2 * N_T, -0.22 * N_L, -0.2 * N_T>, <0.9 * N_T, 0.22 * N_L, 0.85 * N_T>)
	// extensors
	Muscle(<-0.15 * N_T, -0.3 * N_L, 0.25 * N_T>, <0.7 * N_T, 0.25 * N_L, 0.7 * N_T>)
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}



//   _
//  | |    ___  __ _
//  | |   / _ \/ _` |
//  | |__|  __/ (_| |
//  |_____\___|\__, |
//             |___/


#local N_T = N_Leg_Thickness;
#local N_L = N_Thigh_Len;

#declare O_Muscles_Thigh = blob {
	threshold N_MUSCLES_THRESHOLD
	Muscle_Core(<0, 0.1 * N_L, 0>, <0, 0.85 * N_L, 0>, 0.85 * N_T)
	// quadriceps
	Muscle(<0, 0.6 * N_L, -0.5 * N_T>, <0.9 * N_T, 0.28 * N_L, 0.85 * N_T>)
	// vastus medialis (inside, above the knee)
	Muscle(<-0.45 * N_T, 0.22 * N_L, -0.4 * N_T>, <0.6 * N_T, 0.12 * N_L, 0.6 * N_T>)
	// vastus lateralis (outside)
	Muscle(<0.5 * N_T, 0.45 * N_L, -0.1 * N_T>, <0.65 * N_T, 0.25 * N_L, 0.7 * N_T>)
	// hamstrings
	Muscle(<0, 0.6 * N_L, 0.45 * N_T>, <0.85 * N_T, 0.25 * N_L, 0.75 * N_T>)
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#local N_L = N_Shin_Len;

#declare O_Muscles_Calf = blob {
	threshold N_MUSCLES_THRESHOLD
	Muscle_Core(<0, -0.1 * N_L, 0>, <0, -0.6 * N_L, 0>, 0.8 * N_T)
	// gastrocnemius, inner and outer heads
	Muscle(<-0.3 * N_T, -0.2 * N_L, 0.55 * N_T>, <0.6 * N_T, 0.18 * N_L, 0.7 * N_T>)
	Muscle(<0.3 * N_T, -0.17 * N_L, 0.5 * N_T>, <0.6 * N_T, 0.16 * N_L, 0.7 * N_T>)
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}
