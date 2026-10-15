// Tank Turret 

// anim_walk 1
// anim_attack 0
// anim_explosion 3

#include "inc/anim.inc"

#declare TankTexture = texture {
	pigment {
		color rgb <0.5, 0.5, 0.5>
	}
}

#declare TankTexture2 = texture {
	pigment {
		color rgb <0, 0, 0>
	}
}

#declare Tank = cylinder {
  <0, 0, 0>
  <0, 2, 0>
  1
  texture {
    TankTexture
  }
}

#declare HeadSphere = intersection {
  sphere {
    <0, 0, 0>
    1
  }
  box {
    <-10, 0, -10>
    <10, 10, 10>
  }
}

#declare HeadCircle = cylinder {
  <0, 0, 0>
  <0, 0.5, 0>
  1.25
  texture {
    TankTexture2
  }
}

#declare HeadTop = union {
  object { 
    HeadSphere
    translate 0.5 * y
    texture {
      TankTexture
    }
  }
  object {
    HeadCircle 
  }
}

#declare HeadBottom = object {
  HeadTop
  scale <1, -1, 1>
}





#declare nLegLowLength = 2.6;
#declare nLegLowWheel = 0.333;

#declare LegLow = lathe {
  linear_spline
  5
  <0.166, 0>
  <0.166, 0 - (nLegLowLength - nLegLowWheel)>
  <0.444, 0 - (nLegLowLength - nLegLowWheel)>
  <0.444, 0 - nLegLowLength>
  <0, 0 - nLegLowLength>
}

#declare LegHigh = cylinder {
  <0, 0, 0>
  <0, -1, 0>
  0.166
}

#declare Kneel = cylinder {
  <-0.166, 0, 0>
  <0.166, 0, 0>
  0.25
}

#declare Leg = union {
  object {
    Kneel
  }
  object {
    LegHigh
    rotate <90, 0, 0>
  }
  object {
    Kneel
    translate <0, 0, -1>
  }
  object {
    LegLow
    translate <0, 0, -1>
  }
}



#declare Legs = union {
  object {
    Leg
    rotate <37, 0, 0>
    translate -z
  }

  object {
    Leg
    rotate <37, 180, 0>
    translate z
  }

  object {
    Leg
    rotate <37, 90, 0>
    translate -x
  }

  object {
    Leg
    rotate <37, -90, 0>
    translate x
  }
}




#declare TurretBase = lathe {
  linear_spline
  6
  <0.25, 0>
  <0.25, 1.25>
  <0.3, 1.25>
  <0.3, 2>
  <0.22, 2>
  <0.22, 0>
  rotate -90 * x
  texture {
    TankTexture
  }
}



#declare Robo = union {
  object {
    HeadTop
    translate 4 * y
  }
  object {
    Tank
    translate 2 * y
  }
  object {
    HeadBottom 
    translate 2 * y
  }
  object {
    Legs
    rotate 45 * y
    translate 1.75 * y
  }
  object {
    TurretBase
    translate <0, 4.25, -1.2>
  }
}


declare Mob = object {
  Robo
  scale 0.75 * 0.666
}

#declare Shadow = union {
  disc {
    <0, 0, 0>
    y
    1.5
  }
  disc {
    <0, 0, 0>
    y
    1
    scale <3, 1, 0.5>
    rotate 45 * y
  }
  disc {
    <0, 0, 0>
    y
    1
    scale <3, 1, 0.5>
    rotate -45 * y
  }
  scale 0.75
  rotate ANIM_DIRECTION * 45 * y
  pigment {
    color rgbt <0.666, 0.666, 0.666, 0.5>
  }
}

#include "inc/camera.inc"
