#include "colors.inc"
#include "debug.inc"
#include "inc/Camera.inc"
#include "inc/BodyTextures.inc"

#declare BlobTreshold = 0.158;

#include "inc/BodyLengthes.inc"

#declare LegShift = 0.1;
#declare ButtShift = 0.3;
#declare ArmShift = 2.35;
#declare BoobPos = 0.75;

#ifndef (A_LegLeft) 
	/* left */
	/* leg */
	#declare A_LegLeft = 0;
	#declare A_KneelLeft = 0;
	/* arm */
	#declare A_ArmLeft = 0;
	#declare A_ForeArmLeft = 0;

	/* right */
	/* leg */
	#declare A_LegRight = 0;
	#declare A_KneelRight = 0;
	/* arm */
	#declare A_ArmRight = 0;
	#declare A_ForeArmRight = 0;
#end

#declare V_KneelPosLeft = <0, (-ThighLen) * cos(radians(A_LegLeft)), (-ThighLen) * sin(radians(A_LegLeft))>;
#declare V_FootPosLeft = V_KneelPosLeft + <0, (-ShinLen) * cos(radians(A_KneelLeft + A_LegLeft)), (-ShinLen) * sin(radians(A_KneelLeft + A_LegLeft))>;
#declare V_ElbowPosLeft = <0, (-ArmLen) * cos(radians(A_ArmLeft)), (-ArmLen) * sin(radians(A_ArmLeft))>;
#declare V_HandPosLeft = V_ElbowPosLeft + <0, (-ForeArmLen) * cos(radians(A_ForeArmLeft + A_ArmLeft)), (-ForeArmLen) * sin(radians(A_ForeArmLeft + A_ArmLeft))>;
#declare V_KneelPosRight = <0, (-ThighLen) * cos(radians(A_LegRight)), (-ThighLen) * sin(radians(A_LegRight))>;
#declare V_FootPosRight = V_KneelPosRight + <0, (-ShinLen) * cos(radians(A_KneelRight + A_LegRight)), (-ShinLen) * sin(radians(A_KneelRight + A_LegRight))>;
#declare V_ElbowPosRight = <0, (-ArmLen) * cos(radians(A_ArmRight)), (-ArmLen) * sin(radians(A_ArmRight))>;
#declare V_HandPosRight = V_ElbowPosRight + <0, (-ForeArmLen) * cos(radians(A_ForeArmRight + A_ArmRight)), (-ForeArmLen) * sin(radians(A_ForeArmRight + A_ArmRight))>;


#declare P_LegLeft = union {
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, LegThickness
		V_KneelPosLeft, LegThickness * 0.9
		V_FootPosLeft,	LegThickness * 0.7
	}
	sphere {
		0
		1
		scale <1.2, 1.2, 1>
		translate <ButtShift, 0, ButtShift>
	}
	texture {
		T_Legs
	}
}

#declare P_LegRight = union {
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, LegThickness
		V_KneelPosRight, LegThickness * 0.9
		V_FootPosRight,	LegThickness * 0.7
	}
	sphere {
		0
		1
		scale <1.2, 1.2, 1>
		translate <-ButtShift, 0, ButtShift>
	}
	texture {
		T_Legs
	}
}

#ifndef (P_Boot)
	#declare P_Boot = union {
		cylinder {
			<0, 0, 0>
			<0, ShinLen * 0.7, 0>
			LegThickness * 0.9
		}
		cylinder {
			<0, 0, 0>
			<0, -LegThickness, 0>
			LegThickness * 1.1
		}
		pigment {
			Green
		}
	}
#end

#declare P_LegBootLeft = union {
	object {
		P_LegLeft
	}
	object {
		P_Boot
		rotate x * (A_KneelLeft + A_LegLeft)
		translate V_FootPosLeft
	}
}

