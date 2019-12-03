/**
 * @frames 1
 *
 * @description Blue Wizard, with ruby wand
 */
#include "colors.inc"
#include "inc/Camera.inc"

#declare WizardRobeTint = color rgb <0, 0.4, 1>;

#include "inc/Wizard.inc"

#switch (AnimationFrame)
	#case (0)
		#declare TheWizard = O_Wizard;
	#break
	
	#case (1)
		#declare TheWizard = O_Wizard_2;
	#break
#end

object {
	TheWizard
	rotate AnimationAngle * y
}
