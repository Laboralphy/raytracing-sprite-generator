/*
	Prop: wooden armillary sphere. See inc/props/Armillary_Sphere.inc. One
	frame, seen from a three-quarter view slightly from above
	(sprites/armillary_sphere.json).
*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/props/Armillary_Sphere.inc"

object {
	O_Armillary_Sphere
	rotate y * N_Animation_Angle
}
