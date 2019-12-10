#include "inc/body/BodyMetrics.inc"


#declare T_Default = texture {
	pigment {
		color rgb 0.1
	}
}

#declare NULL_OBJECT = sphere { 0, 0 }




//   _____                    
//  |_   _|__  _ __ ___  ___  
//    | |/ _ \| '__/ __|/ _ \ 
//    | | (_) | |  \__ \ (_) |
//    |_|\___/|_|  |___/\___/ 



#declare O_BodyPart_Torso_M = blob {
	threshold N_BodyMetrics_Blob_Threshold
	/* bottom */
	sphere {
		0
		N_Shoulder_Len / 2
		2
		scale <1, 0.8, 0.55>
	}
	
	#ifndef (P_BodyPart_ArmorPart_Skirt)
		/* bottom left */
		sphere {
			<N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
			N_Shoulder_Len / 3.5
			3
		}
		/* bottom right */
		sphere {
			<-N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
			N_Shoulder_Len / 3.5
			3
		}
		/* bottom center */
		sphere {
			<0, -N_Torso_Len * 0.1, -N_Shoulder_Len / 20>
			N_Shoulder_Len / 5
			3
			scale <1, 1.5, 1>
		}
	#end
	
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

	/* neck */
	cylinder {
		<0, N_Torso_Len, 0>
		<0, N_Torso_Len + N_Neck_Len, 0>
		N_Shoulder_Len / 5
		1
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
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#declare O_BodyPart_Torso_M_Armor = union {
	#ifdef (P_BodyPart_ArmorPart_Skirt)
		object {
			P_BodyPart_ArmorPart_Skirt
			translate <0, N_Belt_Height, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Belt)
		object {
			P_BodyPart_ArmorPart_Belt
			translate <0, N_Belt_Height, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Chest)
		object {
			P_BodyPart_ArmorPart_Chest
		}
	#end
}


#declare O_BodyPart_Armored_Torso_M = union {
	#ifdef (P_BodyPart_Torso_Replace)
		object {
			P_BodyPart_Torso_Replace
		}
	#else
		object {
			O_BodyPart_Torso_M
		}
	#end
	object {
		O_BodyPart_Torso_M_Armor
	}
}


#declare O_BodyPart_Torso_F = blob {
	threshold N_BodyMetrics_Blob_Threshold
	/* bottom */
	sphere {
		0
		N_Shoulder_Len / 2
		2
		scale <1, 0.8, 0.55>
	}
	
	#ifndef (P_BodyPart_ArmorPart_Skirt)
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
	#end
	
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
		2
		scale V_BodyPart_Torso_Scale
	}
	
	// neck
	cylinder {
		<0, N_Torso_Len, 0>
		<0, 2 * N_Torso_Len, 0>
		N_Shoulder_Len / 5
		1
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
		<N_BodyPart_Boobs_Spacing, N_Torso_Len - (N_Torso_Len / 6), -N_Shoulder_Len / 6>
		N_BodyPart_Boobs_Size 
		2
	}
	/* right boob */
	sphere {
		<-N_BodyPart_Boobs_Spacing, N_Torso_Len - (N_Torso_Len / 6), -N_Shoulder_Len / 6>
		N_BodyPart_Boobs_Size 
		2
	}
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#declare O_BodyPart_Torso_F_Armor = union {
	#ifdef (P_BodyPart_ArmorPart_Skirt)
		object {
			P_BodyPart_ArmorPart_Skirt
			translate <0, N_Torso_Len / 4, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Belt)
		object {
			P_BodyPart_ArmorPart_Belt
			translate <0, N_Torso_Len / 4, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Chest)
		object {
			P_BodyPart_ArmorPart_Chest
		}
	#end
}

#declare O_BodyPart_Armored_Torso_F = union {
	#ifdef (P_BodyPart_Torso_Replace)
		object {
			P_BodyPart_Torso_Replace
		}
	#else
		object {
			O_BodyPart_Torso_F
		}
	#end
	object {
		O_BodyPart_Torso_F_Armor
	}
}





