/*
	Skull of the skeletons, modelled (the old one, an ovoid with a face image
	painted on it, is kept in inc/skeleton/Skull_old.inc).
	Same size and frame as the old one: origin at the top of the neck, front
	towards -z, about 2 wide, from y = -0.6 (bottom of the jaw) to 1.3, from
	z = -1.3 (front) to 0.7 (back); the scenes scale it by N_Head_Size.

	Cranium with hollow temples and a crack, brow ridge, cheekbones, upper
	jaw, deep dark eye sockets with a glow in their depth, a nasal cavity
	shaped like an upside down heart, two rows of teeth, the mandible.
	The skull carries its own textures (the face image of the scenes no
	longer applies):
		T_Skull_Bone   bone (default: ivory, as the skeleton bones)
		C_Skull_Eyes   colour of the glow in the eye sockets (default: blue)
*/

#ifndef (T_Skull_Bone)
	#declare T_Skull_Bone = texture {
		pigment {
			bozo
			turbulence 0.5
			color_map {
				[0 color rgb <0.82, 0.8, 0.62>]
				[0.7 color rgb <0.78, 0.75, 0.57>]
				[1 color rgb <0.66, 0.62, 0.45>]
			}
			scale 0.35
		}
		normal {
			bumps 0.08
			scale 0.1
		}
		finish {
			diffuse 0.75
			specular 0.15
			roughness 0.05
		}
	}
#end

#ifndef (C_Skull_Eyes)
	#declare C_Skull_Eyes = color rgb <0.35, 0.65, 1>;
#end

// inside the holes: dark, with a little brown at the edges
#declare T_Skull_Hollow = texture {
	pigment {
		color rgb <0.07, 0.05, 0.03>
	}
	finish {
		diffuse 0.4
	}
}

#declare T_Skull_Glow = texture {
	pigment {
		C_Skull_Eyes
	}
	finish {
		ambient 1.4
		diffuse 0
	}
}

#local V_Eye = <0.37, 0.4, -0.92>; // centre of the left eye socket (+x)

// one tooth, standing on y = 0, slightly rounded
#macro Skull_Tooth(N_W, N_H)
	superellipsoid {
		<0.5, 0.5>
		scale <N_W / 2, N_H / 2, 0.06>
		translate y * N_H / 2
	}
#end

// a row of teeth along the front arc of radius N_R, N_Count teeth over
// N_Angle degrees, centred on -z, at height N_Y, growing up (N_Dir = 1) or
// down (N_Dir = -1)
#macro Skull_Teeth(N_R, N_Count, N_Angle, N_Y, N_Dir, N_H)
	union {
		#local I = 0;
		#while (I < N_Count)
			#local N_A = -N_Angle / 2 + N_Angle * (I + 0.5) / N_Count;
			object {
				Skull_Tooth(0.75 * N_R * radians(N_Angle) / N_Count, N_H * (1 - 0.25 * abs(N_A) / N_Angle))
				scale <1, N_Dir, 1>
				translate <0, N_Y, -N_R>
				rotate y * N_A
			}
			#local I = I + 1;
		#end
	}
#end

// cranium and face, before the holes
#local O_Skull_Mass = union {
	// cranium
	sphere {
		0, 1
		scale <0.92, 0.74, 0.95>
		translate <0, 0.55, -0.25>
	}
	// forehead and brow ridge
	sphere {
		0, 1
		scale <0.8, 0.45, 0.5>
		translate <0, 0.55, -0.68>
	}
	// cheekbones
	sphere {
		0, 1
		scale <0.2, 0.12, 0.3>
		translate <0.52, 0.17, -0.72>
	}
	sphere {
		0, 1
		scale <0.2, 0.12, 0.3>
		translate <-0.52, 0.17, -0.72>
	}
	// upper jaw (maxilla), carrying the upper teeth
	sphere {
		0, 1
		scale <0.5, 0.36, 0.42>
		translate <0, 0.02, -0.82>
	}
}

#local O_Skull_Head = difference {
	object {
		O_Skull_Mass
		texture { T_Skull_Bone }
	}
	// eye sockets, deep
	superellipsoid {
		<0.6, 0.6>
		scale <0.28, 0.25, 0.34>
		rotate z * 8
		translate V_Eye
		texture { T_Skull_Hollow }
	}
	superellipsoid {
		<0.6, 0.6>
		scale <0.28, 0.25, 0.34>
		rotate z * -8
		translate V_Eye * <-1, 1, 1>
		texture { T_Skull_Hollow }
	}
	// nasal cavity, an upside down heart
	union {
		sphere { <-0.06, 0.18, 0>, 0.07 }
		sphere { <0.06, 0.18, 0>, 0.07 }
		cone { <0, 0.2, 0>, 0.12, <0, 0.0, 0>, 0.02 }
		scale <1, 1, 2.5>
		translate <0, 0, -1.18>
		texture { T_Skull_Hollow }
	}
	// hollow temples
	sphere {
		<1.02, 0.42, -0.45>, 0.2
		scale <1, 1.2, 1>
		texture { T_Skull_Bone }
	}
	sphere {
		<-1.02, 0.42, -0.45>, 0.2
		scale <1, 1.2, 1>
		texture { T_Skull_Bone }
	}
	// mouth: the gap behind the teeth
	box {
		<-0.32, -0.36, -1.5>, <0.32, -0.16, -0.55>
		texture { T_Skull_Hollow }
	}
	// crack on the forehead, on the right
	sphere_sweep {
		linear_spline 4
		<-0.05, 1.32, -0.45>, 0.025
		<-0.25, 1.15, -0.78>, 0.022
		<-0.18, 0.95, -0.95>, 0.02
		<-0.33, 0.72, -1.02>, 0.014
		texture { T_Skull_Hollow }
	}
}

// mandible: a U along the front, its two branches going up behind the
// cheekbones, the lower teeth on it
#local O_Skull_Mandible = union {
	intersection {
		torus {
			0.44, 0.075
			scale <1, 1.6, 1.05>
		}
		plane {
			z, 0.05
		}
		translate <0, -0.49, -0.52>
	}
	// chin
	sphere {
		0, 1
		scale <0.17, 0.1, 0.08>
		translate <0, -0.55, -0.98>
	}
	// branches
	cylinder {
		<0.44, -0.46, -0.5>, <0.5, 0.05, -0.38>, 0.07
	}
	cylinder {
		<-0.44, -0.46, -0.5>, <-0.5, 0.05, -0.38>, 0.07
	}
	texture { T_Skull_Bone }
}

#declare O_Skel_Skull = union {
	object {
		O_Skull_Head
	}
	object {
		O_Skull_Mandible
	}
	// upper and lower teeth
	object {
		Skull_Teeth(0.82, 8, 70, -0.16, -1, 0.16)
		translate z * 0.02
		texture { T_Skull_Bone }
	}
	object {
		Skull_Teeth(0.8, 8, 66, -0.38, 1, 0.14)
		translate z * 0.03
		texture { T_Skull_Bone }
	}
	// glow in the depth of the eye sockets
	sphere {
		V_Eye + <0, -0.01, 0.14>, 0.1
		texture { T_Skull_Glow }
	}
	sphere {
		V_Eye * <-1, 1, 1> + <0, -0.01, 0.14>, 0.1
		texture { T_Skull_Glow }
	}
}
