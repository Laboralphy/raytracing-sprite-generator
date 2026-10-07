/*
	Sword: straight blade, cross guard, leather grip, round pommel.
	As the other weapons: held in the fist at the origin, pointing up (+y),
	before the body turns it forward. The blade is flat in the y-z plane,
	so that it is seen broad from the side, edge first from the front.

	Textures overridable: T_Sword_Blade (rusty steel by default),
	T_Sword_Hilt (dark iron), T_Sword_Grip (leather).
*/

#include "metals"
#include "inc/body/BodyMetrics.inc"

#ifndef (T_Sword_Blade)
	#declare T_Sword_Blade = texture {
		pigment {
			bozo
			turbulence 0.6
			color_map {
				[0 color rgb <0.62, 0.62, 0.65>]
				[0.6 color rgb <0.52, 0.52, 0.55>]
				[0.72 color rgb <0.45, 0.22, 0.08>]
				[1 color rgb <0.3, 0.12, 0.04>]
			}
			scale 0.12
		}
		finish {
			ambient 0.15
			diffuse 0.6
			specular 0.8
			roughness 0.01
			metallic
		}
	}
#end

#ifndef (T_Sword_Hilt)
	#declare T_Sword_Hilt = texture {
		pigment {
			color rgb <0.2, 0.18, 0.15>
		}
		finish {
			specular 0.6
			roughness 0.02
			metallic
		}
	}
#end

#ifndef (T_Sword_Grip)
	#declare T_Sword_Grip = texture {
		pigment {
			gradient y
			color_map {
				[0 color rgb <0.25, 0.13, 0.05>]
				[0.5 color rgb <0.15, 0.07, 0.02>]
				[1 color rgb <0.25, 0.13, 0.05>]
			}
			scale 0.04
		}
	}
#end

// profile of the blade in the y-z plane, from the guard to the point
#local O_Sword_Blade = prism {
	linear_sweep
	linear_spline
	-0.022, 0.022, 6
	<0.15, -0.095>, <1.4, -0.08>, <1.7, 0>, <1.4, 0.08>, <0.15, 0.095>, <0.15, -0.095>
	// prism points are <x, z>, swept along y: x becomes y, the sweep becomes x
	rotate z * 90
	texture {
		T_Sword_Blade
	}
}

#local O_Sword_Hilt = union {
	// cross guard, across the blade
	cylinder {
		<0, 0.13, -0.28>, <0, 0.13, 0.28>, 0.045
	}
	sphere {
		<0, 0.13, -0.28>, 0.065
	}
	sphere {
		<0, 0.13, 0.28>, 0.065
	}
	// pommel
	sphere {
		<0, -0.17, 0>, 0.075
	}
	texture {
		T_Sword_Hilt
	}
}

#local O_Sword_Grip = cylinder {
	<0, -0.12, 0>, <0, 0.11, 0>, 0.035
	texture {
		T_Sword_Grip
	}
}

#declare P_BodyPart_ArmorPart_Weapon = union {
	object {
		O_Sword_Blade
	}
	object {
		O_Sword_Hilt
	}
	object {
		O_Sword_Grip
	}
	scale 1.33 * N_Wrist_Len
}
