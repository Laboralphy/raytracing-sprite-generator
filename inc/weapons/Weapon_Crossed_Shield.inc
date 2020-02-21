#include "metals"
#include "woods"


#local O_Shield_Base = prism {
	linear_spline
	0, 0.25, 6,
    <-1, 1>, <1, 1>, <1, -1>, <0, -1.5>, <-1, -1>, <-1, 1>
	rotate <-90, 0, 0>
}

#local O_Shield_Extruder = object {
	O_Shield_Base
	scale <0.9, 0.9, 2>
	translate <0, 0, 0>
}

#local O_Shield_WoodPanel = object {
	O_Shield_Base
	scale <0.99, 0.99, 0.5>
	translate <0, 0, -0.05>
}

#local O_Shield_Pattern_Cross = union {
	box {
		<-0.666, 0.25, 0>
		<0.666, 0, -0.25>
	}
	box {
		<-0.125, 0.666, 0>
		<0.125, -1, -0.25>
	}
	
}

#declare P_BodyPart_ArmorPart_Shield = union {
	difference {
		object {
			O_Shield_Base
		}
		object {
			O_Shield_Extruder
		}
		texture {
			T_Brass_1A
			normal {
				bumps 0.25
				scale 0.05
			}
		}
	}
	object {
		O_Shield_Pattern_Cross
		texture {
			T_Brass_1A
			normal {
				bumps 0.25
				scale 0.05
			}
		}
	}
	object {
		O_Shield_WoodPanel
		texture {
			T_Wood22
		}
		
	}
	scale 0.66
	translate <0.25, -0.25, 0>
}
