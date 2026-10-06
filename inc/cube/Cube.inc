/*
   ____      _
  / ___|   _| |__   ___
 | |  | | | | '_ \ / _ \
 | |__| |_| | |_) |  __/
  \____\__,_|_.__/ \___|

	Evil cube of dark metal. It moves by rolling forward from one face to the
	next. Faces, seen by someone it faces:
		1 front (-z), 2 top (+y), 3 back (+z), 4 bottom (-y): a face each, its
		features (eyes, mouth) glowing like red hot metal;
		5 and 6 sides (+x, -x): plain riveted plates.
	Each face is face 1 turned by a quarter of a roll: after one roll forward,
	face 2 is in front, upright.

	Posed by inc/frames/cube.inc:
		V_Pose_Extra.x  roll, in quarter turns: > 0 forward around the front
		                bottom edge (1 = on the next face), < 0 backward around
		                the back bottom edge (rocking)
		V_Pose_Extra.y  heat of the features: -1 cold, 0 red hot, 1 white hot
		AV_Body, V_Body_Offset   as for the body: around the ground point, then moved

	O_Cube_Posed: resting on the ground (y = 0), centred on the y axis.
*/

#ifndef (N_Cube_Size)
	#declare N_Cube_Size = 2.2;
#end

#ifndef (T_Cube_Metal)
	#declare T_Cube_Metal = texture {
		pigment {
			color rgb <0.11, 0.11, 0.13>
		}
		normal {
			granite 0.04
			scale 0.15
		}
		finish {
			ambient 0.1
			diffuse 0.7
			specular 1
			roughness 0.01
			metallic
			brilliance 2
			reflection { 0.05 }
		}
	}
#end

#local N_Half = N_Cube_Size / 2;
#local N_Heat = V_Pose_Extra.y;



//    ____ _
//   / ___| | _____      __
//  | |  _| |/ _ \ \ /\ / /
//  | |_| | | (_) \ V  V /
//   \____|_|\___/ \_/\_/


// incandescent metal: dark red at the edges, orange at the core; white when hot
#local C_Cold_Core = rgb <0.04, 0.01, 0>;
#local C_Cold_Edge = rgb <0.02, 0, 0>;
#local C_Red_Core = rgb <1, 0.3, 0.03>;
#local C_Red_Edge = rgb <0.55, 0.04, 0>;
#local C_White_Core = rgb <1, 1, 0.97>;
#local C_White_Edge = rgb <1, 0.8, 0.45>;

#if (N_Heat < 0)
	#local N_F = N_Heat + 1;
	#local C_Glow_Core = C_Cold_Core * (1 - N_F) + C_Red_Core * N_F;
	#local C_Glow_Edge = C_Cold_Edge * (1 - N_F) + C_Red_Edge * N_F;
#else
	#local N_F = min(N_Heat, 1);
	#local C_Glow_Core = C_Red_Core * (1 - N_F) + C_White_Core * N_F;
	#local C_Glow_Edge = C_Red_Edge * (1 - N_F) + C_White_Edge * N_F;
#end

#declare T_Cube_Glow = texture {
	pigment {
		agate
		agate_turb 0.6
		color_map {
			[0 C_Glow_Edge]
			[0.6 C_Glow_Core]
			[1 C_Glow_Core]
		}
		scale 0.3
	}
	finish {
		ambient 1
		diffuse 0
	}
}



//   _____
//  |  ___|_ _  ___ ___
//  | |_ / _` |/ __/ _ \
//  |  _| (_| | (_|  __/
//  |_|  \__,_|\___\___|


// Features of face 1, in face coordinates (-1 to 1, u to the right, v up)
// seen from the front: angry slanted eyes, jagged grin.

#local N_Eye_Points = 5;
#local A_Eye = array[N_Eye_Points] {
	<-0.8, 0.55>, <-0.2, 0.3>, <-0.3, 0.12>, <-0.74, 0.16>, <-0.8, 0.55>
}

