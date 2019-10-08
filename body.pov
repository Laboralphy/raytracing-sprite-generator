#include "colors.inc"
#include "inc/Camera.inc"

#declare BlobTreshold = 0.158;

#declare ShinLen = 3;
#declare ThighLen = 3;
#declare TorsoLen = 4;
#declare ArmLen = 2.5;
#declare ForeArmLen = 2.5;

#declare LegThickness = 1;
#declare ArmThickness = 0.55;

#declare LegShift = 0.1;
#declare ButtShift = 0.3;
#declare ArmShift = 2.35;

#declare BoobSize = 1.4;
#declare BoobPos = 0.75;

#declare HeadSize = 2;

#declare AngleKneelLeft = 0;
#declare AngleLegLeft = <0, 0, 0>;
#declare AngleArmLeft = <0, 0, -10>;
#declare AngleForeArmLeft = <0, 0, 0>;

#declare AngleKneelRight = 30;
#declare AngleLegRight = <-30, 0, 0>;
#declare AngleArmRight = <0, 0, 10>;
#declare AngleForeArmRight = <0, 0, 0>;


#declare C_Legs = Gray50;
#declare C_Torso = Gray40;
#declare C_Arms = Gray70;

#declare LegLeft = union {
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, LegThickness
		<0, -ThighLen, 0>, LegThickness * 0.9
		<
			-LegShift, 
			-ThighLen - ShinLen * cos(radians(AngleKneelLeft)), 
			ShinLen * sin(radians(AngleKneelLeft))
		>, LegThickness * 0.7
		rotate AngleLegLeft
	}
	sphere {
		<ButtShift, 0, ButtShift>
		1.2
	}
	pigment { 
		C_Legs 
	}
}

#declare LegRight = union {
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, LegThickness
		<0, -ThighLen, 0>, LegThickness * 0.9
		<
			LegShift, 
			-ThighLen - ShinLen * cos(radians(AngleKneelRight)), 
			ShinLen * sin(radians(AngleKneelRight))
		>, LegThickness * 0.7
		rotate AngleLegRight
	}
	sphere {
		<-ButtShift, 0, ButtShift>
		1.2
	}
	pigment { 
		C_Legs 
	}
}

#declare Legs = union {
	object {
		LegLeft
		translate <-1.1, 0, 0>
	}
	object {
		LegRight
		translate <1.1, 0, 0>
	}
}

#declare Torso = blob {
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
	pigment {
		C_Torso
	}
}

#declare ArmLeft = blob {
	threshold BlobTreshold
	cylinder {
		ArmThickness * x
		ArmShift * x
		ArmThickness
		1.2
	}
	cylinder { 
		0
		(-ArmLen) * y
		ArmThickness
		1.2 
	}
	cylinder { 
		0
		(-ForeArmLen) * y
		ArmThickness * 0.95
		1.2
		rotate AngleForeArmLeft
		translate <0, -ArmLen, 0>
	}
	rotate AngleArmLeft
	translate -ArmShift * x
	pigment { 
		C_Arms 
	}
}

#declare ArmRight = blob {
	threshold BlobTreshold
	cylinder {
		(-ArmThickness) * x
		(-ArmShift) * x
		ArmThickness
		1.2
	}
	cylinder { 
		0
		(-ArmLen) * y
		ArmThickness
		1.2 
	}
	cylinder { 
		0
		(-ForeArmLen) * y
		ArmThickness * 0.95
		1.2
		rotate AngleForeArmRight
		translate <0, -ArmLen, 0>
	}
	rotate AngleArmRight
	translate ArmShift * x
	pigment { 
		C_Arms 
	}
}

#declare Arms = union {
	object {
		ArmLeft
	}
	object {
		ArmRight
	}
	translate (0.5 + TorsoLen) * y
}

#declare Neck = sor {
	7
	<0.25 + 0, 		-1>
	<0.25 + 0, 		0>
	<0.25 + 0.03,	0.26>
	<0.25 + 0.13,	0.5>
	<0.25 + 0.29,	0.71>
	<0.25 + 0.5,	0.87>
	<0.25 + 1,		1>
	sturm
	scale -y
	translate y
	scale <2, 2, 1>
	translate <0, TorsoLen + 0.6, 0>
	pigment {
		C_Torso
	}
}

#declare Head = ovus {
	2
	0.4
	scale <1.4, -1.4, 1.4>
	rotate <30, 0, 0>
	translate 0.5 * y
	pigment {
		C_Torso
	}
}

#declare Body = union {
	object {
		Legs
	}
	object {
		Torso
	}
	object {
		Arms
	}
	object {
		Neck
	}
	object {
		Head
		translate <0, TorsoLen + HeadSize + 2, 0>
	}
	translate (LegThickness + ThighLen + ShinLen) * y
	scale 0.3
}



#declare Skirt_1 = sor {
	6
	<0, 0>
	<0.5, 0.1>
	<0.75, 0.5>
	<0.9, 0.9>
	<1, 1>
	<1, 2>
	scale <1.8, -1.7, 1>
	translate <0, 1, 0>
	pigment {
		C_Torso
	}
}




union {
	object {
		Body
	}
/*	object {
		Skirt_1
	}*/
	rotate AnimationAngle * y
}

