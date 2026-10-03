#include "woods.inc"
#include "glass.inc"
#include "inc/body/BodyMetrics.inc"

#declare N_WandLength = N_Wrist_Len;
#declare N_Wand_Thickness = N_WandLength / 15;

#declare P_WandStick = cylinder {
	0
	<0, 0, -N_WandLength>
	N_Wand_Thickness
	texture {
		T_Wood22
	}
}

#declare P_WandGem = sphere {
	<0, 0, -N_WandLength>
	N_Wand_Thickness * 1.5
	texture {
		finish { F_Glass6 }
		pigment {
			Col_Glass_Ruby
		}
	}
}

/*
	Flash of a shot at the gem: V_Pose_Extra.y, when the pose sets it
	(0 = none, 1 = full). Used by the witch and the wizard.
*/
#local N_Wand_Flash = 0;
#ifdef (V_Pose_Extra)
	#local N_Wand_Flash = V_Pose_Extra.y;
#end

#declare P_BodyPart_ArmorPart_Weapon = union {
	object { P_WandStick }
	object { P_WandGem }
	#if (N_Wand_Flash > 0)
		sphere {
			<0, 0, -N_WandLength>, 0.28 * N_Wand_Flash
			texture {
				pigment { color rgbt <1, 0.3, 0.6, 0.3> }
				finish { ambient 1 diffuse 0 }
			}
		}
	#end
	translate <0, N_Arm_Thickness - N_Wand_Thickness, 0>
}

