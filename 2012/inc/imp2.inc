// requires "imp1.inc"
////////////////////////////////////////////


#declare ChestF = lathe {
  linear_spline
  4
  <0, 0.5> 
  <1, 0>
  <0.5, 1.25>
  <0.666, 2>
}

#declare ArmF = object {
  Arm
  scale <0.75, 1.15, 0.75>
}

#declare Breasts2 = object {
  intersection {
    sphere {
      <0, 0, 0>
      1
      scale <0.7, 0.6, 0.88>
    }
    sphere {
      <0, 0, -0.75>
      1.5
    }
  }
}

#declare Breasts = blob {
  threshold 0.333

  sphere { 
    <0, 0, 0>
    1
    1
  }

  sphere {
    <0.3, 0, -0.4>
    0.5
    1
  }

  sphere {
    <-0.3, 0, -0.4>
    0.5
    1
  }

}

#declare ImpBodyF = union {
  object {
    ChestF
    scale 0.666 * y
    translate 1.5 * y
  }  
  object {
    Breasts
    translate 3.0 * y
  }
  object {
    Leg
    rotate LegRotation * x
    translate <-0.375, 1.75, 0>
  }
  object {
    Leg
    rotate (0 - LegRotation) * x
    translate <0.375, 1.75, 0>
  }
  /* 
  Arm angle : 90 -o-
             135 /o\
              45 \o/
  */
  object {
    ArmF
    rotate <0, 0, -135>
    translate <0.5, 3.0, 0>
  }
  object {
    ArmF
    rotate <0, 0, 135>
    translate <-0.5, 3.0, 0>
  }
  pigment {
    BodyColor
  }
}

#declare HeadF = union {
  object { 
    HeadBase
  }
  object {
    HeadTop
  }
  object {
    Horn
    rotate -90 * y
    scale <2.5, 2, 4>
    translate <0, 1.25, 0>
  }
  object {
    Horn
    rotate <0, 90, 90>
    scale <1, 1.15, 4>
    translate <1, 1.5, 0>
  }
}

#declare MaskedHeadF = union {
  object {
    HeadF
    pigment {
      BodyColor
    }
  }
  object {
    Mask
    translate <0, 0.15, -0.5>
    pigment {
      MaskColor
    }
  }
}


#declare ImpF = union {
  object {
    ImpBodyF
    scale 0.95 * y
  }
  object {
    MaskedHeadF
    translate 4.75 * y
  }
}

