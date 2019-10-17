#include "inc/BodyParts.inc"

#ifndef(OffsetBody)
	#declare OffsetBody = 0;
#end

#declare BodyF = union {
	
	object {
		P_Legs
	}
	object {
		P_TorsoF
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
	
	translate (LegThickness + ThighLen + ShinLen) * y
	scale 0.3
}


#declare BodyM = union {
	
	object {
		P_Legs
	}
	object {
		P_TorsoM
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
	
	translate (LegThickness + ThighLen + ShinLen) * y
	scale 0.3
}
