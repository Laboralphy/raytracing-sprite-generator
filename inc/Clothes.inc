#include "colors.inc"
#include "finish.inc"
#include "metals.inc"
#include "golds.inc"
#include "inc/BodyLengthes.inc"

#declare Clothe_Skirt_Pleaded_Blue = sor {
	6
	<0, 0>
	<0.5, 0.1>
	<0.75, 0.5>
	<0.9, 0.9>
	<1, 1>
	<1, 2>
	scale <1, -1, 0.7>
	texture {
		pigment {
			radial
			color_map {
				[0, Blue]
				[0.5 Blue * 0.5]
				[1 Blue]
			}
			frequency 16
		}
	}
	translate <0, 2.7, 0>
}


#declare Clothe_Boot_Type1_Top = difference {
	cylinder {
		<0, -1, 0>
		<0, ShinLen * 0.7, 0>
		LegThickness * 0.9
	}
	box {
		<0, 0, LegThickness>
		<LegThickness, LegThickness, -LegThickness>
		rotate z * 45
		translate <0, (ShinLen - LegThickness) * 0.7, 0>
	}
}

#declare Clothe_Boot_Type1_Heel = intersection {
	sphere {
		<0, 0, 0>
		LegThickness
		scale <1, 1, 2>
	}
	box {
		<-LegThickness * 2, 0, 0>
		<LegThickness * 2, LegThickness * 2, -LegThickness * 2>
	}
	translate -LegThickness * y
}

#declare Clothe_Boot_Type1 = union {
	object {
		Clothe_Boot_Type1_Top
	}
	object {
		Clothe_Boot_Type1_Heel
	}
	
	texture {
		pigment {
			Gray05
		}
		finish {
			Phong_Glossy
		}
	}
}

#declare Clothe_ArmWear_Type1 = union {
	sphere {
		<0, ArmLen, 0>
		ArmThickness * 1.75
		pigment {
			radial
			color_map {
				[0.5 Blue]
				[0.5 Blue * 0.5 ]
			}
			frequency 8
		}
	}
	cylinder {
		<0, ArmLen, 0>
		<0, ArmLen * 0.125, 0>
		ArmThickness * 1.1
		pigment {
			Blue
		}
	}
}

#declare Clothe_Bracer_Type1 = torus {
	ArmThickness
	ArmThickness * 0.3
	translate <0, 0.65, 0>
	texture {
		T_Gold_3C
	}
}



/* les ceinture sont basée sur des cylindre de diametre 2 */

#declare Clothe_Belt_Type1_Leather = cylinder {
	0
	y * 0.5
	1.8
	pigment {
		Gray10
	}
}

#declare Clothe_Belt_Type1_Buckle = torus {
	0.9
	0.3
	rotate <90, 0, 0>
	scale 0.33
	texture {
		T_Gold_1B
	}
}

#declare Clothe_Belt_Type1 = union {
	object {
		Clothe_Belt_Type1_Leather
	}
	object {
		Clothe_Belt_Type1_Buckle
		translate <0, 0.3, -2.8>
	}
}
