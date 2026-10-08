/*
	Bat silhouette, wings spread, flying towards -z (seen from below/front).
	Bat(N_Flap): N_Flap from -1 (wings down) to 1 (up). About 1 unit wide.
*/

#declare T_Bat = texture {
	pigment {
		color rgb 0.01
	}
	finish {
		ambient 0
		diffuse 0.2
	}
}

// left wing, scalloped trailing edge, in the x-z plane (prism)
#declare O_Bat_Wing = prism {
	linear_sweep linear_spline -0.01, 0.01, 9,
	<0.05, 0.05>, <0.25, 0.12>, <0.5, 0.08>, <0.55, -0.02>, <0.45, -0.08>, <0.35, -0.02>, <0.25, -0.1>, <0.12, -0.04>, <0.05, 0.05>
}

#macro Bat(N_Flap)
	union {
		object { O_Bat_Wing rotate z * 25 * N_Flap }
		object { O_Bat_Wing scale <-1, 1, 1> rotate z * -25 * N_Flap }
		// body and head with ears
		sphere { 0, 0.06 scale <0.8, 0.8, 1.5> }
		sphere { <0, 0.01, 0.09>, 0.04 }
		cone { <0.02, 0.03, 0.1>, 0.015, <0.03, 0.08, 0.1>, 0 }
		cone { <-0.02, 0.03, 0.1>, 0.015, <-0.03, 0.08, 0.1>, 0 }
		texture { T_Bat }
	}
#end
