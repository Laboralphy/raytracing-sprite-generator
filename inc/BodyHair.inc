#include "colors.inc"
#include "finish.inc"

#declare T_Hair_Blond = texture {
	pigment {
		radial
		color_map {
			[0.5 Gold]
			[0.5 Gold * 0.75 ]
		}
		frequency 24
  	}
}

#declare T_Hair_BlueViolet = texture {
	pigment {
		radial
		color_map {
			[0.5 BlueViolet * 0.75 ]
			[0.5 BlueViolet * 0.3 ]
		}
		frequency 24
  	}
}

#declare P_Hair_Extruder = prism {
	linear_spline
	-10
	1.222
	3
	<0, 0>
	<3, -2>
	<-3, -2>
}

#declare P_Hair_Large_Extruder = prism {
	linear_spline
	-10
	1.222
	3
	<0, 0>
	<15, -2>
	<-15, -2>
}

#declare P_Hair_Ponytail = sphere_sweep {
	cubic_spline
	7
	<0, 0.5, 0>, 0
	<0, 1.5, 1>, 0
	<0, 1.5, 2>, 0.3
	<0, 1, 2>, 0.2
	<0, 0.5, 1.75>, 0.1
	<0, 0, 2>, 0
	<0, 0.5, 2.3>, 0
	translate <0, 0.3, -0.5>
}

#declare P_Hair_Curve_Bell = sor {
	8
	<1.5, 0>
	<1.25, 0.125>
	<1, 0.5>
	<cos(radians(0)), 1 + sin(radians(0))>
	<cos(radians(30)), 1 + sin(radians(30))>
	<cos(radians(60)), 1 + sin(radians(60))>
	<cos(radians(85)), 1 + sin(radians(85))>
	<0, 2>
	open
	sturm
}

#declare P_Hair_Curve_Egg = sor {
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

#declare P_Hair_Curve_Small_Egg = sor {
	8
	<0.5, 0>
	<0.75, 0.25>
	<1, 0.75>
	<cos(radians(0)), 1 + sin(radians(0))>
	<cos(radians(30)), 1 + sin(radians(30))>
	<cos(radians(60)), 1 + sin(radians(60))>
	<cos(radians(85)), 1 + sin(radians(85))>
	<0, 2>
	open
	sturm
}




#declare P_Hair_1 = difference {
	object {
		P_Hair_Curve_Bell
	}
	object {
		P_Hair_Extruder
	}
	texture {
		T_Hair_Blond
	}
}

#declare P_Hair_2 = difference {
	object {
		P_Hair_Curve_Bell
	}
	object {
		P_Hair_Extruder
	}
	texture {
		T_Hair_BlueViolet
	}
}

#declare P_Hair_3 = difference {
	object {
		P_Hair_Curve_Egg
	}
	object {
		P_Hair_Extruder
	}
	texture {
		T_Hair_Blond
	}
}

#declare P_Hair_4 = difference {
	object {
		P_Hair_Curve_Small_Egg
	}
	object {
		P_Hair_Large_Extruder
	}
	texture {
		T_Hair_Blond
	}
}

#declare P_Hair_5 = union {
	object {
		P_Hair_4
	}
	object {
		P_Hair_Ponytail
	}
	texture {
		T_Hair_Blond
	}
}


