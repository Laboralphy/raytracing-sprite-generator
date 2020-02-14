#local N_Size = 1.5;
#include "textures"

#local OneHorn = sphere_sweep {
	cubic_spline
	7
	<0, -1, 0>, 1
	<0, 0, 0>, 1
	<-N_Size, 1, 0>, 0.8
	<0, 1.8, N_Size>, 0.6
	<N_Size, 2.4, 0>, 0.4
	<0, 3, -N_Size>, 0.2
	<0, 3.4, 0>, 0
	scale <0.06, 0.2, 0.06>
	texture {
		DMFWood5
	}
}

#declare P_BodyPart_ArmorPart_Helm = union {
	object { 
		OneHorn
		rotate <-10, 30, 0>
		translate <0, 0.6, 0>
	}
	object { 
		OneHorn
		rotate <5, 20, 17>
		translate <-0.25, 0.5, -0.2>
	}
	object { 
		OneHorn
		rotate <15, 70, 7>
		translate <0.25, 0.4, 0.1>
	}
}
