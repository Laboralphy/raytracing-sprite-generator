/*
                    _     _
 _______  _ __ ___ | |__ (_) ___
|_  / _ \| '_ ` _ \| '_ \| |/ _ \
 / / (_) | | | | | | |_) | |  __/
/___\___/|_| |_| |_|_.__/|_|\___|
  _ __ ___   ___  _ __   __ _ _ __ ___| |__
 | '_ ` _ \ / _ \| '_ \ / _` | '__/ __| '_ \
 | | | | | | (_) | | | | (_| | | | (__| | | |
 |_| |_| |_|\___/|_| |_|\__,_|_|  \___|_| |_|

	King of the zombies: the green zombie of c_zombie_2.pov, a little taller,
	a skull of the skeletons (greenish bone) for a head, a thin golden crown, no shirt nor trousers, a very wide open coat of
	faded blue with golden trims, bell sleeves and pauldrons.
*/

#include "inc/Camera.inc"
#include "inc/frames/zombie.inc"

#declare N_BodyMetrics_Value = 1.05;

#declare C_Skin = color rgb <0.2, 0.3, 0.14>;

#declare T_Skin_Blood = texture {
	pigment {
		agate
		agate_turb 0.5
		color_map {
			[0 color rgb <0.15, 0, 0>]
			[0.25 C_Skin * 0.3]
			[0.6 C_Skin * 0.6]
			[0.95 C_Skin]
		}
	}
}


#declare T_BodyPart_Torso = texture {
	pigment {
		image_map {
			png "png/zombie_torso.png"
			map_type 2
		}
		scale <1, 1.25, 1>
		translate y * 0.25
	}
}

#declare T_BodyPart_Skin = T_Skin_Blood

#include "inc/body/BodyMetrics.inc"

// head: the modelled skull of the skeletons, greenish bone
#declare T_Skull_Bone = texture {
	pigment {
		bozo
		turbulence 0.5
		color_map {
			[0 color rgb <0.48, 0.6, 0.3>]
			[0.7 color rgb <0.4, 0.52, 0.25>]
			[1 color rgb <0.28, 0.38, 0.18>]
		}
		scale 0.35
	}
	normal {
		bumps 0.08
		scale 0.1
	}
	finish {
		diffuse 0.75
		specular 0.15
		roughness 0.05
	}
}
#include "inc/skeleton/Skull"

#declare P_BodyPart_Head_Replace = object {
	O_Skel_Skull
	scale N_Head_Size
}
#include "inc/armors/Boot_Leather_Brown_Dirty"

#declare T_Monarch_Coat = texture {
	pigment {
		agate
		agate_turb 0.4
		color_map {
			[0 color rgb <0.1, 0.14, 0.26>]
			[0.6 color rgb <0.15, 0.2, 0.34>]
			[1 color rgb <0.2, 0.24, 0.36>]
		}
		scale 0.3
	}
	// vertical folds
	normal {
		radial 0.5
		frequency 14
		sine_wave
	}
	finish {
		diffuse 0.75
		specular 0.05
		roughness 0.1
	}
}

#declare T_Monarch_Gold = texture {
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

/*
	Coat: a shell of a wide cone from the shoulders to the ankles, open in
	front (the opening widens downwards), golden hem and front edges. In the
	frame of the torso (origin at the hips, the shoulders at N_Torso_Len).
*/
#local N_Coat_Top = 0.98 * N_Torso_Len;
#local N_Coat_Bottom = -N_Hip_Height + 0.3;
#local N_Coat_Top_Radius = 0.52 * N_Shoulder_Len;
#local N_Coat_Bottom_Radius = 1.15 * N_Shoulder_Len;
#local N_Coat_Thickness = 0.035;
// opening: half width at the top, and its growth downwards
#local N_Open_Top = 0.12;
#local N_Open_Slope = 0.2;
#local N_Trim = 0.07;

#macro Monarch_Coat_Shell(N_Grow)
	difference {
		cone {
			<0, N_Coat_Top, 0>, N_Coat_Top_Radius + N_Grow
			<0, N_Coat_Bottom, 0.1>, N_Coat_Bottom_Radius + N_Grow
		}
		cone {
			<0, N_Coat_Top + 0.01, 0>, N_Coat_Top_Radius - N_Coat_Thickness - N_Grow
			<0, N_Coat_Bottom - 0.01, 0.1>, N_Coat_Bottom_Radius - N_Coat_Thickness - N_Grow
		}
	}
#end

// the front opening, widened by N_Grow on each side
#macro Monarch_Coat_Opening(N_Grow)
	#local N_Norm = sqrt(1 + N_Open_Slope * N_Open_Slope);
	intersection {
		plane { z, 0 }
		plane { <1, N_Open_Slope, 0>, (N_Open_Top + N_Grow + N_Open_Slope * N_Coat_Top) / N_Norm }
		plane { <-1, N_Open_Slope, 0>, (N_Open_Top + N_Grow + N_Open_Slope * N_Coat_Top) / N_Norm }
	}
#end

