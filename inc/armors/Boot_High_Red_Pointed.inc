#include "inc/body/BodyMetrics.inc"

/*
 _     _       _       _                 _
| |__ (_) __ _| |__   | |__   ___   ___ | |_
| '_ \| |/ _` | '_ \  | '_ \ / _ \ / _ \| __|
| | | | | (_| | | | | | |_) | (_) | (_) | |_
|_| |_|_|\__, |_| |_| |_.__/ \___/ \___/ \__|
         |___/

	High boots of glossy red leather: they reach just under the knee
	(N_Boot_High_Top, fraction of the shin), the top edge rising to a point in
	front of the knee (N_Boot_High_Point). Small heel.
	In the frame of P_BodyPart_ArmorPart_Shin: y = 0 at the ankle, N_Shin_Len
	at the knee, front towards -z.
*/

#ifndef (N_Boot_High_Top)
	#declare N_Boot_High_Top = 0.82;
#end
#ifndef (N_Boot_High_Point)
	#declare N_Boot_High_Point = 1.02; // height of the point, in front
#end
#ifndef (T_Boot_High)
	#declare T_Boot_High = texture {
		pigment { color rgb <0.55, 0.03, 0.05> }
		finish {
			ambient 0.1
			diffuse 0.6
			specular 0.9
			roughness 0.006
			reflection 0.05
		}
	}
#end

#local N_Boot_Radius = N_Leg_Thickness * 1.12;
#local N_Top = N_Shin_Len * N_Boot_High_Top;
#local N_Point = N_Shin_Len * N_Boot_High_Point;
// slope of the two sides of the point: at the side of the boot, back at N_Top
#local N_Point_Angle = degrees(atan2(N_Point - N_Top, N_Boot_Radius));

#declare P_BodyPart_ArmorPart_Shin = union {
	intersection {
		cylinder {
			<0, -N_Leg_Thickness, 0>
			<0, N_Point, 0>
			N_Boot_Radius
		}
		// straight top at the back, a point (two slanted planes) in front
		union {
			plane { y, N_Top }
			intersection {
				plane { y, 0 rotate z * N_Point_Angle translate y * N_Point }
				plane { y, 0 rotate z * -N_Point_Angle translate y * N_Point }
				plane { z, 0 }
			}
		}
	}
	// foot (as Boot_Leather_Gray_Glossy)
	intersection {
		sphere {
			<0, 0, 0>
			N_Boot_Radius
			scale <1, 1, 2>
		}
		box {
			<-N_Leg_Thickness * 2, 0, N_Leg_Thickness>
			<N_Leg_Thickness * 2, N_Leg_Thickness * 2, -N_Leg_Thickness * 2>
		}
		translate -N_Leg_Thickness * y
	}
	// heel
	cone {
		<0, -N_Leg_Thickness, N_Leg_Thickness * 0.7>, N_Leg_Thickness * 0.35
		<0, -N_Leg_Thickness * 1.6, N_Leg_Thickness * 0.8>, N_Leg_Thickness * 0.2
	}
	texture { T_Boot_High }
}
