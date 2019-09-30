#include "woods.inc"
#include "glass.inc"

#declare WandLength = 1;

#declare P_WandStick = cylinder {
	0
	<0, 0, -WandLength>
	0.07
	texture {
		T_Wood22
	}
}

#declare P_WandGem = sphere {
	<0, 0, -WandLength>
	0.12
	texture {
		finish { F_Glass6 }
		pigment {
			Col_Glass_Ruby
		}
	}
}

#declare O_Wand = union {
	object { P_WandStick }
	object { P_WandGem }
}
