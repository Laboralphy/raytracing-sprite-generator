#include "inc/Head.inc"
#include "inc/WizardRobe.inc"
#include "inc/WizardHat.inc"
#include "inc/WizardWand.inc"
#include "inc/WizardTalisman.inc"
#include "inc/BodyParts.inc"

#declare P_WizardHead = union {
	object {
		O_WizardHatBrown
		scale 0.95
		rotate 15 * x
		translate 0.15 * y
	}
	object {
		O_BlackMageHead
	}
}


#declare O_Wizard = union {
	object {
		P_WizardHead
		translate 2.7 * y
	}
	object {
		O_WizardRobe
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		scale <0.4, 0.4, 0.3>
		translate <1.1, 1.5, -1.05>
	}
	object {
		P_Hand
		scale <-1, 1, 1>
		rotate <90, 0, 0>
		scale <0.4, 0.4, 0.3>
		translate <-1.1, 1.5, -1.05>
	}
	object {
		O_Wand
		translate <-1.1, 1.6, -1.05>
	}
	object {
		O_WizardTalisman
		scale 0.25
		rotate <100, 0, -20>
		translate <0, 1.6, -1>
	}	
}

#declare O_Wizard_2 = union {
	object {
		P_WizardHead
		translate 2.65 * y
	}
	object {
		O_WizardRobe_2
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		scale <0.4, 0.4, 0.3>
		translate <1.1, 1.45, -1.05>
	}
	object {
		P_Hand
		scale <-1, 1, 1>
		rotate <90, 0, 0>
		scale <0.4, 0.4, 0.3>
		translate <-1.1, 1.45, -1.05>
	}
	object {
		O_Wand
		translate <-1.1, 1.55, -1.05>
	}
	object {
		O_WizardTalisman
		scale 0.25
		rotate <100, 0, -20>
		translate <0, 1.55, -1>
	}
}
