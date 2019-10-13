#include "colors.inc"
#include "finish.inc"
#include "inc/BodyLengthes.inc"

#declare Skirt_Pleaded_Blue = sor {
	6
	<0, 0>
	<0.5, 0.1>
	<0.75, 0.5>
	<0.9, 0.9>
	<1, 1>
	<1, 2>
	scale <1, -1, 0.6>
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


#declare Boot_Type1_Top = difference {
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

#declare Boot_Type1_Heel = intersection {
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

#declare Boot_Type1 = union {
	object {
		Boot_Type1_Top
	}
	object {
		Boot_Type1_Heel
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



