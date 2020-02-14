/*


@frames 5

*/

#include "inc/Camera.inc"
#include "inc/MyShapes"


#declare N_Head_Size = 1;
#declare N_Skel_Skull_OrbitSize = 0.4;
#declare N_Skel_Skull_OrbitDist = 0.5;

// lobe arrière
#declare O_Skel_Skull_Part1 = ovus {
	1
	0.2
	scale <1, -1, 1>
	rotate <40, 0, 0>
	translate <0, 0.6, 0> 
	scale <1, 0.8, 1>
}

#declare O_Skel_Skull_Jaw = union {
	object {
		CreateHalfPipe(0.2)
		scale <1, 1, -1>
	}
	object {
		CreateQuarterDisc()
		scale <1, 0.2, 0.5>
		rotate -z * 90
		translate <0.8, 1, 0>
	}
	object {
		CreateQuarterDisc()
		scale <1, 0.2, 0.5>
		rotate -z * 90
		translate <-1, 1, 0>
	}
	scale <1, 0.5, 1> * 0.7
	rotate <-10, 0, 0>
	translate <0, 0.3, -0.25>
}


#declare O_Object_1 = union {
	object {
		O_Skel_Skull_Jaw
	}
	object {
		O_Skel_Skull_Part1
		translate <0, 0.75, -0.3>
	}
	texture {
		pigment {
			color rgb 0.8
		}
	}
	texture {
		pigment {
			image_map {
				png "png/skull_face.png"
				map_type 2
			}
		}
		scale <1, 2, 1>
		translate <0, 0.175, -0.25>
	}
}

object {
	O_Object_1
	rotate y * N_Animation_Angle
}
