

#include "inc/MyShapes"
#include "colors"
#include "inc/body/BodyParts"
#include "inc/jack/Lantern"

#declare WizardRobeTint = color rgb 0.05;
#declare T_WizardHatFabric = texture {
	pigment {
		color rgb <0.05, 0.05, 0.05>
	}
}

#include "inc/wizard/Robe"
#include "inc/wizard/Hat"



#local P_Hand = object {
	O_BodyPart_Hand
	scale 1.5
	texture {
		pigment {
			color rgb 0.2
		}
	}
}


#local PumpkinHead = torus {
	1
	1.666
	texture {
		pigment {
			radial
			color_map {
				[0 Orange]
				[1 Red * 0.3]
			}
			frequency 16
		}
		rotate y * 10
	}
}

#local PumpkinHead_Inner = torus {
	1
	1.444
	texture {
		pigment {
			color rgb <1, 1, 0>
		}
	}
}

#local O_Razor_0 = box {
	<-10, 0, 0>
	<10, -20, 20>
	rotate x * 45
	scale <1, 1, 0.5>
}

#local O_Razor_1 = union {
	object {
		O_Razor_0
		translate <0, 0.8, 0>
	}
	object {
		O_Razor_0
		rotate y * 30
		translate <0, 0.9, 0>
	}
	object {
		O_Razor_0
		rotate y * 75
		translate <0, 0.8, 0>
	}
	object {
		O_Razor_0
		rotate y * 100
		translate <0, 0.9, 0>
	}
	object {
		O_Razor_0
		rotate y * 133
		translate <0, 0.8, 0>
	}
	scale 0.5
}

#local O_Razor_2_1 = union {
	object {
		O_Razor_1
	}
	object {
		O_Razor_1
		rotate <0, 39, 0>
	}
	object {
		P_WizardRobeGarb
		scale 0.99
	}
}

#local O_Razor_2_2 = union {
	object {
		O_Razor_1
	}
	object {
		O_Razor_1
		rotate <0, 39, 0>
	}
	object {
		P_WizardRobeGarb_2
		scale 0.99
	}
}

#local Ripped_Wizard_Robe = union {
	difference {	
		object {
			P_WizardRobeGarb
			scale <1, 1.5, 1>
			texture { T_FabricWizardRobe }
		}
		object {
			O_Razor_2_1
			translate <0, -0.225, 0>
		}
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <0.6, 1.2, -0.6>
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <-0.6, 1.2, -0.6>
	}
	scale <1.75, 2.25, 1.75>
}

#local Ripped_Wizard_Robe_15 = union {
	difference {	
		object {
			P_WizardRobeGarb_2
			scale <0.98, 1.55, 0.98>
			texture { T_FabricWizardRobe }
		}
		object {
			O_Razor_2_1
			translate <0, -0.225, 0>
		}
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <0.6, 1.15, -0.6>
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <-0.6, 1.15, -0.6>
	}
	scale <1.75, 2.25, 1.75>
}

#local Ripped_Wizard_Robe_2 = union {
	difference {	
		object {
			P_WizardRobeGarb_2
			scale <1, 1.5, 1>
			texture { T_FabricWizardRobe }
		}
		object {
			O_Razor_2_2
			translate <0, -0.225, 0>
		}
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <0.6, 1.1, -0.6>
	}
	object {
		P_WizardRobeManche
		texture { T_FabricWizardRobe }
		translate <-0.6, 1.1, -0.6>
	}
	scale <1.75, 2.25, 1.75>
}

#local Pumpkin_Face_Digger0 = box {
	<-1, 1, 1>
	<1, -1, -2>
	rotate 45 * z
	scale <0.66, 1.3, 1.3>
}

#local Pumpkin_Face_Digger1 = union {
	cylinder {
		<0, 0, 1>
		<0, 0, -2>
		1.5
	}
	object {
		Pumpkin_Face_Digger0
		rotate 8 * z
	}
	object {
		Pumpkin_Face_Digger0
		scale <1, 0.92, 1>
		rotate -8 * z
	}
	object {
		Pumpkin_Face_Digger0
		scale <1, 0.95, 1>
		rotate 24 * z
	}
	object {
		Pumpkin_Face_Digger0
		scale <1, 0.95, 1>
		rotate -24 * z
	}
	translate y
}

#local Pumpkin_Face_1 = difference {
	cylinder {
		<0, 0, 0>
		<0, 0, -1>
		1
	}
	object {
		Pumpkin_Face_Digger1
	}
}

#local Pumpkin_Nose_1 = prism {
	linear_spline
	-1, 0, 4,
	<-1, 0>, <-1, 1>, <-1.6, 0>, <-1, 0>
	scale 0.4
	rotate <90, 0, 180>
	translate <-0.3, -0.3, 0>
}

#local Pumpkin_Eye_1 = cylinder {
	<0, 0, 0>
	<0, 0, -1>
	0.444
	scale <1, 0.5, 1>
	rotate -15 * z
	translate <-0.6, 0.4, 0>
}

#local Pumpkin_Face_2 = union {
	object {
		Pumpkin_Face_1
	}
	object {
		Pumpkin_Nose_1
	}
	object {
		Pumpkin_Nose_1
		scale <-1, 1, 1>
	}
	object {
		Pumpkin_Eye_1
	}
	object {
		Pumpkin_Eye_1
		scale <-1, 1, 1>
	}
	texture {
		pigment {
			color rgb <0.8, 0.8, 0>
		}
	}
}

#local Pumpkin_Head_2 = difference {
	object {
		PumpkinHead
		scale 0.4
	}
	object {
		Pumpkin_Face_2
		scale <0.55, 0.55, 10>
	}
}

#local Pumpkin_Head_3 = union {
	object {
		Pumpkin_Head_2
	}
	object {
		PumpkinHead_Inner
		scale 0.4
	}
	object {
		O_WizardHatBrown
		scale 0.8
		rotate x * 5
		translate <0, 0.5, 0>
	}
}

#declare O_JackOLantern = union {
	object {
		Pumpkin_Head_3
		translate <0, 3.9, 0>
	}
	object {
		Ripped_Wizard_Robe
	}
	object {
		P_Hand
		rotate <90, 0, 80>
		translate <1, 2.7, -1>
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		translate <1, 2.7, -1>
		scale <-1, 0, 0>
	}
	object {
		O_Lantern
		scale 0.2
		translate <1, 2.75, -1.2>
	}
	scale 0.8
}

#declare O_JackOLantern_15 = union {
	object {
		Pumpkin_Head_3
		translate <0, 3.8, 0>
	}
	object {
		Ripped_Wizard_Robe_15
	}
	object {
		P_Hand
		rotate <90, 0, 80>
		translate <1, 2.6, -1>
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		translate <1, 2.6, -1>
		scale <-1, 0, 0>
	}
	object {
		O_Lantern
		scale 0.2
		translate <1, 2.65, -1.2>
	}
	scale 0.8
}

#declare O_JackOLantern_2 = union {
	object {
		Pumpkin_Head_3
		translate <0, 3.7, 0>
	}
	object {
		Ripped_Wizard_Robe_2
	}
	object {
		P_Hand
		rotate <90, 0, 80>
		translate <1, 2.5, -1>
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		translate <1, 2.5, -1>
		scale <-1, 0, 0>
	}
	object {
		O_Lantern
		scale 0.2
		translate <1, 2.55, -1.2>
	}
	scale 0.8
}
