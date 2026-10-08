/*
	Wooden armillary sphere, the size of the old globe and on the same
	stand (inc/props/Globe.inc): a fixed horizon ring on four arms, a
	meridian ring, and inside, tilted on the axis as the globe, the
	celestial rings (equator, tropics, polar circles, colure) and the wide
	band of the ecliptic marked with the signs; a small earth in the middle.
	Dark walnut for the mounting, light wood for the celestial rings, brass
	for the pins.
	O_Armillary_Sphere: about 4 units high, 2.3 wide, on the floor (y = 0).
*/

#include "inc/props/Globe.inc"

#declare T_Armillary_Light_Wood = texture {
	pigment {
		wood
		turbulence 0.1
		color_map {
			[0 color rgb <0.6, 0.42, 0.22>]
			[0.7 color rgb <0.52, 0.35, 0.17>]
			[1 color rgb <0.42, 0.27, 0.12>]
		}
		scale 0.05
	}
	finish {
		specular 0.4
		roughness 0.03
	}
}

// the ecliptic band: light wood with dark marks (the signs)
#declare T_Armillary_Ecliptic =
texture {
	T_Armillary_Light_Wood
}
texture {
	pigment {
		radial
		frequency 12
		color_map {
			[0 rgbt <0.15, 0.07, 0.03, 0>]
			[0.08 rgbt <0.15, 0.07, 0.03, 0>]
			[0.08 rgbt <0.15, 0.07, 0.03, 1>]
			[1 rgbt <0.15, 0.07, 0.03, 1>]
		}
	}
}

// a hoop around the y axis: radius N_R, width N_W along y, thickness N_T
#macro Armillary_Hoop(N_R, N_W, N_T)
	difference {
		cylinder {
			<0, -N_W / 2, 0>, <0, N_W / 2, 0>, N_R + N_T / 2
		}
		cylinder {
			<0, -N_W, 0>, <0, N_W, 0>, N_R - N_T / 2
		}
	}
#end

#local N_R = N_Globe_R;
#local N_Y = N_Globe_Y;

#declare O_Armillary_Sphere = union {
	object {
		O_Globe_Stand
	}
	// celestial rings, tilted on the axis
	union {
		// equator
		object {
			Armillary_Hoop(N_R - 0.06, 0.07, 0.045)
		}
		// tropics and polar circles
		#local A_Parallels = array[4] { 0.4, -0.4, 0.88, -0.88 }
		#local I = 0;
		#while (I < 4)
			#local N_H = A_Parallels[I] * (N_R - 0.06);
			object {
				Armillary_Hoop(sqrt(pow(N_R - 0.06, 2) - N_H * N_H), 0.045, 0.035)
				translate y * N_H
			}
			#local I = I + 1;
		#end
		// colure: vertical, across the meridian
		object {
			Armillary_Hoop(N_R - 0.06, 0.06, 0.04)
			rotate z * 90
			rotate y * 90
		}
		texture {
			T_Armillary_Light_Wood
		}
		rotate z * N_Globe_Tilt
		translate y * N_Y
	}
	// ecliptic band, wide, tilted against the equator
	object {
		Armillary_Hoop(N_R - 0.03, 0.2, 0.04)
		rotate x * 23.4
		rotate z * N_Globe_Tilt
		translate y * N_Y
		texture {
			T_Armillary_Ecliptic
		}
	}
	// axis, small earth in the middle, pins
	union {
		cylinder {
			<0, -N_R - 0.12, 0>, <0, N_R + 0.12, 0>, 0.025
			texture {
				T_Globe_Brass
			}
		}
		sphere {
			0, 0.2
			texture {
				T_Globe_Map
				scale 0.25
			}
		}
		sphere {
			<0, N_R + 0.14, 0>, 0.05
			texture {
				T_Globe_Brass
			}
		}
		rotate z * N_Globe_Tilt
		translate y * N_Y
	}
	// meridian ring (in the plane of the axis), dark wood
	object {
		Armillary_Hoop(N_R + 0.02, 0.08, 0.05)
		rotate x * 90
		translate y * N_Y
		texture {
			T_Globe_Wood
		}
	}
	// horizon ring: a flat wide ring, fixed, on four arms from the stand
	object {
		Armillary_Hoop(N_R + 0.12, 0.04, 0.16)
		translate y * N_Y
		texture {
			T_Globe_Wood
		}
	}
	#local I = 0;
	#while (I < 4)
		cylinder {
			<0.05, N_Globe_Stand_Top - 0.02, 0>, <N_R + 0.06, N_Y - 0.03, 0>, 0.03
			rotate y * (45 + 90 * I)
			texture {
				T_Globe_Wood
			}
		}
		#local I = I + 1;
	#end
	// cradle under the meridian
	cylinder {
		<0, N_Globe_Stand_Top - 0.02, 0>, <0, N_Y - N_R - 0.04, 0>, 0.05
		texture {
			T_Globe_Wood
		}
	}
}
