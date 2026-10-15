
#declare Chest = sphere {
  <0, 0, 0>
  1
  scale <1, 1, 1>
}

#declare Leg = cone {
  <0, 0, 0>
  0.375
  <0, -1.5, 0>
  0
}

#declare Arm = cone {
  <0, 0, 0>
  0.375
  <0, 1.25, 0>
  0
}

#declare HeadBase = intersection {
  sphere {
    <0, 0, 0>
    1
    scale <1.5, 1.5, 1.5>
  }
  box {
    <-1.5, 0, -1.5>
    <1.5, -1.5, 1.5>
  }
}

#declare HeadTop = intersection {
  sphere {
    <0, 0, 0>
    1
    scale <1.5, 2.25, 1.5>
  }
  box {
    <-1.5, 0, -1.5>
    <1.5, 2.25, 1.5>
  }
}

#declare MaskEye = cylinder {
  <0, 0, -10>
  <0, 0, 10>
  0.25
}

#declare MaskEyes = union {
  object {
    MaskEye
    translate -0.5 * x
  }
  object {
    MaskEye
    translate 0.5 * x
  }
}

#declare MaskMouth = cylinder {
  <0, 0, -10>
  <0, 0, 10>
  1
  scale <0.25, AttackFrame / 10, 1>
}




#declare Horn = difference {
  intersection {
  // 1.85
    sphere {
      <1.85, 0, 0>
      2
    }
    sphere {
      <-1.85, 0, 0>
      2
    }
  }
  sphere {
    <0, 0.1, -0.5>
    0.85
  }
}

#declare Mask = difference {
  sphere {
    <0, 0, 0>
    1
    scale <1.25, 1.5, 1.1>
  }
  object {
    MaskEyes
    translate <0, -0.25, -1>
  }
  #if (AttackFrame > 0)
    object {
      MaskMouth
      translate <0, -1, -1>
    }
  #end
}

#declare Head = union {
  object { 
    HeadBase
  }
  object {
    HeadTop
  }
  object {
    Horn
    rotate -90 * y
    scale <2.5, 3.5, 4>
    translate <0, 1.25, 0>
  }
  object {
    Horn
    rotate 90 * y
    scale <2.5, 2.5, 4>
    translate <-0.1, 1, 0>
  }
}

#declare MaskedHead = union {
  object {
    Head
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

#declare ImpBody = union {
  object {
    Chest
    translate 2.25 * y
  }
  object {
    Leg
    rotate LegRotation * x
    translate <-0.375, 1.5, 0>
  }
  object {
    Leg
    rotate (0 - LegRotation) * x
    translate <0.375, 1.5, 0>
  }
  /* 
  Arm angle : 90 -o-
             135 /o\
              45 \o/
  */
  object {
    Arm
    rotate <0, 0, -135>
    translate <0.666, 2.5, 0>
  }
  object {
    Arm
    rotate <0, 0, 135>
    translate <-0.666, 2.5, 0>
  }
  pigment {
    BodyColor
  }
}

#declare Imp = union {
  object {
    ImpBody
  }
  object {
    MaskedHead
    translate 4.5 * y
  }
}





