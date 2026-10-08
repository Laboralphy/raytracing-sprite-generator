/*
	Prop: the brazier, out (dark coals, dim embers, pokers). See
	inc/props/Brazier.inc. One frame (sprites/brazier_out.json).
*/

#include "colors.inc"
#include "inc/Camera.inc"
#declare N_Brazier_Lit = 0;
#include "inc/props/Brazier.inc"

object {
	O_Brazier
	rotate y * N_Animation_Angle
}
