#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/Head.inc"
#include "inc/WizardRobe.inc"
#include "inc/WizardHat.inc"



#declare CharacterHeight = 4;

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
		translate 2.8 * y
	}
	object {
		O_WizardRobe
		scale <1.75, 2.25, 1.75>
	}
}

#declare O_Wizard_2 = union {
	object {
		P_WizardHead
		translate 2.6 * y
	}
	object {
		O_WizardRobe_2
		scale <1.75, 2.25, 1.75>
	}
}


object {
	O_Wizard_2
	rotate <0, 0, 0>
}
