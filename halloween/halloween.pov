/*
  _           _ _
 | |__   __ _| | | _____      _____  ___ _ __
 | '_ \ / _` | | |/ _ \ \ /\ / / _ \/ _ \ '_ \
 | | | | (_| | | | (_) \ V  V /  __/  __/ | | |
 |_| |_|\__,_|_|_|\___/ \_/\_/ \___|\___|_| |_|

	Halloween night: a haunted house on a hill against a huge full moon,
	a dead tree, a graveyard behind an iron fence, carved pumpkins lit from
	inside in the foreground, bats, ground mist.

	povray +Ihalloween.pov +Ohalloween.png +W1920 +H1080 +A0.2 +AM2 +R3 +L../inc
	(run from this folder; the assets are in inc/)
*/

#version 3.7;

global_settings {
	assumed_gamma 1.0
	max_trace_level 8
}

#include "colors.inc"
#include "inc/Pumpkin.inc"
#include "inc/Tombstone.inc"
#include "inc/DeadTree.inc"
#include "inc/House.inc"
#include "inc/Bat.inc"

camera {
	location <0.3, 1.7, -9.5>
	look_at <0, 2.6, 20>
	right x * 16 / 9
	angle 62
}



//       _
//   ___| | ___   _
//  / __| |/ / | | |
//  \__ \   <| |_| |
//  |___/_|\_\\__, |
//            |___/

sky_sphere {
	pigment {
		gradient y
		color_map {
			[0 color rgb <0.05, 0.015, 0.03>]
			[0.05 color rgb <0.02, 0.008, 0.03>]
			[0.2 color rgb <0.004, 0.004, 0.014>]
			[1 color rgb <0.0005, 0.0005, 0.002>]
		}
	}
	// stars: only the highest peaks of the pattern, small round specks
	pigment {
		bozo
		color_map {
			[0 rgbt <1, 1, 1, 1>]
			[0.86 rgbt <1, 1, 1, 1>]
			[0.9 rgbt <0.85, 0.88, 1, 0>]
			[1 rgbt <1, 1, 1, 0>]
		}
		scale 0.0018
	}
}

#local V_Moon = <-28, 46, 300>;

// the moon, glowing, with darker seas
sphere {
	V_Moon, 24
	texture {
		pigment {
			bozo
			turbulence 0.6
			color_map {
				[0 color rgb <1, 0.95, 0.75>]
				[0.55 color rgb <0.95, 0.88, 0.68>]
				[0.7 color rgb <0.75, 0.68, 0.52>]
				[1 color rgb <0.8, 0.74, 0.58>]
			}
			scale 7
		}
		finish {
			ambient 1.3
			diffuse 0
		}
	}
	no_shadow
}

// halo around the moon
disc {
	0, -z, 90
	texture {
		pigment {
			// 1 at the centre, 0 at the edge
			spherical
			color_map {
				[0 rgbt <0.5, 0.5, 0.6, 1>]
				[0.5 rgbt <0.5, 0.5, 0.6, 0.93>]
				[0.75 rgbt <0.65, 0.62, 0.6, 0.8>]
				[1 rgbt <0.8, 0.75, 0.65, 0.65>]
			}
			scale 90
		}
		finish {
			ambient 1
			diffuse 0
		}
	}
	// behind the moon
	translate V_Moon + <0, 0, 40>
	no_shadow
}

// moonlight, cold, from behind the scene
light_source {
	V_Moon
	color rgb <0.4, 0.45, 0.75> * 1.3
	parallel
	point_at <0, 0, 0>
}

// faint cold fill from the viewer side, so that the foreground is not black
light_source {
	<6, 12, -25>
	color rgb <0.05, 0.05, 0.09>
	shadowless
}

// ground mist
fog {
	fog_type 2
	distance 18
	color rgbt <0.09, 0.1, 0.16, 0.2>
	fog_offset 0.05
	fog_alt 0.45
	turbulence <0.6, 0.3, 0.6>
	turb_depth 0.5
}



//    __ _ _ __ ___  _   _ _ __   __| |
//   / _` | '__/ _ \| | | | '_ \ / _` |
//  | (_| | | | (_) | |_| | | | | (_| |
//   \__, |_|  \___/ \__,_|_| |_|\__,_|
//   |___/

#declare T_Grass = texture {
	pigment {
		bozo
		turbulence 0.7
		color_map {
			[0 color rgb <0.03, 0.05, 0.02>]
			[0.5 color rgb <0.05, 0.07, 0.03>]
			[1 color rgb <0.07, 0.06, 0.03>]
		}
		scale 1.5
	}
	normal {
		bumps 0.8
		scale 0.15
	}
	finish {
		ambient 0
		diffuse 0.7
	}
}

plane {
	y, 0
	texture { T_Grass }
}

// hill of the house
sphere {
	<9, -58, 85>, 65
	texture { T_Grass }
}

// dirt path from the gate to the hill
#declare T_Path = texture {
	pigment {
		color rgb <0.12, 0.09, 0.06>
	}
	normal {
		bumps 0.5
		scale 0.2
	}
	finish {
		ambient 0
		diffuse 0.7
	}
}

sphere_sweep {
	b_spline 6
	<-1, 0, -8>, 0.9
	<0.5, 0, 2>, 0.8
	<0, 0, 10>, 0.8
	<2.5, 0, 25>, 0.7
	<5, 0, 40>, 0.6
	<7, 0, 55>, 0.5
	scale <1, 0.02, 1>
	texture { T_Path }
}



//   _
//  | |__   ___  _   _ ___  ___
//  | '_ \ / _ \| | | / __|/ _ \
//  | | | | (_) | |_| \__ \  __/
//  |_| |_|\___/ \__,_|___/\___|

