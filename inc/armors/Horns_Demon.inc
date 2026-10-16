/*
 _
| |__   ___  _ __ _ __  ___
| '_ \ / _ \| '__| '_ \/ __|
| | | | (_) | |  | | | \__ \
|_| |_|\___/|_|  |_| |_|___/

	Two demon horns pointing up, slightly curved outwards then back in.
	O_Horn_Demon is the left one (+x), its base at the origin; O_Horns_Demon
	puts both on the head, in the frame of the helm slot.
*/

#ifndef (N_Horn_Len)
	#declare N_Horn_Len = 0.5;
#end
#ifndef (N_Horn_Radius)
	#declare N_Horn_Radius = 0.2;
#end
#ifndef (T_Horn_Demon)
	#declare T_Horn_Demon = texture {
		pigment {
			gradient y
			color_map {
				[0 color rgb <0.3, 0.08, 0.06>]
				[1 color rgb <0.03, 0.02, 0.02>]
			}
			scale N_Horn_Len * 1.01
		}
		finish { ambient 0.1 diffuse 0.6 specular 0.7 roughness 0.01 }
	}
#end

#declare O_Horn_Demon = sphere_sweep {
	b_spline
	6
	<-0.05, -0.1, 0>, N_Horn_Radius
	<0, 0, 0>, N_Horn_Radius
	<0.2, 0.35, 0.03> * N_Horn_Len / 0.5, N_Horn_Radius * 0.75
	<0.25, 0.7, 0.08> * N_Horn_Len / 0.5, N_Horn_Radius * 0.4
	<0.15, 1.0, 0.12> * N_Horn_Len / 0.5, N_Horn_Radius * 0.1
	<0.1, 1.1, 0.13> * N_Horn_Len / 0.5, 0
	scale 0.5
	texture { T_Horn_Demon }
}

#ifndef (V_Horns_Position)
	// base of the left horn on the hair, helm frame
	#declare V_Horns_Position = <0.25, 0.98, -0.15>;
#end

#declare O_Horns_Demon = union {
	object { O_Horn_Demon rotate z * -10 translate V_Horns_Position }
	object { O_Horn_Demon rotate z * -10 translate V_Horns_Position scale <-1, 1, 1> }
}
