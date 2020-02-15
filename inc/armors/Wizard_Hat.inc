#include "golds.inc"

#ifndef(T_WizardHatFabric)
	#declare T_WizardHatFabric = texture {
		pigment {
			color rgb <0.7, 0.3, 0.1>
		}
	}
#end

#declare T_FabricLeatherBlack = texture {
	pigment {
		color rgb <0.1, 0.1, 0.1>
	}
}

/* height is about 2.41 */
#declare P_WizardHatTop = sphere_sweep {
	linear_spline
	3
	<0, 0, 0>, 1
	<0.43, 1.59, 0> 0.45
	<1.26, 2.36> 0.05
	rotate <0, -45, 0>
}

#declare P_WizardHatBase = union {
	cone {
		<0, 0.1, 0>, 1.75
		<0, 0.5, 0>, 0
	}
	cylinder {
		<0, 0.0001, 0>
		<0, 0.1, 0>, 1.75
	}
}

#declare P_WizardHatBelt = intersection {
	cylinder {
		<0, 0.1, 0>
		<0, 0.7, 0>
		1.2
	}
	object { 
		P_WizardHatTop 
	}
	translate <0, -0.1, 0>
	scale 1.1
	translate <0, 0.1, 0>
}

#declare P_WizardHatBuckle = torus {
	0.3, 0.05
	rotate <-65, 0, 0>
	translate <0, 0.60, -0.975>
}

#declare P_WizardHatBaseTop = union {
	object {
		P_WizardHatTop
	}
	object {
		P_WizardHatBase
	}
}

#declare P_WizardHatBound = box {
	<-2, 0, -2>
	<2, 3, 2>
}

#declare P_WizardHat = intersection {
	object {
		P_WizardHatBaseTop
	}
	object {
		P_WizardHatBound
	}
}

#declare O_WizardHat = union {
	object {
		P_WizardHat
		texture { T_WizardHatFabric }
	}
	object {
		P_WizardHatBelt
		texture { T_FabricLeatherBlack }
	}
	object {
		P_WizardHatBuckle
		texture { T_Gold_1A }
	}
	scale 0.55
	rotate x * 20
	translate <0, 0.75, 0>
}
