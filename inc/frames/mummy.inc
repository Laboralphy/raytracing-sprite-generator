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

		#case (9)
			// DEATH 1: hit, head thrown back, knees giving way
			#declare AV_Thigh_Left = <25, 0, 0>;
			#declare AV_Shin_Left = <-45, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 45>;
			#declare AV_Wrist_Left = <40, 0, 0>;
			#declare AV_Arm_Right = <50, 0, -50>;
			#declare AV_Wrist_Right = <50, 0, 0>;
			#declare AV_Torso = <25, 0, 0>;
			#declare AV_Head = <35, 0, 0>;
			#declare V_Body_Offset = y * -0.3;
		#break

		#case (10)
			// DEATH 2: knees buckling, twisting to the side
			#declare AV_Thigh_Left = <55, 0, 0>;
			#declare AV_Shin_Left = <-90, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-75, 0, 0>;
			#declare AV_Arm_Left = <70, 0, 60>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <40, 0, -40>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <10, -20, 15>;
			#declare AV_Head = <20, 0, 20>;
			#declare AV_Body = <0, 0, 15>;
			#declare V_Body_Offset = <1.0, -0.7, 0>;
		#break

		#case (11)
			// DEATH 3: falling on the right side
			#declare AV_Thigh_Left = <70, 0, 0>;
			#declare AV_Shin_Left = <-110, 0, 0>;
			#declare AV_Thigh_Right = <50, 0, 0>;
			#declare AV_Shin_Right = <-95, 0, 0>;
			#declare AV_Arm_Left = <90, 0, 60>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -30>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-20, -20, 10>;
			#declare AV_Head = <-10, 0, 25>;
			#declare AV_Body = <0, 0, 50>;
			#declare V_Body_Offset = <2.25, -0.6, 0>;
		#break

		#case (12)
			// DEATH 4: hitting the ground
			#declare AV_Thigh_Left = <90, 0, 0>;
			#declare AV_Shin_Left = <-120, 0, 0>;
			#declare AV_Thigh_Right = <75, 0, 0>;
			#declare AV_Shin_Right = <-110, 0, 0>;
			#declare AV_Arm_Left = <100, 0, 50>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <80, 0, -15>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-35, -15, 5>;
			#declare AV_Head = <-30, 0, 15>;
			#declare AV_Body = <0, 0, 85>;
			#declare V_Body_Offset = <2.65, 0.05, 0>;
		#break

		#case (13)
			// DEATH 5: lying on the right side
			#declare AV_Thigh_Left = <80, 0, 0>;
			#declare AV_Shin_Left = <-105, 0, 0>;
			#declare AV_Thigh_Right = <70, 0, 0>;
			#declare AV_Shin_Right = <-110, 0, 0>;
			#declare AV_Arm_Left = <95, 0, 30>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <85, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-35, -10, 0>;
			#declare AV_Head = <-35, 0, 5>;
			#declare AV_Body = <0, 0, 90>;
			#declare V_Body_Offset = <2.65, 0.25, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
