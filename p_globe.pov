/*
	Prop: old wooden globe. See inc/props/Globe.inc. One frame, seen from a
	three-quarter view slightly from above (sprites/globe.json).
*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/props/Globe.inc"

object {
	O_Globe
	rotate y * N_Animation_Angle
}
