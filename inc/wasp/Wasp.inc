/*
 __      __
 \ \    / /_ _ ____ __
  \ \/\/ / _` (_-< '_ \
   \_/\_/\__,_/__/ .__/
                 |_|

	Giant wasp, flying above the floor: glossy black chitin with yellow
	bands, big dark red compound eyes, orange mandibles, curled antennae,
	two pairs of smoky amber wings, six legs hanging under the thorax, and a
	long striped abdomen ending in a stinger. Head towards -z.

	Built around the centre of the thorax, then lifted to N_Wasp_Height and
	scaled by N_Wasp_Scale (around the ground point, as the other creatures).

	Posed by inc/frames/wasp.inc:
		V_Pose_Extra.x    wing beat, degrees (> 0: wings up, < 0: down)
		V_Pose_Extra.y    abdomen curl, degrees (> 0: curled down and
		                  forward under the body, to sting)
		V_Pose_Extra.z    legs folded (0: hanging, 1: curled up, dead);
		                  the wings sweep back with it
		AV_Head           head, around the neck
		AV_Body           whole wasp, around the centre of the thorax
		                  (x < 0: nose down, z: roll, 180 = on its back)
		V_Body_Offset     moves the whole wasp (y: bobbing, falling)

	Colours (declare them before the include to make a variant):
		C_Wasp_Dark       chitin (black)
		C_Wasp_Yellow     bands, face, shoulder marks, lower legs
		C_Wasp_Eye        compound eyes
		C_Wasp_Mandible   mandibles
		C_Wasp_Wing       wing membrane (rgb, its transparency is fixed)
		C_Wasp_Vein       wing veins
		C_Wasp_Stinger    stinger
	N_Wasp_Hue_Shift (degrees, default 0) turns the hue of all of them
	(the dark chitin barely changes): 120 gives a green wasp, 200 a blue one.
	The textures T_Wasp_* can also be replaced as a whole.
*/

#ifndef (N_Wasp_Scale)
	#declare N_Wasp_Scale = 1;
#end
// height of the centre of the thorax, before N_Wasp_Scale
#ifndef (N_Wasp_Height)
	#declare N_Wasp_Height = 2.6;
#end

#ifndef (C_Wasp_Dark)
	#declare C_Wasp_Dark = color rgb <0.035, 0.03, 0.03>;
#end
#ifndef (C_Wasp_Yellow)
	#declare C_Wasp_Yellow = color rgb <0.9, 0.62, 0.04>;
#end
#ifndef (C_Wasp_Eye)
	#declare C_Wasp_Eye = color rgb <0.45, 0.02, 0.01>;
#end
#ifndef (C_Wasp_Mandible)
	#declare C_Wasp_Mandible = color rgb <0.6, 0.25, 0.02>;
#end
#ifndef (C_Wasp_Wing)
	#declare C_Wasp_Wing = color rgb <0.6, 0.42, 0.18>;
#end
#ifndef (C_Wasp_Vein)
	#declare C_Wasp_Vein = color rgb <0.2, 0.12, 0.04>;
#end
#ifndef (C_Wasp_Stinger)
	#declare C_Wasp_Stinger = color rgb <0.15, 0.08, 0.03>;
#end

#ifndef (N_Wasp_Hue_Shift)
	#declare N_Wasp_Hue_Shift = 0;
#end
// a colour with its hue turned by N_Wasp_Hue_Shift (colors.inc, via inc/Camera.inc)
#macro Wasp_Hue(C)
	#local C_Out = C;
	#if (N_Wasp_Hue_Shift != 0)
		#local V_HSV = CRGB2HSV(C);
		#local C_Out = CHSV2RGB(<mod(V_HSV.x + N_Wasp_Hue_Shift + 360, 360), V_HSV.y, V_HSV.z>);
	#end
	C_Out
#end
#local C_Dark = Wasp_Hue(C_Wasp_Dark);
#local C_Yellow = Wasp_Hue(C_Wasp_Yellow);
#local C_Eye = Wasp_Hue(C_Wasp_Eye);
#local C_Mandible = Wasp_Hue(C_Wasp_Mandible);
#local C_Wing = Wasp_Hue(C_Wasp_Wing);
#local C_Vein = Wasp_Hue(C_Wasp_Vein);
#local C_Stinger = Wasp_Hue(C_Wasp_Stinger);

#ifndef (T_Wasp_Black)
	#declare T_Wasp_Black = texture {
		pigment {
			color C_Dark
		}
		normal {
			bumps 0.08
			scale 0.05
		}
		finish {
			ambient 0.1
			diffuse 0.6
			specular 0.8
			roughness 0.012
		}
	}
#end

#ifndef (T_Wasp_Yellow)
	#declare T_Wasp_Yellow = texture {
		pigment {
			color C_Yellow
		}
		finish {
			ambient 0.1
			diffuse 0.7
			specular 0.6
			roughness 0.02
		}
	}
#end

