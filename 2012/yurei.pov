/****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ******/
/****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ******/
/****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ****** YUREI 2 ******/


// anim_walk 1
// anim_attack 0
// anim_explosion 3


#include "inc/anim.inc"

#declare LowerTexture = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0.6, 0.6, 0.6>]
			[1 color rgb <1, 1, 1>]
		}
		frequency 20
	}
}

#declare HairTexture = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0.4, 0.6, 0.7>]
			[0.5 color rgb <0, 0, 0>]
			[1 color rgb <0.4, 0.6, 0.7>]
		}
		frequency 30
	}
}

#declare ShirtTexture = texture {
	pigment {
		color rgb <0.9, 0.9, 0.9>
	}
}


#declare ArmTexture = texture {
	pigment {
		color rgb <1, 1, 1>
	}
}

#declare HeadTexture = texture {
	pigment {
		image_map {
			png "textures/face_yurei4.png"
			map_type 1
			interpolate 4
		}
	}
	scale <0.5, 0.5, 0.5>
}

#declare NeckTexture = texture {
	pigment {
		color rgb <1, 1, 1>
	}
}

#include "inc/imp1.inc"
#include "inc/yurei/head.inc"
#include "inc/yurei/face_longhair2.inc"
#include "inc/yurei/lower_robe2.inc"
#include "inc/yurei/base.inc"


#include "inc/camera.inc"
