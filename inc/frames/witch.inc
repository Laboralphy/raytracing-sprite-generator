/*
	Poses of the witch: wand in the right hand.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	Numbering: 0 STAND, 1 ATTACK (original, unused), 2-4 WALK, 5 ATTACK (fire;
	the recovery is a blend towards 0), 6 IDLE, 7 PAIN, 8-12 DEATH.
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Arm_Left = <0, 0, 10>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -10>;
			#declare AV_Wrist_Right = <0, 0, 0>;
		#break

		#case (1)
			// ATTACK: wand forward
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <-20, 0, 10>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <50, 0, -10>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (2)
			// WALK 1
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <20, 0, 10>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (3)
			// WALK 2
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 10>;
			#declare AV_Wrist_Left = <5, 0, 0>;
			#declare AV_Arm_Right = <-5, 0, -10>;
			#declare AV_Wrist_Right = <5, 0, 0>;
		#break

		#case (4)
			// WALK 3
			#declare AV_Thigh_Left = <-15, 0, 0>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <-20, 0, 10>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <20, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (5)
			// ATTACK: fire, wand held out, kicking up a little (recoil), flash at the tip
			#declare AV_Thigh_Left = <20, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <-10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <-15, 0, 20>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <80, 0, -5>;
			#declare AV_Wrist_Right = <15, 0, 0>;
			#declare AV_Torso = <3, 0, 0>;
			#declare AV_Head = <3, 0, 0>;
			#declare V_Body_Offset = <0, -0.05, 0.3>; // back a little: the wand stays in the frame
			#declare V_Pose_Extra = <0, 0.7, 0>; // flash, see inc/armors/Wand_Ruby_Sphere.inc
		#break

		#case (6)
			// IDLE: hand on the hip, head tilted
			#declare AV_Thigh_Left = <0, 0, 4>;
			#declare AV_Thigh_Right = <5, 0, 0>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, -110>;
			#declare AV_Arm_Right = <15, 0, -12>;
			#declare AV_Wrist_Right = <50, 0, 0>;
			#declare AV_Torso = <0, -5, 6>;
			#declare AV_Head = <0, 10, -15>;
		#break

		#case (7)
			// PAIN: thrown backward
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <40, 0, 45>;
			#declare AV_Wrist_Left = <50, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -50>;
			#declare AV_Wrist_Right = <50, 0, 0>;
			#declare AV_Torso = <12, 0, -5>;
			#declare AV_Head = <12, -10, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (8)
			// DEATH 1: hit, head thrown back, knees giving way
			#declare AV_Thigh_Left = <25, 0, 0>;
			#declare AV_Shin_Left = <-45, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 45>;
			#declare AV_Wrist_Left = <40, 0, 0>;
			#declare AV_Arm_Right = <70, 0, -60>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <25, 0, 0>;
			#declare AV_Head = <35, 0, 0>;
			#declare V_Body_Offset = y * -0.25;
		#break

		#case (9)
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
			#declare V_Body_Offset = <0.75, -0.55, 0>;
		#break

		#case (10)
			// DEATH 3: falling on the right side
			#declare AV_Thigh_Left = <85, 0, 0>;
			#declare AV_Shin_Left = <-120, 0, 0>;
			#declare AV_Thigh_Right = <70, 0, 0>;
			#declare AV_Shin_Right = <-110, 0, 0>;
			#declare AV_Arm_Left = <90, 0, 60>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -30>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-35, -20, 10>;
			#declare AV_Head = <-55, 0, 25>;
			#declare AV_Body = <0, 0, 50>;
			#declare V_Body_Offset = <2.2, -0.5, 0>;
		#break

		#case (11)
			// DEATH 4: hitting the ground
			#declare AV_Thigh_Left = <90, 0, 0>;
			#declare AV_Shin_Left = <-110, 0, 0>;
			#declare AV_Thigh_Right = <75, 0, 0>;
			#declare AV_Shin_Right = <-100, 0, 0>;
			#declare AV_Arm_Left = <100, 0, 50>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <80, 0, -15>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-40, -15, 5>;
			#declare AV_Head = <-60, 0, 15>;
			#declare AV_Body = <0, 0, 85>;
			#declare V_Body_Offset = <2.45, 0.05, 0>;
		#break

		#case (12)
			// DEATH 5: lying on the right side
			#declare AV_Thigh_Left = <80, 0, 0>;
			#declare AV_Shin_Left = <-95, 0, 0>;
			#declare AV_Thigh_Right = <70, 0, 0>;
			#declare AV_Shin_Right = <-100, 0, 0>;
			#declare AV_Arm_Left = <95, 0, 30>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <85, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-40, -10, 0>;
			#declare AV_Head = <-65, 0, 5>;
			#declare AV_Body = <0, 0, 90>;
			#declare V_Body_Offset = <2.45, 0.25, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
