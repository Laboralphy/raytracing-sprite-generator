/*
	Poses of the knight: shield on the left arm, weapon in the right hand.
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
*/
#macro Pose_Define(N_Pose)
	// shield arm by default: raised in front of the body
	#declare AV_Arm_Left = <80, 0, 10>;
	#declare AV_Wrist_Left = <0, 0, -80>;

	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <45, 0, 0>;
		#break

		#case (1)
			// ATTACK 1: weapon raised
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <80, -40, 10>;
			#declare AV_Arm_Right = <130, 20, 20>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (2)
			// ATTACK 2: strike
			#declare AV_Thigh_Left = <40, 0, 0>;
			#declare AV_Shin_Left = <-40, 0, 0>;
			#declare AV_Thigh_Right = <-30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <80, -45, 10>;
			#declare AV_Arm_Right = <15, 0, 0>;
			#declare AV_Wrist_Right = <45, 0, 0>;
			#declare V_Body_Offset = y * -0.2;
		#break

		#case (3)
			// WALK 1
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Right = <-20, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (4)
			// WALK 2
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Right = <-5, 0, -10>;
			#declare AV_Wrist_Right = <5, 0, 0>;
		#break

		#case (5)
			// WALK 3
			#declare AV_Thigh_Left = <-15, 0, 0>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Right = <20, 0, -10>;
			#declare AV_Wrist_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (6)
			// IDLE: guard relaxed, shield a little lower
			#declare AV_Thigh_Left = <5, 0, 0>;
			#declare AV_Shin_Left = <-8, 0, 0>;
			#declare AV_Arm_Left = <70, 0, 10>;
			#declare AV_Arm_Right = <-10, 0, -12>;
			#declare AV_Wrist_Right = <35, 0, 0>;
			#declare AV_Torso = <-3, 5, 3>;
			#declare AV_Head = <5, 10, 0>;
			#declare V_Body_Offset = y * -0.02;
		#break

		#case (7)
			// PAIN: thrown backward, shield knocked aside
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <55, -20, 30>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <25, -10, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (8)
			// DEATH 1: hit, head thrown back, knees giving way
			#declare AV_Thigh_Left = <25, 0, 0>;
			#declare AV_Shin_Left = <-45, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <60, 0, 35>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <50, 0, -50>;
			#declare AV_Wrist_Right = <50, 0, 0>;
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
			#declare AV_Arm_Left = <70, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, -60>;
			#declare AV_Arm_Right = <40, 0, -40>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <10, -20, 15>;
			#declare AV_Head = <20, 0, 20>;
			#declare AV_Body = <0, 0, 15>;
			#declare V_Body_Offset = <1.0, -0.55, 0>;
		#break

		#case (10)
			// DEATH 3: falling on the right side
			#declare AV_Thigh_Left = <70, 0, 0>;
			#declare AV_Shin_Left = <-100, 0, 0>;
			#declare AV_Thigh_Right = <50, 0, 0>;
			#declare AV_Shin_Right = <-85, 0, 0>;
			#declare AV_Arm_Left = <85, 0, 45>;
			#declare AV_Wrist_Left = <0, 0, -70>;
			#declare AV_Arm_Right = <60, 0, -30>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-20, -20, 10>;
			#declare AV_Head = <-10, 0, 25>;
			#declare AV_Body = <0, 0, 50>;
			#declare V_Body_Offset = <1.95, -0.5, 0>;
		#break

		#case (11)
			// DEATH 4: hitting the ground
			#declare AV_Thigh_Left = <90, 0, 0>;
			#declare AV_Shin_Left = <-110, 0, 0>;
			#declare AV_Thigh_Right = <75, 0, 0>;
			#declare AV_Shin_Right = <-100, 0, 0>;
			#declare AV_Arm_Left = <95, 0, 40>;
			#declare AV_Wrist_Left = <0, 0, -80>;
			#declare AV_Arm_Right = <80, 0, -15>;
			#declare AV_Wrist_Right = <30, 0, 0>;
			#declare AV_Torso = <-35, -15, 5>;
			#declare AV_Head = <-30, 0, 15>;
			#declare AV_Body = <0, 0, 85>;
			#declare V_Body_Offset = <2.15, 0.05, 0>;
		#break

		#case (12)
			// DEATH 5: lying on the right side, shield on top
			#declare AV_Thigh_Left = <80, 0, 0>;
			#declare AV_Shin_Left = <-95, 0, 0>;
			#declare AV_Thigh_Right = <70, 0, 0>;
			#declare AV_Shin_Right = <-100, 0, 0>;
			#declare AV_Arm_Left = <95, 0, 30>;
			#declare AV_Wrist_Left = <0, 0, -80>;
			#declare AV_Arm_Right = <85, 0, -5>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-35, -10, 0>;
			#declare AV_Head = <-35, 0, 5>;
			#declare AV_Body = <0, 0, 90>;
			#declare V_Body_Offset = <2.15, 0.25, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