#declare P_LegBootRight = union {
	object {
		P_LegRight
	}
	object {
		P_Boot
		scale <-1, 1, 1>
		rotate x * (A_LegRight + A_KneelRight)
		translate V_FootPosRight
	}
}

#declare P_Legs = union {
	object {
		P_LegBootLeft
		translate <-1.1, 0, 0>
	}
	object {
		P_LegBootRight
		translate <1.1, 0, 0>
	}
}

#ifndef (P_Belt)
	#declare P_Belt = cylinder {
		0
		y
		3
		pigment {
			Green
		}
	}
#end

#declare P_Torso = union {
	blob {
		threshold 0.5
		sphere {
			0
			3 
			2
			scale <1, 0.5, 0.5>
		}
		cylinder {
			0.5 * y
			TorsoLen * y
			2.5
			2
			scale <1, 1, 0.5>
		}
		sphere {
			<2.2, TorsoLen + 0.5, 0>
			1.2
			1
		}
		sphere {
			<-2.2, TorsoLen + 0.5, 0>
			1.2
			1
		}
		sphere {
			<BoobPos, TorsoLen, -BoobSize / 2>
			BoobSize 
			2
		}
		sphere {
			<-BoobPos, TorsoLen, -BoobSize / 2>
			BoobSize 
			2
		}
		texture {
			T_Torso
		}
	}
	object {
		P_Belt
		scale <1, 1, 0.5>
		translate <0, 1.6, 0>
	}
}



#ifndef (P_ArmWear)
	#declare P_ArmWear = union {
		sphere {
			<0, ArmLen, 0>
			ArmThickness * 1.75
			pigment {
				Gray10
			}
		}
		cylinder {
			<0, ArmLen, 0>
			<0, ArmLen * 0.125, 0>
			ArmThickness * 1.1
			pigment {
				Gray10
			}
		}
	}
#end



#ifndef (P_Glove)
	#declare P_Glove = union {
		cylinder {
			<0, ForeArmLen, 0>
			<0, ForeArmLen * 0.25, 0>
			ArmThickness * 1.1
		}
		sphere {
			<0, ForeArmLen, 0>
			ArmThickness * 1.15
		}
		pigment {
			Gray10
		}
	}
#end

#ifndef (P_Glove_Right)
	#declare P_Glove_Right = P_Glove;
#end

#ifndef (P_Glove_Left)
	#declare P_Glove_Left = P_Glove;
#end


#declare P_Finger = sphere_sweep {
	linear_spline
	3
	<0, 0, 0>, FingerThickness
	<0, -FingerLen, 0>, FingerThickness
	<-FingerLen / 4, (-1.5) * FingerLen, 0>, FingerThickness
}
#declare P_Thumb = sphere_sweep {
	linear_spline
	3
	<FingerLen * 0.4, FingerLen * 0.3, FingerLen * 0.3>, FingerThickness * 1.5
	<0, 0, 0>, FingerThickness
	<0, -FingerLen * 0.75, 0>, FingerThickness
}
#declare P_Fingers = union {
	object {
		P_Finger
	}
	object {
		P_Finger
		translate <0, 0, -1.8 * FingerThickness>
	}
	object {
		P_Finger
		translate <0, 0, 1.8 * FingerThickness>
	}
	object {
		P_Thumb
		rotate <5, 0, 5>
		translate <-2.5 * FingerThickness, 0.3, -2.5 * FingerThickness>
	}
	blob {
		threshold BlobTreshold
		sphere {
			<0, 0, -1.8 * FingerThickness>, FingerThickness * 1.6, 0.5
		}
		sphere {
			<0, 0, 0>, FingerThickness * 1.6, 0.5
		}
		sphere {
			<0, 0, 1.8 * FingerThickness>, FingerThickness * 1.6, 0.5
		}
		sphere {
			<0, ArmThickness, 0>, ArmThickness * 1.2, 2
			scale <0.5, 0.7, 1>
		}
	}
}
#declare P_Hand = union {
	object {
		P_Fingers
		translate <ArmThickness * 0.5, -0.5, 0>
	}
	texture {
		T_Arms
	}
}


