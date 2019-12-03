#include "woods.inc"
#include "inc/MetalCircle.inc"

#declare P_BarrelBody_1 = intersection {
	sphere {
		<0, 0, 0>
		1
		scale <0.8, 1.5, 0.8>
	}
	box {
		-1
		1
	}
	texture {
		T_Wood12
		scale <1, 10, 1>
	}
	texture {
		pigment {
			radial
			color_map {
				[0.05 rgbf <1, 1, 1, 1>]
				[0.90 rgbf <1, 1, 1, 1>]
				[0.92 rgbf <0, 0, 0, 0.8>]
				[0.95 rgbf <0, 0, 0, 0.8>]
			}
			frequency 16
		}		
	}
	translate y
}

#declare P_BarrelBouchon = cylinder {
	0
	z * 0.9
	0.1
	texture {
		T_Wood26
	}
}


#declare O_Barrel = union {
	object {
		P_BarrelBody_1
	}
	object {
		P_MetalCircle
		scale 0.62
	}
	object {
		P_MetalCircle
		scale 0.75
		translate 1.6 * y
	}
	object {
		P_MetalCircle
		scale 0.75
		translate 0.4 * y
	}
	object {
		P_MetalCircle
		scale 0.62
		translate 2 * y
	}
	object {
		P_BarrelBouchon
		rotate y * 140
		translate y
	}
	translate y * 0.05
}

