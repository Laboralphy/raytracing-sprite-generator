// evil otto
#include "inc/clock.inc"

#declare OttoColor1 = color rgb <0.75, 0.75, 0.75>;
#declare OttoColor2 = color rgb <0.4, 0.4, 0.4>;
#declare OttoFireColor = color rgb <0, 0, 0>;



#switch (FrameIndex)
  #case (6)
    #declare OttoFireColor = color rgb <1, 1, 1>;
    #declare FrameIndex = 0;
  #break

  #case (7)
    #declare OttoFireColor = color rgb <1, 0.5, 0.5>;
    #declare FrameIndex = 0;
  #break

  #case (8)
    #declare OttoFireColor = color rgb <1, 0, 0>;
    #declare FrameIndex = 0;
  #break

  #case (9)
    #declare OttoFireColor = color rgb <0.5, 0, 0>;
    #declare FrameIndex = 0;
  #break
#end



#declare Eye1 = union {
  cylinder {
    <0, 0, 0>
    <0, 0, 1>
    1
  }
  box {
    <-1, 0, 0>
    <1, 1, 1>
  }
}

#declare EyeHider = union {
  cylinder {
    <0, 0, -1>
    <0, 0, 2>
    1
  }
  box {
    <0, 0, -1>
    <2, -2, 2>
  }
}

#declare EyeHalf = difference {
  object {
    Eye1
  }
  object {
    EyeHider
    translate y
  }
}

#declare EyeBlack = union {
  object {
    EyeHalf
  }
  object {
    EyeHalf
    rotate 180 * z
    translate -y
  }
}

#declare EyesBlack = union {
  object {
    EyeBlack
    translate -1.5 * x
  }
  object {
    EyeBlack
    rotate 180 * y
    translate <1.5, 0, 1>
  }
}

#declare Mouth = difference {
  cylinder {
    <0, 0, 0>
    <0, 0, 1>
    1
  }
  cylinder {
    <0, 0.5, -1>
    <0, 0.5, 2>
    1.1
  }
}

#declare EyesAndMouth = union {
  object {
    EyesBlack
    translate <0, 2, 0>
    scale <1, 1, 4>
  }
  object {
    Mouth
    scale <2, 2, 4>
  }

}

#declare Face = sphere {
  <0, 0, 0>
  1
  scale <3.5, 4, 3.5>
  pigment { 
    checker
      pigment {
        OttoColor1
      }
      pigment {
        OttoColor2
      }
    scale <10, 10, 10>
    translate 5 * y
  }
}

#declare Otto = difference {
  object {
    Face
  }
  object {
    EyesAndMouth
    translate <0, -0.6, -5>
    pigment {
	OttoFireColor      
    }
  }
  scale <0.5, 0.5, 0.5>
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
  Otto
  rotate CameraAngle * y
  translate (4 + (0.5 * sin(radians(FrameIndex * 30)))) * y
}

disc {
  <0, 0, 0>
  y
  1.5
  pigment {
    ShadowDiscColor
  }
}

