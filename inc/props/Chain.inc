/*
      _           _
  ___| |__   __ _(_)_ __
 / __| '_ \ / _` | | '_ \
| (__| | | | (_| | | | | |
 \___|_| |_|\__,_|_|_| |_|

	Hanging chain of iron links, built downwards from y = 0.

	Link (before scaling): two straight sides and two half rings, the centre
	of the wire running 2 units above and below the centre of the link, with a
	wire radius of N_Chain_Wire. Each link passes through the previous one, so
	the links are 2 * 2 - 2 * N_Chain_Wire apart.
*/

#ifndef (N_Chain_Wire)
	#declare N_Chain_Wire = 0.5;
#end

#ifndef (T_Chain_Iron)
	#declare T_Chain_Iron = texture {
		pigment {
			granite
			color_map {
				[0.0 color rgb <0.22, 0.21, 0.2>]
				[0.6 color rgb <0.3, 0.29, 0.28>]
				[0.8 color rgb <0.35, 0.2, 0.1>]
				[1.0 color rgb <0.25, 0.12, 0.05>]
			}
			scale 0.3
		}
		finish {
			specular 0.4
			roughness 0.05
			metallic
		}
	}
#end

#declare P_Chain_Link = union {
	cylinder { <-1, -1, 0>, <-1, 1, 0>, N_Chain_Wire }
	cylinder { <1, -1, 0>, <1, 1, 0>, N_Chain_Wire }
	intersection {
		torus { 1, N_Chain_Wire rotate x * 90 }
		plane { -y, 0 }
		translate y
	}
	intersection {
		torus { 1, N_Chain_Wire rotate x * 90 }
		plane { y, 0 }
		translate -y
	}
}

#declare N_Chain_Link_Pitch = 4 - 2 * N_Chain_Wire;
#declare N_Chain_Link_Height = 4 + 2 * N_Chain_Wire;

/*
	Chain(N_Links, N_Scale): N_Links links hanging from y = 0, scaled by
	N_Scale. The bottom of the last link is at
		-(N_Links - 1) * N_Chain_Link_Pitch * N_Scale - N_Chain_Link_Height * N_Scale
*/
#macro Chain(N_Links, N_Scale)
	union {
		#local I = 0;
		#while (I < N_Links)
			object {
				P_Chain_Link
				rotate y * 90 * mod(I, 2)
				translate -y * (N_Chain_Link_Height / 2 + I * N_Chain_Link_Pitch)
			}
			#local I = I + 1;
		#end
		texture { T_Chain_Iron }
		scale N_Scale
	}
#end

/* bottom of a chain made by Chain(N_Links, N_Scale), from its top */
#macro Chain_Length(N_Links, N_Scale)
	((N_Links - 1) * N_Chain_Link_Pitch + N_Chain_Link_Height) * N_Scale
#end
