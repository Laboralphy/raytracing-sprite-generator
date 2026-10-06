/*
  ____  _ _
 / ___|| (_)_ __ ___   ___
 \___ \| | | '_ ` _ \ / _ \
  ___) | | | | | | | |  __/
 |____/|_|_|_| |_| |_|\___|

	Greenish translucent slime (a D&D ooze): a swollen, lumpy body and 4
	misshapen pseudopods on the diagonals, used as legs. A dark nucleus and a
	few bubbles float inside. It spits a glob of acid forward (-z).

	Posed by inc/frames/slime.inc:
		V_Pose_Extra.x    height: the slime is scaled by 1 + x vertically, and
		                  spreads horizontally to keep roughly its volume
		                  (-0.7: a crushed flan)
		V_Pose_Extra.z    spit, 0 to 1: the glob leaves the front of the body,
		                  first held by a strand, then free
		AV_Thigh_Left     the pseudopods: x = walk phase (degrees, each leg a
		                  quarter turn later than the previous), y = walk
		                  amplitude (0 still, 1 walking), z = reach (0 normal,
		                  -0.5 pulled in)
		AV_Body, V_Body_Offset   as for the body: around the ground point, then moved

	O_Slime_Posed: on the ground (y = 0), centred on the y axis.
*/

// overall scale (1: about 1.5 units high, 4 units across the pseudopods)
#ifndef (N_Slime_Size)
	#declare N_Slime_Size = 1.35;
#end

#ifndef (T_Slime)
	#declare T_Slime = texture {
		pigment {
			color rgbf <0.35, 0.85, 0.15, 0.65>
		}
		normal {
			bumps 0.12
			scale 0.25
		}
		finish {
			ambient 0.2
			diffuse 0.6
			specular 0.9
			roughness 0.004
			reflection { 0.04 }
		}
	}
#end

#ifndef (T_Slime_Spit)
	#declare T_Slime_Spit = texture {
		pigment {
			color rgbf <0.6, 1, 0.2, 0.3>
		}
		finish {
			ambient 0.5
			diffuse 0.5
			specular 0.9
			roughness 0.004
		}
	}
#end

#local I_Slime = interior {
	ior 1.1
}

#local N_SLIME_THRESHOLD = 0.5;
// a lone component of radius R has its surface at R * sqrt(1 - sqrt(threshold))
#local N_SLIME_SURFACE = 1 / sqrt(1 - sqrt(N_SLIME_THRESHOLD));

// blob component whose surface, alone, is the ellipsoid of half-axes
// N_Radius * V_Scale around V_Center
#macro Slime_Gob(V_Center, N_Radius, V_Scale)
	Slime_Gob_Turned(V_Center, N_Radius, V_Scale, 0)
#end

// the same, then turned by N_Angle around the y axis
#macro Slime_Gob_Turned(V_Center, N_Radius, V_Scale, N_Angle)
	sphere {
		0, N_Radius * N_SLIME_SURFACE, 1
		scale V_Scale
		translate V_Center
		rotate y * N_Angle
	}
#end

#local N_Phase = AV_Thigh_Left.x;
#local N_Amplitude = AV_Thigh_Left.y;
#local N_Reach = 1 + AV_Thigh_Left.z;
#local N_Spit = V_Pose_Extra.z;



//   _
//  | |    ___  __ _ ___
//  | |   / _ \/ _` / __|
//  | |__|  __/ (_| \__ \
//  |_____\___|\__, |___/
//             |___/


// one pseudopod along +x, turned by N_Angle; N_Size makes it misshapen.
// N_Extension (-1 to 1) pushes it out and lifts it while it moves forward.
#macro Slime_Leg(N_Angle, N_Size, N_Length, N_Extension, N_Lift)
	#local N_L = N_Length * N_Reach;
	Slime_Gob_Turned(<0.6 * N_L, 0.35, 0> , 0.3 * N_Size, <1.1, 0.9, 1>, N_Angle)
	Slime_Gob_Turned(<(1.0 + 0.2 * N_Extension) * N_L, 0.2 + 0.5 * N_Lift, 0>, 0.24 * N_Size, <1.2, 0.8, 1>, N_Angle)
	Slime_Gob_Turned(<(1.4 + 0.3 * N_Extension) * N_L, 0.12 + N_Lift, 0>, 0.2 * N_Size, <1.4, 0.65, 1.15>, N_Angle)
#end

