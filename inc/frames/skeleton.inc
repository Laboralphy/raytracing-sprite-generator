/*
	Poses of the skeleton: sword in the right hand, free left arm, upright
	walk like the knight (inc/frames/knight.inc, same numbering): the arms
	swing against the legs.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	Numbering: 0 STAND, 1-2 ATTACK, 3-5 WALK, 6 IDLE, 7 PAIN, 8-12 DEATH.
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND: sword held low, pointing forward
			#declare AV_Arm_Left = <0, 0, 12>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
		#break

		#case (1)
			// ATTACK 1: sword raised over the shoulder
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <35, 0, 20>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <150, 20, 20>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <5, -15, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (2)
			// ATTACK 2: slash
			#declare AV_Thigh_Left = <40, 0, 0>;
			#declare AV_Shin_Left = <-40, 0, 0>;
			#declare AV_Thigh_Right = <-30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <-20, 0, 25>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <50, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-10, 15, 0>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (3)
			// WALK 1: left leg forward, right arm forward
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <-25, 0, 10>;
			#declare AV_Wrist_Left = <15, 0, 0>;
			#declare AV_Arm_Right = <15, 0, -10>;
			#declare AV_Wrist_Right = <35, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (4)
			// WALK 2: passing
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <0, 0, 10>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -10>;
			#declare AV_Wrist_Right = <40, 0, 0>;
		#break

		#case (5)
			// WALK 3: right leg forward, left arm forward
			#declare AV_Thigh_Left = <-15, 0, 0>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <25, 0, 10>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (6)
			// IDLE: head tilted, sword lowered
			#declare AV_Thigh_Left = <5, 0, 0>;
			#declare AV_Shin_Left = <-8, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 14>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <-15, 0, -12>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-3, 5, 3>;
			#declare AV_Head = <5, 10, -8>;
			#declare V_Body_Offset = y * -0.02;
		#break

		#case (7)
			// PAIN: thrown backward, arms flung out
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <30, 0, 40>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <25, -10, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		/*
			Death: as the knight (see inc/frames/knight.inc), falling backward
			onto the back, rendered from a three-quarter view.
		*/
		#case (8)
			// DEATH 1: hit, head snapping back, arms flung forward
			#declare AV_Thigh_Left = <10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, 0>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 30>;
			#declare AV_Wrist_Left = <20, 0, 0>;
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
			#declare AV_Arm_Left = <100, 0, 35>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <100, 0, -40>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <6, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <25, 0, 0>;
			#declare V_Body_Offset = <0, -0.35, -0.4>;
		#break

		#case (10)
			// DEATH 3: falling on the back
			#declare AV_Thigh_Left = <50, 0, 0>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-60, 0, 0>;
			#declare AV_Arm_Left = <130, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -45>;
			#declare AV_Wrist_Right = <-45, 0, 0>;
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
			#declare AV_Arm_Left = <-10, 0, 70>; // flat on the ground (x ~ 0, z = spread)
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -70>;
			#declare AV_Wrist_Right = <-90, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <88, 18, 0>;
			#declare V_Body_Offset = <0, 0.1, -1.6>;
		#break

		#case (12)
			// DEATH 5: lying on the back, arms and legs fallen flat, skull turned aside
			#declare AV_Thigh_Left = <8, 0, 8>;
			#declare AV_Shin_Left = <-12, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -6>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -35>;
			#declare AV_Wrist_Right = <-90, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <90, 20, 0>;
			#declare V_Body_Offset = <0, 0.3, -1.4>;
		#break
	#end
#end

#include "inc/Pose.inc"
