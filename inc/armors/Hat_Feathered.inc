/*
	Feathered hat (bycocket, as Robin Hood's): a felt crown peaked at the
	front, a narrow brim turned up at the back, a leather band and a long
	feather stuck in the band on the left side, sweeping back and up.

	O_Hat_Feathered is built in a unit frame, as O_Helm_Horned_Cap: the crown
	covers the upper half of the unit sphere (base on y = 0), front towards
	-z. Each character scales and places it on its head (c_goblin_archer.pov).

	Textures overridable: T_Hat_Felt, T_Hat_Band, T_Hat_Feather.
	N_Hat_Feather_Size scales the feather (1 by default).
*/

#ifndef (T_Hat_Felt)
	#declare T_Hat_Felt = texture {
		pigment {
			bozo
			turbulence 0.5
			color_map {
				[0 color rgb <0.3, 0.17, 0.08>]
				[1 color rgb <0.24, 0.13, 0.06>]
			}
			scale 0.3
		}
		normal {
			bumps 0.15
			scale 0.05
		}
		finish {
			specular 0.03
			roughness 0.2
		}
	}
#end

#ifndef (T_Hat_Band)
	#declare T_Hat_Band = texture {
		pigment {
			color rgb <0.1, 0.06, 0.03>
		}
		finish {
			specular 0.15
			roughness 0.05
		}
	}
#end

#ifndef (T_Hat_Feather)
	#declare T_Hat_Feather = texture {
		pigment {
			gradient z
			color_map {
				[0 color rgb <0.85, 0.12, 0.06>]
				[0.85 color rgb <0.75, 0.08, 0.05>]
				[1 color rgb <0.95, 0.85, 0.7>]
			}
			// along the vane, from its root (z = 0) to its tip (z = 1)
		}
		finish {
			specular 0.1
			roughness 0.1
		}
	}
#end

#ifndef (N_Hat_Feather_Size)
	#declare N_Hat_Feather_Size = 1;
#end

// crown: upper half of an ovoid, its top pushed forward into a peak
#local O_Hat_Crown = intersection {
	sphere {
		0, 1
		scale <0.98, 1.75, 1.12>
	}
	plane {
		-y, 0
	}
	// shear: the higher, the more forward
	matrix <
		1, 0, 0,
		0, 1, -0.45,
		0, 0, 1,
		0, 0, 0
	>
	texture {
		T_Hat_Felt
	}
}

// brim: a thin oval disc, longer at the front, its back turned up
#local O_Hat_Brim = difference {
	cylinder {
		<0, -0.04, 0>, <0, 0.04, 0>, 1
		scale <1.3, 1.5, 1.5>
		translate z * -0.2
	}
	cylinder {
		<0, -1, 0>, <0, 1, 0>, 0.9
		scale <1, 1, 1.05>
	}
	rotate x * -22
	texture {
		T_Hat_Felt
	}
}

#local O_Hat_Band = torus {
	1, 0.06
	scale <1.02, 1, 1.12>
	translate y * 0.12
	texture {
		T_Hat_Band
	}
}

// feather: a flat vane along +z from its root, with its quill
#local O_Hat_Feather = union {
	sphere {
		<0, 0, 0.5>, 0.5
		scale <0.06, 0.28, 1>
		texture {
			T_Hat_Feather
		}
	}
	cylinder {
		<0, 0, -0.08>, <0, 0, 0.95>, 0.02
		texture {
			pigment {
				color rgb <0.95, 0.9, 0.8>
			}
		}
	}
	scale 2.1 * N_Hat_Feather_Size
	// curving up towards the back
	rotate x * -32
	// a little outward
	rotate y * 12
}

#declare O_Hat_Feathered = union {
	object {
		O_Hat_Crown
	}
	object {
		O_Hat_Brim
	}
	object {
		O_Hat_Band
	}
	object {
		O_Hat_Feather
		translate <0.98, 0.18, -0.15>
	}
}
