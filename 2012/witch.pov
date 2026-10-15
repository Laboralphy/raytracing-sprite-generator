/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/


// anim_walk 3
// anim_attack 0
// anim_explosion 3


#include "inc/anim.inc"

#declare SkirtTexture = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0, 0, 0.3>]
			[1 color rgb <0, 0, 1>]
		}
		frequency 20
	}
}

#declare HairTexture = texture {
	pigment {
		radial
		color_map {
			[0 color rgb <0.8, 0.5, 0.1>]
			[0.5 color rgb <0.5, 0.2, 0>]
			[1 color rgb <0.8, 0.5, 0.1>]
		}
		frequency 30
	}
}

#declare ShirtTexture = texture {
	pigment {
		color rgb <0, 0, 1>
	}
}

#declare LegTexture = texture {
	pigment {
		checker
		color rgb <1, 0.6, 0.5>
		color rgb <0, 0, 1>
		translate <-0.5, 0.2, 0.3>
	}
}

#declare ArmTexture = texture {
	pigment {
		color rgb <1, 0.6, 0.5>
	}
}

#declare HeadTexture = texture {
	pigment {
		image_map {
			png "textures/face_witch.png"
			map_type 1
			interpolate 4
		}
	}
}

#declare NeckTexture = texture {
	pigment {
		color rgb <1, 0.6, 0.5>
	}
}

#declare HatTexture = texture {
	pigment {
		color rgb <0, 0, 1>
	}
}

#include "inc/imp1.inc"
#include "inc/imp2.inc"
#include "inc/witch.inc"






#include "inc/camera.inc"