// abdomen: black and yellow bands along z, the tip black
#ifndef (T_Wasp_Bands)
	#declare T_Wasp_Bands = texture {
		pigment {
			gradient z
			color_map {
				[0 C_Dark]
				[0.42 C_Dark]
				[0.48 C_Yellow]
				[1 C_Yellow]
			}
			scale 0.36
			translate z * 0.1
		}
		finish {
			ambient 0.1
			diffuse 0.65
			specular 0.8
			roughness 0.015
		}
	}
#end

#ifndef (T_Wasp_Eye)
	#declare T_Wasp_Eye = texture {
		pigment {
			color C_Eye
		}
		normal {
			// facets
			cells 0.4
			scale 0.025
		}
		finish {
			ambient 0.25
			diffuse 0.6
			specular 1
			roughness 0.005
		}
	}
#end

#ifndef (T_Wasp_Wing)
	#declare T_Wasp_Wing = texture {
		pigment {
			// veins: darker lines across a smoky amber membrane
			gradient x
			color_map {
				[0 rgbt <C_Vein.red, C_Vein.green, C_Vein.blue, 0.05>]
				[0.1 rgbt <C_Wing.red, C_Wing.green, C_Wing.blue, 0.45>]
				[1 rgbt <C_Wing.red, C_Wing.green, C_Wing.blue, 0.45>]
			}
			scale 0.4
		}
		finish {
			ambient 0.2
			diffuse 0.5
			specular 0.6
			roughness 0.02
		}
	}
#end

#local N_Beat = V_Pose_Extra.x;
#local N_Curl = V_Pose_Extra.y;
#local N_Fold = V_Pose_Extra.z;



//   _   _                    _
//  | | | | ___  __ _  __| |
//  | |_| |/ _ \/ _` |/ _` |
//  |  _  |  __/ (_| | (_| |
//  |_| |_|\___|\__,_|\__,_|

// one mandible, left side (+x): a curved hook closing towards the middle
#local O_Wasp_Mandible = sphere_sweep {
	linear_spline
	4,
	<0.12, -0.12, -0.2>, 0.075
	<0.19, -0.26, -0.4>, 0.06
	<0.12, -0.38, -0.5>, 0.04
	<0.02, -0.4, -0.46>, 0.012
	texture {
		pigment {
			color C_Mandible
		}
		finish {
			specular 0.8
			roughness 0.01
		}
	}
}

// one antenna, left side: up and forward, curling down at the tip
#local O_Wasp_Antenna = sphere_sweep {
	linear_spline
	5,
	<0.08, 0.12, -0.26>, 0.03
	<0.18, 0.4, -0.38>, 0.026
	<0.28, 0.58, -0.6>, 0.024
	<0.34, 0.56, -0.85>, 0.022
	<0.36, 0.42, -1.0>, 0.02
	texture {
		T_Wasp_Black
	}
}

// head, centred on its own origin (the neck is behind it, +z)
#local O_Wasp_Head = union {
	sphere {
		0, 1
		scale <0.34, 0.3, 0.28>
		texture {
			T_Wasp_Black
		}
	}
	// yellow face plate
	sphere {
		0, 1
		scale <0.2, 0.18, 0.1>
		translate <0, -0.04, -0.22>
		texture {
			T_Wasp_Yellow
		}
	}
	// compound eyes, kidney shaped, on the sides
	#local I = -1;
	#while (I <= 1)
		sphere {
			0, 1
			scale <0.13, 0.25, 0.18>
			rotate x * 15
			translate <0.24 * I, 0.04, -0.05>
			texture {
				T_Wasp_Eye
			}
		}
		#local I = I + 2;
	#end
	object {
		O_Wasp_Mandible
	}
	object {
		O_Wasp_Mandible
		scale <-1, 1, 1>
	}
	object {
		O_Wasp_Antenna
	}
	object {
		O_Wasp_Antenna
		scale <-1, 1, 1>
	}
}



//  __        ___
//  \ \      / (_)_ __   __ _ ___
//   \ \ /\ / /| | '_ \ / _` / __|
//    \ V  V / | | | | | (_| \__ \
//     \_/\_/  |_|_| |_|\__, |___/
//                      |___/

// a wing along +x from its root (origin): a thin oval
#macro Wasp_Wing(N_Len, N_Width)
	sphere {
		0, 1
		scale <N_Len / 2, 0.008, N_Width / 2>
		translate x * N_Len / 2
		texture {
			T_Wasp_Wing
		}
	}
#end

// left wings (+x), leading edge raised (so that they show from the front
// too), swept back, beating around the body axis
#local O_Wasp_Wings_Left = union {
	object {
		Wasp_Wing(2.1, 0.62)
		rotate x * 30
		rotate y * (-22 - 35 * N_Fold)
		rotate z * N_Beat
	}
	object {
		Wasp_Wing(1.5, 0.45)
		rotate x * 30
		rotate y * (-42 - 30 * N_Fold)
		rotate z * (N_Beat * 0.85 - 4)
		translate z * 0.18
	}
	translate <0.16, 0.3, -0.05>
}