#local O_Monarch_Coat = union {
	difference {
		Monarch_Coat_Shell(0)
		Monarch_Coat_Opening(0)
		texture { T_Monarch_Coat }
	}
	// golden hem and front edges, a little thicker than the cloth
	intersection {
		difference {
			Monarch_Coat_Shell(0.012)
			Monarch_Coat_Opening(0)
		}
		union {
			plane { y, N_Coat_Bottom + N_Trim * 1.5 }
			Monarch_Coat_Opening(N_Trim)
		}
		texture { T_Monarch_Gold }
	}
	// high collar behind the neck, golden rim
	difference {
		cone {
			<0, N_Coat_Top - 0.05, 0.02>, N_Coat_Top_Radius * 0.7
			<0, N_Coat_Top + 0.3, 0.08>, N_Coat_Top_Radius * 0.8
		}
		cone {
			<0, N_Coat_Top - 0.06, 0.02>, N_Coat_Top_Radius * 0.7 - 0.03
			<0, N_Coat_Top + 0.31, 0.08>, N_Coat_Top_Radius * 0.8 - 0.03
		}
		plane { z, -0.02 }
		texture { T_Monarch_Coat }
	}
	intersection {
		torus { N_Coat_Top_Radius * 0.8 - 0.015, 0.025 }
		plane { z, -0.02 }
		translate <0, N_Coat_Top + 0.3, 0.08>
		texture { T_Monarch_Gold }
	}
}

// the coat cannot drape: when the body falls on its back (AV_Body.x from 0
// to 90), it is flattened against the back, so that it lies spread on the
// ground instead of standing like a barrel
#local N_Coat_Fall = min(1, max(0, AV_Body.x / 90));
#declare P_BodyPart_ArmorPart_Chest = object {
	O_Monarch_Coat
	scale <1 - 0.25 * N_Coat_Fall, 1, 1 - 0.75 * N_Coat_Fall>
}

/*
	Pauldrons of the coat: a cloth dome, golden rim (origin at the elbow,
	shoulder at N_Arm_Len)
*/
#declare P_BodyPart_ArmorPart_Shoulder = union {
	intersection {
		sphere {
			0, 1
			scale <2.4, 1.7, 2.3> * N_Arm_Thickness
		}
		plane {
			-y, 0.2 * N_Arm_Thickness
		}
		texture { T_Monarch_Coat }
	}
	torus {
		1, 0.1
		scale <2.35, 1.6, 2.25> * N_Arm_Thickness
		translate -y * 0.2 * N_Arm_Thickness
		texture { T_Monarch_Gold }
	}
	scale 1.2
	translate <0.4 * N_Arm_Thickness, N_Arm_Len - 0.2 * N_Arm_Thickness, 0>
}

/*
	Bell sleeves: upper arm (origin at the elbow, shoulder at N_Arm_Len),
	forearm (origin at the elbow, down to -N_Wrist_Len), golden cuff
*/
#declare P_BodyPart_ArmorPart_Arm = cone {
	<0, N_Arm_Len, 0>, 1.6 * N_Arm_Thickness
	<0, -0.05, 0>, 2.0 * N_Arm_Thickness
	texture { T_Monarch_Coat }
}

#local N_Sleeve_End = -0.7 * N_Wrist_Len;
#declare P_BodyPart_ArmorPart_Elbow = union {
	difference {
		cone {
			<0, 0.05, 0>, 2.0 * N_Arm_Thickness
			<0, N_Sleeve_End, 0>, 2.8 * N_Arm_Thickness
		}
		cone {
			<0, 0.06, 0>, 2.0 * N_Arm_Thickness - 0.03
			<0, N_Sleeve_End - 0.01, 0>, 2.8 * N_Arm_Thickness - 0.03
		}
		texture { T_Monarch_Coat }
	}
	difference {
		cone {
			<0, N_Sleeve_End + 0.08, 0>, 2.65 * N_Arm_Thickness + 0.01
			<0, N_Sleeve_End, 0>, 2.8 * N_Arm_Thickness + 0.01
		}
		cone {
			<0, N_Sleeve_End + 0.09, 0>, 2.65 * N_Arm_Thickness - 0.03
			<0, N_Sleeve_End - 0.01, 0>, 2.8 * N_Arm_Thickness - 0.03
		}
		texture { T_Monarch_Gold }
	}
}

/*
	Thin golden crown: a narrow band and small points (in the frame of the
	helm slot, in head sizes, as the crown of c_mummy_1.pov)
*/
#declare P_BodyPart_ArmorPart_Helm = union {
	difference {
		cylinder {
			<0, 0, 0>, <0, 0.14, 0>, 0.86
		}
		cylinder {
			<0, -1, 0>, <0, 1, 0>, 0.82
		}
	}
	#local I = 0;
	#while (I < 10)
		cone {
			<0, 0.12, 0>, 0.07, <0, 0.38, 0>, 0.01
			scale <1, 1, 0.4>
			translate z * -0.84
			rotate y * I * 36
		}
		#local I = I + 1;
	#end
	texture { T_Monarch_Gold }
	// centred on the cranium of the skull (its centre is in front of the neck)
	rotate x * 4
	translate <0, 1.3, -0.3>
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