#macro Slime_Legs()
	// angle, size, length, phase offset of each leg: deliberately uneven
	#local A_Legs = array[4][4] {
		{45, 1.05, 1, 0},
		{135, 0.9, 0.92, 90},
		{225, 1, 1.05, 180},
		{315, 0.85, 0.95, 270}
	}
	#local I = 0;
	#while (I < 4)
		#local N_A = N_Phase + A_Legs[I][3];
		#local N_Extension = N_Amplitude * sin(radians(N_A));
		#local N_Lift = N_Amplitude * 0.12 * max(0, cos(radians(N_A)));
		Slime_Leg(A_Legs[I][0], A_Legs[I][1], A_Legs[I][2], N_Extension, N_Lift)
		#local I = I + 1;
	#end
#end



//   ____            _
//  | __ )  ___   __| |_   _
//  |  _ \ / _ \ / _` | | | |
//  | |_) | (_) | (_| | |_| |
//  |____/ \___/ \__,_|\__, |
//                     |___/


#local O_Slime_Jelly = blob {
	threshold N_SLIME_THRESHOLD
	// swollen centre, and lumps on top
	Slime_Gob(<0, 0.85, 0>, 0.72, <1, 0.85, 1>)
	Slime_Gob(<0.3, 1.2, -0.15>, 0.38, 1)
	Slime_Gob(<-0.35, 1.1, 0.2>, 0.4, 1)
	Slime_Gob(<0.05, 1.05, 0.45>, 0.32, 1)
	Slime_Gob(<-0.25, 0.9, -0.45>, 0.3, 1)
	// mouth swelling while spitting
	#if (N_Spit > 0)
		Slime_Gob(<0, 0.8, -0.7>, 0.28 * min(1, 3 * N_Spit), 1)
	#end
	Slime_Legs()
}

// nucleus and bubbles, inside the jelly
#local O_Slime_Inside = union {
	sphere {
		<0.1, 0.8, 0.05>, 0.22
		scale <1, 0.8, 1>
		texture {
			pigment {
				color rgb <0.08, 0.2, 0.03>
			}
			finish {
				specular 0.4
			}
		}
	}
	#local A_Bubbles = array[6] {
		<-0.3, 1.05, -0.2, 0.08>, <0.35, 0.6, -0.35, 0.06>, <-0.1, 0.45, 0.3, 0.07>,
		<0.4, 1.1, 0.25, 0.05>, <-0.45, 0.7, 0.1, 0.06>, <0.15, 1.3, -0.1, 0.045>
	}
	#local I = 0;
	#while (I < 6)
		sphere {
			<A_Bubbles[I].x, A_Bubbles[I].y, A_Bubbles[I].z>, A_Bubbles[I].t
			texture {
				pigment {
					color rgbf <1, 1, 1, 0.8>
				}
				finish {
					ambient 0.3
					specular 1
					roughness 0.002
				}
			}
		}
		#local I = I + 1;
	#end
}

// the glob of acid and its strand
#local O_Slime_Spit = blob {
	threshold N_SLIME_THRESHOLD
	#local N_Z = -0.9 - 0.9 * N_Spit;
	Slime_Gob(<0, 0.85, N_Z>, 0.26, <0.9, 0.9, 1.2>)
	#if (N_Spit < 0.6)
		// strand, thinner as the glob goes away
		#local N_Strand = 0.1 * (1 - N_Spit / 0.6);
		#local I = 1;
		#while (I < 4)
			Slime_Gob(<0, 0.82, -0.7 + (N_Z + 0.7) * I / 4>, N_Strand, 1)
			#local I = I + 1;
		#end
	#else
		// droplets
		Slime_Gob(<0.12, 0.95, N_Z + 0.35>, 0.07, 1)
		Slime_Gob(<-0.1, 0.75, N_Z + 0.45>, 0.06, 1)
	#end
	texture {
		T_Slime_Spit
	}
	interior {
		I_Slime
	}
}

#local N_Height = 1 + V_Pose_Extra.x;
#local N_Width = pow(N_Height, -0.35);

#declare O_Slime = union {
	intersection {
		object {
			O_Slime_Jelly
		}
		// flat on the ground
		plane {
			-y, 0
		}
		translate y * -0.06
		texture {
			T_Slime
		}
		interior {
			I_Slime
		}
	}
	object {
		O_Slime_Inside
	}
	#if (N_Spit > 0)
		object {
			O_Slime_Spit
		}
	#end
}

#declare O_Slime_Posed = object {
	O_Slime
	scale <N_Width, N_Height, N_Width> * N_Slime_Size
	rotate AV_Body
	translate V_Body_Offset
}
