/*

  ___ _ __ _____      ___ __
 / __| '__/ _ \ \ /\ / / '_ \
| (__| | | (_) \ V  V /| | | |
 \___|_|  \___/ \_/\_/ |_| |_|

	Golden crown with gems: a band that flares slightly upwards, 8 fleurons
	topped with pearls, a big gem at the front and small ones around the band.
	Built around the y axis, base at y = 0, radius 1 at the base: each
	character places and scales it on its head.
*/

#ifndef (T_Crown_Gold)
	#declare T_Crown_Gold = texture {
		pigment { color rgb <0.95, 0.6, 0.08> }
		finish {
			ambient 0.2
			diffuse 0.6
			specular 0.9
			roughness 0.01
			metallic
			reflection 0.2
		}
	}
#end
#ifndef (T_Crown_Pearl)
	#declare T_Crown_Pearl = texture {
		pigment { color rgb <1, 0.97, 0.9> }
		finish { ambient 0.25 diffuse 0.7 specular 0.6 roughness 0.02 }
	}
#end
#macro Crown_Gem(C)
	texture {
		pigment { color C }
		finish { ambient 0.6 diffuse 0.6 specular 1 roughness 0.002 reflection 0.1 }
	}
#end
#ifndef (C_Crown_Gem_Main)
	#declare C_Crown_Gem_Main = color rgb <0.9, 0.05, 0.1>;
#end
#ifndef (C_Crown_Gem_1)
	#declare C_Crown_Gem_1 = color rgb <0.05, 0.75, 0.2>;
#end
#ifndef (C_Crown_Gem_2)
	#declare C_Crown_Gem_2 = color rgb <0.1, 0.35, 1>;
#end
#ifndef (N_Crown_Gems)
	#declare N_Crown_Gems = 1; // 0: plain gold crown
#end
#ifndef (N_Crown_Height)
	#declare N_Crown_Height = 0.45; // band only, fleurons are 0.45 higher
#end

#local N_Flare = 1.12; // radius at the top of the band

#declare O_Crown_Gold_Gems = union {
	union {
		// band
		difference {
			cone { <0, 0, 0>, 1, <0, N_Crown_Height, 0>, N_Flare }
			cone { <0, -0.01, 0>, 0.9, <0, N_Crown_Height + 0.01, 0>, N_Flare - 0.1 }
		}
		// rims
		torus { 1, 0.06 }
		torus { N_Flare, 0.06 translate y * N_Crown_Height }
		// fleurons: a diamond point topped by a pearl, small balls between them
		#local I = 0;
		#while (I < 8)
			union {
				prism {
					linear_sweep
					linear_spline
					-0.04, 0.04
					5
					<-0.2, 0>, <0, 0.32>, <0.2, 0>, <0, -0.12>, <-0.2, 0>
					rotate x * -90
					translate <0, N_Crown_Height, -N_Flare>
				}
				sphere {
					<0, N_Crown_Height + 0.4, -N_Flare>, 0.09
					texture { T_Crown_Pearl }
				}
				sphere {
					<0, N_Crown_Height + 0.08, -N_Flare>, 0.06
					rotate y * 22.5
				}
				rotate y * I * 45
			}
			#local I = I + 1;
		#end
		texture { T_Crown_Gold }
	}
	// gems on the band: big one at the front, alternating colours around
	#if (N_Crown_Gems)
	sphere {
		0, 0.22
		scale <1, 1.25, 0.6>
		translate <0, N_Crown_Height / 2, -0.98>
		Crown_Gem(C_Crown_Gem_Main)
	}
	#local I = 1;
	#while (I < 8)
		sphere {
			0, 0.14
			scale <1, 1, 0.6>
			translate <0, N_Crown_Height / 2, -0.98>
			rotate y * I * 45
			#if (mod(I, 2) = 1)
				Crown_Gem(C_Crown_Gem_1)
			#else
				Crown_Gem(C_Crown_Gem_2)
			#end
		}
		#local I = I + 1;
	#end
	#end
}
