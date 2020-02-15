#include "colors.inc"

#declare T_Hair_Red = texture {
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
