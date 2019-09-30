#declare T_FabricRed = texture {
	pigment {
		color Red
	}
}

#declare T_FabricCyan = texture {
	pigment {
		color Cyan
	}
}

#declare T_FabricWizardRobe = T_FabricCyan;

/* main robe body */
#declare P_WizardRobeGarb = object {
	sor {
		7
		<0, 0>
		<0.26, 0.04>
		<0.54, 0.21>
		<0.61, 0.54>
		<0.72, 0.83>
		<0.79, 0.91>
		<1, 1>
		sturm
	}
	scale -1
	translate <0, 1, 0>
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

#declare P_WizardRobeGarb_2 = object {
	sor {
		7
		<0, 0>
		<0.26, 0.04>
		<0.54, 0.21>
		<0.61, 0.54>
		<0.72, 0.71>
		<0.89, 0.95>
		<1.15, 1>
		sturm
	}
	scale -0.95
	translate <0, 0.95, 0>
}

#declare O_WizardRobe = union {
	object {
		P_WizardRobeGarb
	}
	object {
		P_WizardRobeManche
		translate <0.6, 0.7, -0.6>
	}
	object {
		P_WizardRobeManche
		translate <-0.6, 0.7, -0.6>
	}
	texture { T_FabricWizardRobe }
}

#declare O_WizardRobe_2 = union {
	object {
		P_WizardRobeGarb_2
	}
	object {
		P_WizardRobeManche
		translate <0.6, 0.6, -0.6>
	}
	object {
		P_WizardRobeManche
		translate <-0.6, 0.6, -0.6>
	}
	texture { T_FabricWizardRobe }
}


