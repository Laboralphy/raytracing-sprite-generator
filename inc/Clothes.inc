#include "colors.inc"
#include "finish.inc"
#include "metals.inc"
#include "golds.inc"
#include "woods.inc"
#include "inc/BodyLengthes.inc"




/*** ACCESSORIES ****** ACCESSORIES ****** ACCESSORIES ***/
/*** ACCESSORIES ****** ACCESSORIES ****** ACCESSORIES ***/
/*** ACCESSORIES ****** ACCESSORIES ****** ACCESSORIES ***/

#declare Clothe_Armor_Spike = cone {
	<0, 0, 0>
	ArmThickness * 0.75
	<0, 3 * ArmThickness, 0>
	0
}




/*** TEXTURES ****** TEXTURES ****** TEXTURES ****** TEXTURES ***/
/*** TEXTURES ****** TEXTURES ****** TEXTURES ****** TEXTURES ***/
/*** TEXTURES ****** TEXTURES ****** TEXTURES ****** TEXTURES ***/

#declare T_Clothe_Armor = texture {
	T_Chrome_1A
	normal {
		dents 1
		scale 0.2
	}
}




/*** ROBES ****** ROBES ****** ROBES ****** ROBES ****** ROBES ***/
/*** ROBES ****** ROBES ****** ROBES ****** ROBES ****** ROBES ***/
/*** ROBES ****** ROBES ****** ROBES ****** ROBES ****** ROBES ***/

#declare Clothe_Skirt_Pleaded_Blue = sor {
	6
	<0, 0>
	<0.4, 0.1>
	<0.75, 0.5>
	<0.9, 0.9>
	<1, 1>
	<1, 2>
	scale <1, -1, 0.7>
	texture {
		pigment {
			radial
			color_map {
				[0, Blue]
				[0.5 Blue * 0.5]
				[1 Blue]
			}
			frequency 16
		}
	}
}


#declare Clothe_Mail_Skirt = cone {
	0
	0.8
	<0, -1, 0>
	1.2
	scale <0.7, 0.9, 0.5>
	texture {
		pigment {
			hexagon
			pigment { Gray50 },
			pigment { Gray30 },
			pigment { Gray20 }
		}
		scale 0.1
		rotate 90 * x
		normal {
			bumps 1
			scale 0.1
		}
	}
}


/*** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ***/
/*** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ***/
/*** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ****** SHIRTS ***/

#declare Clothes_Shirt_Armor = sor {
	5
	<0.4, -1>
	<0.8, 0>
	<1,	0.8>
	<0.8, 1> 
	<0.4, 2>
	sturm
	scale <0.71, 1.25, 0.5>
	texture {
		T_Clothe_Armor
		scale 0.25
	}
}





/*** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ***/
/*** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ***/
/*** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ****** BOOTS ***/



/* Fancy boots */ 

#declare Clothe_Boot_Leather_Top = difference {
	cylinder {
		<0, -1, 0>
		<0, ShinLen * 0.7, 0>
		LegThickness * 0.9
	}
	box {
		<0, 0, LegThickness>
		<LegThickness, LegThickness, -LegThickness>
		rotate z * 45
		translate <0, (ShinLen - LegThickness) * 0.7, 0>
	}
}

#declare Clothe_Boot_Leather_Heel = intersection {
	sphere {
		<0, 0, 0>
		LegThickness
		scale <1, 1, 2>
	}
	box {
		<-LegThickness * 2, 0, 0>
		<LegThickness * 2, LegThickness * 2, -LegThickness * 2>
	}
	translate -LegThickness * y
}

#declare Clothe_Boot_Leather = union {
	object {
		Clothe_Boot_Leather_Top
	}
	object {
		Clothe_Boot_Leather_Heel
	}
	
	texture {
		pigment {
			Gray05
		}
		finish {
			Phong_Glossy
		}
	}
}



/* barbarian boots */

#declare Clothe_Boot_Barbarian_Top = union {
	cylinder {
		<0, -1, 0>
		<0, ShinLen * 0.5, 0>
		LegThickness * 1
		texture {
			pigment {
				color rgb <0.5, 0.3, 0>
			}
		}
	}
	union {
		cylinder {
			<0, ShinLen * 0.25, 0>
			<0, ShinLen * 0.5, 0>
			LegThickness * 1.2
		}
		torus {
			LegThickness * 0.9
			LegThickness * 0.3
			translate <0, ShinLen * 0.25, 0>
		}
		torus {
			LegThickness * 0.9
			LegThickness * 0.3
			translate <0, ShinLen * 0.5, 0>
		}
		texture {
			pigment {
				color rgb <0.15, 0.10, 0>
			}
		}
	}
}

