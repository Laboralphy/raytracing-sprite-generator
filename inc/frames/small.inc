/*
	Poses of a small creature (c_dummy_small.pov: goblin, imp...): weapon
	in the right hand, small trotting steps instead of a walk (body leaning
	forward, elbows bent, a flight phase between the steps), the head kept
	steady (it compensates the lean of the torso).
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	Numbering: 0 STAND, 1-2 ATTACK, 3-6 TROT (4 frames), 7 IDLE, 8 PAIN,
	9-13 DEATH.
	With a shield (P_BodyPart_ArmorPart_Shield): declare N_Small_Shield before
	this file; the left arm then holds it up in front of the body instead of
	swinging (Small_Shield_Arm).
*/

// trot: torso leaning forward, head upright, elbows bent
#macro Small_Trot_Base()
	#declare AV_Torso = <-12, 0, 0>;
	#declare AV_Head = <10, 0, 0>;
	#declare AV_Wrist_Left = <70, 0, 0>;
	#declare AV_Wrist_Right = <70, 0, 0>;
#end

// shield arm, applied after the pose when N_Small_Shield is declared
#macro Small_Shield_Arm(N_Pose)
	#switch (N_Pose)
		#range (0, 0)
			#declare AV_Arm_Left = <70, 0, 10>;
			#declare AV_Wrist_Left = <0, 0, -75>;
		#break
		#case (1)
			#declare AV_Arm_Left = <70, -30, 10>;
			#declare AV_Wrist_Left = <0, 0, -75>;
		#break
		#case (2)
			#declare AV_Arm_Left = <75, -40, 10>;
			#declare AV_Wrist_Left = <0, 0, -75>;
		#break
		#range (3, 6)
			// trotting: the shield bobs a little
			#declare AV_Arm_Left = <55 + 10 * mod(N_Pose - 3, 2), 0, 10>;
			#declare AV_Wrist_Left = <0, 0, -75>;
		#break
		#case (7)
			#declare AV_Arm_Left = <60, 0, 12>;
			#declare AV_Wrist_Left = <0, 0, -70>;
		#break
		#case (8)
			// pain: shield knocked aside
			#declare AV_Arm_Left = <45, -20, 30>;
			#declare AV_Wrist_Left = <0, 0, -60>;
		#break
		#range (9, 13)
			// death: the arm moves as without shield, the shield stays flat on it
			#declare AV_Wrist_Left = <0, 0, -60 - 5 * (N_Pose - 9)>;
		#break
	#end
#end

#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND: knees slightly bent, sword ready
			#declare AV_Thigh_Left = <10, 0, 5>;
			#declare AV_Shin_Left = <-15, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, -5>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 15>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <-5, 0, -12>;
			#declare AV_Wrist_Right = <50, 0, 0>;
			#declare AV_Torso = <-5, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare V_Body_Offset = y * -0.03;
		#break

		#case (1)
			// ATTACK 1: sword raised over the shoulder, crouching
			#declare AV_Thigh_Left = <35, 0, 5>;
			#declare AV_Shin_Left = <-40, 0, 0>;
			#declare AV_Thigh_Right = <-10, 0, -5>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <30, 0, 25>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <150, 20, 20>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <0, -15, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (2)
			// ATTACK 2: slash, lunging
			#declare AV_Thigh_Left = <50, 0, 5>;
			#declare AV_Shin_Left = <-50, 0, 0>;
			#declare AV_Thigh_Right = <-25, 0, -5>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <-25, 0, 25>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-15, 15, 0>;
			#declare AV_Head = <10, -10, 0>;
			#declare V_Body_Offset = <0, -0.12, -0.1>;
		#break

		#case (3)
			// TROT 1: left foot reaching forward, right foot kicked back, in the air
			Small_Trot_Base()
			#declare AV_Thigh_Left = <40, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <-25, 0, 0>;
			#declare AV_Shin_Right = <-70, 0, 0>;
			#declare AV_Arm_Left = <-30, 0, 12>;
			#declare AV_Arm_Right = <35, 0, -12>;
			#declare V_Body_Offset = y * 0.04;
		#break

		#case (4)
			// TROT 2: on the left foot, right leg tucked, lowest point
			Small_Trot_Base()
			#declare AV_Thigh_Left = <10, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <35, 0, 0>;
			#declare AV_Shin_Right = <-90, 0, 0>;
			#declare AV_Arm_Left = <0, 0, 12>;
			#declare AV_Arm_Right = <5, 0, -12>;
			#declare V_Body_Offset = y * -0.06;
		#break

		#case (5)
			// TROT 3: right foot reaching forward, left foot kicked back, in the air
			Small_Trot_Base()
			#declare AV_Thigh_Left = <-25, 0, 0>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <35, 0, 12>;
			#declare AV_Arm_Right = <-30, 0, -12>;
			#declare V_Body_Offset = y * 0.04;
		#break

		#case (6)
			// TROT 4: on the right foot, left leg tucked, lowest point
			Small_Trot_Base()
			#declare AV_Thigh_Left = <35, 0, 0>;
			#declare AV_Shin_Left = <-90, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 12>;
			#declare AV_Arm_Right = <0, 0, -12>;
			#declare V_Body_Offset = y * -0.06;
		#break

		#case (7)
			// IDLE: shifting weight, shoulders up, head nearly still
			#declare AV_Thigh_Left = <15, 0, 5>;
			#declare AV_Shin_Left = <-25, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -8>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 18>;
			#declare AV_Wrist_Left = <40, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -15>;
			#declare AV_Wrist_Right = <60, 0, 0>;
			#declare AV_Torso = <-8, 5, 3>;
			#declare AV_Head = <8, 5, 0>;
			#declare V_Body_Offset = y * -0.05;
		#break

		#case (8)
			// PAIN: thrown backward
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <30, 0, 40>;
			#declare AV_Wrist_Left = <30, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <15, -10, 0>;
			#declare V_Body_Offset = y * -0.05;
		#break

		/*
			Death: as the knight (see inc/frames/knight.inc), falling backward
			onto the back, rendered from a three-quarter view; distances
			reduced for the small body.
		*/
		#case (9)
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
			#declare AV_Head = <25, 0, 0>;
			#declare V_Body_Offset = y * -0.05;
		#break

		#case (10)
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
			#declare V_Body_Offset = <0, -0.2, -0.25>;
		#break

		#case (11)
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
			#declare V_Body_Offset = <0, -0.3, -0.9>;
		#break

		#case (12)
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
			#declare V_Body_Offset = <0, 0.05, -0.9>;
		#break

		#case (13)
			// DEATH 5: lying on the back, arms and legs fallen flat, head turned aside
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
			#declare V_Body_Offset = <0, 0.2, -0.8>;
		#break
	#end
	#ifdef (N_Small_Shield)
		Small_Shield_Arm(N_Pose)
	#end
#end

#include "inc/Pose.inc"
