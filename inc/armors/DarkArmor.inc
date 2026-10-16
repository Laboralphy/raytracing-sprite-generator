/*
     _            _
  __| | __ _ _ __| | __   __ _ _ __ _ __ ___   ___  _ __
 / _` |/ _` | '__| |/ /  / _` | '__| '_ ` _ \ / _ \| '__|
| (_| | (_| | |  |   <  | (_| | |  | | | | | | (_) | |
 \__,_|\__,_|_|  |_|\_\  \__,_|_|  |_| |_| |_|\___/|_|

	Armor of the dark knight: the shapes of ChromedArmor_1 (included for its
	untextured parts), in blackened steel eaten by reddish rust (T_Dark_Armor),
	more spikes on the pauldrons, big horns curving forward on the helm
	(N_Dark_Horn_Size), a crimson cape hung from the shoulders (in the chest
	slot, flattened against the back when lying, see AV_Body.x).
*/

#include "inc/armors/ChromedArmor_1.inc"

#ifndef (T_Dark_Armor)
	#declare T_Dark_Armor = texture {
		bozo
		turbulence 0.8
		texture_map {
			[0 pigment { color rgb <0.11, 0.11, 0.13> }
				normal { dents 0.6 scale 0.2 }
				finish { ambient 0.08 diffuse 0.5 specular 0.7 roughness 0.01 metallic reflection 0.08 }]
			[0.68 pigment { color rgb <0.14, 0.12, 0.13> }
				normal { dents 0.6 scale 0.2 }
				finish { ambient 0.08 diffuse 0.5 specular 0.6 roughness 0.015 metallic reflection 0.05 }]
			[0.78 pigment { color rgb <0.48, 0.13, 0.04> }
				normal { granite 0.3 scale 0.05 }
				finish { ambient 0.1 diffuse 0.7 specular 0.05 roughness 0.1 }]
			[1 pigment { color rgb <0.3, 0.07, 0.02> }
				normal { granite 0.3 scale 0.05 }
				finish { ambient 0.1 diffuse 0.7 specular 0.05 roughness 0.1 }]
		}
		scale 0.15
	}
#end
#ifndef (T_Dark_Horn)
	#declare T_Dark_Horn = texture {
		pigment {
			gradient x
			color_map {
				[0 color rgb <0.55, 0.5, 0.42>]
				[0.6 color rgb <0.3, 0.25, 0.2>]
				[1 color rgb <0.05, 0.04, 0.04>]
			}
		}
		finish { ambient 0.1 diffuse 0.6 specular 0.6 roughness 0.01 }
	}
#end
#ifndef (T_Dark_Cape)
	#declare T_Dark_Cape = texture {
		pigment { color rgb <0.32, 0.005, 0.025> }
		// vertical folds
		normal {
			radial 0.6
			frequency 16
			sine_wave
		}
		finish { diffuse 0.75 specular 0.08 roughness 0.08 }
	}
#end
#ifndef (N_Dark_Horn_Size)
	#declare N_Dark_Horn_Size = 1;
#end



/*
     _    _      _
 ___| | _(_)_ __| |_
/ __| |/ / | '__| __|
\__ \   <| | |  | |_
|___/_|\_\_|_|   \__|

	dark mail
*/

#declare P_BodyPart_ArmorPart_Skirt = cone {
	<0, 0, 0>
	0.45 * N_Shoulder_Len
	<0, -N_Thigh_Len / 1.5, 0>
	0.6 * N_Shoulder_Len
	open
	scale V_BodyPart_Torso_Scale
	texture {
		pigment {
			hexagon
			pigment { color rgb 0.2 },
			pigment { color rgb 0.12 },
			pigment { color rgb <0.2, 0.07, 0.04> }
		}
		scale 0.05
		rotate 90 * x
		normal {
			bumps 1
			scale 0.1
		}
		finish { specular 0.4 roughness 0.02 metallic }
	}
}



/*
      _               _
  ___| |__   ___  ___| |_
 / __| '_ \ / _ \/ __| __|
| (__| | | |  __/\__ \ |_
 \___|_| |_|\___||___/\__|

	breastplate and cape
*/

#local O_Dark_Breastplate = sor {
	5
	<0.9 * N_Shoulder_Len / 2, 0>
	<0.9 * N_Shoulder_Len / 2, N_Torso_Len / 4> // belt position
	<1.3 * N_Shoulder_Len / 2, N_Torso_Len>
	<0.9 * N_Shoulder_Len / 2, 1.33 * N_Torso_Len>
	<0.9 * N_Shoulder_Len / 2, 1.33 * N_Torso_Len + 1>
	sturm
	scale V_BodyPart_Torso_Scale * <0.85, 1, 1>
	texture {
		T_Dark_Armor
		scale 0.25
	}
}

// crimson cape, as the one of c_mummy_1.pov: a shell of a cone behind the
// body (+z), down to the calves, ragged hem
#ifndef (N_Dark_Cape_Bottom)
	#declare N_Dark_Cape_Bottom = -1.55 * N_Torso_Len;
#end
#local N_Cape_Top = 0.98 * N_Torso_Len;
#ifdef (AV_Body)
	#local N_Cape_Flatten = 1 - 0.75 * min(max(AV_Body.x / 90, 0), 1);
#else
	#local N_Cape_Flatten = 1;
