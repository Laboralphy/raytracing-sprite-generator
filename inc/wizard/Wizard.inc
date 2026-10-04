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
			#if (N_Wizard_Fade > 0)
				// dying: fades out with the head (inc/wizard/Head.inc)
				color rgbt <0.3, 0.3, 0.3, N_Wizard_Fade>
			#else
				color rgb 0.3
			#end
		}
	}
}
#declare O_Wand = object {
	P_BodyPart_ArmorPart_Weapon
	scale 1.25
}


/*
          _                  _ 
__      _(_)______ _ _ __ __| |
\ \ /\ / / |_  / _` | '__/ _` |
 \ V  V /| |/ / (_| | | | (_| |
  \_/\_/ |_/___\__,_|_|  \__,_|

	Assembly, driven by the pose (inc/frames/wizard.inc, through inc/Pose.inc):
		AV_Arm_Right   wand arm (sleeve, hand, wand), around the shoulder; x > 0 = forward
		AV_Arm_Left    other arm
		AV_Head        head and hat, around the neck
		AV_Body        whole body, around the ground point
		V_Body_Offset  whole body translation
		V_Pose_Extra   x: death (0 = standing, 1 = empty robe on the ground): the head and the
		                  hands fade out in the first half, the robe sinks, the hat falls
		                  on it, the wand drops in front
		               y: flash of a shot at the tip of the wand (0 = none, 1 = full)
		               z: robe shape, from 0 to 1: the 2 surfaces of revolution of the robe
		                  (P_WizardRobeGarb, P_WizardRobeGarb_2) are morphed point by point,
		                  and the sleeves, the head and the hands follow its height (walking)
	Distances before the final scale 0.8.
*/

#ifndef (V_Pose_Extra)
	#declare V_Pose_Extra = <0, 0, 0>;
#end

/*
	The robe without its sleeves, morphed between its 2 shapes by N_Shape
	(0 = P_WizardRobeGarb, 1 = P_WizardRobeGarb_2, see inc/wizard/Robe.inc:
	same 8 points, but the second is wider at the bottom and 5% shorter).
	The pure shapes use the original objects.
*/
#macro Wizard_Robe_Garb(N_Shape)
	#if (N_Shape = 0)
		object { P_WizardRobeGarb }
	#elseif (N_Shape = 1)
		object { P_WizardRobeGarb_2 }
	#else
		#local A_Shape_1 = array[8] { <0, 0>, <0.26, 0.04>, <0.54, 0.21>, <0.61, 0.54>, <0.72, 0.83>, <0.79, 0.91>, <0.95, 0.99>, <1, 1> }
		#local A_Shape_2 = array[8] { <0, 0>, <0.26, 0.04>, <0.54, 0.21>, <0.61, 0.54>, <0.72, 0.83>, <0.82, 0.91>, <1, 0.99>, <1.1, 1> }
		#local N_Height = 1 - 0.05 * N_Shape;
		sor {
			8
			#local I = 0;
			#while (I < 8)
				A_Shape_1[I] * (1 - N_Shape) + A_Shape_2[I] * N_Shape
				#local I = I + 1;
			#end
			sturm
			scale <1, -N_Height, 1>
			translate <0, N_Height, 0>
		}
	#end
#end

#local O_Wizard_Sleeve = object {
	P_WizardRobeManche
	texture { T_FabricWizardRobe }
}

/* rotation around a pivot, only when there is one (keeps the unposed render exact) */
#macro Wizard_Rotate_Around(V_Angles, V_Pivot)
	#if (vlength(V_Angles) > 0)
		translate -V_Pivot
		rotate V_Angles
		translate V_Pivot
	#end
#end

#local N_Shape = min(1, max(0, V_Pose_Extra.z));
/* height of the sleeves (before the robe scale), and rise of the head, the hands, the wand and the talisman */
#local N_Sleeve_Height = 0.675 - 0.025 * N_Shape;
#local N_Rise = -0.05 * N_Shape;
#local N_Collapse = V_Pose_Extra.x;
#local V_Shoulder_Right = <-1.05, 1.8 + N_Rise, -0.7>;
#local V_Wand_Hand = <-1.1, 1.6 + N_Rise, -1.05>;

#local O_Wizard_Arm_Right = union {
	object {
		O_Wizard_Sleeve
		translate <-0.6, N_Sleeve_Height, -0.6>
		scale <1.75, 2.25, 1.75>
	}
	#if (N_Wizard_Fade < 1)
		object {
			P_Hand
			scale <-1, 1, 1>
			rotate <90, 0, 0>
			translate <-1.1, 1.5 + N_Rise, -1.05>
		}
	#end
	#if (N_Collapse = 0)
		object {
			O_Wand // its flash comes from V_Pose_Extra.y, see inc/armors/Wand_Ruby_Sphere.inc
			translate V_Wand_Hand
		}
	#end
	Wizard_Rotate_Around(AV_Arm_Right, V_Shoulder_Right)
}

#local O_Wizard_Arm_Left = union {
	object {
		O_Wizard_Sleeve
		translate <0.6, N_Sleeve_Height, -0.6>
		scale <1.75, 2.25, 1.75>
	}
	#if (N_Wizard_Fade < 1)
		object {
			P_Hand
			rotate <90, 0, 0>
			translate <1.1, 1.5 + N_Rise, -1.05>
		}
	#end
	Wizard_Rotate_Around(AV_Arm_Left, V_Shoulder_Right * <-1, 1, 1>)
}

#declare O_Wizard_Posed = union {
	#if (N_Collapse = 0)
		object {
			P_WizardHead
			#if (vlength(AV_Head) > 0)
				rotate AV_Head
			#end
			translate (2.7 + N_Rise) * y
		}
	#else
		/*
			Dying: the hat (and the fading head) come down with the top of the
			robe, and the hat ends up lying on it.
		*/
		#local N_Robe_Top_End = 2.25 * (1 - 0.05 * N_Shape) * (1 - 0.85);
		#local N_Head_Y = (2.7 + N_Rise) * (1 - N_Collapse) + (N_Robe_Top_End - 0.15) * N_Collapse;
		union {
			object {
				O_WizardHatBrown
				scale 0.95
				rotate 15 * x
				translate 0.15 * y
			}
			#if (N_Wizard_Fade < 1)
				object {
					O_BlackMageHead
				}
			#end
			#if (vlength(AV_Head) > 0)
				rotate AV_Head
			#end
			rotate z * 10 * N_Collapse
			translate N_Head_Y * y
		}
		// the wand drops in front of the robe
		object {
			O_Wand
			rotate y * 30 * N_Collapse
			translate V_Wand_Hand + (<-0.5, 0.12, -1.7> - V_Wand_Hand) * N_Collapse
		}
	#end
	object {
		Wizard_Robe_Garb(N_Shape)
		texture { T_FabricWizardRobe }
		scale <1.75, 2.25, 1.75>
		#if (N_Collapse > 0)
			scale <1 + 0.25 * N_Collapse, 1 - 0.85 * N_Collapse, 1 + 0.25 * N_Collapse>
		#end
	}
	union {
		object { O_Wizard_Arm_Right }
		object { O_Wizard_Arm_Left }
		object {
			O_WizardTalisman
			scale 0.25
			rotate <100, 0, -20>
			translate <0, 1.6 + N_Rise, -1>
		}
		#if (N_Collapse > 0)
			translate -y * 1.3 * N_Collapse
		#end
	}
	scale 0.8
	#if (vlength(AV_Body) > 0)
		rotate AV_Body
	#end
	translate V_Body_Offset
}
