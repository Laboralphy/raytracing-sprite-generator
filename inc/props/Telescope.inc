/*
	Antique refracting telescope on a wooden tripod: brass tube with a dew
	shield, rings, a dark lens, a draw tube and its eyepiece, a small finder
	scope; brass fork mount; walnut tripod with a round shelf between the
	legs. Same woods and brass as the old globe (inc/props/Globe.inc).
	The tube points towards -x, raised by N_Telescope_Elevation degrees.
	O_Telescope: about 3.3 units high before N_Telescope_Scale (1.2 by
	default: about 4 units), on the floor (y = 0).
*/

#include "inc/props/Globe.inc"

#ifndef (N_Telescope_Scale)
	#declare N_Telescope_Scale = 1.2;
#end
#ifndef (N_Telescope_Elevation)
	#declare N_Telescope_Elevation = 30;
#end

#local N_Head = 2.3; // top of the tripod
#local N_Tube_Len = 2.6;
#local N_Tube_R = 0.11;

#declare T_Telescope_Lens = texture {
	pigment {
		color rgb <0.03, 0.05, 0.08>
	}
	finish {
		specular 1
		roughness 0.002
		reflection 0.2
	}
}

// one leg, from the head down and out, a little tapered
#local O_Telescope_Leg = cone {
	<0, N_Head - 0.05, 0>, 0.055, <0.85, 0, 0>, 0.035
	texture {
		T_Globe_Wood
	}
}

// the tube, along -x from its pivot (balance point), the objective at -x
#local O_Telescope_Tube = union {
	// main tube, slightly tapered towards the eyepiece
	cone {
		<-1.55, 0, 0>, N_Tube_R, <1.05, 0, 0>, N_Tube_R * 0.8
		texture {
			T_Globe_Brass
		}
	}
	// dew shield at the objective, wider
	cylinder {
		<-1.85, 0, 0>, <-1.5, 0, 0>, N_Tube_R * 1.3
		texture {
			T_Globe_Brass
		}
	}
	// lens, set back in the dew shield
	cylinder {
		<-1.8, 0, 0>, <-1.78, 0, 0>, N_Tube_R * 1.2
		texture {
			T_Telescope_Lens
		}
	}
	// rings
	#local A_Rings = array[4] { -1.5, -0.8, 0, 0.9 }
	#local I = 0;
	#while (I < 4)
		torus {
			N_Tube_R * (1 - 0.2 * (A_Rings[I] + 1.55) / 2.6) + 0.01, 0.02
			rotate z * 90
			translate x * A_Rings[I]
			texture {
				T_Globe_Brass
			}
		}
		#local I = I + 1;
	#end
	// draw tube and eyepiece
	cylinder {
		<1.05, 0, 0>, <1.4, 0, 0>, 0.05
		texture {
			T_Globe_Brass
		}
	}
	cylinder {
		<1.4, 0, 0>, <1.52, 0, 0>, 0.07
		texture {
			T_Globe_Wood
		}
	}
	// focusing knob
	cylinder {
		<1.15, 0, -0.09>, <1.15, 0, 0.09>, 0.025
		texture {
			T_Globe_Brass
		}
	}
	// finder scope, on two small posts
	union {
		cylinder {
			<-0.6, N_Tube_R + 0.1, 0>, <0.25, N_Tube_R + 0.1, 0>, 0.035
		}
		cylinder {
			<-0.45, 0, 0>, <-0.45, N_Tube_R + 0.1, 0>, 0.015
		}
		cylinder {
			<0.1, 0, 0>, <0.1, N_Tube_R + 0.1, 0>, 0.015
		}
		texture {
			T_Globe_Brass
		}
	}
}

#declare O_Telescope = union {
	// tripod
	object {
		O_Telescope_Leg
	}
	object {
		O_Telescope_Leg
		rotate y * 120
	}
	object {
		O_Telescope_Leg
		rotate y * 240
	}
	// round shelf between the legs
	cylinder {
		<0, 0.95, 0>, <0, 1.0, 0>, 0.45
		texture {
			T_Globe_Wood
		}
	}
	// head of the tripod and fork mount
	cylinder {
		<0, N_Head - 0.12, 0>, <0, N_Head + 0.02, 0>, 0.14
		texture {
			T_Globe_Wood
		}
	}
	union {
		box {
			<-0.06, N_Head, -0.17>, <0.06, N_Head + 0.05, 0.17>
		}
		box {
			<-0.05, N_Head, -0.17>, <0.05, N_Head + 0.25, -0.13>
		}
		box {
			<-0.05, N_Head, 0.13>, <0.05, N_Head + 0.25, 0.17>
		}
		cylinder {
			<0, N_Head + 0.22, -0.19>, <0, N_Head + 0.22, 0.19>, 0.03
		}
		texture {
			T_Globe_Brass
		}
	}
	object {
		O_Telescope_Tube
		rotate z * -N_Telescope_Elevation
		translate y * (N_Head + 0.22)
	}
	scale N_Telescope_Scale
}
