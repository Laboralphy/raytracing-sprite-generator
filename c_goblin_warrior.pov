/*
             _     _ _                                 _
  __ _  ___ | |__ | (_)_ __    __      ____ _ _ __ _ __(_) ___  _ __
 / _` |/ _ \| '_ \| | | '_ \   \ \ /\ / / _` | '__| '__| |/ _ \| '__|
| (_| | (_) | |_) | | | | | |   \ V  V / (_| | |  | |  | | (_) | |
 \__, |\___/|_.__/|_|_|_| |_|    \_/\_/ \__,_|_|  |_|  |_|\___/|_|
 |___/

Goblin warrior: the goblin (inc/goblin/Goblin.inc) with a horned leather cap
(inc/armors/Helm_Horned_Cap.inc), iron
pauldrons, iron arm guards (vambraces, elbow cops, upper arm plates) and a
round shield on the left arm (the poses hold it up: N_Small_Shield).

*/

#declare N_Small_Shield = 1;

#include "inc/Camera.inc"
#include "inc/frames/small.inc"
#include "inc/goblin/Goblin.inc"

#declare T_Goblin_Iron = texture {
	pigment {
		bozo
		turbulence 0.5
		color_map {
			[0 color rgb <0.36, 0.36, 0.38>]
			[0.7 color rgb <0.3, 0.3, 0.32>]
			[1 color rgb <0.35, 0.2, 0.1>]
		}
		scale 0.06
	}
	normal {
		dents 0.4
		scale 0.08
	}
	finish {
		ambient 0.12
		diffuse 0.7
		specular 0.7
		roughness 0.02
		metallic
	}
}



//   _   _      _
//  | | | | ___| |_ __ ___
//  | |_| |/ _ \ | '_ ` _ \
//  |  _  |  __/ | | | | | |
//  |_| |_|\___|_|_| |_| |_|


// horned cap (inc/armors/Helm_Horned_Cap.inc), in the frame of the helm
// slot, in head sizes (as the ears): over the top of the head, the ears
// sticking out under it
#include "inc/armors/Helm_Horned_Cap.inc"

#declare V_Goblin_Helm_Centre = <0, 1.12, 0.02>;

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		O_Goblin_Ear
	}
	object {
		O_Goblin_Ear
		scale <-1, 1, 1>
	}
	object {
		O_Helm_Horned_Cap
		scale 1.08
		rotate x * 12
		scale <1, 0.95, 1.05>
		translate V_Goblin_Helm_Centre
		scale N_Head_Size
	}
}



//      _
//     / \   _ __ _ __ ___  ___
//    / _ \ | '__| '_ ` _ \/ __|
//   / ___ \| |  | | | | | \__ \
//  /_/   \_\_|  |_| |_| |_|___/


// pauldron: two riveted plates over the shoulder (origin at the elbow)
#declare P_BodyPart_ArmorPart_Shoulder = union {
	sphere {
		0, 1
		scale <2.3, 1.5, 2.2> * N_Arm_Thickness
		translate <0.6, 0.1, 0> * N_Arm_Thickness
	}
	sphere {
		0, 1
		scale <2.2, 0.9, 2.1> * N_Arm_Thickness
		translate <0.9, -0.7, 0> * N_Arm_Thickness
	}
	// rivets
	sphere {
		<2.6, 0.2, -0.6> * N_Arm_Thickness, 0.25 * N_Arm_Thickness
	}
	sphere {
		<2.6, 0.2, 0.6> * N_Arm_Thickness, 0.25 * N_Arm_Thickness
	}
	translate y * N_Arm_Len
	texture {
		T_Goblin_Iron
	}
}

// upper arm plate (origin at the elbow)
#declare P_BodyPart_ArmorPart_Arm = cone {
	<0, 0.25 * N_Arm_Len, 0>, N_Arm_Thickness * 1.35
	<0, 0.7 * N_Arm_Len, 0>, N_Arm_Thickness * 1.5
	texture {
		T_Goblin_Iron
	}
}

// elbow cop (origin at the elbow)
#declare P_BodyPart_ArmorPart_Elbow = union {
	sphere {
		0, N_Arm_Thickness * 1.45
	}
	// wing on the outer side
	sphere {
		0, N_Arm_Thickness * 1.1
		scale <0.35, 1, 1>
		translate x * N_Arm_Thickness * 1.25
	}
	texture {
		T_Goblin_Iron
	}
}

// vambrace (origin at the hand), replaces the leather bracer
#declare P_BodyPart_ArmorPart_Wrist = union {
	cone {
		<0, 0.1 * N_Wrist_Len, 0>, N_Arm_Thickness * 1.35
		<0, 0.75 * N_Wrist_Len, 0>, N_Arm_Thickness * 1.55
	}
	torus {
		N_Arm_Thickness * 1.38, N_Arm_Thickness * 0.18
		translate y * 0.12 * N_Wrist_Len
	}
	texture {
		T_Goblin_Iron
	}
}



//   ____  _     _      _     _
//  / ___|| |__ (_) ___| | __| |
//  \___ \| '_ \| |/ _ \ |/ _` |
//   ___) | | | | |  __/ | (_| |
//  |____/|_| |_|_|\___|_|\__,_|


// round shield of planks, iron rim and boss; front towards -z
#local N_Shield_Radius = 0.48;

#declare P_BodyPart_ArmorPart_Shield = union {
	cylinder {
		0, <0, 0, -0.06>, N_Shield_Radius
		texture {
			pigment {
				gradient x
				color_map {
					[0 color rgb <0.35, 0.22, 0.1>]
					[0.9 color rgb <0.42, 0.28, 0.13>]
					[0.9 color rgb <0.15, 0.08, 0.03>]
					[1 color rgb <0.15, 0.08, 0.03>]
				}
				scale 0.16
			}
		}
	}
	torus {
		N_Shield_Radius, 0.035
		rotate x * 90
		translate z * -0.03
		texture {
			T_Goblin_Iron
		}
	}
	sphere {
		0, N_Shield_Radius * 0.3
		scale <1, 1, 0.7>
		translate z * -0.05
		texture {
			T_Goblin_Iron
		}
	}
	translate <0.12, -0.12, 0>
}

#include "inc/body/BodyParts.inc"

object {
	O_BodyPart_Armored_Body_M
	rotate y * N_Animation_Angle
}