#local N_Mouth_Points = 17;
#local A_Mouth = array[N_Mouth_Points] {
	// upper teeth, left to right
	<-0.78, -0.12>, <-0.5, -0.42>, <-0.33, -0.24>, <-0.17, -0.42>, <0, -0.24>,
	<0.17, -0.42>, <0.33, -0.24>, <0.5, -0.42>, <0.78, -0.12>,
	// lower teeth, right to left
	<0.6, -0.72>, <0.4, -0.52>, <0.2, -0.72>, <0, -0.52>, <-0.2, -0.72>,
	<-0.4, -0.52>, <-0.6, -0.72>, <-0.78, -0.12>
}

// extruded outline A (face coordinates), from depth N_Front to N_Back below
// the surface of face 1
#macro Cube_Feature(A, N_Count, N_Front, N_Back)
	prism {
		linear_sweep
		linear_spline
		N_Half - N_Back, N_Half - N_Front, N_Count
		#local I = 0;
		#while (I < N_Count)
			A[I] * N_Half
			#local I = I + 1;
		#end
		// prism points are <x, z>, swept along y: turn it to <x, y>, swept along -z
		rotate x * -90
	}
#end

#macro Cube_Features(N_Front, N_Back)
	union {
		Cube_Feature(A_Eye, N_Eye_Points, N_Front, N_Back)
		object {
			Cube_Feature(A_Eye, N_Eye_Points, N_Front, N_Back)
			scale <-1, 1, 1>
		}
		Cube_Feature(A_Mouth, N_Mouth_Points, N_Front, N_Back)
	}
#end

// rivets in the corners of a face (face 1)
#local O_Cube_Rivets = union {
	#local N_U = -1;
	#while (N_U <= 1)
		#local N_V = -1;
		#while (N_V <= 1)
			sphere {
				0, 0.08
				scale <1, 1, 0.7>
				translate <N_U * 0.82, N_V * 0.82, -1> * N_Half
			}
			#local N_V = N_V + 2;
		#end
		#local N_U = N_U + 2;
	#end
}

// raised plate of the sides (face 1)
#local O_Cube_Plate = box {
	<-0.68, -0.68, -1.05> * N_Half
	<0.68, 0.68, -0.9> * N_Half
}



//    ____      _
//   / ___|   _| |__   ___
//  | |  | | | | '_ \ / _ \
//  | |__| |_| | |_) |  __/
//   \____\__,_|_.__/ \___|


// faces 1 to 4: face 1 turned by -1/4 roll each time (rotate x * 90 is
// the roll backward)
#local O_Cube_Shell = difference {
	superellipsoid {
		<0.12, 0.12>
		scale N_Half
	}
	#local I = 0;
	#while (I < 4)
		object {
			Cube_Features(-0.1, 0.12)
			rotate x * 90 * I
		}
		#local I = I + 1;
	#end
	texture {
		T_Cube_Metal
	}
}

#declare O_Cube = union {
	object {
		O_Cube_Shell
	}
	#local I = 0;
	#while (I < 4)
		object {
			Cube_Features(0.015, 0.12)
			rotate x * 90 * I
			texture {
				T_Cube_Glow
			}
		}
		object {
			O_Cube_Rivets
			rotate x * 90 * I
			texture {
				T_Cube_Metal
			}
		}
		#local I = I + 1;
	#end
	// faces 5 and 6
	#local I = -1;
	#while (I <= 1)
		union {
			object {
				O_Cube_Plate
			}
			object {
				O_Cube_Rivets
			}
			rotate y * 90 * I
			texture {
				T_Cube_Metal
			}
		}
		#local I = I + 2;
	#end
}

#local N_Roll = V_Pose_Extra.x;

#declare O_Cube_Posed = object {
	O_Cube
	translate y * N_Half
	#if (N_Roll >= 0)
		// forward, around the front bottom edge
		translate z * N_Half
		rotate x * -90 * N_Roll
		translate z * -N_Half
	#else
		// backward, around the back bottom edge
		translate z * -N_Half
		rotate x * -90 * N_Roll
		translate z * N_Half
	#end
	rotate AV_Body
	translate V_Body_Offset
}
