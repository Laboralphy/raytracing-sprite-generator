#ifndef (BODY_METRICS_INCLUDED)
	#declare BODY_METRICS_INCLUDED = 1;

	/* global size of the body */
	#ifndef (N_BodyMetrics_Value) 
		#declare N_BodyMetrics_Value = 1;
	#end

	/* member size (if body size = 1) */
	#ifndef (N_BodyMetrics_Member_Factor) 
		#declare N_BodyMetrics_Member_Factor = 0.87;
	#end
	
	/* leg thickness */
	#ifndef (N_BodyMetrics_Leg_Thickness) 
		#declare N_BodyMetrics_Leg_Thickness = 0.175;
	#end
	
	/* arm thickness */
	#ifndef (N_BodyMetrics_Arm_Thickness) 
		#declare N_BodyMetrics_Arm_Thickness = 0.125;
	#end
	
	#declare N_Torso_Len = N_BodyMetrics_Value; // size of torso from shoulder to legs
	#declare N_Shoulder_Len = N_Torso_Len; // distance between two shoulders
	#declare N_Lower_Member_Len = N_Torso_Len * N_BodyMetrics_Member_Factor; // default memebrs length
	#declare N_Upper_Member_Len = N_Torso_Len * N_BodyMetrics_Member_Factor * 0.75; // default memebrs length
	#declare N_Arm_Len = N_Upper_Member_Len; // arm length from shoulder to elbow
	#declare N_Wrist_Len = N_Upper_Member_Len; // distance from elbow to hand
	#declare N_Thigh_Len = N_Lower_Member_Len; // distance from torso to kneel
	#declare N_Shin_Len = N_Lower_Member_Len; // distance from kneel to foot
	#declare N_Neck_Len = N_Torso_Len * 0.666; 
	#declare N_Head_Size = N_Shoulder_Len / 1.75;
	#declare N_BodyPart_Boobs_Size = N_Shoulder_Len / 3;
	#declare N_BodyPart_Boobs_Spacing = N_Shoulder_Len / 5;
	#declare N_Leg_Thickness = N_BodyMetrics_Leg_Thickness;
	#declare N_Arm_Thickness = N_BodyMetrics_Arm_Thickness;
	#declare N_Finger_Thickness = N_BodyMetrics_Arm_Thickness * 0.35;
	#declare N_Finger_Len = N_Arm_Thickness * 1.0;
	#declare N_Belt_Height = N_Torso_Len / 10;

	#ifndef (AV_Thigh_Left)
		#declare AV_Thigh_Left = <0, 0, 0>;
	#end
	
	#ifndef (AV_Shin_Left)
		#declare AV_Shin_Left = <0, 0, 0>;
	#end
	
	#ifndef (AV_Thigh_Right)
		#declare AV_Thigh_Right = <0, 0, 0>;
	#end
	
	#ifndef (AV_Shin_Right)
		#declare AV_Shin_Right = <0, 0, 0>;
	#end

	#ifndef (AV_Arm_Left)
		#declare AV_Arm_Left = <0, 0, 10>;
	#end
	
	#ifndef (AV_Wrist_Left)
		#declare AV_Wrist_Left = <15, 0, 0>;
	#end
	
	#ifndef (AV_Arm_Right)
		#declare AV_Arm_Right = <0, 0, -10>;
	#end
	
	#ifndef (AV_Wrist_Right)
		#declare AV_Wrist_Right = <15, 0, 0>;
	#end

	#declare V_BodyPart_Torso_Scale = <1, 1, 0.65>;
#end
