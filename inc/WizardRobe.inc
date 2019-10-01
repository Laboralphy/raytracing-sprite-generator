#declare WizardRobeHeight = 2; /* initial height of the robe */
#declare WizardRobeHeightSmaller = 0.95;  /* the second version is smaller by a certain percentage */
#declare WizardRobeHeight_2 = WizardRobeHeight * WizardRobeHeightSmaller; /* initial height of the robe */
#declare WizardRobeMancheDeltaHeight = 1.55; /* diference between robe top and manche top */

#ifndef(WizardRobeTint)
	#declare WizardRobeTint = Cyan;
#end

#declare T_FabricWizardRobeRadial = texture {
	pigment {
		radial
		color_map {
			[0.5 WizardRobeTint]
			[0.5 WizardRobeTint * 0.85 ]
		}
		frequency 16
  	}
}

#declare T_FabricWizardRobePlain = texture {
	pigment {
		color WizardRobeTint
	}
}

#declare T_FabricWizardRobe = T_FabricWizardRobeRadial;

#declare P_WizardRobeGarb = object {
	sor {
		8
		<0, 0>
		<0.26, 0.04>
		<0.54, 0.21>
		<0.61, 0.54>
		<0.72, 0.83>
		<0.79, 0.91>
		<0.95, 0.99>
		<1, 1>
		sturm
	}
	scale <1, -1, 1>
	translate <0, 1, 0>
}


#declare P_WizardRobeGarb_2 = object {
	sor {
		8
		<0, 0>
		<0.26, 0.04>
		<0.54, 0.21>
		<0.61, 0.54>
		<0.72, 0.83>
		<0.82, 0.91>
		<1.10, 0.99>
		<1.30, 1>
		sturm
	}
	scale <1, -0.95, 1>
	translate <0, 0.95, 0>
}


#declare P_WizardRobeMancheLower = intersection {
	sphere {
		<0, 0, 0>
		1
		hollow
	}
	box {
		<-1, -1, 0>
		<1, 0, 1>
	}
	hollow
	scale <0.2, 0.7, 0.7>	
}

#declare P_WizardRobeMancheUpper = object {
	P_WizardRobeMancheLower
	scale <1, -0.25, 1>
	
}

#declare P_WizardRobeMancheFilled = union {
	object {
		P_WizardRobeMancheLower
	}
	object {
		P_WizardRobeMancheUpper
	}
}

#declare P_WizardRobeManche = difference {
	object {
		P_WizardRobeMancheFilled
	}
	object {
		P_WizardRobeMancheFilled
		translate -z * 0.3
	}
	scale 0.8
}








#declare O_WizardRobe = union {
	object {
		P_WizardRobeGarb
		texture { T_FabricWizardRobe }
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <0.6, 0.675, -0.6>
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <-0.6, 0.675, -0.6>
	}
	scale <1.75, 2.25, 1.75>
}

#declare O_WizardRobe_2 = union {
	object {
		P_WizardRobeGarb_2
		texture { T_FabricWizardRobe }
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <0.6, 0.65, -0.6>
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <-0.6, 0.65, -0.6>
	}
	scale <1.75, 2.25, 1.75>
}
