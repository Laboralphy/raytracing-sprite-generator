/*
	Poses of the troll: bow legs (thighs y -10, z +-30, shins z -+45), arms
	held away from the body (z +-50), unarmed.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Thigh_Left = <0, -10, 30>;
			#declare AV_Shin_Left = <0, 0, -45>;
			#declare AV_Thigh_Right = <0, -10, -30>;
			#declare AV_Shin_Right = <0, 0, 45>;
			#declare AV_Arm_Left = <0, 0, 50>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <0, 0, -50>;
			#declare AV_Wrist_Right = <0, 0, 60>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (1)
			// ATTACK 1: right claw drawn back
			#declare AV_Thigh_Left = <30, -10, 30>;
			#declare AV_Shin_Left = <-30, 0, -45>;
			#declare AV_Thigh_Right = <-15, -10, -30>;
			#declare AV_Shin_Right = <-35, 0, 45>;
			#declare AV_Arm_Left = <20, 0, 50>;
			#declare AV_Wrist_Left = <10, 0, -60>;
			#declare AV_Arm_Right = <0, 0, -50>;
			#declare AV_Wrist_Right = <90, 0, 60>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (2)
			// ATTACK 2: strike
			#declare AV_Thigh_Left = <30, -10, 30>;
			#declare AV_Shin_Left = <-30, 0, -45>;
			#declare AV_Thigh_Right = <-5, -10, -30>;
			#declare AV_Shin_Right = <-45, 0, 45>;
			#declare AV_Arm_Left = <0, 0, 50>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <90, 0, -50>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (3)
			// WALK 1
			#declare AV_Thigh_Left = <30, -10, 30>;
			#declare AV_Shin_Left = <-30, 0, -45>;
			#declare AV_Thigh_Right = <-15, -10, -30>;
			#declare AV_Shin_Right = <-35, 0, 45>;
			#declare AV_Arm_Left = <-20, 0, 50>;
			#declare AV_Wrist_Left = <10, 0, -60>;
			#declare AV_Arm_Right = <20, 0, -50>;
			#declare AV_Wrist_Right = <10, 0, 60>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (4)
			// WALK 2
			#declare AV_Thigh_Left = <15, -10, 30>;
			#declare AV_Shin_Left = <-30, 0, -45>;
			#declare AV_Thigh_Right = <10, -10, -30>;
			#declare AV_Shin_Right = <-20, 0, 45>;
			#declare AV_Arm_Left = <-5, 0, 50>;
			#declare AV_Wrist_Left = <5, 0, -60>;
			#declare AV_Arm_Right = <5, 0, -50>;
			#declare AV_Wrist_Right = <5, 0, 60>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (5)
			// WALK 3
			#declare AV_Thigh_Left = <-15, -10, 30>;
			#declare AV_Shin_Left = <-35, 0, -45>;
			#declare AV_Thigh_Right = <30, -10, -30>;
			#declare AV_Shin_Right = <-30, 0, 45>;
			#declare AV_Arm_Left = <15, 0, 50>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <-20, 0, -50>;
			#declare AV_Wrist_Right = <10, 0, 60>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (6)
			// IDLE: hunched, swaying, arms hanging
			#declare AV_Thigh_Left = <8, -10, 30>;
			#declare AV_Shin_Left = <-15, 0, -45>;
			#declare AV_Thigh_Right = <5, -10, -30>;
			#declare AV_Shin_Right = <-12, 0, 45>;
			#declare AV_Arm_Left = <15, 0, 40>;
			#declare AV_Wrist_Left = <15, 0, -50>;
			#declare AV_Arm_Right = <10, 0, -45>;
			#declare AV_Wrist_Right = <10, 0, 55>;
			#declare AV_Torso = <-12, 8, 5>;
			#declare AV_Head = <10, -15, 0>;
			#declare V_Body_Offset = y * -0.18;
		#break

		#case (7)
			// PAIN: thrown backward, arms flung up
			#declare AV_Thigh_Left = <-10, -10, 30>;
			#declare AV_Shin_Left = <-20, 0, -45>;
			#declare AV_Thigh_Right = <15, -10, -30>;
			#declare AV_Shin_Right = <-30, 0, 45>;
			#declare AV_Arm_Left = <40, 0, 70>;
			#declare AV_Wrist_Left = <40, 0, -40>;
			#declare AV_Arm_Right = <30, 0, -75>;
			#declare AV_Wrist_Right = <40, 0, 40>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <25, -10, 0>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (8)
			// DEATH 1: hit, head thrown back, knees giving way
			#declare AV_Thigh_Left = <25, -10, 30>;
			#declare AV_Shin_Left = <-45, 0, -45>;
			#declare AV_Thigh_Right = <15, -10, -30>;
			#declare AV_Shin_Right = <-35, 0, 45>;
			#declare AV_Arm_Left = <50, 0, 65>;
			#declare AV_Wrist_Left = <40, 0, -40>;
			#declare AV_Arm_Right = <40, 0, -65>;
			#declare AV_Wrist_Right = <50, 0, 40>;
			#declare AV_Torso = <25, 0, 0>;
			#declare AV_Head = <35, 0, 0>;
			#declare V_Body_Offset = y * -0.45;
		#break

		#case (9)
			// DEATH 2: knees buckling, twisting to the side
			#declare AV_Thigh_Left = <60, -10, 20>;
			#declare AV_Shin_Left = <-100, 0, -30>;
			#declare AV_Thigh_Right = <45, -10, -20>;
			#declare AV_Shin_Right = <-90, 0, 30>;
			#declare AV_Arm_Left = <70, 0, 60>;
			#declare AV_Wrist_Left = <30, 0, -40>;
			#declare AV_Arm_Right = <40, 0, -40>;
			#declare AV_Wrist_Right = <40, 0, 40>;
			#declare AV_Torso = <10, -20, 15>;
			#declare AV_Head = <20, 0, 20>;
			#declare AV_Body = <0, 0, 15>;
			#declare V_Body_Offset = <1.0, -1.0, 0>;
		#break

		#case (10)
			// DEATH 3: falling on the right side
			#declare AV_Thigh_Left = <85, -10, 15>;
			#declare AV_Shin_Left = <-130, 0, -20>;
			#declare AV_Thigh_Right = <65, -10, -15>;
			#declare AV_Shin_Right = <-120, 0, 20>;
			#declare AV_Arm_Left = <90, 0, 50>;
			#declare AV_Wrist_Left = <20, 0, -30>;
			#declare AV_Arm_Right = <60, 0, -30>;
			#declare AV_Wrist_Right = <30, 0, 30>;
			#declare AV_Torso = <-25, -20, 10>;
			#declare AV_Head = <-10, 0, 25>;
			#declare AV_Body = <0, 0, 50>;
			#declare V_Body_Offset = <2.8, -0.9, 0>;
		#break

		#case (11)
			// DEATH 4: hitting the ground
			#declare AV_Thigh_Left = <90, 0, 0>;
			#declare AV_Shin_Left = <-130, 0, 0>;
			#declare AV_Thigh_Right = <80, 0, 0>;
			#declare AV_Shin_Right = <-125, 0, 0>;
			#declare AV_Arm_Left = <70, 0, 5>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <80, 0, -10>;
			#declare AV_Wrist_Right = <30, 0, 20>;
			#declare AV_Torso = <-40, -15, 5>;
			#declare AV_Head = <-30, 0, 15>;
			#declare AV_Body = <0, 0, 85>;
			#declare V_Body_Offset = <3.4, 0.05, 0>;
		#break

		#case (12)
			// DEATH 5: lying on the right side, curled up
			#declare AV_Thigh_Left = <85, 0, 0>;
			#declare AV_Shin_Left = <-120, 0, 0>;
			#declare AV_Thigh_Right = <80, 0, 0>;
			#declare AV_Shin_Right = <-125, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 0>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <85, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 20>;
			#declare AV_Torso = <-40, -10, 0>;
			#declare AV_Head = <-35, 0, 5>;
			#declare AV_Body = <0, 0, 90>;
			#declare V_Body_Offset = <3.4, 0.3, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
