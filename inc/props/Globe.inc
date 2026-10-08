/*
	Old wooden globe: a small round pedestal, a turned wooden stand, a brass
	meridian ring and the globe, tilted on its axis. The map is not a real
	one: parchment "lands" in a brownish green "sea" (a cloud texture), with
	a grid of meridians and parallels.
	O_Globe: about 4 units high (64 px with the default frame), 2.1 wide,
	on the floor (y = 0).
*/

// dark varnished walnut
#declare T_Globe_Wood = texture {
	pigment {
		wood
		turbulence 0.08
		color_map {
			[0 color rgb <0.28, 0.14, 0.06>]
			[0.6 color rgb <0.2, 0.09, 0.04>]
			[1 color rgb <0.14, 0.06, 0.025>]
		}
		scale 0.06
		rotate x * 90
	}
	finish {
		specular 0.45
		roughness 0.025
	}
}

#declare T_Globe_Brass = texture {
	pigment {
		color rgb <0.62, 0.45, 0.18>
	}
	finish {
		ambient 0.12
		diffuse 0.65
		specular 0.8
		roughness 0.015
		metallic
	}
}

// the map, then the grid over it (most of it transparent): a layered texture
#declare T_Globe_Map =
texture {
	pigment {
		bozo
		turbulence 0.8
		octaves 5
		color_map {
			[0 color rgb <0.22, 0.27, 0.2>]
			[0.5 color rgb <0.3, 0.33, 0.24>]
			[0.53 color rgb <0.55, 0.42, 0.24>]
			[0.56 color rgb <0.78, 0.66, 0.44>]
			[1 color rgb <0.7, 0.58, 0.36>]
		}
		scale 0.45
	}
	finish {
		specular 0.3
		roughness 0.04
	}
}
texture {
	pigment {
		gradient y
		color_map {
			[0 rgbt <0.25, 0.15, 0.06, 0>]
			[0.06 rgbt <0.25, 0.15, 0.06, 1>]
			[1 rgbt <0.25, 0.15, 0.06, 1>]
		}
		scale 0.33
	}
}
texture {
	pigment {
		radial
		frequency 12
		color_map {
			[0 rgbt <0.25, 0.15, 0.06, 0>]
			[0.06 rgbt <0.25, 0.15, 0.06, 1>]
			[1 rgbt <0.25, 0.15, 0.06, 1>]
		}
	}
}

#declare N_Globe_R = 0.95; // radius of the globe
#declare N_Globe_Y = 2.85; // centre of the globe
#declare N_Globe_Tilt = 23;
#local N_R = N_Globe_R;
#local N_Y = N_Globe_Y;
#local N_Tilt = N_Globe_Tilt;

// pedestal and turned stand, up to y = 1.9 (shared with the armillary
// sphere, inc/props/Armillary_Sphere.inc)
#declare N_Globe_Stand_Top = 1.9;

#declare O_Globe_Stand = union {
	// pedestal: a low moulded disc
	sor {
		6
		<0, 0>
		<0.62, 0>
		<0.62, 0.1>
		<0.52, 0.16>
		<0.45, 0.24>
		<0, 0.24>
		sturm
		texture {
			T_Globe_Wood
		}
	}
	// turned stand, up to the cradle under the ring
	sor {
		10
		<0.18, 0.2>
		<0.2, 0.24>
		<0.12, 0.45>
		<0.16, 0.7>
		<0.09, 1.0>
		<0.08, 1.3>
		<0.13, 1.55>
		<0.07, 1.7>
		<0.1, 1.82>
		<0.06, 1.9>
		sturm
		texture {
			T_Globe_Wood
		}
	}
}

#declare O_Globe = union {
	object {
		O_Globe_Stand
	}
	// globe and its meridian ring, tilted together
	union {
		sphere {
			0, N_R
			texture {
				T_Globe_Map
			}
		}
		// brass meridian ring, around the globe in the x-y plane
		torus {
			N_R + 0.08, 0.04
			rotate x * 90
			texture {
				T_Globe_Brass
			}
		}
		// axis pins, and a knob at the top
		cylinder {
			<0, -N_R - 0.14, 0>, <0, N_R + 0.14, 0>, 0.03
			texture {
				T_Globe_Brass
			}
		}
		sphere {
			<0, N_R + 0.16, 0>, 0.06
			texture {
				T_Globe_Brass
			}
		}
		rotate z * N_Tilt
		translate y * N_Y
	}
	// cradle holding the ring at the bottom
	cylinder {
		<0, 1.88, 0>, <0, N_Y - N_R - 0.06, 0>, 0.05
		texture {
			T_Globe_Brass
		}
	}
}
