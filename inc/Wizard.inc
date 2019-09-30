#include "inc/Head.inc"
#include "inc/WizardRobe.inc"
#include "inc/WizardHat.inc"
#include "inc/WizardWand.inc"
#include "inc/WizardTalisman.inc"

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

#declare P_WizardHandRight = sphere {
	<0, 0, 0>
	0.25
	texture {
		pigment {
			image_map {
				png "png/w_hand.png"
				map_type 1
			}
		}
	}
	rotate <0, 0, 45>
}

#declare P_WizardHandLeft = object {
	P_WizardHandRight
	scale <-1, 1, 1>
}

#declare P_WizardHandRightWand = union {
	object {
		P_WizardHandRight
	}
	object {
		O_Wand
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
	object {
		P_WizardHandLeft
		translate <1.1, 1.6, -1.05>
	}
	object {
		P_WizardHandRightWand
		translate <-1.1, 1.6, -1.05>
	}
	object {
		O_WizardTalisman
		scale 0.25
		rotate <90, 0, -20>
		translate <0, 1.6, -1.25>
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
	object {
		P_WizardHandLeft
		translate <1.1, 1.4, -1.05>
	}
	object {
		P_WizardHandRightWand
		translate <-1.1, 1.4, -1.05>
	}
	object {
		O_WizardTalisman
		scale 0.25
		rotate <90, 0, -20>
		translate <0, 1.45, -1.25>
	}
}
