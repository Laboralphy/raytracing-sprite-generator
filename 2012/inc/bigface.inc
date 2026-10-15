// bigface.inc

#declare nStep = 0;

#ifndef (bAttack) 
  #declare bAttack = 0;
#end

#ifndef (bParry) 
  #declare bParry = 0;
#end

#switch (FrameIndex) 
  #case (0)
    #declare nStep = 0;
  #break

  #case (1)
    #declare nStep = 45;
  #break

  #case (2)
    #declare nStep = 90;
  #break

  #case (3)
    #declare nStep = 45;
  #break

  #case (4)
    #declare nStep = 0;
  #break

  #case (5)
    #declare nStep = -45;
  #break

  #case (6)
    #declare nStep = -90;
  #break

  #case (7)
    #declare nStep = -45;
  #break

  #case (8)
    #declare nStep = 0;
    #declare bAttack = 1;
  #break
#end


#declare BellyDown = sphere {
  <0, 0, 0>
  1.5
}

#declare BellyUp = cone {
  <0, 0, 0>
  1.6
  2 * y
  0.8
}

#declare Belly = union {
  object { 
    BellyDown 
    translate 1.75 * y
  }
  object { 
    BellyUp 
    translate 2 * y
    texture {
      pigment {  
        checker 
        color ShirtColor1
        color ShirtColor2
      }
      scale <100, 0.333, 100>
      translate <-50, 0, -50>
    }
  }
}

#declare FaceBase = sphere {
  <0, 0, 0>
  2
}















#declare Arm = sphere {
  <0, 0, 0>
  1
  scale <1, 0.333, 0.5>
}

#if (bParry) 

#declare ArmLeft = object {
  Arm
  rotate <0, -90, -20>
  translate <1.5, 0, -0.5>
}

#else

#declare ArmLeft = object {
  Arm
  rotate -20 * z
  translate 1.5 * x
}

#end


#if (bAttack)

#declare ArmRight = object {
  union {
    object {
      Arm
    }
    object {
      Knife
      rotate 90 * z
      translate <-1, 0, 0>
    }
  }
  rotate <0, -90, 20>
  translate <-1.5, 0, -0.5>
}

#else

#declare ArmRight = object {
  union {
    object {
      Arm
    }
    object {
      Knife
      translate <-0.75, 0.333, 0>
    }
  }
  rotate 20 * z
  translate -1.5 * x
}

#end

#declare Arms = union {
  object {
    ArmLeft
    rotate y * nStep * (1 - bParry) / 5
  }
  object {
    ArmRight
    rotate y * nStep / 5
  }
}

#declare Foot = intersection {
  sphere {
    <0, 0, 0>
    1
  }
  box {
    <-1, 0, -1>
    <1, 1, 1>
  }
}

#declare FootLeft = object {
  Foot
}

#declare FootRight = object {
  Foot
}


#declare Feet = union {
  object {
    FootRight
    translate -1.25 * x - sin(nStep) * z
  }
  object {
    FootLeft
    translate 1.25 * x + sin(nStep) * z
  }
}




#declare BigFace = union {
  object {
    Belly
    pigment {
      color rgb <0.4, 0.4, 0.4>
    }
  }
  object {
    FaceBase
    pigment {
      image_map {
        png FaceTexture
        map_type 1
      }
    }
    translate 5.25 * y
  }
  object {
    Arms
    translate 2.8 * y
    pigment {
      color rgb <0.4, 0.4, 0.4>
    }
  }
  object {
    Feet
  }
}


