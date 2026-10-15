#include "inc/clock.inc"
#include "finish.inc"

#declare SlimeColor = color rgb <0, 1, 0>;

#include "inc/slime.inc"



camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -10>
  color <1, 1, 1>
}




object {
  Slime
  translate (3.5 + 0.25 * sin(FrameIndex * pi / 4)) * y 
  rotate CameraAngle * y
}

disc {
  <0, 0, 0>
  y
  1.5
  pigment {
    ShadowDiscColor
  }
}
