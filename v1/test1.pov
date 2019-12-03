#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/Head.inc"
#include "inc/WizardRobe.inc"
#include "inc/WizardHat.inc"

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
	scale <-1, 0, 0>
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
		P_WizardHandRight
		translate <-1.1, 1.6, -1.05>
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
	O_Wizard
	rotate <0, 0, 0>
}
