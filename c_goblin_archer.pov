/*
             _     _ _
  __ _  ___ | |__ | (_)_ __
 / _` |/ _ \| '_ \| | | '_ \
| (_| | (_) | |_) | | | | | |
 \__, |\___/|_.__/|_|_|_| |_|
 |___/

Goblin archer: the goblin (inc/goblin/Goblin.inc) with a bow
(inc/weapons/Weapon_Bow.inc) instead of the short sword, the archer poses
(inc/frames/archer.inc), a quiver on the back (inc/weapons/Quiver.inc) and
a feathered hat (inc/armors/Hat_Feathered.inc) instead of a helm.

*/

#include "inc/Camera.inc"
#include "inc/frames/archer.inc"
#include "inc/goblin/Goblin.inc"

// no sword: the bow takes the left hand, the right hand draws
#undef P_BodyPart_ArmorPart_Weapon

#include "inc/weapons/Weapon_Bow.inc"

// quiver scaled down to the goblin
#declare N_Quiver_Len = 0.75;
#declare N_Quiver_Radius = 0.1;
#include "inc/weapons/Quiver.inc"

// quiver hung on the jerkin, on the back (+z), its mouth above the right shoulder
#declare P_BodyPart_ArmorPart_Chest = union {
	object {
		P_BodyPart_ArmorPart_Chest
	}
	object {
		O_Quiver
		rotate z * 35
		translate <0.22, 0.2, 0.28>
	}
}

// feathered hat, in the frame of the helm slot, in head sizes (as the
// ears): over the top of the head, the ears sticking out under the brim
#include "inc/armors/Hat_Feathered.inc"

#declare V_Goblin_Hat_Centre = <0, 1.42, 0.05>;

#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		O_Goblin_Ear
	}
	object {
		O_Goblin_Ear
		scale <-1, 1, 1>
	}
	object {
		O_Hat_Feathered
		scale 0.82
		rotate x * 6
		translate V_Goblin_Hat_Centre
		scale N_Head_Size
	}
}

#include "inc/body/BodyParts.inc"

object {
	O_BodyPart_Armored_Body_M
	rotate y * N_Animation_Angle
}
