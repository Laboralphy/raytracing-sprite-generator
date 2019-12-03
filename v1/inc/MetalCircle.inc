/*
 Metal circle with rivets used for barrels
 */


#include "metals.inc"


#declare P_MetalCircleRing = difference {
	cylinder {
		<0, -0.1, 0>
		<0, 0.1, 0>
		1
	}
	cylinder {
		<0, -1, 0>
		<0, 1, 0>
		0.9
	}
	texture {
		T_Chrome_1B
	}
}

#declare P_MetalCircleRivet = sphere {
	<0, 0, 0>
	0.06
	scale <1, 1, 0.5>
	texture {
		T_Chrome_1D
	}
}

#declare RivetAngle = 15;

#declare P_MetalCircle = union {
	object {
		P_MetalCircleRing
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 1, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 2, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 3, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 4, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 5, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 6, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 7, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 8, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 9, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 10, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 11, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 12, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 13, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 14, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 15, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 16, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 17, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 18, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 19, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 20, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 21, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 22, 0>
	}
	object {
		P_MetalCircleRivet
		translate <0, 0, -1>
		rotate <0, RivetAngle * 23, 0>
	}
}
