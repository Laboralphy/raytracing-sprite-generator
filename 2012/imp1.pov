#include "inc/clock.inc"
#include "inc/impanim.inc"

#declare BodyColor = pigment {
  color rgb <0, 0, 0>
}

#declare MaskColor = pigment {
  color rgb <1, 1, 1>
}


#include "inc/imp1.inc"

camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -10>
  color rgb <1, 1, 1>
}


object {
  Imp 
  rotate CameraAngle * y
  translate JumpHeight * y
  scale 0.9
  pigment { 
    BodyColor 
  }
}

disc {
  <0, 0, 0>
  y
  1.5
  pigment {
    ShadowDiscColor
  }
}

