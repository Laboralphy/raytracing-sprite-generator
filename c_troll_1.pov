/*

@frames 5

*/

#include "inc/Camera.inc"
#include "inc/frames/troll.inc"

#declare C_Skin = color rgb <0.2, 0.3, 0.15>;

#declare T_Skin_Green = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 C_Skin * 0.9]
			[0.25 C_Skin * 0.6]
			[0.95 C_Skin]
		}
	}
  scale 0.1
}

#declare T_Wart_Green = texture {
	pigment {
		agate
		agate_turb 0.9
		color_map {
			[0 C_Skin * 0.3]
			[0.25 C_Skin * 0.1]
			[0.95 C_Skin * 0.5]
		}
	}
  scale 0.1
}


#declare T_BodyPart_Skin = T_Skin_Green;

#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/troll_face.png"
			map_type 1
		}
	}
}




#declare N_BodyMetrics_Member_Factor = 1.5;
#declare N_BodyMetrics_Leg_Thickness = 0.15;
#declare N_BodyMetrics_Arm_Thickness = 0.15;
#declare AV_Head_Offset = <0, -0.3, -0.4>;

#declare N_BodyMetrics_Nose_Angle = 40;
#declare N_BodyMetrics_Nose_Length = 1.2;

#include "inc/hair/Saiyan"
#include "inc/hair/Texture_Black_Gray"
#include "inc/armors/Short_Trousers_Pagne_Troll"


#declare O_Wart = sphere {
  <0, 0, 0>
  0.09
}

#declare O_Warts = union {
  object {
    O_Wart
    translate <0, 0.1 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, 30, 0>
  }
  object {
    O_Wart
    translate <0, 0.2 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, 170, 0>
  }
  object {
    O_Wart
    translate <0, 0.3 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, -60, 0>
  }
  object {
    O_Wart
    translate <0, 0.4 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, 90, 0>
  }
  object {
    O_Wart
    translate <0, 0.5 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, 150, 0>
  }
  object {
    O_Wart
    translate <0, 0.6 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, -80, 0>
  }
  object {
    O_Wart
    translate <0, 0.7 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, 10, 0>
  }
  object {
    O_Wart
    translate <0, 0.8 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, -25, 0>
  }
  object {
    O_Wart
    translate <0, 0.9 * N_Upper_Member_Len, -N_BodyMetrics_Arm_Thickness>
    rotate <0, -175, 0>
  }
}

#declare P_BodyPart_ArmorPart_Shoulder = object {
  O_Warts
  rotate <0, 10, 0>
  texture {
    T_Wart_Green
  }
}

#declare P_BodyPart_ArmorPart_Wrist = object {
  O_Warts
  rotate <0, 166, 0>
  scale 0.8
  texture {
    T_Wart_Green
  }
}

#declare P_BodyPart_ArmorPart_Thigh = object {
  O_Warts
  rotate <0, -45, 0>
  scale 0.75
  texture {
    T_Wart_Green
  }
}

#declare P_BodyPart_ArmorPart_Chest = object {
  O_Warts
  scale 1.4
  texture {
    T_Wart_Green
  }
}


#declare O_Troll_Ear_Left = intersection {
  ovus {
    0.2
    0.05
  }
  box {
    <-10, -10, -10>
    <0, 10, 10>
    rotate <0, 0, -15>
  }
  scale <1, 1.2, 0.8>
  translate <0.66, 0.5, 0>
  rotate <30, 0, 0>
  texture {
    T_Skin_Green
  }
}

#declare O_Troll_Ear_Right = object {
  O_Troll_Ear_Left
  scale <-1, 0, 0>
}


#declare P_BodyPart_ArmorPart_Helm = union{
  object {
    P_Saiyan_Forest
    scale <1.3, 1, 1>
    translate <0, 0.1, 0>
    texture {
      T_Hair_Black_Gray
    }
  }
  object {
    O_Troll_Ear_Left
  }
  object {
    O_Troll_Ear_Right
  }
}


#include "inc/armors/Boot_Troll"
#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
	translate y * N_OffsetBody
}