//     _                   
//    | |    ___  __ _ ___ 
//    | |   / _ \/ _` / __|
//    | |__|  __/ (_| \__ \
//    |_____\___|\__, |___/
//               |___/     


#declare O_BodyPart_Thigh = sphere_sweep {
	linear_spline
	2
	<0, 0, 0>, N_Leg_Thickness * 1.1
	<0, -N_Thigh_Len, 0>, N_Leg_Thickness
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#declare O_BodyPart_Thigh_Armor = object {
	#ifdef (P_BodyPart_ArmorPart_Thigh)
		P_BodyPart_ArmorPart_Thigh
	#else
		NULL_OBJECT
	#end
	translate <0, -N_Thigh_Len, 0>
}

#declare O_BodyPart_Armored_Thigh = union {
	object {
		O_BodyPart_Thigh
	}
	object {
		O_BodyPart_Thigh_Armor
	}
}

#declare O_BodyPart_Shin = sphere_sweep {
	linear_spline
	2
	<0, 0, 0>, N_Leg_Thickness
	<0, -N_Shin_Len, 0>, N_Leg_Thickness * 0.8
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#declare O_BodyPart_Shin_Armor = union {
	#ifdef (P_BodyPart_ArmorPart_Shin)
		object {
			P_BodyPart_ArmorPart_Shin
			translate <0, -N_Shin_Len, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Kneel)
		object {
			P_BodyPart_ArmorPart_Kneel
		}
	#end
}

#declare O_BodyPart_Armored_Shin = union {
	object {
		O_BodyPart_Shin
	}
	object {
		O_BodyPart_Shin_Armor
	}
}

#declare O_BodyPart_Armored_Leg_Left = union {
	object {
		O_BodyPart_Armored_Thigh
	}
	object {
		O_BodyPart_Armored_Shin
		rotate AV_Shin_Left
		translate <0, -N_Thigh_Len, 0>
	}
	rotate AV_Thigh_Left
}

#declare O_BodyPart_Armored_Leg_Right = union {
	object {
		O_BodyPart_Armored_Thigh
		scale <-1, 1, 1>
	}
	object {
		O_BodyPart_Armored_Shin
		scale <-1, 1, 1>
		rotate AV_Shin_Right
		translate <0, -N_Thigh_Len, 0>
	}
	rotate AV_Thigh_Right
}





//   _   _                 _ 
//  | | | | __ _ _ __   __| |
//  | |_| |/ _` | '_ \ / _` |
//  |  _  | (_| | | | | (_| |
//  |_| |_|\__,_|_| |_|\__,_|




#declare O_BodyPart_Hand_Finger = sphere_sweep {
	linear_spline
	3
	<0, 0, 0>, N_Finger_Thickness
	<0, -N_Finger_Len, 0>, N_Finger_Thickness
	<-N_Finger_Len, -N_Finger_Len, 0>, N_Finger_Thickness
}

#declare O_BodyPart_Hand_Thumb = sphere_sweep {
	linear_spline
	3
	<N_Finger_Len * 0.4, N_Finger_Len * 0.3, N_Finger_Len * 0.3>, N_Finger_Thickness * 1.5
	<0, 0, 0>, N_Finger_Thickness
	<0, -N_Finger_Len * 0.75, 0>, N_Finger_Thickness
}

#declare O_BodyPart_Hand_Fingers = union {
	object {
		O_BodyPart_Hand_Finger
	}
	object {
		O_BodyPart_Hand_Finger
		translate <0, 0, -1.8 * N_Finger_Thickness>
	}
	object {
		O_BodyPart_Hand_Finger
		translate <0, 0, 1.8 * N_Finger_Thickness>
	}
	object {
		O_BodyPart_Hand_Thumb
		rotate <5, 0, 5>
		translate <-2.5 * N_Finger_Thickness, N_Finger_Thickness, -2.5 * N_Finger_Thickness>
	}
	blob {
		threshold 0.158
		sphere {
			<0, 0, -1.8 * N_Finger_Thickness>, N_Finger_Thickness * 1.6, 0.5
		}
		sphere {
			<0, 0, 0>, N_Finger_Thickness * 1.6, 0.5
		}
		sphere {
			<0, 0, 1.8 * N_Finger_Thickness>, N_Finger_Thickness * 1.6, 0.5
		}
		sphere {
			<0, N_Arm_Thickness, 0>, N_Arm_Thickness * 1.2, 2
			scale <0.5, 0.7, 1>
		}
	}
}

