/*
	Poses of the mummy: mace in the right hand, slow shambling walk.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	Numbering differs from the zombie: 0 STAND, 1-3 ATTACK, 4-6 WALK,
	7 IDLE, 8 PAIN, 9-13 DEATH.
*/
#macro Pose_Define(N_Pose)
	// knees always slightly bent
	#declare AV_Thigh_Left = <10, 0, 0>;
	#declare AV_Shin_Left = <-20, 0, 0>;
	#declare AV_Thigh_Right = <8, 0, 0>;
	#declare AV_Shin_Right = <-20, 0, 0>;

	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Arm_Left = <20, 0, 10>;
			#declare AV_Wrist_Left = <45, 0, 0>;
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
		#break

		#case (1)
			// ATTACK 1: mace raised
			#declare AV_Arm_Left = <-30, 0, 10>;
			#declare AV_Wrist_Left = <110, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -10>;
			#declare AV_Wrist_Right = <40, 0, 0>;
		#break

		#case (2)
			// ATTACK 2: strike
			#declare AV_Arm_Left = <-40, 0, 10>;
			#declare AV_Wrist_Left = <130, 0, 0>;
			#declare AV_Arm_Right = <15, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
		#break

		#case (3)
			// ATTACK 3: left hand forward
			#declare AV_Arm_Left = <85, 0, 10>;
			#declare AV_Wrist_Left = <5, 0, 0>;
			#declare AV_Arm_Right = <10, 0, -10>;
			#declare AV_Wrist_Right = <35, 0, 0>;
		#break

		#case (4)
			// WALK 1
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 10>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <10, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
		#break

		#case (5)
			// WALK 2
			#declare AV_Arm_Left = <0, 0, 10>;
			#declare AV_Wrist_Left = <5, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -10>;
			#declare AV_Wrist_Right = <5, 0, 0>;
			#declare V_Body_Offset = y * 0.025;
		#break

		#case (6)
			// WALK 3
			#declare AV_Thigh_Left = <7, 0, 0>;
			#declare AV_Thigh_Right = <13, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 10>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
		#break

		#case (7)
			// IDLE: slumped, head hanging on the side
			#declare AV_Arm_Left = <15, 0, 6>;
			#declare AV_Wrist_Left = <35, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -12>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <-10, 5, -4>;
			#declare AV_Head = <-15, -10, -15>;
			#declare V_Body_Offset = y * -0.03;
		#break

		#case (8)
			// PAIN: thrown backward
			#declare AV_Thigh_Left = <-5, 0, 0>;
			#declare AV_Shin_Left = <-25, 0, 0>;
			#declare AV_Thigh_Right = <20, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <35, 0, 40>;
			#declare AV_Wrist_Left = <50, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <25, -10, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		/*
			Death: falling backward onto the back (render it from a
			three-quarter view, "view": 3 in the spec). The body slides forward
			(V_Body_Offset.z < 0) so that the lying body, not the feet, ends up
			in the middle of the frame, and turns a little (AV_Body.y) so that, lying
			flat, it stays within the width of the frame.
		*/
		#case (9)
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

		#case (10)
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
			#declare V_Body_Offset = <0, -0.35, -0.46>;
		#break

		#case (11)
			// DEATH 3: falling on the back
			#declare AV_Thigh_Left = <50, 0, 0>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-60, 0, 0>;
			#declare AV_Arm_Left = <140, 0, 40>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -45>;
			#declare AV_Wrist_Right = <-45, 0, 0>;
			#declare AV_Torso = <5, 0, 0>;
			#declare AV_Head = <15, 0, 0>;
			#declare AV_Body = <60, 8, 0>;
			#declare V_Body_Offset = <0, -0.45, -1.84>;
		#break

		#case (12)
			// DEATH 4: hitting the ground, knees up
			#declare AV_Thigh_Left = <80, 0, 5>;
			#declare AV_Shin_Left = <-115, 0, 0>;
			#declare AV_Thigh_Right = <70, 0, -5>;
			#declare AV_Shin_Right = <-105, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 70>; // flung out flat on the ground (x ~ 0, z = spread): they then come back along the ground
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -70>;
			#declare AV_Wrist_Right = <-90, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <88, 28, 0>;
			#declare V_Body_Offset = <0, 0.1, -0.75>;
		#break

		#case (13)
			// DEATH 5: lying on the back, arms and legs fallen flat, head turned aside
			#declare AV_Thigh_Left = <8, 0, 8>;
			#declare AV_Shin_Left = <-12, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -6>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 40>; // flat on the ground, away from the body
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -35>;
			#declare AV_Wrist_Right = <-90, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <90, 30, 0>;
			#declare V_Body_Offset = <0, 0.3, -0.55>;
		#break
	#end
#end

#include "inc/Pose.inc"
