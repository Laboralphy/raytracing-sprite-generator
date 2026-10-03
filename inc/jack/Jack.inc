

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

/*
	The ripped robe, in 3 shapes (index 0 to 2) that make it ripple. The
	sleeves are apart, they move with the arms.
*/
#local A_Jack_Robe = array[3] {
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
		scale <1.75, 2.25, 1.75>
	},
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
		scale <1.75, 2.25, 1.75>
	},
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
		scale <1.75, 2.25, 1.75>
	}
}

/* height of the sleeves (before the robe scale) and rise of the head and the hands, per robe shape */
#local A_Jack_Sleeve_Height = array[3] { 1.1, 1.15, 1.2 }
#local A_Jack_Rise = array[3] { 0, 0.1, 0.2 }

#local O_Jack_Sleeve = object {
	P_WizardRobeManche
	texture { T_FabricWizardRobe }
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

/*
   _            _    
  (_) __ _  ___| | __
  | |/ _` |/ __| |/ /
  | | (_| | (__|   < 
 _/ |\__,_|\___|_|\_\
|__/                 

	Assembly, driven by the pose (inc/frames/jack.inc, through inc/Pose.inc):
		AV_Arm_Left    lantern arm (sleeve, hand, lantern), around the shoulder; x > 0 = forward
		AV_Arm_Right   other arm
		AV_Head        pumpkin, around its centre
		AV_Body        whole body, around the ground point
		V_Body_Offset  whole body translation (floating)
		V_Pose_Extra   x: collapse of the robe (0 = standing, 1 = empty robe on the ground)
		               y: flame (0 = normal, 1 = out, < 0 = blazing), see inc/jack/Lantern.inc
		               z: robe shape, 0 to 2
	Distances before the final scale 0.8.
*/

/* rotation around a pivot, only when there is one (keeps the unposed render exact) */
#macro Jack_Rotate_Around(V_Angles, V_Pivot)
	#if (vlength(V_Angles) > 0)
		translate -V_Pivot
		rotate V_Angles
		translate V_Pivot
	#end
#end

#local N_Robe = min(2, max(0, int(V_Pose_Extra.z + 0.5)));
#local N_Rise = A_Jack_Rise[N_Robe];
#local N_Collapse = V_Pose_Extra.x;
#local V_Shoulder = <1.05, 3.0 + N_Rise, -0.8>;
#local V_Lantern_Hand = <1, 2.55 + N_Rise, -1.2>;

#local O_Jack_Arm_Left = union {
	object {
		O_Jack_Sleeve
		translate <0.6, A_Jack_Sleeve_Height[N_Robe], -0.6>
		scale <1.75, 2.25, 1.75>
	}
	object {
		P_Hand
		rotate <90, 0, 80>
		translate <1, 2.5 + N_Rise, -1>
	}
	#if (N_Collapse = 0)
		object {
			O_Lantern
			scale 0.2
			translate V_Lantern_Hand
		}
	#end
	Jack_Rotate_Around(AV_Arm_Left, V_Shoulder)
}

#local O_Jack_Arm_Right = union {
	object {
		O_Jack_Sleeve
		translate <-0.6, A_Jack_Sleeve_Height[N_Robe], -0.6>
		scale <1.75, 2.25, 1.75>
	}
	object {
		P_Hand
		rotate <90, 0, 0>
		translate <1, 2.5 + N_Rise, -1>
		scale <-1, 1, 1>
	}
	Jack_Rotate_Around(AV_Arm_Right, V_Shoulder * <-1, 1, 1>)
}

#declare O_JackOLantern_Posed = union {
	object {
		Pumpkin_Head_3
		#if (vlength(AV_Head) > 0)
			rotate AV_Head
		#end
		translate <0, 3.7 + N_Rise, 0>
		#if (N_Collapse > 0)
			// falls to the ground, in front of the robe
			translate <0.7, 0.75 - (3.7 + N_Rise), -1.3> * N_Collapse
		#end
	}
	object {
		A_Jack_Robe[N_Robe]
		#if (N_Collapse > 0)
			scale <1 + 0.25 * N_Collapse, 1 - 0.88 * N_Collapse, 1 + 0.25 * N_Collapse>
		#end
	}
	union {
		object { O_Jack_Arm_Left }
		object { O_Jack_Arm_Right }
		#if (N_Collapse > 0)
			translate -y * 2.4 * N_Collapse
		#end
	}
	#if (N_Collapse > 0)
		// the lantern drops and tips over, in front of the robe
		object {
			O_Lantern
			scale 0.2
			rotate z * 90 * N_Collapse
			translate V_Lantern_Hand + (<-0.9, 0.3, -1.8> - V_Lantern_Hand) * N_Collapse
		}
	#end
	scale 0.8
	#if (vlength(AV_Body) > 0)
		rotate AV_Body
	#end
	translate V_Body_Offset
}
