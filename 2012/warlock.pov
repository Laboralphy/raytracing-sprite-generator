#include "inc/clock.inc"



#declare HatColor = color rgb <1, 0.666, 0.1>;
#declare RobeColor = color rgb <1, 0.2, 0>;
#declare SkinColor = color rgb <1, 0.9, 0.75>;
#declare WandColor = color rgb <0, 0, 0>;
#declare FaceTexture = "textures/facebm.png"

#declare StepOffset = 0.25 * FrameIndex;



#include "inc/warlock_hat.inc"


#declare Robe1 = sphere {
  <0, 0, 0>
  1
  scale <1.25, 0.75, 1.25>
}

#declare Robe2 = lathe {
  quadratic_spline
  6
  <0, 2>
  <1.25, 2>
  <1.25, 1>
  <1.5, 0.5>
  <2, 0.25>
  <2, 0>
}

#declare Robe3 = lathe {
  quadratic_spline
  6
  <0, 2>
  <1.25, 2>
  <1.25, 1>
  <1.5, 0.5>
  <1.85, 0>
  <1.9, -0.25>
}


#if (FrameIndex)
#declare Robe = union {
  object {
    Robe1
    translate 2 * y
  }
  object {
    Robe3
  }
  pigment {
    RobeColor
  } 
}
#else
#declare Robe = union {
  object {
    Robe1
    translate 2 * y
  }
  object {
    Robe2
  }
  pigment {
    RobeColor
  } 
}
#end



#declare Head = sphere {
  <0, 0, 0>
  1
  pigment {
    image_map {
      png FaceTexture
      map_type 1
    }
    
  }
  scale 1.25
  translate 3 * y
}


#declare Hand = sphere {
  <0, 0, 0>
  0.375
  pigment {
    SkinColor
  }
}

#declare Wand = cylinder {
  <0, 0, 0>
  <0, 0, -1.5>
  0.066
}

#declare Hands = union {
  object {
    Hand
    translate x
  }
  object {
    Hand
    translate -x
  }
  object {
    Wand
    translate -x
  }
}


#declare Warlock = union {
  object {
    Robe
    translate StepOffset * y
  }
  object {
    Head
    translate StepOffset * y
  }
  object {
    Hat
    translate (3.5 + StepOffset) * y
  }
  object {
    Hands
    translate <0, 1.66 + StepOffset, -1>
  }
}












camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -25>
  color <1, 1, 1>
}


object {
  Warlock
  rotate CameraAngle * y
}

