#declare N_BodyMetrics_Arm_Thickness = 0.06;
#declare N_BodyMetrics_Leg_Thickness = 0.07;
#declare N_BodyMetrics_Blob_Threshold = 3;
#include "inc/body/BodyMetrics"
#declare N_Finger_Thickness = N_Finger_Thickness * 2;
#declare N_Finger_Len = N_Finger_Len * 3;

// vertebre

#declare N_Skel_Vertebre_Count = 8;
#declare N_Skel_Vertebre_Size = N_Torso_Len / 6;
#declare N_Skel_Spine_Amplitude = N_Torso_Len / 8;
#declare N_Skel_Rib_Thickness = 0.12;
#declare N_Skel_Rib_Aperture = 10;

#declare O_Skel_Vertebre = sphere {
	0
	N_Skel_Vertebre_Size / 2
}

#declare O_Skel_Rib_Left = union {
	intersection { 
		torus {
			1
			N_Skel_Rib_Thickness
		}
		box {
			<-10, -10, -10>
			<0, 10, 10>
		}
	}
	sphere {
		<0, 0, -1>
		N_Skel_Rib_Thickness
	}
	rotate <0, N_Skel_Rib_Aperture, 0>
	scale V_BodyPart_Torso_Scale / 2
	scale <0.8, 1, 0.5>
	translate <0, 0, -V_BodyPart_Torso_Scale.z / 4>
}

#declare O_Skel_Rib_Right = object {
	O_Skel_Rib_Left
	scale <-1, 1, 1>
}

#declare O_Skel_Ribbed_Vertebre = union {
	object {
		O_Skel_Vertebre
	}
	object {
		O_Skel_Rib_Right
	}
	object {
		O_Skel_Rib_Left
	}
}


#declare O_Skel_Spine = union {
	#for (I_Vertebre, 0, N_Skel_Vertebre_Count + N_Skel_Vertebre_Count / 2, 1)
		#local N_Cond = 0;
		#if (mod(I_Vertebre, 2))
			#local N_Cond = N_Cond + 1;
		#end
		#if (I_Vertebre > 4)
			#local N_Cond = N_Cond + 2;
		#end
		#if (I_Vertebre < (N_Skel_Vertebre_Count - 2))
			#local N_Cond = N_Cond + 4;
		#end
			
		object {
			#if (N_Cond = 7)
				O_Skel_Ribbed_Vertebre
			#else
				O_Skel_Vertebre
			#end
			translate <
				0, 
				N_Torso_Len * I_Vertebre / N_Skel_Vertebre_Count, 
				N_Skel_Spine_Amplitude * sin(radians(180 * I_Vertebre / N_Skel_Vertebre_Count))
			>
		}
	#end
}
