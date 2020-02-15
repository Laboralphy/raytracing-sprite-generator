#include "inc/hair/Cutter_Normal"

#declare P_Hair_Egg_Short_Curl = difference {
	sor {
		8
		<0.5, 0>
		<0.75, 0.125>
		<1, 0.5>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(85)), 1 + sin(radians(85))>
		<0, 2>
		open
		sturm
	}
	object {
		P_Cutter_Normal
	}
	scale 0.6
}
