/**
 * @frames 1
 *
 * @description Red Wizard, with ruby wand
 */
#include "colors.inc"
#include "inc/Camera.inc"

#declare WizardRobeTint = Red;

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
