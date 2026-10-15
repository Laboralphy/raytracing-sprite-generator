#include "inc/clock.inc"
#include "colors.inc"
#include "metals.inc"

#declare HatColor = color rgb <0, 0, 0>;
#include "inc/warlock_hat.inc"

camera {
  location <0, 4, -22>
  look_at <0, 4, 0>
}

light_source {
  <0, 4, -22>
  color rgb <1, 1, 1>
}



#declare PumpkinColor1 = color rgb <0.8, 0.4, 0>;
#declare PumpkinColor2 = color rgb <1, 0.5, 0>;



#declare HalfCylinder = difference {
  cylinder {
    <0, 0, 0>
    <0, 0, 1>
    1
  }
  box {
    <-2, 0, -1>
    <2, 2, 2>
  }
}

#declare Eye = difference {
  object {
    HalfCylinder
  }
  box {
    <-0.1, 1, -1>
    <0.1, -0.4, 2>
  }
}

#declare Eyes = union {
  object {
    Eye
    scale <1.3, 1.3, 1>
    rotate -25 * z
    translate -1.8 * x
  }
  object {
    Eye
    scale <1.3, 1.3, 1>
    rotate 25 * z
    translate 1.8 * x
  }
}

#declare MouthShape = difference {
  object {
    HalfCylinder
    scale <1, 0.666, 1>
  }
  object {
    HalfCylinder
    scale <1.4, 1, 2>
    translate <0, 0.7, -0.1>
  }
}

#declare Tooth = box { 
  <0, -0.5, -2>
  <0.5, 2, 2>
}

#declare Teeth = union {
  object {
    Tooth
    translate <0, 0, 0>
  }
  object {
    Tooth
    rotate 15 * z
    translate <2, 0, 0>
  }
  object {
    Tooth
    rotate -15 * z
    translate <-1.3, -2.5, 0>
  }
  object {
    Tooth
    rotate 10 * z
    translate <1.1, -2.8, 0>
  }
  object {
    Tooth
    rotate 10 * z
    translate <2.1, -2.8, 0>
  }
}

#declare Mouth = difference {
  object {
    MouthShape
    scale <3, 3, 1>
  }
  object {
    Teeth
    translate <-1, -0.7, 0>
  }
}


#declare FaceExtruder = union {
  object {
    Eyes
    translate 2 * y
  }
  object {
    Mouth
  }
  pigment {
    Yellow
  }
}



#declare HeadSphere = sphere {
  <0, 0, 0>
  2.5
  scale <1, 0.8, 1>
  texture {
    pigment {
      radial color_map {[0 PumpkinColor1][1 color PumpkinColor2]}
      frequency 20
    }
  }
}

#declare Head = union {
  difference {
    object {
      HeadSphere
    }
    object {
      FaceExtruder
      scale <0.5, 0.5, 4>
      translate <0, -0.3, -2.5>
    } 
  }
  sphere {
    <0, 0, 0>
    2
    scale <1, 0.8, 1>
    pigment {
      Yellow
    }
  }
}


#declare MantleUp = sphere {
  <0, 0, 0>
  1
  scale <2, 1, 1.5>
  pigment { color Black }
}

#declare MantleDown = cone {
  <0, 0, 0>
  2
  <0, -5, 0>
  3
  scale <1, 1, 0.75>
  pigment { color Black }
}

#declare Mantle = union {
  object {
    MantleUp
  }
  object {
    MantleDown
  }
}


#declare LampCellBase = box {
  <0, 0, 0>
  <1, 0.1, 1> 
}

#declare LampCellTige = box {
  <0, 0, 0>
  <0.1, 1, 0.1> 
}

#declare LampCellFrame = union {
  object {
    LampCellBase
  }
  object {
    LampCellBase
    translate 0.9 * y
  }
  object {
    LampCellTige
  }
  object {
    LampCellTige
    translate 0.9 * x
  }
  object {
    LampCellTige
    translate 0.9 * z
  }
  object {
    LampCellTige
    translate 0.9 * (x + z)
  }
}

#declare LampCell = union {
  object {
    LampCellFrame
    texture { T_Brass_1A }
  }
  box {
    <0.1, 0.1, 0.1>
    <0.9, 0.9, 0.9>
    pigment { 
      color rgb <1, 1, 1>
    }
  }
}

#declare LampBase = union {
  object {
    LampCell
  }
  object {
    LampCell
    translate x
  }
  object {
    LampCell
    translate z
  }
  object {
    LampCell
    translate x + z
  }

  object {
    LampCell
    translate y
  }
  object {
    LampCell
    translate y + x
  }
  object {
    LampCell
    translate y + z
  }
  object {
    LampCell
    translate y + x + z
  }
}

#declare LampTriangle = triangle {
  <0, 1, 0>
  <1, 0, 1>
  <1, 0, -1>
}

#declare LampTop = union {
  object {
    LampTriangle
  }
  object {
    LampTriangle
    rotate 90 * y
  }
  object {
    LampTriangle
    rotate 180 * y
  }
  object {
    LampTriangle
    rotate 270 * y
  }
}

#declare Lamp = union {
  object { 
    LampBase
    translate <-1, -3, 0>
  }
  object {
    LampTop
    translate <0, -1, 1>
    texture { T_Brass_1A }
  }
}

#declare Pumpkin = union {
  object {
    Head
    translate 8 * y
  }
  object {
    Hat
    scale 1.666
    translate <0, 9.333, 0.333>
  }
  object {
    Mantle
    translate 5.5 * y
  }
  object {
    Lamp
    rotate 20 * sin(radians(FrameIndex * 60)) * z
    translate <2, 6, -3>
  }
}






object {
  Pumpkin
  scale 0.6
  rotate CameraAngle * y
}

disc {
  <0, 0, 0>
  y
  2
  pigment {
    color ShadowDiscColor
  }
}

