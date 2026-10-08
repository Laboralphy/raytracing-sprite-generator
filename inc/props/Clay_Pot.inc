/*
	Brown clay pot (jar): round belly, narrow neck, flared rim, dark inside.
	O_Clay_Pot: about 1.6 units high, 1.1 wide, on the floor (y = 0).
*/

#declare T_Clay_Pot = texture {
	pigment {
		gradient y
		color_map {
			[0 color rgb <0.5, 0.27, 0.13>]
			[0.82 color rgb <0.5, 0.27, 0.13>]
			[0.82 color rgb <0.3, 0.15, 0.07>]
			[0.9 color rgb <0.3, 0.15, 0.07>]
			[0.9 color rgb <0.5, 0.27, 0.13>]
		}
		scale 1.6
		warp {
			turbulence 0.02
		}
	}
	normal {
		bumps 0.15
		scale 0.08
	}
	finish {
		specular 0.15
		roughness 0.06
	}
}

#declare O_Clay_Pot = union {
	sor {
		9
		<0.25, -0.05>
		<0.3, 0>
		<0.5, 0.25>
		<0.56, 0.6>
		<0.45, 1.05>
		<0.28, 1.3>
		<0.26, 1.45>
		<0.36, 1.58>
		<0.38, 1.65>
		open
		sturm
		texture {
			T_Clay_Pot
		}
	}
	// bottom
	cylinder {
		<0, 0, 0>, <0, 0.02, 0>, 0.3
		texture {
			T_Clay_Pot
		}
	}
	// dark inside, seen through the mouth
	cylinder {
		<0, 1.0, 0>, <0, 1.5, 0>, 0.27
		texture {
			pigment {
				color rgb <0.06, 0.03, 0.02>
			}
		}
	}
}
