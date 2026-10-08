/*
	Prop: antique refracting telescope on its tripod. See
	inc/props/Telescope.inc. One frame, seen from a three-quarter view
	slightly from above (sprites/telescope.json).
*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/props/Telescope.inc"

object {
	O_Telescope
	rotate y * N_Animation_Angle
}