#declare Clothe_Boot_Barbarian = union {
	object {
		Clothe_Boot_Barbarian_Top
	}
	object {
		Clothe_Boot_Leather_Heel
		texture {
			pigment {
				color rgb <0.5, 0.3, 0>
			}
		}
	}
}

/* Knight solerets */

#declare Clothe_Boot_Soleret_Top = union {
	cone {
		<0, -1, 0>
		LegThickness * 1
		<0, ShinLen * 0.5, 0>
		LegThickness * 1.3
	}
	torus {
		LegThickness * 1
		LegThickness * 0.3
		translate <0, ShinLen * 0.5, 0>
	}
	texture {
		T_Clothe_Armor
	}
}

#declare Clothe_Boot_Soleret = union {
	object {
		Clothe_Boot_Soleret_Top
	}
	object {
		Clothe_Boot_Leather_Heel
		texture {
			T_Clothe_Armor
		}
	}
	cylinder {
		<0, -1, 0>
		<0, ShinLen, 0>
		LegThickness * 1.05
		texture {
			T_Clothe_Armor
		}
	}
	sphere {
		<0, ShinLen, 0>
		LegThickness * 1.15
		texture {
			T_Clothe_Armor
		}
	}
	object {
		Clothe_Armor_Spike
		rotate x * (-90)
		translate <0, ShinLen, -0.5>
		texture {
			T_Clothe_Armor
		}
	}
}






/*** LEGGING ****** LEGGING ****** LEGGING ****** LEGGING ******/
/*** LEGGING ****** LEGGING ****** LEGGING ****** LEGGING ******/
/*** LEGGING ****** LEGGING ****** LEGGING ****** LEGGING ******/

#declare Clothe_Legging_Armor = union {
	cylinder {
		0
		<0, -ShinLen, 0>
		LegThickness * 1.1
	}
	cone {
		0
		LegThickness
		<0, -ShinLen / 2, 0>
		LegThickness * 1.2
	}
	texture {
		T_Clothe_Armor
	}
}






/*** SHOULDER ****** SHOULDER ****** SHOULDER ****** SHOULDER ******/
/*** SHOULDER ****** SHOULDER ****** SHOULDER ****** SHOULDER ******/
/*** SHOULDER ****** SHOULDER ****** SHOULDER ****** SHOULDER ******/

#declare Clothe_Shoulder_Fancy_Blue = union {
	sphere {
		<0, ArmLen, 0>
		ArmThickness * 1.75
		pigment {
			radial
			color_map {
				[0.5 Blue]
				[0.5 Blue * 0.5 ]
			}
			frequency 8
		}
	}
	cylinder {
		<0, ArmLen, 0>
		<0, ArmLen * 0.125, 0>
		ArmThickness * 1.1
		pigment {
			Blue
		}
	}
}


#declare Clothe_Shoulder_Armor_Pad = union {
	sphere {
		<0, ArmLen, 0>
		ArmThickness * 1.75
	}
	/* first shoulder pike */
	object {
		Clothe_Armor_Spike
		translate y * ArmLen
	}
	/* second shoulder pike */
	object {
		Clothe_Armor_Spike
		rotate <0, 0, -60>
		translate y * ArmLen
	}
	cylinder {
		<0, ArmLen, 0>
		<0, ArmLen * 0.125, 0>
		ArmThickness * 1.3
	}
	texture {
		T_Clothe_Armor
	}
}




/*** WRIST ****** WRIST ****** WRIST ****** WRIST ****** WRIST ***/
/*** WRIST ****** WRIST ****** WRIST ****** WRIST ****** WRIST ***/
/*** WRIST ****** WRIST ****** WRIST ****** WRIST ****** WRIST ***/

/* golden wrist bracers */

#declare Clothe_Wrist_Bracer_Gold = torus {
	ArmThickness
	ArmThickness * 0.3
	translate <0, 0.65, 0>
	texture {
		T_Gold_3C
	}
}

#declare Clothe_Wrist_Gauntlet = union {
	cone {
		<0, ForeArmLen, 0>
		ArmThickness * 1.3
		<0, 0, 0>
		ArmThickness * 1.1
	}
	sphere {
		<0, ForeArmLen, 0>
		ArmThickness * 1.6
	}
	object {
		Clothe_Armor_Spike
		rotate z * (-90)
		translate <0, ForeArmLen, 0>
	}
	texture {
		T_Clothe_Armor
	}
}








/*** BELT ****** BELT ****** BELT ****** BELT ****** BELT ******/
/*** BELT ****** BELT ****** BELT ****** BELT ****** BELT ******/
/*** BELT ****** BELT ****** BELT ****** BELT ****** BELT ******/

/* les ceintures sont basées sur des cylindres de diametre 2 */

