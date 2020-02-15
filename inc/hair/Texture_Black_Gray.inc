#include "colors.inc"

// texture pour cheuveux blonds
#declare T_Hair_Black_Gray = texture {
	pigment {
		radial
		color_map {
			[0 Black]
			[0.5 Black]
			[0.7 Gray15]
			[0.6 Gray05 ]
			[1 Black]
		}
		frequency 32		
  	}
  	rotate <0, 0, 0>
}
