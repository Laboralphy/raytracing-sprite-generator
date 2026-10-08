/*
 _ __ ___  _   _ _ __ ___  _ __ ___  _   _ 
| '_ ` _ \| | | | '_ ` _ \| '_ ` _ \| | | |
| | | | | | |_| | | | | | | | | | | | |_| |
|_| |_| |_|\__,_|_| |_| |_|_| |_| |_|\__, |
                                     |___/ 

@frames 6

*/

#include "inc/Camera.inc"
#include "inc/frames/mummy.inc"
#declare C_Skin = color rgb <0.15, 0.15, 0.15>;

#declare T_Skin_Blood = texture {
	pigment {
		image_map {
			png "png/mummy_skin.png"
			map_type 2
		}
	}
}


#declare T_BodyPart_Face = texture {
  pigment {
    image_map {
			png "png/mummy_face.png"
			map_type 2
    }
  }
  translate -0.2 * y
}

#declare T_BodyPart_Skin = T_Skin_Blood

#declare N_BodyMetrics_Member_Factor = 1.1;
#declare N_BodyMetrics_Leg_Thickness = 0.15;
#declare N_BodyMetrics_Arm_Thickness = 0.11;
#include "inc/armors/MaleShirt_Big_Amulet"
#include "inc/armors/Belt_Golden_Baudrier"
#include "inc/weapons/Weapon_Ornate_Mace"
#include "inc/armors/Boot_Mummy_Ragged"



//   ____      _ _     _
//  |  _ \ ___ | (_)___| |__
//  | |_) / _ \| | / __| '_ \
//  |  __/ (_) | | \__ \ | | |
//  |_|   \___/|_|_|___/_| |_|
//
//  muscles, golden pauldrons, a crimson cape and a crown: a king, not a dummy

// muscles under the bandages (see inc/armors/Muscles.inc)
#declare N_Muscles_Bulk = 1.5;
#include "inc/armors/Muscles"
#declare P_BodyPart_ArmorPart_Arm = object { O_Muscles_Arm }
#declare P_BodyPart_ArmorPart_Elbow = object { O_Muscles_Forearm }
#declare P_BodyPart_ArmorPart_Thigh = object { O_Muscles_Thigh }
#declare P_BodyPart_ArmorPart_Kneel = object { O_Muscles_Calf }

#declare T_Mummy_Gold = texture {
	pigment {
		color rgb <0.85, 0.62, 0.18>
	}
	finish {
		ambient 0.15
		diffuse 0.55
		specular 0.9
		roughness 0.01
		metallic
		reflection { 0.1 metallic }
	}
}

#declare T_Mummy_Ruby = texture {
	pigment {
		color rgb <0.7, 0.02, 0.05>
	}
	finish {
		ambient 0.3
		specular 1
		roughness 0.003
	}
}

#declare T_Mummy_Cape = texture {
	pigment {
		color rgb <0.3, 0.008, 0.025>
	}
	// vertical folds
	normal {
		radial 0.6
		frequency 16
		sine_wave
	}
	finish {
		diffuse 0.75
		specular 0.08
		roughness 0.08
	}
}

// golden pauldron: a dome with a thick rim and a ruby (origin at the elbow)
#declare P_BodyPart_ArmorPart_Shoulder = union {
	intersection {
		sphere {
			0, 1
			scale <2.3, 1.7, 2.2> * N_Arm_Thickness
		}
		plane {
			-y, 0.2 * N_Arm_Thickness
		}
		texture { T_Mummy_Gold }
	}
	torus {
		1, 0.12
		scale <2.25, 1.6, 2.15> * N_Arm_Thickness
		translate -y * 0.2 * N_Arm_Thickness
		texture { T_Mummy_Gold }
	}
	sphere {
		<0, 1.7, 0> * N_Arm_Thickness, 0.35 * N_Arm_Thickness
		texture { T_Mummy_Ruby }
	}
	scale 1.2
	translate <0.4 * N_Arm_Thickness, N_Arm_Len - 0.2 * N_Arm_Thickness, 0>
}

// crimson cape, hung from the shoulders, down the back to the calves:
// a shell of a cone behind the body (+z), its hem ragged; two golden
// clasps at the front of the shoulders. In the frame of the torso
// (origin at the hips, the shoulders at N_Torso_Len).
#local N_Cape_Top = 0.98 * N_Torso_Len;
#local N_Cape_Bottom = -1.6;
#local O_Mummy_Cape = difference {
	cone {
		<0, N_Cape_Top, 0>, 0.52 * N_Shoulder_Len
		<0, N_Cape_Bottom, 0.2>, 0.95 * N_Shoulder_Len
	}
	cone {
		<0, N_Cape_Top + 0.01, 0>, 0.52 * N_Shoulder_Len - 0.04
		<0, N_Cape_Bottom - 0.01, 0.2>, 0.95 * N_Shoulder_Len - 0.04
	}
	// open in front
	plane {
		z, -0.05
	}
	// ragged hem
	#local S = seed(4);
	#local I = 0;
	#while (I < 9)
		box {
			<-0.06, -0.25, -2>, <0.06, 0.12, 2>
			rotate z * (rand(S) - 0.5) * 30
			translate <-0.8 + I * 0.2, N_Cape_Bottom + 0.05 * rand(S), 0>
		}
		#local I = I + 1;
	#end
	texture { T_Mummy_Cape }
}

#declare P_BodyPart_ArmorPart_Chest = union {
	object {
		P_BodyPart_ArmorPart_Chest
	}
	object {
		O_Mummy_Cape
	}
	// clasps
	sphere {
		<0.4 * N_Shoulder_Len, 0.92 * N_Torso_Len, -0.12>, 0.07
		texture { T_Mummy_Gold }
	}
	sphere {
		<-0.4 * N_Shoulder_Len, 0.92 * N_Torso_Len, -0.12>, 0.07
		texture { T_Mummy_Gold }
	}
}

// golden crown: a band, points with a small ball, rubies (in the frame of
// the helm slot, in head sizes)
#declare P_BodyPart_ArmorPart_Helm = union {
	difference {
		cylinder {
			<0, 0, 0>, <0, 0.32, 0>, 0.88
		}
		cylinder {
			<0, -1, 0>, <0, 1, 0>, 0.8
		}
		texture { T_Mummy_Gold }
	}
	#local I = 0;
	#while (I < 8)
		// a point, flattened along the band, and its ball
		union {
			cone {
				<0, 0.3, 0>, 0.17, <0, 0.75, 0>, 0.02
				scale <1, 1, 0.35>
			}
			sphere {
				<0, 0.78, 0>, 0.065
			}
			translate z * -0.84
			rotate y * I * 45
			texture { T_Mummy_Gold }
		}
		sphere {
			<0, 0.16, -0.88>, 0.07
			scale <1, 1, 0.6>
			rotate y * (I * 45 + 22.5)
			texture { T_Mummy_Ruby }
		}
		#local I = I + 1;
	#end
	scale <1, 1, 1.05>
	rotate x * -8
	translate y * 1.45
	scale N_Head_Size
}

#include "inc/body/BodyParts.inc"


#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}


object {
	O_Character_1
	rotate y * N_Animation_Angle
}
