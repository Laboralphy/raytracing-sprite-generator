#include "metals"

#local T_Main = texture {
  T_Brass_1A
  normal {
    dents
    scale 0.5
  }
}


#local O_Weapon_Shaft = cylinder {
	0
	<0, 1, 0>
	0.05
  texture { T_Main }
}

#local O_Weapon_Head = intersection {
  sphere {
    0
    0.3
  }
  cylinder {
    <0, -10, 0>
    <0, 10, 0>
    0.2
  }
  texture {
    T_Main
  }
}

#local O_Weapon_Grenaille = sphere {
  0
  0.05
  texture {
    T_Chrome_1A
  }
}

#local N_Random = 0.19;

#local O_Weapon_Grenailled_Head = union {
  object {
    O_Weapon_Head
  }
  object {
    O_Weapon_Grenaille
    translate <0, 0.12, N_Random>
  }
  object {
    O_Weapon_Grenaille
    translate <0, -0.12, N_Random>
  }
  object {
    O_Weapon_Grenaille
    translate <0, 0.12, -N_Random>
  }
  object {
    O_Weapon_Grenaille
    translate <0, -0.12, -N_Random>
  }
  object {
    O_Weapon_Grenaille
    translate <N_Random, 0.12, 0>
  }
  object {
    O_Weapon_Grenaille
    translate <N_Random, -0.12, 0>
  }
  object {
    O_Weapon_Grenaille
    translate <-N_Random, 0.12, 0>
  }
  object {
    O_Weapon_Grenaille
    translate <-N_Random, -0.12, 0>
  }
}


#declare P_BodyPart_ArmorPart_Weapon = union {
	object {
		O_Weapon_Shaft
	}
	object {
		O_Weapon_Grenailled_Head
		translate <0, 1, 0>
	}
  
	scale 1.33 * N_Wrist_Len
}
