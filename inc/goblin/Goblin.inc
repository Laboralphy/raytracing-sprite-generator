/*
	Goblin: the small dummy (c_dummy_small.pov, poses inc/frames/small.inc)
	with green skin, long nose, big pointed ears (O_Goblin_Ear, in the helm
	slot), leather armor (studded jerkin, bracers, belt, ripped trousers
	under a leather skirt, boots) and a short sword.
	Face: png/goblin_face.png (made by tools/goblin_face.py).

	Used by c_goblin.pov and c_goblin_warrior.pov: include it after the pose
	file, redefine the pieces to change (P_*), then include BodyParts.inc.
	The measures can be overridden before it.
*/

// small body: short legs, long arms, big head (see c_dummy_small.pov)
#ifndef (N_BodyMetrics_Value)
	#declare N_BodyMetrics_Value = 0.65;
#end
#ifndef (N_BodyMetrics_Leg_Factor)
	#declare N_BodyMetrics_Leg_Factor = 0.65;
#end
#ifndef (N_BodyMetrics_Arm_Factor)
	#declare N_BodyMetrics_Arm_Factor = 0.95;
#end
#ifndef (N_BodyMetrics_Head_Factor)
	#declare N_BodyMetrics_Head_Factor = 1.35;
#end
#ifndef (N_BodyMetrics_Leg_Thickness)
	#declare N_BodyMetrics_Leg_Thickness = 0.12;
#end
#ifndef (N_BodyMetrics_Arm_Thickness)
	#declare N_BodyMetrics_Arm_Thickness = 0.095;
#end
#ifndef (N_BodyMetrics_Nose_Angle)
	#declare N_BodyMetrics_Nose_Angle = 40;
#end
#ifndef (N_BodyMetrics_Nose_Length)
	#declare N_BodyMetrics_Nose_Length = 1.0;
#end

#include "inc/body/BodyMetrics.inc"

#declare C_Goblin_Skin = color rgb <0.42, 0.52, 0.16>;

#declare T_BodyPart_Skin = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 C_Goblin_Skin * 0.85]
			[0.3 C_Goblin_Skin * 0.65]
			[0.95 C_Goblin_Skin]
		}
	}
	scale 0.1
}

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/goblin_face.png"
			map_type 1
		}
	}
}

#declare T_Goblin_Leather = texture {
	pigment {
		bozo
		turbulence 0.4
		color_map {
			[0 color rgb <0.3, 0.17, 0.07>]
			[1 color rgb <0.2, 0.1, 0.04>]
		}
		scale 0.08
	}
	normal {
		wrinkles 0.3
		scale 0.1
	}
	finish {
		specular 0.15
		roughness 0.05
	}
}

#declare T_Goblin_Studs = texture {
	pigment {
		color rgb <0.45, 0.42, 0.38>
	}
	finish {
		specular 0.8
		roughness 0.01
		metallic
	}
}



//   _____
//  | ____|__ _ _ __ ___
//  |  _| / _` | '__/ __|
//  | |__| (_| | |  \__ \
//  |_____\__,_|_|  |___/


// one ear, left side (+x), in the frame of the helm slot: a long flattened
// cone pointing outward and a little up and back
#declare O_Goblin_Ear = cone {
	0, 0.26, <1, 0, 0>, 0
	scale <1, 1, 0.35>
	rotate z * 18
	rotate y * -20
	scale N_Head_Size * 1.3
	translate <0.75 * N_Head_Size, 1.05 * N_Head_Size, 0>
	texture {
		T_BodyPart_Skin
	}
}

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		O_Goblin_Ear
	}
	object {
		O_Goblin_Ear
		scale <-1, 1, 1>
	}
}



//   _               _   _
//  | |    ___  __ _| |_| |__   ___ _ __
//  | |   / _ \/ _` | __| '_ \ / _ \ '__|
//  | |__|  __/ (_| | |_| | | |  __/ |
//  |_____\___|\__,_|\__|_| |_|\___|_|


// jerkin: same profile as the knight's breastplate, in leather, with studs
#declare P_BodyPart_ArmorPart_Chest = union {
	sor {
		5
		<0.9 * N_Shoulder_Len / 2, 0>
		<0.9 * N_Shoulder_Len / 2, N_Torso_Len / 4>
		<1.25 * N_Shoulder_Len / 2, N_Torso_Len>
		<0.9 * N_Shoulder_Len / 2, 1.2 * N_Torso_Len>
		<0.9 * N_Shoulder_Len / 2, 1.2 * N_Torso_Len + 1>
		sturm
		clipped_by {
			plane {
				y, 1.08 * N_Torso_Len
			}
		}
		texture {
			T_Goblin_Leather
		}
	}
	// two rows of studs on the front
	#local I = 0;
	#while (I < 4)
		#local N_U = (I - 1.5) * 0.12;
		sphere {
			<N_U, 0.45 * N_Torso_Len, -0.53 * N_Shoulder_Len>, 0.03
			texture {
				T_Goblin_Studs
			}
		}
		sphere {
			<N_U, 0.75 * N_Torso_Len, -0.6 * N_Shoulder_Len>, 0.03
			texture {
				T_Goblin_Studs
			}
		}
		#local I = I + 1;
	#end
	scale V_BodyPart_Torso_Scale * <0.9, 1, 1>
}

// bracers on the forearms (origin at the hand)
#declare P_BodyPart_ArmorPart_Wrist = cone {
	<0, 0.1 * N_Wrist_Len, 0>, N_Arm_Thickness * 1.25
	<0, 0.65 * N_Wrist_Len, 0>, N_Arm_Thickness * 1.4
	texture {
		T_Goblin_Leather
	}
}

#include "inc/armors/Short_Trousers_Ripped_Dark"

// leather skirt of strips over the trousers (hides the crotch)
#declare P_BodyPart_ArmorPart_Skirt = union {
	object {
		P_BodyPart_ArmorPart_Skirt
	}
	difference {
		cone {
			<0, 0.02, 0>, 0.47 * N_Shoulder_Len
			<0, -N_Thigh_Len * 0.85, 0>, 0.66 * N_Shoulder_Len
			open
		}
		// slits between the strips
		#local I = 0;
		#while (I < 8)
			box {
				<-0.015, -1, 0>, <0.015, -N_Thigh_Len * 0.12, 1>
				rotate y * (I * 45 + 22.5)
			}
			#local I = I + 1;
		#end
		// deeper than the torso scale: covers the buttocks of the torso blob
		scale <1, 1, 0.9>
		texture {
			T_Goblin_Leather
		}
	}
}
#include "inc/armors/Belt_Thick_Dark_Leather_Iron_Round_Buckle"
#include "inc/armors/Boot_Leather_Brown_Dirty"
#include "inc/weapons/Weapon_Sword"
