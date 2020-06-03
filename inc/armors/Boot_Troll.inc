#include "inc/body/BodyMetrics.inc"

/* for a boot, use N_BodyMetrics_Leg_Thickness and N_Shin_Len */


#local O_Skel_Foot_Finger = sphere_sweep {
	linear_spline
	4
	0, N_Finger_Thickness
	<0, 0, -N_Finger_Len>, N_Finger_Thickness * 1.2
	<0, 0, -N_Finger_Len>, N_Finger_Thickness / 2
	<0, 0, -N_Finger_Len * 2>, N_Finger_Thickness / 2
  texture {
    T_BodyPart_Skin
  }
}

#local O_Skel_Foot_Finger_And_Claw = union {
  object {
    O_Skel_Foot_Finger
  }
  intersection {
    sphere {
      <0, 0, -N_Finger_Len * 2>, 
      N_Finger_Thickness * 1
      scale <0.25, 1, 1>
      texture {
        pigment {
          color rgb 0.025
        }
      }
    }
    box {
      <-10, 0, -10>
      <10, 10, 10>
    }
    translate <0, -0.5 * N_Finger_Thickness, 0>
  }
}

#declare O_Skel_Foot = union {
	object {
		O_Skel_Foot_Finger_And_Claw 
	}
	object {
		O_Skel_Foot_Finger_And_Claw 
		rotate <0, 20, 0>
	}
	object {
		O_Skel_Foot_Finger_And_Claw 
		rotate <0, -20, 0>
	}
	object {
		O_Skel_Foot_Finger_And_Claw 
		rotate <0, -10, 0>
	}
	object {
		O_Skel_Foot_Finger_And_Claw 
		rotate <0, 10, 0>
	}
}


#local O_Boot_Shin = cone {
	<0, 0, 0>
	N_BodyMetrics_Leg_Thickness * 1.1
	<0, N_Shin_Len, 0>
	N_BodyMetrics_Leg_Thickness * 0.8
  texture {
    T_BodyPart_Skin
  }
}

#declare P_BodyPart_ArmorPart_Shin = union {
  object {
    O_Skel_Foot
    scale <2, 2, 2>
  }
  object {
    O_Boot_Shin
  }
  rotate <0, -40, 0>
}
