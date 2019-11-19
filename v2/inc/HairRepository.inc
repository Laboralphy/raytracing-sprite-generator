#include "colors.inc"

#declare O_Ondulator = union {
	cone {
		<0, 0, 0>
		0
		<0, 0, -2>
		0.9
	}
	cone {
		<0, 0.25, 0>
		0
		<0, 0.25, -2>
		0.8
	}
	cone {
		<0, 0.5, 0>
		0
		<0, 0.5, -2>
		0.7
	}
	cone {
		<0, 0.75, 0>
		0
		<0, 0.75, -2>
		0.55
	}
}

#declare P_HairRepository_Extruder_Normal = union {
	prism {
		linear_spline
		-10
		1
		3
		<0, 0>
		<1.5, -2>
		<-1.5, -2>
	}
	object {
		O_Ondulator
		rotate <0, 30, 0>
	}
	object {
		O_Ondulator
		rotate <0, -30, 0>
	}
}

#declare P_HairRepository_Extruder_Large = prism {
	linear_spline
	-10
	1
	3
	<0, 0>
	<15, -2>
	<-15, -2>
}


#declare T_HairRepository_Blond = texture {
	pigment {
		radial
		color_map {
			[0 Gold * 0.5]
			[0.4 Gold]
			[0.6 Gold * 0.75 ]
			[1 Gold * 0.5]
		}
		frequency 24		
  	}
  	rotate <0, 0, 0>
}

#declare T_HairRepository_Red = texture {
	pigment {
		radial
		color_map {
			[0 VioletRed * 0.5]
			[0.4 VioletRed]
			[0.6 VioletRed * 0.75 ]
			[1 VioletRed * 0.5]
		}
		frequency 24		
  	}
  	rotate <0, 0, 0>
}


#declare P_HairRepository_Egg = difference {
	sor {
		8
		<0.5, 0>
		<0.75, 0.125>
		<1, 0.5>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(85)), 1 + sin(radians(85))>
		<0, 2>
		open
		sturm
	}
	object {
		P_HairRepository_Extruder_Normal
	}
	scale 0.6
}


#declare P_HairRepository_Egg_Long = difference {
	sor {
		9
		<1, -1>
		<0.85, -0.3>
		<0.95, 0.125>
		<1, 0.5>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(85)), 1 + sin(radians(85))>
		<0, 2>
		sturm
	}
	object {
		P_HairRepository_Extruder_Normal
	}
	scale 0.6
}

#declare P_HairRepository_Egg_Long_Curl = difference {
	sor {
		9
		<1.9, -0.4>
		<1.3, -0.3>
		<1, 0.125>
		<1, 0.5>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(85)), 1 + sin(radians(85))>
		<0, 2>
		sturm
	}
	object {
		P_HairRepository_Extruder_Normal
	}
	scale 0.6
}
