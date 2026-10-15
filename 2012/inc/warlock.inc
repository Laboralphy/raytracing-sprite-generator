/****** WARLOCK ****** WARLOCK ****** WARLOCK ******/
/****** WARLOCK ****** WARLOCK ****** WARLOCK ******/
/****** WARLOCK ****** WARLOCK ****** WARLOCK ******/




#declare Robe2 = lathe {
  bezier_spline
  4
  <1, 5>
  <4, 4>
  <1, 0.5>
  <4, 0>
  texture {
    RobeTexture
  } 
  scale 0.5
}

#declare Robe3 = lathe {
  bezier_spline
  4
  <0, 5.5>
  <4, 3.5>
  <1.5, 2>
  <3.5, 0>
  texture {
    RobeTexture
  } 
  scale 0.5
}



#if (ANIM_FRAME)
#declare Robe = union {
  object {
    Robe3
  }
  texture {
    RobeTexture
  } 
}
#else
#declare Robe = union {
  object {
    Robe2
  }
  texture {
    RobeTexture
  } 
}
#end



#declare Head = sphere {
  <0, 0, 0>
  1
  texture {
	FaceTexture
  }
  scale 1.25
  translate 3 * y
}


#declare Hand = sphere {
  <0, 0, 0>
  0.375
  pigment {
    SkinColor
  }
}

#declare Wand = cylinder {
  <0, 0, 0>
  <0, 0, -1.5>
  0.066
}

#declare Hands = union {
  object {
    Hand
    translate x
  }
  object {
    Hand
    translate -x
  }
  object {
    Wand
    translate -x
  }
}


#declare Warlock = union {
  object {
    Robe
//    translate StepOffset * y
  }
  object {
    Head
    translate StepOffset * y
  }
  object {
    Hat
	scale 1.1
    translate (3.5 + StepOffset) * y
  }
  object {
    Hands
    translate <0, 1.66 + StepOffset, -1>
  }
}





#declare Mob = object {
  Warlock
  scale 0.5
}


