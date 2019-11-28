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

#declare P_BodyPart_ArmorPart_Weapon = union {
	object { P_WandStick }
	object { P_WandGem }
	translate <0, N_Arm_Thickness - N_Wand_Thickness, 0>
}

