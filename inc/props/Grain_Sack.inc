/*
	Sack of grain: burlap, bulging at the bottom, tied with a rope, a tuft of
	cloth above the knot, a few grains spilled in front.
	O_Grain_Sack: about 1.7 units high, 1.2 wide, on the floor (y = 0).
*/

#declare T_Grain_Sack_Burlap = texture {
	pigment {
		average
		pigment_map {
			[1 gradient x color_map { [0 color rgb <0.62, 0.5, 0.32>] [0.5 color rgb <0.48, 0.37, 0.22>] [1 color rgb <0.62, 0.5, 0.32>] } scale 0.035]
			[1 gradient y color_map { [0 color rgb <0.62, 0.5, 0.32>] [0.5 color rgb <0.48, 0.37, 0.22>] [1 color rgb <0.62, 0.5, 0.32>] } scale 0.035]
		}
	}
	normal {
		wrinkles 0.4
		scale 0.15
	}
	finish {
		specular 0.02
		roughness 0.2
	}
}

#declare T_Grain_Sack_Rope = texture {
	pigment {
		color rgb <0.35, 0.25, 0.12>
	}
	normal {
		bumps 0.5
		scale 0.02
	}
}

#declare T_Grain = texture {
	pigment {
		color rgb <0.8, 0.65, 0.3>
	}
	finish {
		specular 0.3
	}
}

#declare O_Grain_Sack = union {
	blob {
		threshold 0.5
		// wide slumped bottom, bulging on the sides
		sphere { <0, 0.35, 0>, 1, 1 scale <1, 0.7, 0.85> }
		sphere { <0.3, 0.45, -0.05>, 0.6, 0.8 }
		sphere { <-0.3, 0.42, 0.05>, 0.6, 0.8 }
		// body, square shouldered
		sphere { <0, 0.8, 0>, 0.85, 1 scale <1, 0.9, 0.85> }
		// gathered neck
		cylinder { <0, 1.15, 0>, <0, 1.35, 0>, 0.22, 0.8 }
		// tuft above the knot, spread out
		sphere { <0, 1.5, 0>, 0.3, 1 scale <1.3, 0.7, 1.2> }
		sphere { <0.12, 1.52, -0.05>, 0.18, 0.6 }
		sphere { <-0.12, 1.5, 0.06>, 0.18, 0.6 }
		texture {
			T_Grain_Sack_Burlap
		}
		clipped_by {
			plane {
				-y, 0
			}
		}
	}
	// rope round the neck
	torus {
		0.13, 0.035
		translate y * 1.33
		texture {
			T_Grain_Sack_Rope
		}
	}
	torus {
		0.13, 0.035
		translate y * 1.27
		texture {
			T_Grain_Sack_Rope
		}
	}
	// spilled grains
	union {
		#local S = seed(11);
		#local I = 0;
		#while (I < 18)
			sphere {
				0, 1
				scale <0.03, 0.02, 0.02>
				rotate y * rand(S) * 180
				translate <(rand(S) - 0.5) * 0.8, 0.02, -0.75 - rand(S) * 0.3>
			}
			#local I = I + 1;
		#end
		texture {
			T_Grain
		}
	}
}
