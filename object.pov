/*


@frames 5

*/

#include "inc/Camera.inc"
#include "colors"
#include "metals"
#include "glass"


#local O_Lantern_Bottom = cone {
	0.5 * y, 0
	y, 1.5
}

#local O_Lantern_Glass = cone {
	y, 1
	4 * y, 1.5
}

#local O_Lantern_Top = cone {
	4 * y, 2
	5 * y, 0
}

#local O_Lantern_TopNotch = sphere {
	5 * y, 0.5
}

#local O_Lantern_Ring = torus {
	1, 0.2
	rotate x * 90
	translate 6 * y
}

#local C_LanternLight = color rgb <1, 0.7, 0>;
#local T_Lantern_Metal = T_Brass_1A;
#local T_OldGlass = texture {
	pigment {
		Col_Glass_General
	}
	finish {
		F_Glass4
	}
}

#local O_Lantern_MetallicParts = union {
	object {
		O_Lantern_Bottom
	}
	object {
		O_Lantern_Top
	}
	object {
		O_Lantern_TopNotch
	}
	object {
		O_Lantern_Ring
	}
	texture { 
		T_Lantern_Metal 
	}
}

#local O_Lantern_LightBulb = sphere {
	0, 0.3
	texture {
		pigment {
			C_LanternLight
		}
		finish {
			ambient 0.8
			diffuse 0.6
		}
	}
}

#declare O_Lantern = union {
	object {
		O_Lantern_MetallicParts
	}
	object {
		O_Lantern_Glass
		texture {
			T_OldGlass
		}
		interior {
			I_Glass_Caustics2
		}
	}
	light_source {
		2 * y
		color C_LanternLight
		looks_like {
			O_Lantern_LightBulb
		}
	}
	//translate <0, -7, 0>
}



#declare O_Object_1 = O_Lantern;

object {
	O_Object_1
	rotate y * N_Animation_Angle
}
