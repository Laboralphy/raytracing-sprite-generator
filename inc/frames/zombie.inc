/*
	Poses of the zombie (also used by the ghoul and the skeleton): see inc/Pose.inc

	Angle conventions (degrees):
		limbs hang down: x > 0 moves them forward
		AV_Torso, AV_Head, AV_Body point up: x > 0 tilts them backward, x < 0 forward
		z: sideways (left arm: z > 0 away from the body)
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Arm_Left = <20, 0, 10>;
			#declare AV_Wrist_Left = <45, 0, 0>;
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
		#break

		#case (1)
			// ATTACK 1
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <85, 0, 10>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <90, 0, -10>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (2)
			// ATTACK 2
			#declare AV_Thigh_Left = <40, 0, 0>;
			#declare AV_Shin_Left = <-40, 0, 0>;
			#declare AV_Thigh_Right = <-30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <70, 0, 10>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <85, 0, -10>;
			#declare AV_Wrist_Right = <15, 0, 0>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (3)
			// WALK 1
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <95, 0, 10>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <90, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (4)
			// WALK 2
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <100, 0, 10>;
			#declare AV_Wrist_Left = <5, 0, 0>;
			#declare AV_Arm_Right = <85, 0, -10>;
			#declare AV_Wrist_Right = <5, 0, 0>;
		#break

		#case (5)
			// WALK 3
			#declare AV_Thigh_Left = <-15, 0, 0>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <90, 0, 10>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <90, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (6)
			// IDLE: swaying, head hanging
			#declare AV_Thigh_Left = <5, 0, 0>;
			#declare AV_Shin_Left = <-10, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 5>;
			#declare AV_Wrist_Left = <35, 0, 0>;
			#declare AV_Arm_Right = <-5, 0, -15>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <-8, 0, 6>;
			#declare AV_Head = <-15, 10, 10>;
			#declare V_Body_Offset = y * -0.03;
		#break

		#case (7)
			// PAIN: thrown backward
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <40, 0, 40>;
			#declare AV_Wrist_Left = <50, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <60, 0, 0>;
			#declare AV_Torso = <20, 0, -5>;
			#declare AV_Head = <30, -10, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		/*
			Death: falling backward onto the back (render it from a
			three-quarter view, "view": 3 in the spec). The body slides forward
			(V_Body_Offset.z < 0) so that the lying body, not the feet, ends up
			in the middle of the frame, and turns a little (AV_Body.y) so that, lying
			flat, it stays within the width of the frame.
		*/
		#case (8)
			// DEATH 1: hit, head snapping back, arms flung forward
			#declare AV_Thigh_Left = <10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, 0>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <70, 0, 30>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -35>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <20, 0, 0>;
			#declare AV_Head = <30, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (9)
			// DEATH 2: tipping backward, knees giving way
			#declare AV_Thigh_Left = <35, 0, 0>;
			#declare AV_Shin_Left = <-55, 0, 0>;
			#declare AV_Thigh_Right = <25, 0, 0>;
			#declare AV_Shin_Right = <-45, 0, 0>;
			#declare AV_Arm_Left = <110, 0, 35>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <100, 0, -40>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <15, 0, 0>;
			#declare AV_Head = <12, 0, 0>;
			#declare AV_Body = <25, 0, 0>;
			#declare V_Body_Offset = <0, -0.35, -0.4>;
		#break

		#case (10)
			// DEATH 3: falling on the back
			#declare AV_Thigh_Left = <50, 0, 0>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-60, 0, 0>;
			#declare AV_Arm_Left = <140, 0, 40>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -45>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare AV_Torso = <5, 0, 0>;
			#declare AV_Head = <15, 0, 0>;
			#declare AV_Body = <60, 8, 0>;
			#declare V_Body_Offset = <0, -0.45, -1.6>;
		#break

		#case (11)
			// DEATH 4: hitting the ground, knees up
			#declare AV_Thigh_Left = <65, 0, 5>;
			#declare AV_Shin_Left = <-90, 0, 0>;
			#declare AV_Thigh_Right = <55, 0, -5>;
			#declare AV_Shin_Right = <-80, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 70>; // flung out flat on the ground (x ~ 0, z = spread): they then come back along the ground
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -70>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <88, 18, 0>;
			#declare V_Body_Offset = <0, 0.1, -1.6>;
		#break

		#case (12)
			// DEATH 5: lying on the back, arms and legs fallen flat, head turned aside
			#declare AV_Thigh_Left = <8, 0, 8>;
			#declare AV_Shin_Left = <-12, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -6>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 40>; // flat on the ground, away from the body
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -35>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <90, 20, 0>;
			#declare V_Body_Offset = <0, 0.3, -1.4>;
		#break
	#end
#end

#include "inc/Pose.inc"
