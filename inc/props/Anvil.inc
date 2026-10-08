/*
	Smithy anvil on a wooden stump, on the floor (y = 0). The horn points
	towards -x. Dark cast iron (as the cauldron) with a polished working face
	and worn bright edges, so that it reads at sprite size; two tool holes in
	the face; an iron hoop around the stump.
	O_Anvil: about 2 units high, 1.6 long.
*/

#declare T_Anvil_Iron = texture {
	pigment {
		color rgb <0.07, 0.07, 0.08>
	}
	normal {
		dents 0.3
		scale 0.1
	}
	finish {
		ambient 0.1
		diffuse 0.6
		specular 0.7
		roughness 0.02
		metallic
	}
}

// polished working face
#declare T_Anvil_Face = texture {
	pigment {
		color rgb <0.62, 0.62, 0.64>
	}
	finish {
		ambient 0.15
		diffuse 0.7
		specular 0.9
		roughness 0.008
		metallic
	}
}

#declare T_Anvil_Stump = texture {
	pigment {
		bozo
		color_map {
			[0 color rgb <0.3, 0.18, 0.08>]
			[1 color rgb <0.18, 0.1, 0.04>]
		}
		scale <0.05, 1, 0.05>
	}
	normal {
		bumps 0.5
		scale <0.03, 0.4, 0.03>
	}
}

// year rings on the top of the stump
#declare T_Anvil_Rings = texture {
	pigment {
		onion
		color_map {
			[0 color rgb <0.6, 0.45, 0.28>]
			[0.7 color rgb <0.55, 0.4, 0.24>]
			[1 color rgb <0.4, 0.27, 0.14>]
		}
		scale 0.08
	}
}

#local N_Stump = 1.05;

// a worn bright edge, from A to B
#macro Anvil_Edge(V_A, V_B)
	cylinder {
		V_A, V_B, 0.022
		texture {
			T_Anvil_Face
		}
	}
#end

#declare O_Anvil = union {
	// stump
	cylinder {
		<0, 0, 0>, <0, N_Stump - 0.01, 0>, 0.48
		texture {
			T_Anvil_Stump
		}
	}
	cylinder {
		<0, N_Stump - 0.01, 0>, <0, N_Stump, 0>, 0.47
		texture {
			T_Anvil_Rings
		}
	}
	// anvil
	union {
		// feet
		box {
			<-0.42, 0, -0.3>, <0.42, 0.14, 0.3>
		}
		// waist, narrower
		box {
			<-0.25, 0.14, -0.17>, <0.25, 0.48, 0.17>
		}
		// body under the face, flaring out
		prism {
			linear_sweep
			linear_spline
			-0.2, 0.2, 5
			<-0.25, 0.48>, <0.25, 0.48>, <0.5, 0.62>, <-0.55, 0.62>, <-0.25, 0.48>
			rotate x * -90
		}
		// horn
		intersection {
			cone {
				<-0.55, 0, 0>, 0.2, <-1.05, 0, 0>, 0.01
				scale <1, 1, 0.9>
			}
			plane {
				y, 0
			}
			translate y * 0.78
		}
		// face
		box {
			<-0.55, 0.62, -0.2>, <0.58, 0.78, 0.2>
		}
		texture {
			T_Anvil_Iron
		}
		translate y * N_Stump
	}
	// polished face, with its two tool holes (hardy, square; pritchel, round)
	difference {
		box {
			<-0.53, 0.775, -0.18>, <0.56, 0.785, 0.18>
		}
		box {
			<0.32, 0.7, -0.05>, <0.42, 0.8, 0.05>
		}
		cylinder {
			<0.18, 0.7, 0>, <0.18, 0.8, 0>, 0.035
		}
		translate y * N_Stump
		texture {
			T_Anvil_Face
		}
	}
	// worn edges of the face and of the horn
	union {
		Anvil_Edge(<-0.55, 0.78, -0.2>, <0.58, 0.78, -0.2>)
		Anvil_Edge(<-0.55, 0.78, 0.2>, <0.58, 0.78, 0.2>)
		Anvil_Edge(<0.58, 0.78, -0.2>, <0.58, 0.78, 0.2>)
		Anvil_Edge(<-0.55, 0.78, -0.18>, <-1.05, 0.78, 0>)
		Anvil_Edge(<-0.55, 0.78, 0.18>, <-1.05, 0.78, 0>)
		// bottom edge of the feet, front
		Anvil_Edge(<-0.42, 0.01, -0.3>, <0.42, 0.01, -0.3>)
		translate y * N_Stump
	}
	// iron hoop around the stump
	cylinder {
		<0, 0.78, 0>, <0, 0.88, 0>, 0.49
		texture {
			T_Anvil_Iron
		}
	}
}
