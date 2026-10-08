/*
	Dead tree: recursive gnarled branches. Dead_Tree(N_Seed, N_Height).
	Origin at the foot of the trunk.
*/

#declare T_Dead_Bark = texture {
	pigment {
		color rgb <0.025, 0.02, 0.018>
	}
	normal {
		bumps 0.8
		scale <0.05, 0.3, 0.05>
	}
	finish {
		ambient 0
		diffuse 0.6
	}
}

// branch from V_From along V_Dir, of length N_Len and base radius N_R
#macro Tree_Branch(V_From, V_Dir, N_Len, N_R, N_Depth, S)
	// gnarled: four segments, each bent at random
	#local V_A = V_From + vnormalize(V_Dir + <rand(S) - 0.5, 0, rand(S) - 0.5> * 0.7) * N_Len * 0.3;
	#local V_B = V_A + vnormalize(V_Dir + <rand(S) - 0.5, 0, rand(S) - 0.5> * 0.9) * N_Len * 0.3;
	#local V_To = V_B + vnormalize(V_Dir + <rand(S) - 0.5, rand(S) * 0.2, rand(S) - 0.5> * 0.9) * N_Len * 0.4;
	sphere_sweep {
		linear_spline 4
		V_From, N_R
		V_A, N_R * 0.82
		V_B, N_R * 0.72
		V_To, N_R * 0.55
	}
	#if (N_Depth > 0)
		#local N_Children = 2 + int(rand(S) * 2);
		#local I = 0;
		#while (I < N_Children)
			// spreading out: the children lean further from the vertical
			#local V_New = vnormalize(V_Dir) + <rand(S) - 0.5, rand(S) * 0.2, rand(S) - 0.5> * 2.2;
			Tree_Branch(V_To, V_New, N_Len * (0.6 + 0.15 * rand(S)), N_R * 0.62, N_Depth - 1, S)
			#local I = I + 1;
		#end
	#end
#end

#macro Dead_Tree(N_Seed, N_Height)
	#local S = seed(N_Seed);
	union {
		// roots
		#local I = 0;
		#while (I < 5)
			sphere_sweep {
				linear_spline 3
				<0, 0.4, 0>, 0.3
				vrotate(<0.6, 0.05, 0>, y * (I * 72 + rand(S) * 30)), 0.15
				vrotate(<1.2, -0.1, 0>, y * (I * 72 + rand(S) * 30)), 0.05
			}
			#local I = I + 1;
		#end
		Tree_Branch(<0, 0, 0>, <0.25, 1, 0>, N_Height * 0.4, 0.42, 6, S)
		texture { T_Dead_Bark }
	}
#end
