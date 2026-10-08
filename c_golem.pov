/*
             _
   __ _  ___ | | ___ _ __ ___
  / _` |/ _ \| |/ _ \ '_ ` _ \
 | (_| | (_) | |  __/ | | | | |
  \__, |\___/|_|\___|_| |_| |_|
  |___/

Clay golem: massive body, short thick legs, long and heavy arms, small head
sunk between the shoulders. Brown clay with mineral cracks, rock lumps on
the chest, the back, the shoulders and the knees, stone fists and block
feet. Minimal face: two glowing amber slits and a mouth line.
Fights with its fists (poses inc/frames/golem.inc).

*/

// size of the golem: everything given in absolute units below (thicknesses,
// rock blocks of the limbs, hips, head offset) follows it
#declare N_Golem_Scale = 1.36;

#declare N_BodyMetrics_Value = 1.1 * N_Golem_Scale;
#declare N_BodyMetrics_Member_Factor = 0.85;
#declare N_BodyMetrics_Leg_Factor = 0.8;
#declare N_BodyMetrics_Arm_Factor = 1.1;
#declare N_BodyMetrics_Head_Factor = 0.75;
#declare N_BodyMetrics_Leg_Thickness = 0.3 * N_Golem_Scale;
#declare N_BodyMetrics_Arm_Thickness = 0.24 * N_Golem_Scale;
#declare N_Hip_Spacing = 0.42 * N_Golem_Scale;
// head sunk between the shoulders, a little forward
#declare AV_Head_Offset = <0, -0.5, -0.2> * N_Golem_Scale;

#include "inc/Camera.inc"
#include "inc/frames/golem.inc"
#include "inc/body/BodyMetrics.inc"

#declare T_Golem_Clay = texture {
	pigment {
		granite
		color_map {
			[0 color rgb <0.3, 0.15, 0.06>]
			[0.5 color rgb <0.24, 0.12, 0.045>]
			[1 color rgb <0.17, 0.08, 0.03>]
		}
		scale 0.8
	}
	normal {
		crackle 0.6
		scale 0.22
	}
	finish {
		ambient 0.12
		diffuse 0.8
		specular 0.05
		roughness 0.2
	}
}

// darker, rougher clay for the rock lumps
#declare T_Golem_Rock = texture {
	pigment {
		granite
		color_map {
			[0 color rgb <0.25, 0.12, 0.05>]
			[0.6 color rgb <0.19, 0.09, 0.035>]
			[1 color rgb <0.13, 0.06, 0.025>]
		}
		scale 0.6
	}
	normal {
		crackle 0.9
		scale 0.18
	}
	finish {
		ambient 0.1
		diffuse 0.8
		specular 0.03
		roughness 0.25
	}
}

#declare C_Golem_Glow = color rgb <1, 0.6, 0.15>;

#declare T_BodyPart_Skin = T_Golem_Clay;

// a rounded rock block of half sizes V_Size, centred on V_Centre
#macro Golem_Block(V_Centre, V_Size)
	superellipsoid {
		<0.45, 0.45>
		scale V_Size
		translate V_Centre
	}
#end



//   _   _                _
//  | | | | ___  __ _  __| |
//  | |_| |/ _ \/ _` |/ _` |
//  |  _  |  __/ (_| | (_| |
//  |_| |_|\___|\__,_|\__,_|


// a rounded block, two glowing slits for the eyes, a carved mouth line;
// in head sizes, origin at the top of the neck
#declare P_BodyPart_Head_Replace = union {
	difference {
		Golem_Block(<0, 0.75, 0>, <0.85, 0.75, 0.8>)
		// eye slits
		box {
			<-0.55, 0.88, -2>, <-0.15, 1.02, -0.6>
			rotate z * -8
		}
		box {
			<0.15, 0.88, -2>, <0.55, 1.02, -0.6>
			rotate z * 8
		}
		// mouth line
		box {
			<-0.35, 0.36, -2>, <0.35, 0.43, -0.65>
		}
		texture {
			T_Golem_Clay
		}
	}
	// glow at the back of the eye slits
	box {
		<-0.55, 0.88, -0.72>, <-0.15, 1.02, -0.6>
		rotate z * -8
		texture {
			pigment {
				C_Golem_Glow
			}
			finish {
				ambient 1
				diffuse 0
			}
		}
	}
	box {
		<0.15, 0.88, -0.72>, <0.55, 1.02, -0.6>
		rotate z * 8
		texture {
			pigment {
				C_Golem_Glow
			}
			finish {
				ambient 1
				diffuse 0
			}
		}
	}
	scale N_Head_Size
}



