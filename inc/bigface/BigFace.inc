/*
 ____  _       _____
| __ )(_) __ _|  ___|_ _  ___ ___
|  _ \| |/ _` | |_ / _` |/ __/ _ \
| |_) | | (_| |  _| (_| | (_|  __/
|____/|_|\__, |_|  \__,_|\___\___|
         |___/

	Big head on a striped belly, flat arms, a knife in the right hand.
	Model of 2012 (2012/inc/bigface.inc, 2012/inc/knife.inc), same shapes and
	sizes, now posed by inc/frames/bigface.inc. Built in the 2012 units, then
	scaled by N_BigFace_Scale around the ground point. Head towards -z.

	Posed by:
		V_Pose_Extra.x    walk phase, degrees (feet, arm swing, bob)
		V_Pose_Extra.y    walk amount (0: standing, 1: walking)
		AV_Arm_Left       left arm around the shoulder, relative to the rest
		                  pose of Pose_Reset() (<0, 0, 10>): z > 0 raises it
		                  sideways, y > 0 swings it forward
		AV_Arm_Right      the same for the right arm (rest <0, 0, -10>):
		                  z < 0 raises it, y < 0 swings it forward
		AV_Wrist_Right    knife, around the grip, relative to <15, 0, 0>
		AV_Head           head, around the neck
		AV_Body           whole body, around the ground point
		V_Body_Offset     moves the whole body (final units)

	Before the include:
		S_BigFace_Face        face image (png, spherical map)
		C_BigFace_Shirt_1/2   colours of the stripes
*/

#ifndef (N_BigFace_Scale)
	#declare N_BigFace_Scale = 0.6;
#end
#ifndef (S_BigFace_Face)
	#declare S_BigFace_Face = "png/bigface_face.png";
#end
#ifndef (C_BigFace_Shirt_1)
	#declare C_BigFace_Shirt_1 = color rgb <0, 0, 0>;
#end
#ifndef (C_BigFace_Shirt_2)
	#declare C_BigFace_Shirt_2 = color rgb <1, 1, 1>;
#end
#ifndef (C_BigFace_Body)
	#declare C_BigFace_Body = color rgb <0.4, 0.4, 0.4>;
#end
#ifndef (N_BigFace_Stride)
	#declare N_BigFace_Stride = 0.8;
#end

#local N_Phase = V_Pose_Extra.x;
#local AV_Left = AV_Arm_Left - <0, 0, 10>;
#local AV_Right = AV_Arm_Right - <0, 0, -10>;
#local AV_Knife = AV_Wrist_Right - <15, 0, 0>;

/*
	Knife
*/
#declare O_BigFace_Knife = union {
	cylinder {
		<0, -0.5, 0>, <0, 0, 0>, 0.125
		pigment { color rgb <0, 0, 0> }
	}
	cylinder {
		<0, 0, 0>, <0, 0.25, 0>, 0.5
		scale <1, 1, 0.1>
		pigment { color rgb <0, 0, 0> }
	}
	cone {
		<0, 0, 0>, 0.25, <0, 1.25, 0>, 0
		scale <1, 1, 0.1>
		translate y * 0.25
		pigment { color rgb <1, 0.8, 0.8> }
	}
}

/*
	Belly: a ball and a striped cone
*/
#declare O_BigFace_Belly = union {
	sphere {
		<0, 1.75, 0>, 1.5
	}
	cone {
		<0, 2, 0>, 1.6, <0, 4, 0>, 0.8
		texture {
			pigment {
				checker
				color C_BigFace_Shirt_1
				color C_BigFace_Shirt_2
			}
			scale <100, 0.333, 100>
			translate <-50, 0, -50>
		}
	}
	pigment { color C_BigFace_Body }
}

#declare O_BigFace_Head = sphere {
	<0, 0, 0>, 2
	pigment {
		image_map {
			png S_BigFace_Face
			map_type 1
		}
	}
}

/*
	Arms: flat ovals, from the shoulder outwards, sagging 20 degrees
*/
#declare O_BigFace_Arm = sphere {
	<0, 0, 0>, 1
	scale <1, 0.333, 0.5>
	pigment { color C_BigFace_Body }
}

#local N_Swing = -18 * sin(radians(N_Phase)) * V_Pose_Extra.y;

#declare O_BigFace_Arm_Left = object {
	O_BigFace_Arm
	translate x
	rotate z * (-20 + AV_Left.z)
	rotate y * AV_Left.y
	translate x * 0.5
	rotate y * N_Swing
	translate y * 2.8
}

#declare O_BigFace_Arm_Right = union {
	object { O_BigFace_Arm }
	object {
		O_BigFace_Knife
		rotate AV_Knife
		translate <-0.75, 0.333, 0>
	}
	translate -x
	rotate z * (20 + AV_Right.z)
	rotate y * AV_Right.y
	translate -x * 0.5
	rotate y * N_Swing
	translate y * 2.8
}

/*
	Feet: half balls, shuffling. The foot moving forward is lifted.
*/
#declare O_BigFace_Foot = intersection {
	sphere { <0, 0, 0>, 1 }
	box { <-1, 0, -1>, <1, 1, 1> }
	pigment { color C_BigFace_Body }
}

#local N_Step = sin(radians(N_Phase)) * N_BigFace_Stride * V_Pose_Extra.y;
#local N_Lift = cos(radians(N_Phase)) * 0.3 * V_Pose_Extra.y;

#declare O_BigFace_Posed = union {
	union {
		object { O_BigFace_Belly }
		object {
			O_BigFace_Head
			translate y * 1.65
			rotate AV_Head
			translate y * 3.6
		}
		object { O_BigFace_Arm_Left }
		object { O_BigFace_Arm_Right }
		translate y * abs(N_Lift) * 0.4
	}
	object {
		O_BigFace_Foot
		translate <1.25, max(0, N_Lift), -N_Step>
	}
	object {
		O_BigFace_Foot
		translate <-1.25, max(0, -N_Lift), N_Step>
	}
	rotate AV_Body
	scale N_BigFace_Scale
	translate V_Body_Offset
}
