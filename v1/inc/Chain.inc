#include "metals.inc"

#declare CHAIN_THICKNESS = 0.5;


#declare P_Chainon_1 = union {
	cylinder {
		<-1, -1, 0>
		<-1, 1, 0>
		CHAIN_THICKNESS
	}
	cylinder {
		<1, -1, 0>
		<1, 1, 0>
		CHAIN_THICKNESS
	}
}

#declare P_Chainon_2 = intersection {
	torus {
		1
		CHAIN_THICKNESS
		rotate <90, 0, 0>
	}
	box {
		<-2, 0, -2>
		<2, 4, 2>
	}
}

#declare P_ChainMaillon = union {
	object {
		P_Chainon_1
	}
	object {
		P_Chainon_2
		translate y
	}
	object {
		P_Chainon_2
		scale -y
		translate -y
	}
	texture {
		T_Chrome_3C
	}
	scale 0.4
	translate y * 1
}
