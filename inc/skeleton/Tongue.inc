#include "finish"
#include "colors"

#local O_Tongue_Orig = sphere_sweep {
	cubic_spline
	6
	<0, cos(radians(0)), -sin(radians(0)) + 1>, 0.2
	<0, cos(radians(0)), -sin(radians(0))>, 0.16
	<0, cos(radians(30)), -sin(radians(30))>, 0.12
	<0, cos(radians(60)), -sin(radians(60))>, 0.08
	<0, cos(radians(90)), -sin(radians(90))>, 0.04
	<0, cos(radians(90)) - 1, -sin(radians(90))>, 0.3	
} 

#declare O_Tongue_Red = object {
	O_Tongue_Orig
	scale <0.8, 0.3, 0.1>
	translate <0, -0.55, -0.33>
	texture {
		pigment {
			color rgb <0.4, 0, 0>
		}
		finish {
			Phong_Shiny
		}
	}
} 
