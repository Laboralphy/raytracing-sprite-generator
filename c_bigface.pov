/*
 ____  _       _____
| __ )(_) __ _|  ___|_ _  ___ ___
|  _ \| |/ _` | |_ / _` |/ __/ _ \
| |_) | | (_| |  _| (_| | (_|  __/
|____/|_|\__, |_|  \__,_|\___\___|
         |___/

	Bigface of 2012 (2012/bigface.pov). See inc/bigface/BigFace.inc.
*/
#declare S_BigFace_Face = "png/bigface_face.png";
#declare C_BigFace_Shirt_1 = color rgb <0, 0, 0>;
#declare C_BigFace_Shirt_2 = color rgb <1, 1, 1>;

#include "inc/Camera.inc"
#include "inc/frames/bigface.inc"
#include "inc/bigface/BigFace.inc"

object {
	O_BigFace_Posed
	rotate y * N_Animation_Angle
}
