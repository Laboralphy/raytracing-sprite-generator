#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/BodyTextures.inc"

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

#declare BoobSize = 1.5;
#declare BoobPos = 0.75;

#declare HeadSize = 2;


#macro RotatePoint(V_Point, V_Angle)

	#local pitch = radians(V_Angle.x);
	#local yaw = radians(V_Angle.y);
	#local roll = radians(V_Angle.z);

    #local cosa = cos(yaw);
    #local sina = sin(yaw);

    #local cosb = cos(pitch);
    #local sinb = sin(pitch);

    #local cosc = cos(roll);
    #local sinc = sin(roll);

    #local Axx = cosa * cosb;
    #local Axy = cosa * sinb * sinc - sina * cosc;
    #local Axz = cosa * sinb * cosc + sina * sinc;

    #local Ayx = sina * cosb;
    #local Ayy = sina * sinb * sinc + cosa * cosc;
    #local Ayz = sina * sinb * cosc - cosa * sinc;

    #local Azx = -sinb;
    #local Azy = cosb * sinc;
    #local Azz = cosb * cosc;

	#local px = V_Point.x;
    #local py = V_Point.y;
    #local pz = V_Point.z;

    <
		Axx * px + Axy * py + Axz * pz, 
        Ayx * px + Ayy * py + Ayz * pz,
        Azx * px + Azy * py + Azz * pz
	>;
#end

#declare A_LegLeft = 45;
#declare A_KneelLeft = 80;
#declare AV_LegLeft = <A_LegLeft, 0, 0>;
#declare AV_ArmLeft = <0, 0, -10>;
#declare AV_ForeArmLeft = <0, 0, 0>;
#declare V_KneelLeft = <0, -ThighLen, 0>;
#declare V_FootLeft = 
<
	-LegShift, 
	-ThighLen - ShinLen * cos(radians(A_KneelLeft)), 
	ShinLen * sin(radians(A_KneelLeft))
>;
#declare V_BootBaseLeft = RotatePoint(V_FootLeft, AV_LegLeft);

#declare A_KneelRight = 0;
#declare A_LegRight = 0;
#declare AV_LegRight = <A_LegRight, 0, 0>;
#declare AV_ArmRight = <0, 0, 10>;
#declare AV_ForeArmRight = <0, 0, 0>;
#declare V_KneelRight = <0, -ThighLen, 0>;
#declare V_FootRight =
<
	LegShift, 
	-ThighLen - ShinLen * cos(radians(A_KneelRight)), 
	ShinLen * sin(radians(A_KneelRight))
>;
#declare V_BootBaseRight = RotatePoint(V_FootRight, AV_LegRight);


#declare P_LegLeft = union {
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, LegThickness
		V_KneelLeft, LegThickness * 0.9
		V_FootLeft,	LegThickness * 0.7
		rotate AV_LegLeft
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
		V_KneelRight, LegThickness * 0.9
		V_FootRight, LegThickness * 0.7
		rotate AV_LegRight
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

#declare P_Legs = union {
	object {
		P_LegLeft
		translate <-1.1, 0, 0>
	}
	object {
		P_LegRight
		translate <1.1, 0, 0>
	}
}

#declare P_Torso = blob {
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

#declare P_ArmLeft = blob {
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
		rotate AV_ForeArmLeft
		translate <0, -ArmLen, 0>
	}
	rotate AV_ArmLeft
	translate -ArmShift * x
	texture {
		T_Arms
	}
}

#declare P_ArmRight = blob {
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
		rotate AV_ForeArmRight
		translate <0, -ArmLen, 0>
	}
	rotate AV_ArmRight
	translate ArmShift * x
	texture {
		T_Arms
	}
}

#declare P_Arms = union {
	object {
		P_ArmLeft
	}
	object {
		P_ArmRight
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

#declare P_Head = ovus {
	2
	0.4
	scale <1.4, -1.4, 1.4>
	rotate <30, 0, 0>
	translate 0.5 * y
	texture {
		T_Head
	}
	translate <0, TorsoLen + HeadSize + 2, 0>
}

