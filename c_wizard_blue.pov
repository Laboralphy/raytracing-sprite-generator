/**
 *
 * @description Blue Wizard, with ruby wand
 */
#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/frames/wizard.inc"

#declare WizardRobeTint = color rgb <0, 0.4, 1>;

#include "inc/wizard/Wizard.inc"

object {
	O_Wizard_Posed
	rotate N_Animation_Angle * y
}
