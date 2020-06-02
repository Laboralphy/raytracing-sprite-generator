#include "inc/body/BodyMetrics.inc"
#include "metals"

#local T_Gold = texture {
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

#local T_Azur = texture {
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


#declare O_Belt_Golden_Baudrier_Leather = cylinder {
	<0, - 0.25 * N_Torso_Len, 0>
	<0, 0.2 * N_Torso_Len, 0>
	N_Shoulder_Len * 0.5
	scale V_BodyPart_Torso_Scale * 0.85
	texture {T_Gold rotate <-45, 0, 0>}
}
#declare O_Belt_Golden_Baudrier_Leather_1 = cylinder {
	<0, 0.16 * N_Torso_Len, 0>
	<0, 0.24 * N_Torso_Len, 0>
	N_Shoulder_Len * 0.52
	scale V_BodyPart_Torso_Scale * 0.85
	texture {T_Azur rotate <30, 0, 0>}
}
#declare O_Belt_Golden_Baudrier_Leather_2 = cylinder {
	<0, - 0.21 * N_Torso_Len, 0>
	<0, - 0.29 * N_Torso_Len, 0>
	N_Shoulder_Len * 0.52
	scale V_BodyPart_Torso_Scale * 0.85
	texture {T_Azur rotate <30, 0, 0>}
}

#declare P_BodyPart_ArmorPart_Belt = union {
	object {
		O_Belt_Golden_Baudrier_Leather
	}
	object {
		O_Belt_Golden_Baudrier_Leather_1
	}
	object {
		O_Belt_Golden_Baudrier_Leather_2
	}
}
