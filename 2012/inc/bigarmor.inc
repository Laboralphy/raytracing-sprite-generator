#declare bParry = 1;


#switch (FrameIndex) 
  #case (8)
    #declare bParry = 0;
    #declare FrameIndex = 0;
  #break

  #case (9)
    #declare bParry = 0;
    #declare FrameIndex = 8;
  #break
#end



#include "inc/bigface.inc"


#declare Horn = sphere_sweep {
  linear_spline
  3
  <0, 0, 0>, 0.5
  <0.75, 0.75, 0>, 0.333
  <0, 2, 0>, 0.16
}

#declare Horns = union {
  object {
    Horn
    translate 1.25 * x
  }
  object {
    Horn
    rotate 180 * y
    translate -1.25 * x
  }
}

#declare HelmBaseTop = intersection {
  sphere {
    <0, 0, 0>
    2
  }
  cylinder {
    <0, -0.1, 0>
    <0, 3, 0>
    2
  }
}

#declare HelmBaseBottom = cylinder {
  <0, 0, 0>
  <0, -1.5, 0>
  2
}

#declare HelmWithoutHorns = difference{
  union {
    object {
      HelmBaseTop
    }
    object {
      HelmBaseBottom
    }
  }
  union {
    box {
      <-1, 0.5, 0>
      <1, 0, -3>
    }
    box {
      <-0.25, 0.5, 0>
      <0.25, -1, -3>
    }
  }
  pigment {
    ArmorPigment
  }
}



#declare Helm = union {
  object {
    HelmWithoutHorns
  }
  object {
    Horns
    translate 1.25 * y
    pigment {
      color rgb <1, 1, 0.9>
    }
  }
}



#declare Paldron = sphere {
  <0, 0, 0>
  0.5
}

#declare Paldrons = union {
  object { 
    Paldron
    translate 1.25 * x
  }
  object { 
    Paldron
    translate -1.25 * x
  }
}



#declare BellyArmor = union {
  object { 
    BellyDown 
    translate 1.75 * y
  }
  object { 
    BellyUp 
    translate 2 * y
  }
  object {
    Paldrons
    translate 3 * y
  }
  pigment {
    ArmorPigment
  }
}


#if (bParry) 
#declare Shield = prism {
  linear_spline
  0
  0.25
  6
  <0, 0>
  <-1.5, 1>
  <-1.5, 3>
  <1.5, 3>
  <1.5, 1>
  <0, 0>
  rotate <-90, 0, 0>
  translate <1, 0.5, -1.5>
  pigment {
    color rgb <0.3, 0.3, 1>
  }
}
#else
#declare Shield = prism {
  linear_spline
  0
  0.25
  6
  <0, 0>
  <-1.5, 1>
  <-1.5, 3>
  <1.5, 3>
  <1.5, 1>
  <0, 0>
  rotate <-90, 90, 0>
  translate <2.5, 0.5, 0>
  pigment {
    color rgb <0.3, 0.3, 1>
  }
}
#end


#declare BigFaceArmor = union {
  object {
    BellyArmor
    pigment {
      color rgb <0.4, 0.4, 0.4>
    }
  }
  object {
    FaceBase
    scale 0.95
    translate 5.25 * y
    pigment {
      color rgb <0, 0, 0>
    }
  }
  object {
    Helm
    translate 5.25 * y
  }
  object {
    Arms
    translate 2.8 * y
    pigment {
      ArmorPigment
    }
  }
  object {
    Feet
  }
  object {
    Shield
  }
}

