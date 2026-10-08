/*
	Prop: the brazier, lit. See inc/props/Brazier.inc. Four frames of
	flickering flames (poses 0 to 3, sprites/brazier.json); the brazier
	out is p_brazier_out.pov.
*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/props/Brazier.inc"

object {
	O_Brazier
	rotate y * N_Animation_Angle
}