#end
#local O_Dark_Cape = difference {
	cone {
		<0, N_Cape_Top, 0>, 0.56 * N_Shoulder_Len
		<0, N_Dark_Cape_Bottom, 0.25>, 1.0 * N_Shoulder_Len
	}
	cone {
		<0, N_Cape_Top + 0.01, 0>, 0.56 * N_Shoulder_Len - 0.04
		<0, N_Dark_Cape_Bottom - 0.01, 0.25>, 1.0 * N_Shoulder_Len - 0.04
	}
	// open in front
	plane {
		z, 0
	}
	// ragged hem
	#local S = seed(7);
	#local I = 0;
	#while (I < 11)
		box {
			<-0.06, -0.25, -2>, <0.06, 0.12, 2>
			rotate z * (rand(S) - 0.5) * 30
			translate <-1 + I * 0.2, N_Dark_Cape_Bottom + 0.06 * rand(S), 0>
		}
		#local I = I + 1;
	#end
	scale <1, 1, N_Cape_Flatten>
	texture { T_Dark_Cape }
}

#declare P_BodyPart_ArmorPart_Chest = union {
	object { O_Dark_Breastplate }
	object { O_Dark_Cape }
}



/*
 _
| | ___  __ _ ___
| |/ _ \/ _` / __|
| |  __/ (_| \__ \
|_|\___|\__, |___/
        |___/

*/

#local O_Dark_Soleret_Top = union {
	cone {
		<0, -N_Leg_Thickness, 0>
		N_Leg_Thickness * 1
		<0, N_Shin_Len * 0.5, 0>
		N_Leg_Thickness * 1.3
	}
	torus {
		N_Leg_Thickness * 1
		N_Leg_Thickness * 0.3
		translate <0, N_Shin_Len * 0.5, 0>
	}
}

#local O_Dark_Poleyn = union {
	sphere {
		0, N_Leg_Thickness * 1.15
	}
	sphere {
		0, N_Leg_Thickness * 1.25
		scale <1, 1.1, 0.75>
		translate <0, 0, -N_Leg_Thickness * 0.55>
	}
	// outer wing
	sphere {
		0, N_Leg_Thickness * 0.9
		scale <0.35, 1, 1>
		translate <N_Leg_Thickness * 0.95, 0, -N_Leg_Thickness * 0.2>
	}
	object {
		O_Armor_Spike
		scale 1.3
		rotate x * (-90)
		translate <0, 0, -N_Leg_Thickness * 0.9>
	}
}

#declare P_BodyPart_ArmorPart_Shin = union {
	object { O_Dark_Soleret_Top }
	object { O_Soleret_Heel }
	cylinder {
		<0, -N_Leg_Thickness, 0>
		<0, N_Shin_Len, 0>
		N_Leg_Thickness * 1.05
	}
	object {
		O_Dark_Poleyn
		translate <0, N_Shin_Len, 0>
	}
	texture { T_Dark_Armor }
}

#declare P_BodyPart_ArmorPart_Thigh = union {
	cylinder {
		0
		<0, N_Thigh_Len, 0>
		N_Leg_Thickness * 1.1
	}
	cone {
		0
		N_Leg_Thickness
		<0, N_Thigh_Len / 2, 0>
		N_Leg_Thickness * 1.2
	}
	texture { T_Dark_Armor }
}



/*
  __ _ _ __ _ __ ___  ___
 / _` | '__| '_ ` _ \/ __|
| (_| | |  | | | | | \__ \
 \__,_|_|  |_| |_| |_|___/

	pauldrons with a third, bigger spike
*/

#declare P_BodyPart_ArmorPart_Shoulder = union {
	object {
		O_Pauldron
		translate y * N_Arm_Len
	}
	object {
		O_Armor_Spike
		scale 1.4
		rotate <0, 0, -30>
		translate <1.8, 1.6, 0> * N_Arm_Thickness + y * N_Arm_Len
	}
	cone {
		<0, 0, 0>
		N_Arm_Thickness * 1.3
		<0, N_Arm_Len, 0>
		N_Arm_Thickness * 1.6
	}
	texture { T_Dark_Armor }
}

#declare P_BodyPart_ArmorPart_Wrist = union {
	cone {
		<0, N_Wrist_Len, 0>
		N_Arm_Thickness * 1.3
		<0, 0, 0>
		N_Arm_Thickness * 1.1
	}
	sphere {
		<0, N_Wrist_Len, 0>
		N_Arm_Thickness * 1.6
	}
	// spike on the elbow
	object {
		O_Armor_Spike
		rotate x * 90
		translate <0, N_Wrist_Len, N_Arm_Thickness * 1.3>
	}
	texture { T_Dark_Armor }
}



/*
 _          _
| |__   ___| |_ __ ___
| '_ \ / _ \ | '_ ` _ \
| | | |  __/ | | | | | |
|_| |_|\___|_|_| |_| |_|

	same helm, big horns: out to the side, up, then the points forward
	(in head sizes, as the helm of ChromedArmor_1)
*/

#local O_Dark_Helm_Base = difference {
	sor {
		7
		<0.85, -1>
		<0.95, -0.2>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(90)), 1 + sin(radians(90))>
		<0, 2>
		sturm
	}
	object {
		O_Helm_Extruder
	}
	texture {
		T_Dark_Armor
		scale 0.3
	}
}

// left horn (+x), base at the origin
#local O_Dark_Horn = sphere_sweep {
	b_spline
	6
	<-0.3, -0.1, 0>, 0.3
	<0, 0, 0>, 0.28
	<0.55, 0.25, 0.05>, 0.2
	<0.85, 0.85, -0.1>, 0.13
	<0.75, 1.35, -0.45>, 0.05
	<0.65, 1.45, -0.6>, 0
	scale N_Dark_Horn_Size
	texture { T_Dark_Horn scale N_Dark_Horn_Size }
}

#declare P_BodyPart_ArmorPart_Helm = union {
	object { O_Dark_Helm_Base }
	object { O_Dark_Horn translate <0.75, 1.45, 0> }
	object { O_Dark_Horn translate <0.75, 1.45, 0> scale <-1, 1, 1> }
	scale N_Head_Size
}
