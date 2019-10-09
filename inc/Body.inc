#include "inc/BodyParts.inc"

#ifndef(OffsetBody)
	#declare OffsetBody = 0;
#end

#declare Body = union {
	object {
		P_Legs
	}
	object {
		P_Torso
	}
	object {
		P_Arms
	}
	object {
		P_Neck
	}
	object {
		P_Head
	}
	sphere {
		V_BootBaseLeft, 2
		pigment { Red } 
	}
	sphere {
		V_BootBaseRight, 2
		pigment { Red } 
	}
	translate (OffsetBody + LegThickness + ThighLen + ShinLen) * y
	scale 0.3
}
