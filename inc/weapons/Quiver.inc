/*
	Quiver: leather tube, thin metal rings at both ends, a few arrows
	sticking out. O_Quiver is built along +y from its bottom (origin); each
	character hangs it on its back (c_skeleton_archer.pov, c_goblin_archer.pov),
	usually slanting, its mouth above the right shoulder (-x), on the side of
	the drawing hand.
	Include it after inc/weapons/Weapon_Bow.inc (arrow textures).
	Overridable: N_Quiver_Len, N_Quiver_Radius, T_Quiver_Leather, T_Quiver_Metal.
*/
#ifndef (N_Quiver_Len)
	#declare N_Quiver_Len = 1.1;
#end
#ifndef (N_Quiver_Radius)
	#declare N_Quiver_Radius = 0.13;
#end

#ifndef (T_Quiver_Leather)
	#declare T_Quiver_Leather = texture {
		pigment {
			bozo
			color_map {
				[0 color rgb <0.35, 0.18, 0.07>]
				[1 color rgb <0.25, 0.12, 0.04>]
			}
			scale 0.08
		}
		finish {
			specular 0.2
			roughness 0.05
		}
	}
#end

#ifndef (T_Quiver_Metal)
	#declare T_Quiver_Metal = texture {
		pigment {
			color rgb <0.6, 0.55, 0.45>
		}
		finish {
			specular 0.8
			roughness 0.01
			metallic
		}
	}
#end

#declare O_Quiver_Arrow = union {
	cylinder {
		<0, N_Quiver_Len - 0.3, 0>, <0, N_Quiver_Len + 0.22, 0>, 0.02
		texture {
			T_Arrow_Shaft
		}
	}
	box {
		<-0.05, N_Quiver_Len + 0.05, -0.004>, <0.05, N_Quiver_Len + 0.2, 0.004>
		texture {
			T_Arrow_Fletching
		}
	}
	box {
		<-0.004, N_Quiver_Len + 0.05, -0.05>, <0.004, N_Quiver_Len + 0.2, 0.05>
		texture {
			T_Arrow_Fletching
		}
	}
}

// along +y from its bottom (origin)
#declare O_Quiver = union {
	cylinder {
		0, <0, N_Quiver_Len, 0>, N_Quiver_Radius
		texture {
			T_Quiver_Leather
		}
	}
	torus {
		N_Quiver_Radius, 0.025
		texture {
			T_Quiver_Metal
		}
	}
	torus {
		N_Quiver_Radius, 0.025
		translate y * N_Quiver_Len
		texture {
			T_Quiver_Metal
		}
	}
	object {
		O_Quiver_Arrow
		translate <0.05, 0, 0.04>
	}
	object {
		O_Quiver_Arrow
		rotate y * 50
		translate <-0.05, 0.04, 0.03>
	}
	object {
		O_Quiver_Arrow
		rotate y * 20
		translate <0, -0.03, -0.06>
	}
}
