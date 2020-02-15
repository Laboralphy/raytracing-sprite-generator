#include "colors.inc"
#include "inc/Animation.inc"
#declare M_Camera_Height = 3;
#declare M_Camera_Distance = 20;


#if(MODE_DEV = 1)
#declare M_Camera_Height = 0;
	camera {
		orthographic
		location <0, M_Camera_Height, -M_Camera_Distance>
		look_at  <0, M_Camera_Height,  0>
		right x * 1.333333
		up y
		direction z
		angle 45
	}

	box { 
		<-10, 0, 0> 
		<10, -10, 20>
		texture {
			pigment {
				White
			}
		}
	}

	background { color rgb 0.3 }

	plane {
		z
		10
		pigment {
			checker
			pigment { Gray10 }
			pigment { Gray30 }
		}
	}
#else
	camera {
		location <0, M_Camera_Height, -M_Camera_Distance>
		look_at  <0, M_Camera_Height,  0>
		right x * 1.333333
		up y
		direction z
		angle 25
	}
#end

light_source { 
	<2, 4, -M_Camera_Distance> color White
}
