/*
	Piles of books of different sizes and colours, on the floor (y = 0):
	three piles side by side, the books a little askew.
	O_Books: about 1 unit high, 1.8 wide.
*/

#declare A_Book_Colours = array[7] {
	<0.45, 0.08, 0.06>, <0.1, 0.25, 0.12>, <0.1, 0.14, 0.35>, <0.35, 0.2, 0.08>,
	<0.25, 0.08, 0.25>, <0.15, 0.12, 0.1>, <0.5, 0.35, 0.1>
}

#declare T_Book_Pages = texture {
	pigment {
		gradient y
		color_map {
			[0 color rgb <0.85, 0.8, 0.65>]
			[0.5 color rgb <0.7, 0.65, 0.5>]
			[1 color rgb <0.85, 0.8, 0.65>]
		}
		scale 0.02
	}
}

// one book lying flat, width N_W (x), depth N_D (z), thickness N_H (y),
// its spine towards -x; bottom at y = 0
#macro Book(N_W, N_D, N_H, V_Colour)
	union {
		// covers and spine
		difference {
			box {
				<-N_W / 2, 0, -N_D / 2>, <N_W / 2, N_H, N_D / 2>
			}
			box {
				<-N_W / 2 + 0.04, 0.022, -N_D / 2 - 0.1>, <N_W, N_H - 0.022, N_D / 2 + 0.1>
			}
			texture {
				pigment {
					color rgb V_Colour
				}
				finish {
					specular 0.2
					roughness 0.05
				}
			}
		}
		// pages, a little inset
		box {
			<-N_W / 2 + 0.04, 0.022, -N_D / 2 + 0.025>, <N_W / 2 - 0.025, N_H - 0.022, N_D / 2 - 0.025>
			texture {
				T_Book_Pages
			}
		}
	}
#end

// a pile of N_Count books, from the seed S
#macro Book_Pile(N_Count, S)
	union {
		#local N_Y = 0;
		#local I = 0;
		#while (I < N_Count)
			#local N_W = 0.6 + 0.25 * rand(S);
			#local N_D = 0.45 + 0.15 * rand(S);
			#local N_H = 0.11 + 0.08 * rand(S);
			object {
				Book(N_W, N_D, N_H, A_Book_Colours[int(rand(S) * 7)])
				rotate y * (rand(S) * 30 - 15 + 180 * int(rand(S) * 2))
				translate <0.04 * (rand(S) - 0.5), N_Y, 0.04 * (rand(S) - 0.5)>
			}
			#local N_Y = N_Y + N_H;
			#local I = I + 1;
		#end
	}
#end

#declare O_Books = union {
	object {
		Book_Pile(7, seed(7))
		translate <-0.6, 0, 0.15>
	}
	object {
		Book_Pile(4, seed(21))
		rotate y * 20
		translate <0.25, 0, -0.2>
	}
	object {
		Book_Pile(2, seed(5))
		rotate y * -30
		translate <0.85, 0, 0.35>
	}
}
