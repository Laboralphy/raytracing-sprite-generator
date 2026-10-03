/**
 *
 * @description Red Wizard, with ruby wand
 */
#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/frames/wizard.inc"

#declare WizardRobeTint = Red;

#include "inc/wizard/Wizard.inc"

object {
	O_Wizard_Posed
	rotate N_Animation_Angle * y
}