object {
	O_House
	rotate y * 18
	scale 0.95
	translate <9, 6.4, 82>
}

// two dead trees beside the house
object { Dead_Tree(31, 6) translate <-1, 5.2, 78> }
object { Dead_Tree(44, 5) translate <17, 5.4, 80> }



//                                                  _
//    __ _ _ __ __ ___   _____ _   _  __ _ _ __ __| |
//   / _` | '__/ _` \ \ / / _ \ | | |/ _` | '__/ _` |
//  | (_| | | | (_| |\ V /  __/ |_| | (_| | | | (_| |
//   \__, |_|  \__,_| \_/ \___|\__, |\__,_|_|  \__,_|
//   |___/                     |___/

object { Tombstone_Round("R.I.P.") rotate y * -18 rotate z * 6 translate <2.3, 0, 1.2> }
object { Tombstone_Cross() rotate y * 10 rotate z * -9 translate <4.2, 0, 3.6> }
object { Tombstone_Round("1666") rotate y * 12 rotate x * -5 translate <0.9, 0, 5.2> }
object { Tombstone_Round("R.I.P.") scale 0.8 rotate y * -30 rotate z * -12 translate <5.6, 0, 7.4> }
object { Tombstone_Cross() scale 0.9 rotate y * -20 rotate z * 5 translate <-2.4, 0, 7.8> }
object { Tombstone_Round("") scale 0.75 rotate y * 25 rotate z * 15 translate <-4.2, 0, 10.5> }
object { Tombstone_Round("") scale 0.7 rotate y * -10 translate <3.2, 0, 13> }
object { Tombstone_Cross() scale 0.8 rotate z * -15 translate <7.5, 0, 12> }

// wrought iron fence with spikes, a gap for the path
#declare T_Iron = texture {
	pigment {
		color rgb <0.03, 0.03, 0.035>
	}
	finish {
		ambient 0
		diffuse 0.4
		specular 0.5
		roughness 0.02
		metallic
	}
}

#macro Fence(N_From, N_To, N_Z)
	union {
		cylinder { <N_From, 0.5, N_Z>, <N_To, 0.5, N_Z>, 0.03 }
		cylinder { <N_From, 1.45, N_Z>, <N_To, 1.45, N_Z>, 0.03 }
		#local N_X = N_From;
		#while (N_X <= N_To)
			cylinder { <N_X, 0, N_Z>, <N_X, 1.65, N_Z>, 0.025 }
			cone { <N_X, 1.65, N_Z>, 0.06, <N_X, 1.85, N_Z>, 0 }
			#local N_X = N_X + 0.25;
		#end
		texture { T_Iron }
	}
#end

object { Fence(-9, -1.2, 9) rotate z * 1 }
object { Fence(1.4, 10, 9) }
// gate posts
cylinder { <-1.1, 0, 9>, <-1.1, 2.2, 9>, 0.09 texture { T_Iron } }
cylinder { <1.3, 0, 9>, <1.3, 2.2, 9>, 0.09 texture { T_Iron } }
sphere { <-1.1, 2.25, 9>, 0.13 texture { T_Iron } }
sphere { <1.3, 2.25, 9>, 0.13 texture { T_Iron } }



//   _
//  | |_ _ __ ___  ___
//  | __| '__/ _ \/ _ \
//  | |_| | |  __/  __/
//   \__|_|  \___|\___|

// big dead tree framing the moon on the left
object {
	Dead_Tree(7, 7.5)
	scale <1.2, 1, 1.2>
	rotate y * 40
	translate <-4.6, 0, 4>
}



//                                 _    _
//   _ __  _   _ _ __ ___  _ __ | | _(_)_ __  ___
//  | '_ \| | | | '_ ` _ \| '_ \| |/ / | '_ \/ __|
//  | |_) | |_| | | | | | | |_) |   <| | | | \__ \
//  | .__/ \__,_|_| |_| |_| .__/|_|\_\_|_| |_|___/
//  |_|                   |_|

object { Pumpkin(0.6, 1, 0) rotate y * 10 translate <-2.2, 0, -2.6> }
object { Pumpkin(0.4, 2, 1) rotate y * -15 translate <-1.0, 0, -3.6> }
object { Pumpkin(0.34, 3, 2) rotate y * 30 translate <-3.3, 0, -1.6> }
object { Pumpkin(0.45, 4, 1) rotate y * -25 translate <2.0, 0, -2.4> }



//   _           _
//  | |__   __ _| |_ ___
//  | '_ \ / _` | __/ __|
//  | |_) | (_| | |_\__ \
//  |_.__/ \__,_|\__|___/

#local S_Bats = seed(13);
#local I = 0;
#while (I < 9)
	object {
		Bat(rand(S_Bats) * 2 - 1)
		rotate <rand(S_Bats) * 40 - 60, rand(S_Bats) * 360, rand(S_Bats) * 40 - 20>
		scale 2 + rand(S_Bats) * 2.5
		translate <-26 + rand(S_Bats) * 30, 22 + rand(S_Bats) * 28, 120 + rand(S_Bats) * 60>
	}
	#local I = I + 1;
#end
// two closer bats
object { Bat(0.8) rotate <-50, 30, 10> scale 0.9 translate <3.5, 6.5, 12> }
object { Bat(-0.6) rotate <-40, -40, -15> scale 0.7 translate <1.5, 7.8, 16> }
// three bats in front of the moon, in silhouette
object { Bat(0.5) rotate <-80, 10, 0> scale 8 translate V_Moon * 0.5 + <-3, 2, 0> }
object { Bat(-0.3) rotate <-75, -20, 10> scale 6 translate V_Moon * 0.5 + <4, -4, 0> }
object { Bat(1) rotate <-80, 40, 0> scale 4.5 translate V_Moon * 0.5 + <-1, -7, 0> }
