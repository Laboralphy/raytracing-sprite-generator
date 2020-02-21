/*
                                   _                      _ 
  __ _ _ __ _ __ ___   ___  _ __  | |_ _   _ _ __   ___  / |
 / _` | '__| '_ ` _ \ / _ \| '__| | __| | | | '_ \ / _ \ | |
| (_| | |  | | | | | | (_) | |    | |_| |_| | |_) |  __/ | |
 \__,_|_|  |_| |_| |_|\___/|_|     \__|\__, | .__/ \___| |_|
                                       |___/|_|             

Armor with Chrome 1A dented texture
Light Grayish pigment, dull (not shiny)
a few spikes on shoulder
helm: horned helm (horns are copper)
shield : wood and brass cross
weapon : mace with spherical spiked head

*/




#include "colors.inc"
#include "metals.inc"
#include "woods.inc"
#include "inc/body/BodyMetrics.inc"

#declare O_Armor_Spike = cone {
	<0, 0, 0>
	N_Arm_Thickness * 0.75
	<0, 3 * N_Arm_Thickness, 0>
	0
}

#declare T_Armor = texture {
	T_Chrome_1A
	normal {
		dents 1
		scale 0.2
	}
}

/*
     _    _      _   
 ___| | _(_)_ __| |_ 
/ __| |/ / | '__| __|
\__ \   <| | |  | |_ 
|___/_|\_\_|_|   \__|

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
			pigment { Gray50 },
			pigment { Gray30 },
			pigment { Gray20 }
		}
		scale 0.05
		rotate 90 * x
		normal {
			bumps 1
			scale 0.1
		}
	}
}


/*
      _               _   
  ___| |__   ___  ___| |_ 
 / __| '_ \ / _ \/ __| __|
| (__| | | |  __/\__ \ |_ 
 \___|_| |_|\___||___/\__|

*/

#declare P_BodyPart_ArmorPart_Chest = sor {
	5
	<0.9 * N_Shoulder_Len / 2, 0>
	<0.9 * N_Shoulder_Len / 2, N_Torso_Len / 4> // belt position
	<1.3 * N_Shoulder_Len / 2, N_Torso_Len>
	<0.9 * N_Shoulder_Len / 2, 1.33 * N_Torso_Len>
	<0.9 * N_Shoulder_Len / 2, 1.33 * N_Torso_Len + 1>
	sturm
	scale V_BodyPart_Torso_Scale * <0.85, 1, 1>
	texture {
		T_Armor
		scale 0.25
	}
}

/*
 _                 _   
| |__   ___   ___ | |_ 
| '_ \ / _ \ / _ \| __|
| |_) | (_) | (_) | |_ 
|_.__/ \___/ \___/ \__|

*/
#declare O_Soleret_Top = union {
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
	texture {
		T_Armor
	}
}

#declare O_Soleret_Heel = intersection {
	sphere {
		<0, 0, 0>
		N_Leg_Thickness
		scale <1, 1, 2>
	}
	box {
		<-N_Leg_Thickness * 2, 0, 0>
		<N_Leg_Thickness * 2, N_Leg_Thickness * 2, -N_Leg_Thickness * 2>
	}
	translate -N_Leg_Thickness * y
}



/*
 _                
| | ___  __ _ ___ 
| |/ _ \/ _` / __|
| |  __/ (_| \__ \
|_|\___|\__, |___/
        |___/     

*/

#declare P_BodyPart_ArmorPart_Shin = union {
	object {
		O_Soleret_Top
	}
	object {
		O_Soleret_Heel
		texture {
			T_Armor
		}
	}
	cylinder {
		<0, -N_Leg_Thickness, 0>
		<0, N_Shin_Len, 0>
		N_Leg_Thickness * 1.05
		texture {
			T_Armor
		}
	}
	sphere {
		<0, N_Shin_Len, 0>
		N_Leg_Thickness * 1.15
		texture {
			T_Armor
		}
	}
	object {
		O_Armor_Spike
		rotate x * (-90)
		translate <0, N_Shin_Len, 0>
		texture {
			T_Armor
		}
	}
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
	texture {
		T_Armor
	}
}




/*
  __ _ _ __ _ __ ___  ___ 
 / _` | '__| '_ ` _ \/ __|
| (_| | |  | | | | | \__ \
 \__,_|_|  |_| |_| |_|___/
 
*/


