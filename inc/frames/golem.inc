/*
	Poses of the clay golem (c_golem.pov): hunched, knees bent, heavy arms
	hanging forward; heavy stomping walk with a sideways sway; it punches
	with its right fist.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	Numbering (as the knight): 0 STAND, 1-2 ATTACK, 3-5 WALK, 6 IDLE,
	7 PAIN, 8-12 DEATH.
*/

// hunched: torso leaning forward, the head looking ahead
#macro Golem_Hunch()
	#declare AV_Torso = <-10, 0, 0>;
	#declare AV_Head = <10, 0, 0>;
#end

#macro Pose_Define(N_Pose)
	Golem_Hunch()
	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Thigh_Left = <12, 0, 6>;
			#declare AV_Shin_Left = <-18, 0, 0>;
			#declare AV_Thigh_Right = <12, 0, -6>;
			#declare AV_Shin_Right = <-18, 0, 0>;
			#declare AV_Arm_Left = <15, 0, 14>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <15, 0, -14>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (1)
			// ATTACK 1: right fist drawn back, torso twisted
			#declare AV_Thigh_Left = <30, 0, 6>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <-10, 0, -6>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <45, 0, 15>;
			#declare AV_Wrist_Left = <40, 0, 0>;
			#declare AV_Arm_Right = <-35, 0, -25>;
			#declare AV_Wrist_Right = <95, 0, 0>;
			#declare AV_Torso = <-8, -25, 0>;
			#declare AV_Head = <8, 20, 0>;
			#declare V_Body_Offset = y * -0.12;
		#break

		#case (2)
			// ATTACK 2: punch, right arm thrown forward, lunging
			#declare AV_Thigh_Left = <45, 0, 6>;
			#declare AV_Shin_Left = <-45, 0, 0>;
			#declare AV_Thigh_Right = <-25, 0, -6>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <-20, 0, 18>;
			#declare AV_Wrist_Left = <50, 0, 0>;
			#declare AV_Arm_Right = <80, -5, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-18, 15, 0>;
			#declare AV_Head = <15, -20, 0>;
			#declare V_Body_Offset = <0, -0.18, 0.15>;
		#break

		#case (3)
			// WALK 1: left leg forward, swaying onto it
			#declare AV_Thigh_Left = <28, 0, 6>;
			#declare AV_Shin_Left = <-22, 0, 0>;
			#declare AV_Thigh_Right = <-12, 0, -6>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 14>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -14>;
			#declare AV_Wrist_Right = <25, 0, 0>;
			#declare AV_Body = <0, 0, 4>;
			#declare V_Body_Offset = y * -0.12;
		#break

		#case (4)
			// WALK 2: passing, upright
			#declare AV_Thigh_Left = <12, 0, 6>;
			#declare AV_Shin_Left = <-25, 0, 0>;
			#declare AV_Thigh_Right = <18, 0, -6>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <12, 0, 14>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <12, 0, -14>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare V_Body_Offset = y * -0.05;
		#break

		#case (5)
			// WALK 3: right leg forward, swaying onto it
			#declare AV_Thigh_Left = <-12, 0, 6>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <28, 0, -6>;
			#declare AV_Shin_Right = <-22, 0, 0>;
			#declare AV_Arm_Left = <30, 0, 14>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -14>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Body = <0, 0, -4>;
			#declare V_Body_Offset = y * -0.12;
		#break

		#case (6)
			// IDLE: shoulders rolling, head turning
			#declare AV_Thigh_Left = <14, 0, 6>;
			#declare AV_Shin_Left = <-22, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, -6>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <20, 0, 16>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <10, 0, -12>;
			#declare AV_Wrist_Right = <15, 0, 0>;
			#declare AV_Torso = <-12, 6, 3>;
			#declare AV_Head = <12, 12, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (7)
			// PAIN: rocked backward
			#declare AV_Thigh_Left = <-5, 0, 6>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <18, 0, -6>;
			#declare AV_Shin_Right = <-28, 0, 0>;
			#declare AV_Arm_Left = <25, 0, 35>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <25, 0, -35>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <12, 0, -5>;
			#declare AV_Head = <15, -10, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		/*
			Death: as the knight (see inc/frames/knight.inc), falling backward
			onto the back, rendered from a three-quarter view.
		*/
		#case (8)
			// DEATH 1: hit, arms flung forward
			#declare AV_Thigh_Left = <10, 0, 6>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -6>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 30>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -35>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <15, 0, 0>;
			#declare AV_Head = <25, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (9)
			// DEATH 2: tipping backward, knees giving way
			#declare AV_Thigh_Left = <35, 0, 6>;
			#declare AV_Shin_Left = <-55, 0, 0>;
			#declare AV_Thigh_Right = <25, 0, -6>;
			#declare AV_Shin_Right = <-45, 0, 0>;
			#declare AV_Arm_Left = <100, 0, 35>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <100, 0, -40>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <25, 0, 0>;
			#declare V_Body_Offset = <0, -0.35, -0.4>;
		#break

		#case (10)
			// DEATH 3: falling on the back
			#declare AV_Thigh_Left = <50, 0, 6>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, -6>;
			#declare AV_Shin_Right = <-60, 0, 0>;
			#declare AV_Arm_Left = <130, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -45>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Torso = <5, 0, 0>;
			#declare AV_Head = <15, 0, 0>;
			#declare AV_Body = <60, 8, 0>;
			#declare V_Body_Offset = <0, -0.45, -1.6>;
		#break

		#case (11)
			// DEATH 4: hitting the ground, knees up
			#declare AV_Thigh_Left = <65, 0, 8>;
			#declare AV_Shin_Left = <-90, 0, 0>;
			#declare AV_Thigh_Right = <55, 0, -8>;
			#declare AV_Shin_Right = <-80, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 45>; // flat on the ground (x ~ 0, z = spread)
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -45>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Torso = <0, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <88, 18, 0>;
			#declare V_Body_Offset = <0, 0.25, -1.6>;
		#break

		#case (12)
			// DEATH 5: lying on the back, arms and legs fallen flat, head turned aside
			#declare AV_Thigh_Left = <8, 0, 10>;
			#declare AV_Shin_Left = <-12, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -8>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 30>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -28>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Torso = <0, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <90, 20, 0>;
			#declare V_Body_Offset = <0, 0.45, -1.4>;
		#break
	#end
#end

#include "inc/Pose.inc"
