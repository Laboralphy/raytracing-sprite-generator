/*
 ____
|  _ \ ___  ___  ___
| |_) / _ \/ __|/ _ \
|  __/ (_) \__ \  __/
|_|   \___/|___/\___|

	Sets the pose variables (AV_*, V_Body_Offset) for the body, and
	V_Pose_Extra: free for a character's own needs (the body ignores it;
	see inc/jack/Jack.inc), interpolated like the others.

	The including file (inc/frames/<character>.inc) first defines
		#macro Pose_Define(N_Pose) ... #end
	which declares the pose number N_Pose: it only needs to declare what
	differs from Pose_Reset().

	Then this file applies pose N_Pose_From, blended towards N_Pose_To by
	N_Pose_Blend (see inc/Animation.inc). With N_Pose_Blend = 0, it is exactly
	pose N_Pose_From, with no computation.
*/

#macro Pose_Reset()
	/* Same defaults as inc/body/BodyMetrics.inc */
	#declare AV_Thigh_Left = <0, 0, 0>;
	#declare AV_Shin_Left = <0, 0, 0>;
	#declare AV_Thigh_Right = <0, 0, 0>;
	#declare AV_Shin_Right = <0, 0, 0>;
	#declare AV_Arm_Left = <0, 0, 10>;
	#declare AV_Wrist_Left = <15, 0, 0>;
	#declare AV_Arm_Right = <0, 0, -10>;
	#declare AV_Wrist_Right = <15, 0, 0>;
	#declare AV_Torso = <0, 0, 0>;
	#declare AV_Head = <0, 0, 0>;
	#declare AV_Body = <0, 0, 0>;
	#declare V_Body_Offset = <0, 0, 0>;
	#declare V_Pose_Extra = <0, 0, 0>;
#end

#declare N_Pose_Vector_Count = 13;

#macro Pose_Store()
	array[N_Pose_Vector_Count] {
		AV_Thigh_Left, AV_Shin_Left, AV_Thigh_Right, AV_Shin_Right,
		AV_Arm_Left, AV_Wrist_Left, AV_Arm_Right, AV_Wrist_Right,
		AV_Torso, AV_Head, AV_Body, V_Body_Offset,
		V_Pose_Extra
	}
#end

#macro Pose_Load(A_Pose)
	#declare AV_Thigh_Left = A_Pose[0];
	#declare AV_Shin_Left = A_Pose[1];
	#declare AV_Thigh_Right = A_Pose[2];
	#declare AV_Shin_Right = A_Pose[3];
	#declare AV_Arm_Left = A_Pose[4];
	#declare AV_Wrist_Left = A_Pose[5];
	#declare AV_Arm_Right = A_Pose[6];
	#declare AV_Wrist_Right = A_Pose[7];
	#declare AV_Torso = A_Pose[8];
	#declare AV_Head = A_Pose[9];
	#declare AV_Body = A_Pose[10];
	#declare V_Body_Offset = A_Pose[11];
	#declare V_Pose_Extra = A_Pose[12];
#end

#if (N_Pose_Blend = 0)
	Pose_Reset()
	Pose_Define(N_Pose_From)
#else
	Pose_Reset()
	Pose_Define(N_Pose_From)
	#local A_Pose_From = Pose_Store();
	Pose_Reset()
	Pose_Define(N_Pose_To)
	#local A_Pose_To = Pose_Store();
	#local A_Pose_Blend = array[N_Pose_Vector_Count];
	#local I = 0;
	#while (I < N_Pose_Vector_Count)
		#local A_Pose_Blend[I] = A_Pose_From[I] * (1 - N_Pose_Blend) + A_Pose_To[I] * N_Pose_Blend;
		#local I = I + 1;
	#end
	Pose_Load(A_Pose_Blend)
#end
