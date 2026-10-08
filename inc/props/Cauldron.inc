/*
	Dark iron cauldron on three short legs, two ring handles, a dark liquid
	inside.
	O_Cauldron: about 1.4 units high, 1.4 wide before N_Cauldron_Scale
	(1.5 by default: 2.1 units), on the floor (y = 0).
*/

#ifndef (N_Cauldron_Scale)
	#declare N_Cauldron_Scale = 1.5;
#end

#declare T_Cauldron_Iron = texture {
	pigment {
		color rgb <0.07, 0.07, 0.08>
	}
	normal {
		dents 0.3
		scale 0.1
	}
	finish {
		ambient 0.1
		diffuse 0.6
		specular 0.6
		roughness 0.02
		metallic
	}
}

#local N_Y = 0.75; // centre of the belly
#local N_R = 0.7;

#declare O_Cauldron = union {
	// belly: a sphere cut under its top, hollow
	difference {
		sphere {
			0, N_R
			scale <1, 0.9, 1>
		}
		sphere {
			0, N_R - 0.05
			scale <1, 0.9, 1>
		}
		// cut above its top
		plane {
			-y, -0.42
		}
		translate y * N_Y
		texture {
			T_Cauldron_Iron
		}
	}
	// thick rim
	torus {
		sqrt(N_R * N_R - pow(0.42 / 0.9, 2)) - 0.01, 0.055
		translate y * (N_Y + 0.42)
		texture {
			T_Cauldron_Iron
		}
	}
	// liquid, dark green, some way down
	cylinder {
		<0, N_Y + 0.25, 0>, <0, N_Y + 0.26, 0>, N_R - 0.08
		texture {
			pigment {
				color rgb <0.04, 0.09, 0.04>
			}
			finish {
				specular 0.7
				roughness 0.01
				reflection 0.05
			}
		}
	}
	// three short legs
	#local I = 0;
	#while (I < 3)
		cone {
			<0.42, 0.25, 0>, 0.08, <0.5, 0, 0>, 0.05
			rotate y * (I * 120 + 30)
			texture {
				T_Cauldron_Iron
			}
		}
		#local I = I + 1;
	#end
	// ring handles on the sides
	#local I = -1;
	#while (I <= 1)
		torus {
			0.12, 0.025
			rotate z * 90
			translate <I * (N_R + 0.06), N_Y + 0.3, 0>
			texture {
				T_Cauldron_Iron
			}
		}
		#local I = I + 2;
	#end
	scale N_Cauldron_Scale
}