#declare P_BodyPart_ArmorPart_Shoulder = union {
	sphere {
		<0, N_Arm_Len, 0>
		N_Arm_Thickness * 1.85
	}
	/* first shoulder pike */
	object {
		O_Armor_Spike
		translate y * N_Arm_Len
	}
	/* second shoulder pike */
	object {
		O_Armor_Spike
		rotate <0, 0, -60>
		translate y * N_Arm_Len
	}
	cone {
		<0, 0, 0>
		N_Arm_Thickness * 1.3
		<0, N_Arm_Len, 0>
		N_Arm_Thickness * 1.6
	}
	texture {
		T_Armor
	}
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
	texture {
		T_Armor
	}
}


/*
 _          _ _   
| |__   ___| | |_ 
| '_ \ / _ \ | __|
| |_) |  __/ | |_ 
|_.__/ \___|_|\__|
                  
*/



#declare O_Belt_Leather = cylinder {
	<0, 0, 0>
	<0, N_Torso_Len / 4, 0>
	N_Shoulder_Len / 2
	scale V_BodyPart_Torso_Scale
	texture {
		pigment {
			Gray10
		}
	}
}

#declare O_Belt_Buckle = torus {
	0.9
	0.3
	rotate <90, 0, 0>
	scale 0.1
	texture {
		T_Gold_1B
	}
}

#declare P_BodyPart_ArmorPart_Belt = union {
	object {
		O_Belt_Leather
	}
	object {
		O_Belt_Buckle
		translate <0, N_Torso_Len / 8, -V_BodyPart_Torso_Scale.z * N_Shoulder_Len / 2>
	}
}

/*
 _          _           
| |__   ___| |_ __ ___  
| '_ \ / _ \ | '_ ` _ \ 
| | | |  __/ | | | | | |
|_| |_|\___|_|_| |_| |_|

*/


#declare O_Helm_Cutter = union {
	box {
		<-0.666, 1, 0>
		<0.666, 0.75, -2>
	}
	box {
		<-0.25 / 2, 1, 0>
		<0.25 / 2, -1, -2>
	}
}


#declare O_Helm_Base = difference {
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
		O_Helm_Cutter
	}
	texture {
		T_Armor
		scale 0.3
	}
}

#declare O_Helm_Horn = sphere_sweep {
	linear_spline
	3
	<0, 0, 0>, 0.5
	<-1, 1, 0>, 0.25
	<-0.75, 2, 0>, 0.1
	scale 0.4
}


#declare P_BodyPart_ArmorPart_Helm = union {
	object {
		O_Helm_Base
	}
	object {
		O_Helm_Horn
		translate <-0.8, 1.6, 0>
		texture {
			T_Copper_1A
		}
	}
	object {
		O_Helm_Horn
		scale <-1, 1, 1>
		translate <0.8, 1.6, 0>
		texture {
			T_Copper_1A
		}
	}
	scale N_Head_Size
}


/*
     _     _      _     _ 
 ___| |__ (_) ___| | __| |
/ __| '_ \| |/ _ \ |/ _` |
\__ \ | | | |  __/ | (_| |
|___/_| |_|_|\___|_|\__,_|

*/


#declare O_Shield_Base = prism {
	linear_spline
	0, 0.25, 6,
    <-1, 1>, <1, 1>, <1, -1>, <0, -1.5>, <-1, -1>, <-1, 1>
	rotate <-90, 0, 0>
}

#declare O_Shield_Cutter = object {
	O_Shield_Base
	scale <0.9, 0.9, 2>
	translate <0, 0, 0>
}

#declare O_Shield_WoodPanel = object {
	O_Shield_Base
	scale <0.99, 0.99, 0.5>
	translate <0, 0, -0.05>
}

#declare O_Shield_Pattern_Cross = union {
	box {
		<-0.666, 0.25, 0>
		<0.666, 0, -0.25>
	}
	box {
		<-0.125, 0.666, 0>
		<0.125, -1, -0.25>
	}
	
}

#declare P_BodyPart_ArmorPart_Shield = union {
	difference {
		object {
			O_Shield_Base
		}
		object {
			O_Shield_Cutter
		}
		texture {
			T_Brass_1A
			normal {
				bumps 0.25
				scale 0.05
			}
		}
	}
	object {
		O_Shield_Pattern_Cross
		texture {
			T_Brass_1A
			normal {
				bumps 0.25
				scale 0.05
			}
		}
	}
	object {
		O_Shield_WoodPanel
		texture {
			T_Wood22
		}
		
	}
	scale 0.66
	translate <0.25, -0.25, 0>
}