#declare O_BodyPart_Hand = object {
	O_BodyPart_Hand_Fingers
	//rotate A_Hand
	translate <N_Arm_Thickness * 0.5, 0, 0>
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}




//      _                                     _                 _     _   
//     / \   _ __ _ __ ___     __ _ _ __   __| | __      ___ __(_)___| |_ 
//    / _ \ | '__| '_ ` _ \   / _` | '_ \ / _` | \ \ /\ / / '__| / __| __|
//   / ___ \| |  | | | | | | | (_| | | | | (_| |  \ V  V /| |  | \__ \ |_ 
//  /_/   \_\_|  |_| |_| |_|  \__,_|_| |_|\__,_|   \_/\_/ |_|  |_|___/\__|



#declare O_BodyPart_Arm = sphere_sweep {
	linear_spline
	2
	<0, 0, 0>, N_Arm_Thickness * 1.5
	<0, -N_Arm_Len, 0>, N_Arm_Thickness
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}

#declare O_BodyPart_Arm_Armor = union {
	#ifdef (P_BodyPart_ArmorPart_Arm)
		object {
			P_BodyPart_ArmorPart_Arm
			translate <0, -N_Arm_Len, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Shoulder)
		object {
			P_BodyPart_ArmorPart_Shoulder
			translate <0, -N_Arm_Len, 0>
		}
	#end
}

#declare O_BodyPart_Armored_Arm = union {
	object {
		O_BodyPart_Arm
	}
	object {
		O_BodyPart_Arm_Armor
	}
}

#declare O_BodyPart_Wrist = union {
	sphere_sweep {
		linear_spline
		2
		<0, 0, 0>, N_Arm_Thickness
		<0, -N_Wrist_Len, 0>, N_Arm_Thickness
		#ifdef (T_BodyPart_Skin)
		#end
	}
	object {
		O_BodyPart_Hand
		translate <0, -N_Wrist_Len, 0>
	}
	#ifdef (T_BodyPart_Skin)
	texture {
		T_BodyPart_Skin
	}
	#end
}

#declare O_BodyPart_Wrist_Armor = union {
	#ifdef (P_BodyPart_ArmorPart_Wrist)
		object {
			P_BodyPart_ArmorPart_Wrist
			translate <0, -N_Wrist_Len, 0>
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Elbow)
		object {
			P_BodyPart_ArmorPart_Elbow
		}
	#end
}

#declare O_BodyPart_Armored_Wrist = union {
	object {
		O_BodyPart_Wrist
	}
	object {
		O_BodyPart_Wrist_Armor
	}
}

#declare O_BodyPart_Armored_Arm_Left = union {
	object {
		O_BodyPart_Armored_Arm
	}
	union {
		object {
			O_BodyPart_Armored_Wrist
		}
		#ifdef (P_BodyPart_ArmorPart_Shield)
			object {
				P_BodyPart_ArmorPart_Shield
				rotate <0, -90, 0>
				rotate <-90, 0, 0>
				translate <N_Arm_Thickness, -N_Wrist_Len, -0.25 * N_Wrist_Len>
			}
		#end
		rotate AV_Wrist_Left
		translate <0, -N_Arm_Len, 0>
	}
	rotate AV_Arm_Left
}

#declare O_BodyPart_Unarmored_Arm_Left = union {
	object {
		O_BodyPart_Arm
	}
	union {
		object {
			O_BodyPart_Wrist
		}
		rotate AV_Wrist_Left
		translate <0, -N_Arm_Len, 0>
	}
	rotate AV_Arm_Left
}

#declare O_BodyPart_Armored_Arm_Right = union {
	object {
		O_BodyPart_Armored_Arm
		scale <-1, 1, 1>
	}
	union {
		object {
			O_BodyPart_Armored_Wrist
			scale <-1, 1, 1>
		}
		#ifdef (P_BodyPart_ArmorPart_Weapon)
			object {
				P_BodyPart_ArmorPart_Weapon
				rotate <-90, 0, 0>
				translate <0, -N_Wrist_Len, 0>
			}
		#end
		rotate AV_Wrist_Right
		translate <0, -N_Arm_Len, 0>
	}
	rotate AV_Arm_Right
}

