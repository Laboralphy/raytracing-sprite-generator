#include "colors.inc"

// texture pour cheuveux blonds
#declare T_Hair_Blond = texture {
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
