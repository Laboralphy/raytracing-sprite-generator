/*
 _             _
| | __ _ _ __ | |_ ___ _ __ _ __
| |/ _` | '_ \| __/ _ \ '__| '_ \
| | (_| | | | | ||  __/ |  | | | |
|_|\__,_|_| |_|\__\___|_|  |_| |_|

	Brass lantern with a lit flame, standing on y = 0, ring on top.
	N_Lantern_Hook: height of the inside top of the ring, where it hangs.
	(Formerly object.pov.)
*/

#include "colors.inc"
#include "metals.inc"
#include "glass.inc"

#declare N_Lantern_Hook = 6.8;

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
}
