#include "inc/clock.inc"
#include "inc/ravenanim.inc"


#declare BodyColor = color rgb <0, 0, 0>;

#declare BeakColor = color rgb <1, 1, 0.5>;

#declare EyeColor = pigment {
  color rgb <0.5, 0.5, 0.5>
}




#declare Belly = sphere {
  <0, 0, 0>
  1
  scale <1, 0.75, 1>
}

#declare Wing = cone {
  <0, 0, 0>
  1.25
  <0, 0.75, 0>
  0
}

#declare Wings = union {
  object {
    Wing
    translate <1.5, 0.25, 0.5>
  }
  object {
    Wing
    translate <-1.5, 0.25, 0.5>
  }
}

#declare Tail = object {
  cone {
    <0, 0, 0>
    0, 
    <0, -0.25, 2.25>
    0.25
  }
}

#declare Legs = union {
  cylinder {
    <0.33, 0, 0> 
    <0.33, -1.75, 0> 
    0.05
  }
  cylinder {
    <-0.33, 0, 0> 
    <-0.33, -1.75, 0> 
    0.05
  }
  disc {
    <0, -1.75, 0>
    y
    0.5
  }
}

#declare Body = union {
  object {
    Belly
  }
  object {
#if (FrameIndex = 0) 
    Legs
#else
    Wings
#end
  }
  object {
    Tail
    translate <0, -0.15, -0.15>
  }
  pigment {
    BodyColor
  }
}

#declare Eyeball = sphere {
  <0, 0, 0>
  0.5
}

#declare Eyes = union {
  object {
    Eyeball
    translate <-0.5, 0.2, -0.3>
  }
  object {
    Eyeball
    translate <0.5, 0.2, -0.3>
  }
}

#declare Beak = cone {
  <0, 0, 0>
  0.5
  <0, -2, 0>
  0
}

#declare Head = union {
  sphere {
    <0, 0, 0>
    1
    pigment {
      BodyColor
    }
  }
  object {
    Beak
    rotate 45 * x
    translate <0, -0.5, -0.5>
    pigment {
      BeakColor
    }
  }
  object {
    Eyes
    pigment {
      EyeColor
    }
  }
}




#declare Raven = union {
  object {
    Body
    translate <0, 1.75, 0.375>
  }
  object {
    Head
    translate <0, 3, -0.375>
  }
}

camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -10>
  color <1, 1, 1>
}


object {
  Raven
  rotate CameraAngle * y
  translate JumpHeight * y
}

disc {
  <0, 0, 0>
  y
  1.5
  pigment {
    color rgb <0.666, 0.666, 0.666>
  }
}
