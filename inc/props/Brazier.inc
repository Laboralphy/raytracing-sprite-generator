/*
	Brazier: an iron bowl on three legs, full of coals.
	Lit (N_Brazier_Lit = 1, default): glowing coals and flames, animated by
	N_Brazier_Phase (the pose number, 0 to 3, given by the spec: the flames
	change height and lean, the coals pulse, sparks rise).
	Out (N_Brazier_Lit = 0): dark coals and ash with a few dim embers, two
	pokers stuck in the bowl.
	The glowing parts shine (ambient 1): in raycaster-386, the sprite is
	darkened like any other unless it is marked FX_LIGHT_SOURCE.
	O_Brazier: about 2.6 units high lit (flames included), 1.2 wide.
*/

#ifndef (N_Brazier_Lit)
	#declare N_Brazier_Lit = 1;
#end
#ifndef (N_Brazier_Phase)
	#declare N_Brazier_Phase = N_Pose_From;
#end
// random variations of this frame
#local S_Frame = seed(100 + int(N_Brazier_Phase));

#declare T_Brazier_Iron = texture {
	pigment {
		color rgb <0.13, 0.12, 0.12>
	}
	normal {
		dents 0.3
		scale 0.1
	}
	finish {
		ambient 0.1
		diffuse 0.7
		specular 0.5
		roughness 0.03
		metallic
	}
}

#local N_Bowl_Y = 1.15;
#local N_Bowl_R = 0.6;

// one leg, curving out at the foot
#local O_Brazier_Leg = sphere_sweep {
	linear_spline
	4
	<0.3, N_Bowl_Y, 0>, 0.045
	<0.42, 0.6, 0>, 0.04
	<0.52, 0.12, 0>, 0.04
	<0.62, 0.03, 0>, 0.05
	texture {
		T_Brazier_Iron
	}
}

// glow of the coals: bright when lit (pulsing with the frame), dim embers when out
#if (N_Brazier_Lit)
	#local N_Glow = 0.85 + 0.15 * rand(S_Frame);
	#local T_Brazier_Coal = texture {
		pigment {
			granite
			color_map {
				[0 color rgb <1, 0.45, 0.05> * N_Glow]
				[0.45 color rgb <0.7, 0.12, 0.02> * N_Glow]
				[0.55 color rgb <0.06, 0.04, 0.03>]
				[1 color rgb <0.03, 0.02, 0.02>]
			}
			scale 0.15
		}
		finish {
			ambient 1
			diffuse 0
		}
	}
#else
	#local T_Brazier_Coal = texture {
		pigment {
			granite
			color_map {
				[0 color rgb <0.9, 0.25, 0.03>]
				[0.18 color rgb <0.45, 0.07, 0.01>]
				[0.28 color rgb <0.05, 0.04, 0.035>]
				[0.7 color rgb <0.03, 0.025, 0.02>]
				[1 color rgb <0.3, 0.29, 0.27>] // ash
			}
			scale 0.12
		}
		finish {
			ambient 0.6
			diffuse 0.4
		}
	}
#end

#local O_Brazier_Coals = union {
	#local S = seed(3);
	#local I = 0;
	#while (I < 22)
		#local N_A = rand(S) * 360;
		#local N_R = sqrt(rand(S)) * (N_Bowl_R - 0.12);
		sphere {
			0, 1
			scale <0.11, 0.07, 0.09> * (0.8 + 0.5 * rand(S))
			rotate y * rand(S) * 180
			translate vrotate(<N_R, 0, 0>, y * N_A) + y * (N_Bowl_Y + 0.02 + 0.06 * rand(S))
			texture {
				T_Brazier_Coal
			}
		}
		#local I = I + 1;
	#end
}