#declare P_ArmLeft = sphere_sweep {
	linear_spline
	3
	0, ArmThickness
	V_ElbowPosLeft, ArmThickness * 0.9
	V_HandPosLeft, ArmThickness * 0.7
	texture {
		T_Arms
	}
}

#declare P_ArmGloveLeft = union {
	object {
		P_ArmLeft
	}
	object {
		P_Hand
		rotate x * (A_ForeArmLeft + A_ArmLeft)
		translate V_HandPosLeft
	}
	object {
		P_Glove_Left
		rotate x * (A_ForeArmLeft + A_ArmLeft)
		translate V_HandPosLeft
	}
	object {
		P_ArmWear
		rotate x * A_ArmLeft
		translate V_ElbowPosLeft
	}
	rotate z * 10
	translate ArmShift * x
}

#declare P_ArmRight = sphere_sweep {
	linear_spline
	3
	0, ArmThickness
	V_ElbowPosRight, ArmThickness * 0.9
	V_HandPosRight, ArmThickness * 0.7
	texture {
		T_Arms
	}
}

#declare P_ArmGloveRight = union {
	object {
		P_ArmRight
	}
	object {
		P_Hand
		scale <-1, 1, 1>
		rotate x * (A_ForeArmRight + A_ArmRight)
		translate V_HandPosRight
	}
	object {
		P_Glove_Right
		scale <-1, 1, 1>
		rotate x * (A_ForeArmRight + A_ArmRight)
		translate V_HandPosRight
	}
	object {
		P_ArmWear
		scale <-1, 1, 1>
		rotate x * A_ArmRight
		translate V_ElbowPosRight
	}
	rotate (-z) * 10
	translate (-ArmShift) * x
}


#declare P_Arms = union {
	object {
		P_ArmGloveLeft
	}
	object {
		P_ArmGloveRight
	}
	translate (0.5 + TorsoLen) * y
}

#declare P_Neck = sor {
	7
	<0.25 + 0, 		-1>
	<0.25 + 0, 		0>
	<0.25 + 0.03,	0.26>
	<0.25 + 0.13,	0.5>
	<0.25 + 0.29,	0.71>
	<0.25 + 0.5,	0.87>
	<0.25 + 1,		1>
	sturm
	scale <1, -1, 1>
	translate y
	scale <2, 2, 1>
	translate <0, TorsoLen + 0.6, 0>
	texture {
		T_Skin
	}
}


#ifndef (T_Face) 
	#declare T_Face = texture {
		pigment {
			color rgbf <0, 0, 0, 0>
		}	
	}
#end

#declare P_Face = ovus {
	1
	0.2
	scale <1, -1, 1>
	texture {
		T_Head
	}
	texture {
		T_Face
	}
}

#ifndef (P_Hair) 
	#declare P_Hair_Extruder = prism {
		linear_spline
		0
		1.333
		3
		<0, 0>
		<3, -2>
		<-3, -2>
	}
	#declare P_Hair = difference {
		sor {
			8
			<1.5, 0>
			<1.25, 0.125>
			<1, 0.5>
			<cos(radians(0)), 1 + sin(radians(0))>
			<cos(radians(30)), 1 + sin(radians(30))>
			<cos(radians(60)), 1 + sin(radians(60))>
			<cos(radians(85)), 1 + sin(radians(85))>
			<0, 2>
			open
			sturm
		}
		object {
			P_Hair_Extruder
		}
		texture {
			pigment {
				color rgbf <1, 0, 0, 0.5>
			}
		}
	}
#end

#declare P_Head = union {
	object {
		P_Face
		scale HeadSize
		rotate <30, 0, 0>
	}
	object {
		P_Hair
		scale <2.75, 3, 2.75>
		translate (-3) * y
	}
	translate <0, TorsoLen + HeadSize + 2, 0>
}