#declare Clothe_Belt_Type1_Leather = cylinder {
	0
	y * 0.5
	1.9
	pigment {
		Gray10
	}
}

#declare Clothe_Belt_Type1_Buckle = torus {
	0.9
	0.3
	rotate <90, 0, 0>
	scale 0.33
	texture {
		T_Gold_1B
	}
}

#declare Clothe_Belt_Type1 = union {
	object {
		Clothe_Belt_Type1_Leather
	}
	object {
		Clothe_Belt_Type1_Buckle
		translate <0, 0.3, -1.85>
	}
}



/*** HELMS ****** HELMS ****** HELMS ****** HELMS ****** HELMS ******/
/*** HELMS ****** HELMS ****** HELMS ****** HELMS ****** HELMS ******/
/*** HELMS ****** HELMS ****** HELMS ****** HELMS ****** HELMS ******/

#declare Clothe_Helm_Extruder = union {
	box {
		<-0.666, 1, 0>
		<0.666, 0.75, -2>
	}
	box {
		<-0.25 / 2, 1, 0>
		<0.25/2, 0, -2>
	}
}


#declare Clothe_Helm_Type1 = difference {
	sor {
		7
		<1, 0>
		<1, 0.1>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(90)), 1 + sin(radians(90))>
		<0, 2>
		sturm
	}
	Clothe_Helm_Extruder
	texture {
		T_Clothe_Armor
		scale 0.3
	}
}

#declare Clothe_Helm_Horn = sphere_sweep {
	linear_spline
	3
	<0, 0, 0>, 0.5
	<-1, 1, 0>, 0.25
	<-0.75, 2, 0>, 0.1
	scale 0.4
}


#declare Clothe_Helm_Type2 = union {
	object {
		Clothe_Helm_Type1
	}
	object {
		Clothe_Helm_Horn
		translate <-0.8, 1.6, 0>
		texture {
			T_Copper_1A
		}
	}
	object {
		Clothe_Helm_Horn
		scale <-1, 1, 1>
		translate <0.8, 1.6, 0>
		texture {
			T_Copper_1A
		}
	}
}



/*** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ***/
/*** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ***/
/*** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ****** SHIELD ***/

#declare Clothe_Shield_Type1_Base = prism {
	linear_spline
	0, 0.25, 6,
    <-1, 1>, <1, 1>, <1, -1>, <0, -1.5>, <-1, -1>, <-1, 1>
	rotate <-90, 0, 0>
}

#declare Clothe_Shield_Type1_Extruder = object {
	Clothe_Shield_Type1_Base
	scale <0.9, 0.9, 2>
	translate <0, 0, 0>
}

#declare Clothe_Shield_Type1_WoodPanel = object {
	Clothe_Shield_Type1_Base
	scale <0.99, 0.99, 0.5>
	translate <0, 0, -0.05>
}

#declare Clothe_Shield_Pattern_Cross = union {
	box {
		<-0.666, 0.25, 0>
		<0.666, 0, -0.25>
	}
	box {
		<-0.125, 0.666, 0>
		<0.125, -1, -0.25>
	}
	
}

#declare Clothe_Shield_Type1 = union {
	difference {
		object {
			Clothe_Shield_Type1_Base
		}
		object {
			Clothe_Shield_Type1_Extruder
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
		Clothe_Shield_Pattern_Cross
		texture {
			T_Brass_1A
			normal {
				bumps 0.25
				scale 0.05
			}
		}
	}
	object {
		Clothe_Shield_Type1_WoodPanel
		texture {
			T_Wood22
		}
		
	}
	scale 2.333
	translate <0.25, -0.25, 0>
}




/*** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ***/
/*** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ***/
/*** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ****** WEAPON ***/

#declare Weapon_Sword_Hilt = union {
	box {
		<(-ArmThickness) / 2, (-ArmThickness) / 6, ArmThickness / 6>
		<ArmThickness / 2, 0, (-ArmThickness) / 6>
	}
	cylinder {
		0
		<0, -ArmThickness, 0>
		(-ArmThickness) / 6
	}
	texture {
		T_Brass_1A
	}
}

#declare Weapon_Sword_HalfBlade = box {
	0
	1
	translate <-0.5, 0, -0.5>
	rotate 45 * y
}

#declare Weapon_Sword_Blade = union {
	object {
		Weapon_Sword_HalfBlade
		translate <-0.15, 0, 0>
	}
	object {
		Weapon_Sword_HalfBlade
		translate <0.15, 0, 0>
	}
	scale <0.2, 1, 0.075>
	texture {
		T_Chrome_3D
	}
}

#declare Weapon_Sword_Type1 = union {
	object {
		Weapon_Sword_Hilt
	}
	object {
		Weapon_Sword_Blade
	}
	rotate <-90, 0, 0>
}
