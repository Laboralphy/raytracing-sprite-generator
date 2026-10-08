/*
	Carved pumpkin (jack-o'-lantern) lit from inside.
	Pumpkin(N_Size, N_Seed, N_Face): N_Face 0 = classic triangles, 1 = angry
	slits, 2 = surprised round. Origin on the ground, the face towards -z.
	A candle light inside shines out through the carving.
*/

#declare T_Pumpkin_Skin = texture {
	pigment {
		gradient y
		color_map {
			[0 color rgb <0.55, 0.16, 0.0>]
			[0.5 color rgb <0.85, 0.32, 0.02>]
			[1 color rgb <0.6, 0.22, 0.01>]
		}
		scale 2
		translate -y
	}
	normal {
		bumps 0.15
		scale 0.08
	}
	finish {
		ambient 0
		diffuse 0.75
		specular 0.35
		roughness 0.03
	}
}

#declare T_Pumpkin_Flesh = texture {
	pigment {
		color rgb <1, 0.55, 0.1>
	}
	finish {
		ambient 2
		diffuse 0.5
	}
}

#declare T_Pumpkin_Stem = texture {
	pigment {
		color rgb <0.22, 0.2, 0.08>
	}
	normal {
		bumps 0.6
		scale <0.02, 0.2, 0.02>
	}
}

// ribbed body: 10 lobes around y, radius 1, height ~1.5
#macro Pumpkin_Body(N_R)
	union {
		#local I = 0;
		#while (I < 10)
			sphere {
				<0.38 * N_R, 0, 0>, 0.68 * N_R
				scale <1, 1.1, 0.75>
				rotate y * I * 36
			}
			#local I = I + 1;
		#end
	}
#end

// the carving, through the front (-z); prism points are <x, y> once turned
// (rotate x * -90 turns the sweep 0..2 along y into -z)
#macro Pumpkin_Face(N_Face)
	union {
		#switch (N_Face)
			#case (0)
				// triangle eyes and nose, toothy grin
				prism { linear_sweep linear_spline 0, 2, 4, <-0.55, 0.15>, <-0.15, 0.15>, <-0.35, 0.5>, <-0.55, 0.15> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 4, <0.15, 0.15>, <0.55, 0.15>, <0.35, 0.5>, <0.15, 0.15> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 4, <-0.1, -0.05>, <0.1, -0.05>, <0, 0.12>, <-0.1, -0.05> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 11,
					<-0.6, -0.2>, <-0.4, -0.3>, <-0.3, -0.2>, <-0.15, -0.32>, <0, -0.22>, <0.15, -0.32>, <0.3, -0.2>, <0.4, -0.3>, <0.6, -0.2>, <0, -0.6>, <-0.6, -0.2>
					rotate x * -90 }
			#break
			#case (1)
				// angry slanted slits, jagged mouth
				prism { linear_sweep linear_spline 0, 2, 5, <-0.6, 0.35>, <-0.12, 0.15>, <-0.15, 0.05>, <-0.55, 0.18>, <-0.6, 0.35> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 5, <0.6, 0.35>, <0.12, 0.15>, <0.15, 0.05>, <0.55, 0.18>, <0.6, 0.35> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 9,
					<-0.55, -0.15>, <-0.3, -0.3>, <-0.15, -0.18>, <0, -0.35>, <0.15, -0.18>, <0.3, -0.3>, <0.55, -0.15>, <0, -0.55>, <-0.55, -0.15>
					rotate x * -90 }
			#break
			#case (2)
				// round eyes, round open mouth
				cylinder { <-0.3, 0.25, -2>, <-0.3, 0.25, 0>, 0.15 }
				cylinder { <0.3, 0.25, -2>, <0.3, 0.25, 0>, 0.15 }
				cylinder { <0, -0.3, -2>, <0, -0.3, 0>, 0.18 scale <1, 1.3, 1> translate y * 0.09 }
			#break
		#end
	}
#end

#macro Pumpkin(N_Size, N_Seed, N_Face)
	#local S = seed(N_Seed);
	union {
		difference {
			object { Pumpkin_Body(1) }
			object { Pumpkin_Body(0.9) }
			object { Pumpkin_Face(N_Face) }
			// lid cut
			cylinder { <0, 0.62, 0>, <0, 2, 0>, 0.3 }
			texture { T_Pumpkin_Skin }
			interior_texture { T_Pumpkin_Flesh }
		}
		// lid with its stem
		intersection {
			object { Pumpkin_Body(1) }
			cylinder { <0, 0.64, 0>, <0, 2, 0>, 0.28 }
			texture { T_Pumpkin_Skin }
		}
		cone {
			<0, 0.7, 0>, 0.09, <0.08 * (rand(S) - 0.5), 1.05, 0.05>, 0.05
			texture { T_Pumpkin_Stem }
		}
		// candle light
		light_source {
			<0, -0.1, 0>
			color rgb <1, 0.5, 0.12> * 4
			fade_distance 1.5
			fade_power 2
		}
		rotate y * (rand(S) - 0.5) * 20
		scale <1, 0.85 + 0.15 * rand(S), 1> * N_Size
		translate y * 0.68 * N_Size
	}
#end