// poker: an iron rod, pointed and hooked at the bottom (in the coals),
// a ring handle at the top; along +y from its tip
#local O_Brazier_Poker = union {
	cylinder {
		<0, 0.1, 0>, <0, 1.3, 0>, 0.035
	}
	// hooked tip
	cylinder {
		<0, 0.1, 0>, <0.1, 0.02, 0>, 0.03
	}
	// handle
	torus {
		0.09, 0.028
		rotate x * 90
		translate y * 1.39
	}
	// lighter than the brazier: worn by the hands
	texture {
		pigment {
			color rgb <0.32, 0.31, 0.3>
		}
		finish {
			specular 0.7
			roughness 0.02
			metallic
		}
	}
}

// a flame: an elongated drop, yellow at the bottom, red and fading at the top
#macro Brazier_Flame(V_Pos, N_Height, N_Width, N_Tilt)
	sphere {
		0, 1
		texture {
			pigment {
				gradient y
				color_map {
					[0 rgbt <1, 0.95, 0.6, 0>]
					[0.4 rgbt <1, 0.7, 0.15, 0.1>]
					[0.75 rgbt <0.95, 0.3, 0.05, 0.4>]
					[1 rgbt <0.8, 0.1, 0.02, 1>]
				}
				translate y * -0.0
				scale 2
				translate y * -1
			}
			finish {
				ambient 1
				diffuse 0
			}
		}
		scale <N_Width, N_Height, N_Width>
		translate y * N_Height
		rotate z * N_Tilt
		translate V_Pos
		no_shadow
	}
#end

#declare O_Brazier = union {
	// bowl: lower half of a sphere, with a rim
	difference {
		sphere {
			0, N_Bowl_R
			scale <1, 0.6, 1>
		}
		sphere {
			0, N_Bowl_R - 0.04
			scale <1, 0.6, 1>
		}
		plane {
			-y, 0
		}
		translate y * (N_Bowl_Y + 0.12)
		texture {
			T_Brazier_Iron
		}
	}
	torus {
		N_Bowl_R, 0.04
		translate y * (N_Bowl_Y + 0.12)
		texture {
			T_Brazier_Iron
		}
	}
	object {
		O_Brazier_Leg
	}
	object {
		O_Brazier_Leg
		rotate y * 120
	}
	object {
		O_Brazier_Leg
		rotate y * 240
	}
	object {
		O_Brazier_Coals
	}
	#if (N_Brazier_Lit)
		// flames: height and lean change with the frame
		#local A_Flames = array[4][5] {
			// x, z, height, width, lean
			{0, 0, 0.55, 0.22, 0},
			{-0.22, 0.05, 0.38, 0.16, 12},
			{0.2, -0.08, 0.42, 0.17, -10},
			{0.05, 0.22, 0.3, 0.14, -5}
		}
		#local I = 0;
		#while (I < 4)
			Brazier_Flame(
				<A_Flames[I][0], N_Bowl_Y + 0.05, A_Flames[I][1]>,
				A_Flames[I][2] * (0.75 + 0.5 * rand(S_Frame)),
				A_Flames[I][3] * (0.9 + 0.2 * rand(S_Frame)),
				A_Flames[I][4] + 16 * (rand(S_Frame) - 0.5))
			#local I = I + 1;
		#end
		// sparks rising above the flames
		#local I = 0;
		#while (I < 4)
			sphere {
				<(rand(S_Frame) - 0.5) * 0.6, N_Bowl_Y + 0.6 + rand(S_Frame) * 0.9, (rand(S_Frame) - 0.5) * 0.4>, 0.025
				texture {
					pigment {
						color rgb <1, 0.75, 0.3>
					}
					finish {
						ambient 1
						diffuse 0
					}
				}
				no_shadow
			}
			#local I = I + 1;
		#end
	#else
		// two pokers stuck in the coals, leaning on the rim
		object {
			O_Brazier_Poker
			rotate z * -40
			rotate y * 30
			translate <-0.15, N_Bowl_Y - 0.05, 0.1>
		}
		object {
			O_Brazier_Poker
			rotate z * 35
			rotate y * -50
			translate <0.18, N_Bowl_Y - 0.05, -0.05>
		}
	#end
}
