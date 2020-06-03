#include "inc/body/BodyMetrics.inc"

/* Skirt start at 0*y and goes bellow y plane */

#declare C_Jeans = color rgb <0.15, 0.075, 0.02>;

#declare T_Jeans = texture {
	pigment {
		tiling 1
		color_map {
			[0, C_Jeans]
			[0.5 C_Jeans * 0.5]
			[1 C_Jeans]
		}
		rotate <90, 0, 45>
		scale 0.06
	}
}

#local N_PELVISH = 0.5;
#declare O_Short_Trousers_Ripped_Blueish = union {
	cone {
		<0, 0, 0>
		0.425 * N_Shoulder_Len
		<0, -N_Thigh_Len / 3, 0>
		N_PELVISH * N_Shoulder_Len
	}
	cone {
		0
		N_PELVISH * N_Shoulder_Len
		<0, -N_Thigh_Len / 4, 0>
    0
		translate <0, -N_Thigh_Len / 3, 0>
	}
	scale V_BodyPart_Torso_Scale
}


#local Cropper_1 =  cylinder {
  <0.55, -0.4, -10>
  <0.55, -0.4, 10>
  0.3
}

#local Cropper_2 =  object {
  Cropper_1
  scale <-1, 1, 1>
}

#local Croppers = union {
  object {
    Cropper_1
  }
  object {
    Cropper_2
  }
}



#declare P_BodyPart_ArmorPart_Skirt = difference {
  object {
    O_Short_Trousers_Ripped_Blueish
  }
  object {
    Croppers
  }
	texture {
		T_Jeans
	}
}
