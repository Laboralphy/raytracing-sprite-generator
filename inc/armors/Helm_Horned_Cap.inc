/*
	Horned cap (cervelliere): a dark leather half ovoid held by an iron frame
	(ring at the base, two bands crossing over the top, a rivet), and two
	ivory horns on the sides, curving out and up.

	O_Helm_Horned_Cap is built in a unit frame: the cap is the upper half of
	the unit sphere (base on y = 0), front towards -z. Each character scales
	and places it on its head (c_goblin_warrior.pov, c_skeleton_archer.pov).

	Textures overridable: T_Helm_Leather, T_Helm_Iron, T_Helm_Ivory.
	N_Helm_Horn_Size scales the horns (1 by default).
*/

#ifndef (T_Helm_Leather)
	#declare T_Helm_Leather = texture {
		pigment {
			bozo
			turbulence 0.4
			color_map {
				[0 color rgb <0.11, 0.055, 0.02>]
				[1 color rgb <0.07, 0.035, 0.012>]
			}
			scale 0.3
		}
		normal {
			wrinkles 0.3
			scale 0.2
		}
		finish {
			specular 0.08
			roughness 0.08
		}
	}
#end

#ifndef (T_Helm_Iron)
	#declare T_Helm_Iron = texture {
		pigment {
			color rgb <0.22, 0.21, 0.2>
		}
		normal {
			dents 0.3
			scale 0.2
		}
		finish {
			ambient 0.12
			diffuse 0.7
			specular 0.8
			roughness 0.015
			metallic
		}
	}
#end

#ifndef (T_Helm_Ivory)
	#declare T_Helm_Ivory = texture {
		pigment {
			// rings along the horn, darker towards the tip (see O_Helm_Horn)
			gradient y
			color_map {
				[0 color rgb <0.93, 0.88, 0.74>]
				[0.6 color rgb <0.88, 0.82, 0.66>]
				[1 color rgb <0.55, 0.45, 0.32>]
			}
			scale 0.75
		}
		finish {
			specular 0.5
			roughness 0.02
		}
	}
#end

#ifndef (N_Helm_Horn_Size)
	#declare N_Helm_Horn_Size = 1;
#end

// left horn (+x): from the side of the cap, out, then curving up
#local O_Helm_Horn = sphere_sweep {
	linear_spline
	6
	<0, 0, 0>, 0.17
	<0.25, 0.08, 0>, 0.14
	<0.45, 0.25, 0.02>, 0.11
	<0.55, 0.45, 0.05>, 0.08
	<0.56, 0.62, 0.07>, 0.05
	<0.52, 0.75, 0.08>, 0.015
	texture {
		T_Helm_Ivory
	}
	scale N_Helm_Horn_Size
	translate <0.85, 0.42, 0>
}

#declare O_Helm_Horned_Cap = union {
	// leather cap
	intersection {
		sphere {
			0, 1
		}
		plane {
			-y, 0
		}
		texture {
			T_Helm_Leather
		}
	}
	// iron frame
	union {
		torus {
			1, 0.07
		}
		intersection {
			union {
				torus {
					1, 0.05
					rotate x * 90
				}
				torus {
					1, 0.05
					rotate z * 90
				}
			}
			plane {
				-y, 0
			}
		}
		sphere {
			y, 0.11
		}
		texture {
			T_Helm_Iron
		}
	}
	object {
		O_Helm_Horn
	}
	object {
		O_Helm_Horn
		scale <-1, 1, 1>
	}
}
