#local N_Size = 1.5;
#include "textures"

#local OneHorn = cone {
	<0, 0, 0>, 0.1333
	<0, 1, 0>, 0
	texture {
		pigment {
			onion
			color_map {
				[0 Brown]
				[1 Black]
			}
		}
		scale <1, 0.1, 1>
		translate <1, 0, 0>
	}
}

#declare P_BodyPart_ArmorPart_Helm = union {
	object { 
		OneHorn
		translate <0, 0.25, 0>
	}
	object { 
		OneHorn
		rotate <0, 0, 15>
		translate <-0.2, 0.20, 0>
	}
	object { 
		OneHorn
		rotate <-30, 30, -15>
		translate <0.2, 0.20, -0.07>
	}
	object { 
		OneHorn
		rotate <30, 30, -15>
		translate <0.2, 0.20, -0.07>
	}

}
