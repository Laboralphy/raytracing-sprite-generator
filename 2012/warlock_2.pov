#include "inc/anim.inc"

// anim_walk 2
// anim_attack 0
// anim_explosion 3

#declare HatTexture = texture { 
	pigment { 
		color rgb <1, 0.666, 0.1> 
	}
}



#declare RobeTexture = texture {
	pigment {
		color rgb <0, 0.8, 1>
	}
}

#declare SkinColor = color rgb <1, 0.9, 0.75>;
#declare WandColor = color rgb <0, 0, 0>;

#declare FaceTexture = texture {
  pigment {
    image_map {
      png "textures/facebm.png"
      map_type 1
    }
  }
	finish {
		ambient 0.5
	}
}

#declare StepOffset = 0.25 * ANIM_FRAME;



#include "inc/warlock_hat.inc"

#include "inc/warlock.inc"

#include "inc/camera.inc"

