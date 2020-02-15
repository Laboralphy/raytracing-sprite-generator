#include "golds.inc"

#declare P_WizardTalismanRing = torus {
	1
	0.1
}

#declare P_WizardTalismanPentacle = prism {
	linear_sweep
	linear_spline
	-0.1
	0.1
	6
	<1, 0>,
	<-0.809017,  0.587785>,
	<0.309017, -0.951057>,
	<0.309017, 0.951057>,
	<-0.809017, -0.587785>,
	<1, 0>
}

#declare P_WizardTalismanPentacleCenter = cylinder {
	<0, -0.1, 0>
	<0, 0.1, 0>
	0.375
}

#declare O_WizardTalisman = union {
	object {
		P_WizardTalismanRing
	}
	object {
		P_WizardTalismanPentacle
	}
	object {
		P_WizardTalismanPentacleCenter
	}
	texture {
		T_Gold_1A
	}
}