//   ____            _
//  | __ )  ___   __| |_   _
//  |  _ \ / _ \ / _` | | | |
//  | |_) | (_) | (_| | |_| |
//  |____/ \___/ \__,_|\__, |
//                     |___/


// rock masses on the torso (origin at the hips): broad chest, hump on the
// back that hides the neck, belly
#declare P_BodyPart_ArmorPart_Chest = union {
	Golem_Block(<-0.3, 0.78, -0.12> * N_Torso_Len, <0.42, 0.34, 0.32> * N_Torso_Len)
	Golem_Block(<0.3, 0.78, -0.12> * N_Torso_Len, <0.42, 0.34, 0.32> * N_Torso_Len)
	Golem_Block(<0, 0.9, 0.18> * N_Torso_Len, <0.55, 0.4, 0.36> * N_Torso_Len)
	Golem_Block(<0, 0.35, -0.05> * N_Torso_Len, <0.45, 0.32, 0.36> * N_Torso_Len)
	texture {
		T_Golem_Rock
	}
}

// rock mass around the hips (origin at the bottom of the torso, going down):
// hides the shapes of the torso blob
#declare P_BodyPart_ArmorPart_Skirt = union {
	Golem_Block(<0, -0.08, 0> * N_Torso_Len, <0.5, 0.22, 0.36> * N_Torso_Len)
	Golem_Block(<0, -0.22, 0.05> * N_Torso_Len, <0.3, 0.16, 0.3> * N_Torso_Len)
	texture {
		T_Golem_Rock
	}
}

// boulder on the shoulder (origin at the elbow)
#declare P_BodyPart_ArmorPart_Shoulder = union {
	Golem_Block(<0.3 * N_Golem_Scale, N_Arm_Len + 0.1 * N_Golem_Scale, 0>, <0.42, 0.36, 0.42> * N_Golem_Scale)
	Golem_Block(<0.15 * N_Golem_Scale, N_Arm_Len * 0.55, 0>, <0.3, 0.28, 0.3> * N_Golem_Scale)
	texture {
		T_Golem_Rock
	}
}

// stone fist and forearm lump (origin at the hand)
#declare P_BodyPart_ArmorPart_Wrist = union {
	Golem_Block(<0, -0.1, 0> * N_Golem_Scale, <0.34, 0.32, 0.34> * N_Golem_Scale)
	Golem_Block(<0, 0.45 * N_Wrist_Len, 0>, <0.3, 0.32, 0.3> * N_Golem_Scale)
	texture {
		T_Golem_Rock
	}
}

// knee boulder (origin at the knee)
#declare P_BodyPart_ArmorPart_Kneel = Golem_Block(<0, 0, -0.1> * N_Golem_Scale, <0.36, 0.32, 0.34> * N_Golem_Scale)
#declare P_BodyPart_ArmorPart_Kneel = object {
	P_BodyPart_ArmorPart_Kneel
	texture {
		T_Golem_Rock
	}
}

// block foot (origin at the ankle), longer towards the front
#declare P_BodyPart_ArmorPart_Shin = union {
	Golem_Block(<0, -0.05, -0.15> * N_Golem_Scale, <0.36, 0.2, 0.5> * N_Golem_Scale)
	texture {
		T_Golem_Rock
	}
}

#include "inc/body/BodyParts.inc"

object {
	O_BodyPart_Armored_Body_M
	rotate y * N_Animation_Angle
}
