#include "inc/clock.inc"


#declare AbdoTexture = "textures/spider1.png";
#declare ThoraxTexture = "textures/spider2.png";


#declare AbdoPigment = pigment {
  image_map {
    png AbdoTexture
    map_type 1
  }
  rotate 90 * x
}

#declare ThoraxPigment = pigment {
  image_map {
    png ThoraxTexture
    map_type 1
  }
}

#declare EyeColor = color rgb <1, 0, 0>;





#declare Eyes = union {
  sphere {
    <-0.166, 0.222, -1.4>
    0.16
  }
  sphere {
    <-0.4, 0.275, -1.2>
    0.1
  }

  sphere {
    <0.1666, 0.222, -1.4>
    0.16
  }
  sphere {
    <0.4, 0.275, -1.2>
    0.1
  }
  pigment {
    EyeColor
  }
}

#declare Abdomen = sphere {
  <0, 0, 0>
  1
  scale <1, 1, 1.5>
  pigment { 
    AbdoPigment
  }
}

#declare Thorax = sphere {
  <0, 0, 0>
  1
  scale <0.75, 0.75, 1.5>
  pigment { 
    ThoraxPigment
  }
}

#declare Cephalo = object {
  Eyes
}

#declare Cephalothorax = union {
  object {
    Cephalo
  }
  object {
    Thorax
  }
}

#declare LegWidth = 0.1;

#declare Leg = sphere_sweep {
  linear_spline
  3
  <0, 0.5, 0>, LegWidth
  <1.5, 1.5, 0>, LegWidth / 1.5
  <3, 0, 0>, LegWidth / 3  
}

#declare nFrames = 8;
#declare nAmplitude = 25;
#declare LegMove_L = nAmplitude * sin(FrameIndex * 2 * 3.141592654 / nFrames) + nAmplitude;
#declare LegMove_R = nAmplitude * sin((FrameIndex + nFrames / 2) * 2 * 3.141592654 / nFrames) + nAmplitude;

#declare Legs = union {
  object {
    Leg
    rotate -LegMove_L * y
    translate <0.5, 0, 0>
  }
  object {
    Leg
    rotate -0.5 * LegMove_R * y
    translate <0.5, 0, -0.4>
  }
  object {
    Leg
    rotate 0.5 * LegMove_R * y
    translate <0.5, 0, -0.8>
  }
  object {
    Leg
    rotate LegMove_L * y
    translate <0.5, 0, -1.2>
  }
  union {
    object {
      Leg
      rotate -LegMove_R * y
      translate <0.5, 0, 0>
    }
    object {
      Leg
      rotate -0.5 * LegMove_L * y
      translate <0.5, 0, -0.4>
    }
    object {
      Leg
      rotate 0.5 * LegMove_L * y
      translate <0.5, 0, -0.8>
    }
    object {
      Leg
      rotate LegMove_R * y
      translate <0.5, 0, -1.2>
    }
    scale <-1, 1, 1>
  }
}






#declare Spider = union {
  object {
    Abdomen
    translate <0, 1.25, 1.5>
  }
  object {
    Cephalothorax
    translate <0, 1, -0.5>
  }
  object {
    Legs
  }
}



#declare fCameraHeight = 4;

camera {
  location <0, fCameraHeight, -24>
  look_at <0, fCameraHeight, 0>
}

/* top camera 
camera {
  location <0, 10, 0>
  look_at <0, 0, 0>
}
*/
light_source {
  <0, fCameraHeight, -10>
  color rgb <1, 1, 1>
}


object {
  Spider
  scale 0.85
  rotate CameraAngle * y
}

disc {
  <0, 0, 0>
  y
  2
  pigment {
    color rgb <0.666, 0.666, 0.666>
  }
}

