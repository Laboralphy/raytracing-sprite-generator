#include "inc/body/BodyMetrics.inc"
#include "metals"
#include "finish"
#include "glass"

#local T_Amulet_Gold = texture {
  pigment {
    radial
    color_map {
      [0 rgb <0.2, 0.1, 0>]
      [0.1 rgb <0.5, 0.4, 0>]
      [0.5 rgb <1, 0.7, 0>]
      [1 rgb <0.4, 0.2, 0>]
    }
    frequency 16
  }
  finish {
    Phong_Shiny
  }
}

#local T_Amulet_Azur = texture {
  pigment {
    radial
    color_map {
      [0 rgb <0, 0, 0.2>]
      [0.1 rgb <0, 0, 0.5>]
      [0.5 rgb <0, 0.6, 1>]
      [1 rgb <0, 0, 1>]
    }
    frequency 32
  }
  finish {
    Phong_Shiny
  }
}

#local Harnais_Base = blob {
	threshold 0.3
	
	/* bottom left */
	sphere {
		<N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	/* bottom right */
	sphere {
		<-N_Shoulder_Len / 7, -N_Torso_Len * 0.2, N_Shoulder_Len / 20>
		N_Shoulder_Len / 3.5
		3
	}
	/* bottom center */
	sphere {
		<0, -N_Torso_Len * 0.1, -N_Shoulder_Len / 20>
		N_Shoulder_Len / 5
		3
		scale <1, 1.5, 1>
	}
	
	/* main torso parts */

	cylinder {
		0
		<0, N_Torso_Len / 4, 0>
		N_Shoulder_Len / 2
		1
		scale V_BodyPart_Torso_Scale
	}

	cylinder {
		<0, N_Torso_Len / 4, 0>
		<0, 3 * N_Torso_Len / 4, 0>
		N_Shoulder_Len / 2
		1
		scale V_BodyPart_Torso_Scale
	}

	cylinder {
		<0, 3 * N_Torso_Len / 4, 0>
		<0, N_Torso_Len, 0>
		N_Shoulder_Len / 2
		3
		scale V_BodyPart_Torso_Scale
	}


	/* left shoulder */
	sphere {
		<N_Shoulder_Len / 2, N_Torso_Len, 0>
		N_Shoulder_Len / 3
		1
	}
	/* right shoulder */
	sphere {
		<-N_Shoulder_Len / 2, N_Torso_Len, 0>
		N_Shoulder_Len / 3
		1
	}
	translate <0, -N_Torso_Len / 2, 0>
	scale 1.05
	translate <0, N_Torso_Len / 2, 0>
}

#local DiggerStop45 = sphere {
	<0, 0.45, -0.18>
	0.45
}

#local DiggerStop30 = sphere {
	<0, 0.45, -0.18>
	0.3
}

#local DiggerStop25 = sphere {
	<0, 0.45, -0.18>
	0.25
}


#local Digger1 = difference {
	object {
		DiggerStop45
	}
	object {
		DiggerStop30
	}
}
#local Digger2 = difference {
	object {
		DiggerStop30
	}
	object {
		DiggerStop25
	}
}

#local T_Ruby_Gem = texture {
  pigment {
    Col_Glass_Ruby
  }
  finish {
    F_Glass5
  }
}


#local MegaGem = sphere {
  <0, 0.8, -0.3>
  0.1
}

#local MegaGem_Ecrin = difference {
  sphere {
    <0, 0.8, -0.2>
    0.13
  }
  object {
    MegaGem
  }
  texture {
    T_Amulet_Gold
  }
}

#local HarnaisCollarGold_1 = intersection {
	object {
		Harnais_Base
    texture {
      T_Amulet_Gold 
    }
	}
	object {
		Digger1
		translate y * 0.8
	}
}

#local HarnaisCollarGold = difference {
	object {
    HarnaisCollarGold_1
	}
	object {
    MegaGem
	}
}

#local HarnaisCollarLapis = intersection {
	object {
		Harnais_Base
    texture {
      T_Amulet_Azur
    }
	}
	object {
		Digger2
		translate y * 0.8
	}
}

#local Harnais2 = union {
	object {
		HarnaisCollarGold
	}
	object {
		HarnaisCollarLapis
	}
  object {
    MegaGem_Ecrin
  }
  object {
    MegaGem
    texture {
      T_Ruby_Gem
    }
  }
}

#declare P_BodyPart_ArmorPart_Chest = Harnais2;
