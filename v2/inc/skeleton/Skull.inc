#include "inc/MyShapes"


// lobe arrière
#local O_Skel_Skull_Part1 = ovus {
	1
	0.2
	scale <1, -1, 1>
	rotate <40, 0, 0>
	translate <0, 0.6, 0> 
	scale <1, 0.8, 1>
}

#local O_Skel_Skull_Jaw = union {
	object {
		CreateHalfPipe(0.2)
		scale <0.8, 1, -1>
	}
	object {
		CreateQuarterDisc()
		scale <1, 0.2, 0.5>
		rotate -z * 90
		translate <0.6, 1, 0>
	}
	object {
		CreateQuarterDisc()
		scale <1, 0.2, 0.5>
		rotate -z * 90
		translate <-0.8, 1, 0>
	}
	scale <1, 0.5, 1> * 0.7
	rotate <-10, 0, 0>
	translate <0, 0.3, -0.25>
}


#declare O_Skel_Skull = union {
	object {
		O_Skel_Skull_Jaw
		translate <0, -0.75, 0>
	}
	object {
		O_Skel_Skull_Part1
		translate <0, 0, -0.3>
	}
}
