/*
	Carved pumpkin head of Jack-o'-lantern (inc/jack/Jack.inc), after the
	Halloween scene asset (halloween/inc/Pumpkin.inc): a ribbed body of 10
	lobes, hollowed out, a lid with its stem, a classic carved face (triangles). No light
	inside (it would light the whole sprite): the flesh inside glows, seen
	through the carving.
	O_Jack_Pumpkin: centred on the origin, about 2.1 wide and 1.5 high, the
	face towards -z. Face: N_Jack_Pumpkin_Face (0 classic triangles, 1 angry,
	2 surprised; 0 by default).
*/

#ifndef (N_Jack_Pumpkin_Face)
	#declare N_Jack_Pumpkin_Face = 0;
#end

// orange, darker in the grooves between the lobes (radial: one period per
// lobe, 0.5 half way between two lobe centres)
#declare T_Jack_Pumpkin_Skin = texture {
	pigment {
		radial
		frequency 10
		color_map {
			[0 color rgb <0.8, 0.27, 0.02>]
			[0.38 color rgb <0.68, 0.2, 0.01>]
			[0.5 color rgb <0.28, 0.05, 0.0>]
			[0.62 color rgb <0.68, 0.2, 0.01>]
			[1 color rgb <0.8, 0.27, 0.02>]
		}
	}
	normal {
		bumps 0.1
		scale 0.1
	}
	finish {
		diffuse 0.75
		specular 0.12
		roughness 0.06
	}
}

// inside: bright, as if lit by a candle
#declare T_Jack_Pumpkin_Flesh = texture {
	pigment {
		color rgb <1, 0.8, 0.15>
	}
	finish {
		ambient 1
		diffuse 0
	}
}

#declare T_Jack_Pumpkin_Stem = texture {
	pigment {
		color rgb <0.22, 0.2, 0.08>
	}
	normal {
		bumps 0.6
		scale <0.02, 0.2, 0.02>
	}
}

// ribbed body: 10 lobes around y
#macro Jack_Pumpkin_Body(N_R)
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
#macro Jack_Pumpkin_Face(N_Face)
	union {
		#switch (N_Face)
			#case (0)
				prism { linear_sweep linear_spline 0, 2, 4, <-0.55, 0.15>, <-0.15, 0.15>, <-0.35, 0.5>, <-0.55, 0.15> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 4, <0.15, 0.15>, <0.55, 0.15>, <0.35, 0.5>, <0.15, 0.15> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 4, <-0.1, -0.05>, <0.1, -0.05>, <0, 0.12>, <-0.1, -0.05> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 11,
					<-0.6, -0.2>, <-0.4, -0.3>, <-0.3, -0.2>, <-0.15, -0.32>, <0, -0.22>, <0.15, -0.32>, <0.3, -0.2>, <0.4, -0.3>, <0.6, -0.2>, <0, -0.6>, <-0.6, -0.2>
					rotate x * -90 }
			#break
			#case (1)
				prism { linear_sweep linear_spline 0, 2, 5, <-0.6, 0.35>, <-0.12, 0.15>, <-0.15, 0.05>, <-0.55, 0.18>, <-0.6, 0.35> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 5, <0.6, 0.35>, <0.12, 0.15>, <0.15, 0.05>, <0.55, 0.18>, <0.6, 0.35> rotate x * -90 }
				prism { linear_sweep linear_spline 0, 2, 9,
					<-0.55, -0.15>, <-0.3, -0.3>, <-0.15, -0.18>, <0, -0.35>, <0.15, -0.18>, <0.3, -0.3>, <0.55, -0.15>, <0, -0.55>, <-0.55, -0.15>
					rotate x * -90 }
			#break
			#case (2)
				cylinder { <-0.3, 0.25, -2>, <-0.3, 0.25, 0>, 0.15 }
				cylinder { <0.3, 0.25, -2>, <0.3, 0.25, 0>, 0.15 }
				cylinder { <0, -0.3, -2>, <0, -0.3, 0>, 0.18 scale <1, 1.3, 1> translate y * 0.09 }
			#break
		#end
	}
#end

#declare O_Jack_Pumpkin = union {
	difference {
		object { Jack_Pumpkin_Body(1) }
		object { Jack_Pumpkin_Body(0.9) }
		// carving a little larger than in the Halloween scene: readable in a sprite
		object { Jack_Pumpkin_Face(N_Jack_Pumpkin_Face) scale <1.2, 1.25, 1> }
		// lid cut
		cylinder { <0, 0.62, 0>, <0, 2, 0>, 0.3 }
		texture { T_Jack_Pumpkin_Skin }
		interior_texture { T_Jack_Pumpkin_Flesh }
	}
	// glowing core, seen through the carving
	object {
		Jack_Pumpkin_Body(0.86)
		texture { T_Jack_Pumpkin_Flesh }
	}
	// lid with its stem
	intersection {
		object { Jack_Pumpkin_Body(1) }
		cylinder { <0, 0.64, 0>, <0, 2, 0>, 0.28 }
		texture { T_Jack_Pumpkin_Skin }
	}
	cone {
		<0, 0.7, 0>, 0.09, <0.03, 1.05, 0.05>, 0.05
		texture { T_Jack_Pumpkin_Stem }
	}
}
