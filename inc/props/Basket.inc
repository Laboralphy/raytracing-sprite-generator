/*
	Wicker basket with its lid, standing on the floor (y = 0).
	O_Basket: about 1.3 units high, 1.1 wide.
*/

#declare T_Basket_Wicker = texture {
	pigment {
		gradient y
		color_map {
			[0 color rgb <0.62, 0.45, 0.22>]
			[0.5 color rgb <0.45, 0.3, 0.13>]
			[1 color rgb <0.62, 0.45, 0.22>]
		}
		scale 0.09
	}
	// vertical stakes through the woven strands
	normal {
		radial 0.7
		frequency 28
	}
	finish {
		specular 0.1
		roughness 0.1
	}
}

#declare T_Basket_Rim = texture {
	pigment {
		color rgb <0.4, 0.27, 0.12>
	}
	normal {
		bumps 0.4
		scale 0.03
	}
}

#declare O_Basket = union {
	// body, a little wider at the top
	cone {
		<0, 0, 0>, 0.45, <0, 0.85, 0>, 0.55
		texture {
			T_Basket_Wicker
		}
	}
	torus {
		0.55, 0.05
		translate y * 0.85
		texture {
			T_Basket_Rim
		}
	}
	torus {
		0.45, 0.04
		translate y * 0.03
		texture {
			T_Basket_Rim
		}
	}
	// lid: a low dome with a rim and a knob
	intersection {
		sphere {
			0, 1
			scale <0.6, 0.28, 0.6>
		}
		plane {
			-y, 0
		}
		translate y * 0.88
		texture {
			T_Basket_Wicker
			rotate x * 90
		}
	}
	torus {
		0.6, 0.045
		translate y * 0.9
		texture {
			T_Basket_Rim
		}
	}
	torus {
		0.08, 0.035
		rotate x * 90
		translate y * 1.22
		texture {
			T_Basket_Rim
		}
	}
}
