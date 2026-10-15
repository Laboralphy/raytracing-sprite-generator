#include "inc/clock.inc"

#declare FaceTexture = "textures/face2.png";
#declare ShirtColor1 = color rgb <0, 0, 0>;
#declare ShirtColor2 = color rgb <1, 0.75, 0.75>;

#include "inc/knife.inc"
#include "inc/bigface.inc"

camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -10>
  color rgb <1, 1, 1>
}


object {
  BigFace
  scale 0.8
  rotate CameraAngle * y
}

disc {
  <0, 0, 0>
  y
  1.5
  pigment {
    color ShadowDiscColor
  }
}

