#include "inc/wizard/Head.inc"
#include "inc/wizard/Robe.inc"
#include "inc/wizard/Hat.inc"
#include "inc/armors/Wand_Ruby_Sphere.inc"
#include "inc/wizard/Talisman.inc"
#include "inc/body/BodyParts.inc"

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

#declare P_Hand = object {
	O_BodyPart_Hand
	scale 1.5
	texture {
		pigment {
			color rgb 0.3
		}
	}
}
#declare O_Wand = object {
	P_BodyPart_ArmorPart_Weapon
	scale 1.25
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
		translate <1.1, 1.5, -1.05>
	}
	object {
		P_Hand
		scale <-1, 1, 1>
		rotate <90, 0, 0>
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
		translate <1.1, 1.45, -1.05>
	}
	object {
		P_Hand
		scale <-1, 1, 1>
		rotate <90, 0, 0>
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
