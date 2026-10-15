#include "inc/clock.inc"


#declare BodyColor = color rgb <0, 0, 0>;
#declare EyeColor = color rgb <1, 0, 0>;
#declare StripeColor = color rgb <1, 1, 0>;
#declare WingColor = color rgbt <1, 1, 1, 0.5>;




#declare HeadToraxBase = lathe {
  linear_spline
  5
  <0, 0>
  <1, 1>
  <0.25, 1.75>
  <1, 3>
  <0, 4.5>
  pigment {
    BodyColor
  }
}


#declare Eye = sphere {
  <0, 0, 0>
  0.5
  pigment {
    EyeColor
  }
}

#declare HeadTorax = union {
  object { 
    HeadToraxBase 
  }
  object {
    Eye
    translate 0.75 * x + y
  }
  object {
    Eye
    translate -0.75 * x + y
  }
}


#declare Abdomen = lathe {
  linear_spline
  4
  <0, 0>
  <1, 1.75>
  <1, 2.25>
  <0, 4>
  texture {
    pigment {  
      checker 
      BodyColor
      StripeColor
    }
    scale <100, 0.5, 100>
    translate <-50, 0, -50>
  }
}



#declare LegTop = cone {
  <0, 0, 0>
  0.125
  <0, 1, 0>
  0
}

#declare LegBottom = cone {
  <0, 0, 0>
  0.125
  <0, -1, 0>
  0
}

#declare LegL = union {
  object {
    LegTop
    rotate 15 * x
  }
  object {
    LegBottom
    rotate -15 * x
  }
  rotate -90 * y
  pigment {
    BodyColor
  }
}

#declare LegR = union {
  object {
    LegTop
    rotate -15 * x
  }
  object {
    LegBottom
    rotate 15 * x
  }
  rotate -90 * y
  pigment {
    BodyColor
  }
}


#declare WingUp = triangle {
  <0, 0, 0>
  <-3, 3, 5>
  <-5, 1, 6>
  scale 0.75
}

#declare WingDown = triangle {
  <0, 0, 0>
  <-5, 1, 6>
  <-3, -1, 5>
  scale 0.75
}


#if (FrameIndex = 0)
  #declare WingR1 = WingUp;
#else
  #declare WingR1 = WingDown;
#end



#declare WingL1 = object {
  WingR1
  scale <-1, 1, 1>
}

#declare WingR2 = object {
  WingR1
  scale <0.6, 0.4, 0.75>
  rotate -45 * z
}

#declare WingL2 = object {
  WingR2
  scale <-1, 1, 1>
}


#declare Wings = union {
  object {
    WingR1
  }
  object {
    WingR2
  }
  object {
    WingL1
  }
  object {
    WingL2
  }
  pigment {
    WingColor
  }
}


#declare Wasp = union {
  object { 
    HeadTorax 
    rotate x * 90
    translate -3 * z
  }
  object {
    Abdomen
    rotate x * 120
    translate 1 * z
  }

  object {
    LegL
    translate <0.5, -1.5, 0>
  }
  object {
    LegL
    translate <0.5, -1.5, -0.5>
  }
  object {
    LegL
    translate <0.5, -1.5, 0.5>
  }

  object {
    LegR
    translate <-0.5, -1.5, 0>
  }
  object {
    LegR
    translate <-0.5, -1.5, -0.5>
  }
  object {
    LegR
    translate <-0.5, -1.5, 0.5>
  }

  object {
    Wings
    translate y
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
  Wasp
  scale 0.5
  translate 5 * y
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