//   _
//  | |    ___  __ _ ___
//  | |   / _ \/ _` / __|
//  | |__|  __/ (_| \__ \
//  |_____\___|\__, |___/
//             |___/

/*
	One leg, left side: hip under the thorax, knee out to the side, foot
	hanging down. N_Fold curls the knee in and the foot under the body.
	V_Shift: z offset of the knee and the foot (front legs forward, hind
	legs back), N_Len: length factor.
*/
#macro Wasp_Leg(N_Z, N_Shift, N_Len)
	#local V_Hip = <0.2, -0.25, N_Z>;
	#local V_Knee = <0.62, -0.42, N_Z + N_Shift * 0.5> * (1 - N_Fold) + <0.42, -0.1, N_Z + N_Shift * 0.2> * N_Fold;
	#local V_Ankle = <0.72, -0.42 - 0.62 * N_Len, N_Z + N_Shift> * (1 - N_Fold) + <0.3, 0.1, N_Z> * N_Fold;
	#local V_Foot = V_Ankle + <0.02, -0.18, 0.06> * (1 - N_Fold) + <-0.12, 0.05, 0> * N_Fold;
	union {
		sphere_sweep {
			linear_spline
			3,
			V_Hip, 0.065
			V_Knee, 0.05
			V_Ankle, 0.035
			texture {
				T_Wasp_Black
			}
		}
		// yellow lower leg
		sphere_sweep {
			linear_spline
			2,
			V_Ankle, 0.034
			V_Foot, 0.022
			texture {
				T_Wasp_Yellow
			}
		}
	}
#end

#local O_Wasp_Legs_Left = union {
	Wasp_Leg(-0.22, -0.3, 0.9)
	Wasp_Leg(0.02, 0.05, 1)
	Wasp_Leg(0.25, 0.45, 1.2)
}



//      _    _         _
//     / \  | |__   __| | ___  _ __ ___   ___ _ __
//    / _ \ | '_ \ / _` |/ _ \| '_ ` _ \ / _ \ '_ \
//   / ___ \| |_) | (_| | (_) | | | | | |  __/ | | |
//  /_/   \_\_.__/ \__,_|\___/|_| |_| |_|\___|_| |_|

// from the waist (origin) along +z, hanging a little down at rest
#local O_Wasp_Abdomen = union {
	// waist (petiole)
	cylinder {
		<0, 0, -0.05>, <0, 0, 0.3>, 0.08
		texture {
			T_Wasp_Black
		}
	}
	// striped body, its tip narrowing
	intersection {
		sphere {
			0, 1
			scale <0.5, 0.46, 0.85>
		}
		plane {
			-z, 0
			inverse
		}
		translate z * 0.95
		texture {
			T_Wasp_Bands
		}
	}
	intersection {
		sphere {
			0, 1
			scale <0.5, 0.46, 0.85>
		}
		plane {
			z, 0
			inverse
		}
		// rear half, drawn out into a point
		scale <1, 1, 1.25>
		translate z * 0.95
		texture {
			T_Wasp_Bands
		}
	}
	// stinger
	cone {
		<0, 0, 1.95>, 0.06, <0, 0, 2.35>, 0
		texture {
			pigment {
				color C_Stinger
			}
			finish {
				specular 1
				roughness 0.005
			}
		}
	}
	rotate x * 18
}



//      _                           _     _
//     / \   ___ ___  ___ _ __ ___ | |__ | |_   _
//    / _ \ / __/ __|/ _ \ '_ ` _ \| '_ \| | | | |
//   / ___ \\__ \__ \  __/ | | | | | |_) | | |_| |
//  /_/   \_\___/___/\___|_| |_| |_|_.__/|_|\__, |
//                                          |___/

#declare O_Wasp_Posed = object {
	union {
		// thorax: black, with yellow marks on the shoulders and under the wings
		sphere {
			0, 1
			scale <0.4, 0.38, 0.5>
			texture {
				T_Wasp_Black
			}
		}
		#local I = -1;
		#while (I <= 1)
			sphere {
				0, 1
				scale <0.12, 0.06, 0.2>
				rotate z * -35 * I
				translate <0.25 * I, 0.22, -0.12>
				texture {
					T_Wasp_Yellow
				}
			}
			#local I = I + 2;
		#end
		// neck, then the head
		cylinder {
			<0, 0, -0.35>, <0, 0, -0.6>, 0.1
			texture {
				T_Wasp_Black
			}
		}
		object {
			O_Wasp_Head
			translate z * -0.2
			rotate AV_Head
			translate <0, 0.02, -0.68>
		}
		object {
			O_Wasp_Abdomen
			rotate x * N_Curl
			translate <0, -0.08, 0.42>
		}
		object {
			O_Wasp_Legs_Left
		}
		object {
			O_Wasp_Legs_Left
			scale <-1, 1, 1>
		}
		object {
			O_Wasp_Wings_Left
		}
		object {
			O_Wasp_Wings_Left
			scale <-1, 1, 1>
		}
		rotate AV_Body
		translate y * N_Wasp_Height
	}
	translate V_Body_Offset
	scale N_Wasp_Scale
}
