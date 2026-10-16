/*
	Broad sword: a wide blade with a dark fuller, heavy downswept cross guard,
	long leather grip, spiked pommel. Same frame as Weapon_Sword: held in the
	fist at the origin, pointing up (+y), the blade flat in the y-z plane.

	Textures overridable: T_Broad_Sword_Blade (dark steel with rust),
	T_Broad_Sword_Hilt, T_Broad_Sword_Grip.
*/

#include "inc/body/BodyMetrics.inc"

#ifndef (T_Broad_Sword_Blade)
	#declare T_Broad_Sword_Blade = texture {
		pigment {
			bozo
			turbulence 0.6
			color_map {
				[0 color rgb <0.5, 0.5, 0.53>]
				[0.6 color rgb <0.4, 0.4, 0.43>]
				[0.75 color rgb <0.4, 0.15, 0.06>]
				[1 color rgb <0.25, 0.08, 0.03>]
			}
			scale 0.12
		}
		finish { ambient 0.15 diffuse 0.6 specular 0.8 roughness 0.01 metallic }
	}
#end
#ifndef (T_Broad_Sword_Hilt)
	#declare T_Broad_Sword_Hilt = texture {
		pigment { color rgb <0.13, 0.12, 0.12> }
		finish { specular 0.6 roughness 0.02 metallic }
	}
#end
#ifndef (T_Broad_Sword_Grip)
	#declare T_Broad_Sword_Grip = texture {
		pigment {
			gradient y
			color_map {
				[0 color rgb <0.2, 0.05, 0.03>]
				[0.5 color rgb <0.1, 0.03, 0.02>]
				[1 color rgb <0.2, 0.05, 0.03>]
			}
			scale 0.04
		}
	}
#end

// profile of the blade in the y-z plane, from the guard to the point
#local O_Broad_Sword_Blade = prism {
	linear_sweep
	linear_spline
	-0.03, 0.03, 7
	<0.18, -0.16>, <1.25, -0.15>, <1.6, -0.08>, <1.8, 0>, <1.6, 0.08>, <1.25, 0.15>, <0.18, 0.16>
	// prism points are <x, z>, swept along y: x becomes y, the sweep becomes x
	rotate z * 90
	texture { T_Broad_Sword_Blade }
}

// dark fuller down the middle of the blade, on both faces
#local O_Broad_Sword_Fuller = box {
	<-0.032, 0.25, -0.035>, <0.032, 1.3, 0.035>
	texture { T_Broad_Sword_Hilt }
}

#local O_Broad_Sword_Hilt = union {
	// cross guard, downswept at the ends
	sphere_sweep {
		linear_spline
		4
		<0, 0.06, -0.42>, 0.04
		<0, 0.15, -0.25>, 0.055
		<0, 0.15, 0.25>, 0.055
		<0, 0.06, 0.42>, 0.04
	}
	// pommel and its spike
	sphere {
		<0, -0.22, 0>, 0.08
	}
	cone {
		<0, -0.26, 0>, 0.04, <0, -0.38, 0>, 0
	}
	texture { T_Broad_Sword_Hilt }
}

#local O_Broad_Sword_Grip = cylinder {
	<0, -0.16, 0>, <0, 0.12, 0>, 0.04
	texture { T_Broad_Sword_Grip }
}

#declare P_BodyPart_ArmorPart_Weapon = union {
	object { O_Broad_Sword_Blade }
	object { O_Broad_Sword_Fuller }
	object { O_Broad_Sword_Hilt }
	object { O_Broad_Sword_Grip }
	scale 1.33 * N_Wrist_Len
}