#declare O_BodyPart_Unarmored_Arm_Right = union {
	object {
		O_BodyPart_Arm
		scale <-1, 1, 1>
	}
	union {
		object {
			O_BodyPart_Wrist
			scale <-1, 1, 1>
		}
		rotate AV_Wrist_Right
		translate <0, -N_Arm_Len, 0>
	}
	rotate AV_Arm_Right
}





//   _   _                _                   _   _   _           _    
//  | | | | ___  __ _  __| |   __ _ _ __   __| | | \ | | ___  ___| | __
//  | |_| |/ _ \/ _` |/ _` |  / _` | '_ \ / _` | |  \| |/ _ \/ __| |/ /
//  |  _  |  __/ (_| | (_| | | (_| | | | | (_| | | |\  |  __/ (__|   < 
//  |_| |_|\___|\__,_|\__,_|  \__,_|_| |_|\__,_| |_| \_|\___|\___|_|\_\


/*
#declare O_BodyPart_Neck = sor {
	7
	<0.2 + 0, 		-1>
	<0.2 + 0, 		0>
	<0.2 + 0.03,	0.26>
	<0.2 + 0.13,	0.5>
	<0.2 + 0.29,	0.71>
	<0.2 + 0.5,	0.87>
	<0.2 + 1,		1>
	sturm
	scale <1.2, -1, 0.5> * N_Neck_Len
	translate <0, N_Neck_Len, 0>
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
}
*/

#declare O_BodyPart_Head = ovus {
	1
	0.2
	scale <1, -1, 1> * N_Head_Size
	rotate <30, 0, 0>
	translate <0, 0.6 * N_Head_Size, 0> 
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
	#ifdef (T_BodyPart_Face) 
		texture {
			T_BodyPart_Face
		}
	#end
}


/*
 _          _           
| |__   ___| |_ __ ___  
| '_ \ / _ \ | '_ ` _ \ 
| | | |  __/ | | | | | |
|_| |_|\___|_|_| |_| |_|

*/

#declare O_BodyPart_Armored_Head = union {
	#ifdef (P_BodyPart_Head_Replace) 
		object {
			P_BodyPart_Head_Replace
		}
	#else
		object {
			O_BodyPart_Head
		}
	#end
	#ifdef (P_BodyPart_ArmorPart_Helm)
		object {
			P_BodyPart_ArmorPart_Helm
			translate <0, -N_Head_Size / 2 + 0.1, 0>
		}
	#end
}







#declare O_BodyPart_Armored_Body_F = union {
	object {
		O_BodyPart_Armored_Torso_F
		translate <0, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Head
		translate <0, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len + N_Neck_Len, 0>
	}
	object {
		O_BodyPart_Armored_Leg_Left
		translate <N_Shoulder_Len / 4, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Leg_Right
		translate <-N_Shoulder_Len / 4, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Arm_Left
		translate <N_Shoulder_Len / 2, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len, 0>
	}
	object {
		O_BodyPart_Armored_Arm_Right
		translate <-N_Shoulder_Len / 2, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len, 0>
	}
}

#declare O_BodyPart_Armored_Body_M = union {
	object {
		O_BodyPart_Armored_Torso_M
		translate <0, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Head
		translate <0, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len + N_Neck_Len, 0>
	}
	object {
		O_BodyPart_Armored_Leg_Left
		translate <N_Shoulder_Len / 4, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Leg_Right
		translate <-N_Shoulder_Len / 4, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness, 0>
	}
	object {
		O_BodyPart_Armored_Arm_Left
		translate <N_Shoulder_Len / 2, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len, 0>
	}
	object {
		O_BodyPart_Armored_Arm_Right
		translate <-N_Shoulder_Len / 2, N_Shin_Len + N_Thigh_Len + N_Leg_Thickness + N_Torso_Len, 0>
	}
}

