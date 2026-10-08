/*
	Haunted Victorian house, for a far silhouette: main block, a tower with
	a pointed roof, gables, a chimney, a few lit windows. Origin at the
	middle of its foot, the front towards -z. About 10 units high.
*/

#declare T_House_Wall = texture {
	pigment {
		color rgb <0.05, 0.045, 0.06>
	}
	finish {
		ambient 0
		diffuse 0.5
	}
}

#declare T_House_Lit = texture {
	pigment {
		color rgb <1, 0.75, 0.3>
	}
	finish {
		ambient 1.2
		diffuse 0
	}
}

#declare T_House_Dark_Window = texture {
	pigment {
		color rgb <0.02, 0.02, 0.03>
	}
	finish {
		ambient 0
		specular 0.6
		roughness 0.01
	}
}

#macro House_Window(V_Pos, B_Lit)
	box {
		<-0.35, -0.55, -0.05>, <0.35, 0.55, 0.05>
		translate V_Pos
		#if (B_Lit)
			texture { T_House_Lit }
		#else
			texture { T_House_Dark_Window }
		#end
	}
#end

#declare O_House = union {
	union {
		// main block
		box { <-5, 0, -3>, <3, 5.5, 3> }
		// gable roof of the main block
		prism { linear_sweep linear_spline -3.3, 3.3, 4, <-5.4, 5.5>, <3.4, 5.5>, <-1, 8.5>, <-5.4, 5.5>
			rotate x * -90 rotate y * 0 }
		// side wing with its own gable
		box { <3, 0, -2>, <6.5, 4, 2> }
		prism { linear_sweep linear_spline -2.3, 2.3, 4, <2.8, 4>, <6.9, 4>, <4.85, 6.4>, <2.8, 4> rotate x * -90 }
		// tower
		cylinder { <-5, 0, -3>, <-5, 9, -3>, 1.4 }
		cone { <-5, 9, -3>, 1.7, <-5, 13.5, -3>, 0 }
		// spike on the tower
		cylinder { <-5, 13.5, -3>, <-5, 14.4, -3>, 0.05 }
		// chimney, a little crooked
		box { <0.5, 6, 0.5>, <1.3, 9.5, 1.3> rotate z * 4 }
		texture { T_House_Wall }
	}
	// windows (front face at z = -3)
	House_Window(<-2.5, 3.8, -3.05>, 1)
	House_Window(<-0.5, 3.8, -3.05>, 0)
	House_Window(<1.5, 3.8, -3.05>, 1)
	House_Window(<-2.5, 1.5, -3.05>, 0)
	House_Window(<1.5, 1.5, -3.05>, 0)
	House_Window(<4.75, 2.5, -2.05>, 1)
	// round tower window, lit
	cylinder { <-5, 7, -4.45>, <-5, 7, -4.35>, 0.4 texture { T_House_Lit } }
	// door, dark with a faint glow under it
	box { <-0.9, 0, -3.05>, <0.1, 2, -3.0> texture { T_House_Dark_Window } }
}
