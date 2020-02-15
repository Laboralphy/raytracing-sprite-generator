#include "inc/hair/Cutter_Normal"

// Coiffure type oeuf long bouclé
#declare P_Hair_Egg_Long_Curl = difference {
	sor {
		9
		<1.9, -0.4>
		<1.3, -0.3>
		<1, 0.125>
		<1, 0.5>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(85)), 1 + sin(radians(85))>
		<0, 2>
		sturm
	}
	object {
		P_Hair_Cutter_Normal
	}
	scale 0.6
}
