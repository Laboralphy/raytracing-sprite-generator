/*
	Poses of Bigface: see inc/Pose.inc, and the header of
	inc/bigface/BigFace.inc for how the model reads them (arm angles are
	relative to the rest pose of Pose_Reset()).
	Numbering: 0 STAND, 1-3 ATTACK (raises the knife, stabs forward,
	recovers), 4-7 WALK (shuffling feet, phase 0, 90, 180, 270), 8 IDLE,
	9 PAIN, 10-14 DEATH (falls on its back, rests on head and belly).
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// STAND
		#break

		#case (1)
			// ATTACK 1: knife raised high, leaning back
			#declare AV_Arm_Right = <0, 15, -55>;
			#declare AV_Wrist_Right = <15, 0, 30>;
			#declare AV_Arm_Left = <0, 0, 25>;
			#declare AV_Body = <6, 0, 0>;
			#declare AV_Head = <8, 0, 0>;
		#break

		#case (2)
			// ATTACK 2: stabs forward, leaning in
			#declare AV_Arm_Right = <0, -50, -25>;
			#declare AV_Wrist_Right = <-75, 0, 0>;
			#declare AV_Arm_Left = <0, -20, 0>;
			#declare AV_Body = <-4, 0, 0>;
			#declare AV_Head = <-8, 0, 0>;
		#break

		#case (3)
			// ATTACK 3: recovers
			#declare AV_Arm_Right = <0, -25, -15>;
			#declare AV_Wrist_Right = <-35, 0, 0>;
			#declare AV_Body = <-4, 0, 0>;
		#break

		#case (4)
			// WALK 1: left foot passing, lifted
			#declare V_Pose_Extra = <0, 1, 0>;
		#break

		#case (5)
			// WALK 2: left foot forward
			#declare V_Pose_Extra = <90, 1, 0>;
		#break

		#case (6)
			// WALK 3: right foot passing, lifted
			#declare V_Pose_Extra = <180, 1, 0>;
		#break

		#case (7)
			// WALK 4: right foot forward
			#declare V_Pose_Extra = <270, 1, 0>;
		#break

		#case (8)
			// IDLE: head tilted, arms lowered, a little lower
			#declare AV_Arm_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <0, 0, 0>;
			#declare AV_Head = <4, 0, 6>;
			#declare V_Body_Offset = y * -0.04;
		#break

		#case (9)
			// PAIN: thrown back, arms up
			#declare AV_Arm_Left = <0, -20, 45>;
			#declare AV_Arm_Right = <0, 20, -45>;
			#declare AV_Wrist_Right = <15, 0, -20>;
			#declare AV_Head = <12, 0, -10>;
			#declare AV_Body = <6, 0, 0>;
		#break

		#case (10)
			// DEATH 1: hit, head thrown back
			#declare AV_Arm_Left = <0, -10, 55>;
			#declare AV_Arm_Right = <0, 10, -55>;
			#declare AV_Head = <25, 0, 0>;
			#declare AV_Body = <15, 0, 0>;
		#break

		#case (11)
			// DEATH 2: toppling backwards
			#declare AV_Arm_Left = <0, -10, 70>;
			#declare AV_Arm_Right = <0, 10, -70>;
			#declare AV_Head = <20, 0, 0>;
			#declare AV_Body = <40, 8, 0>;
			#declare V_Body_Offset = <0, 0, -0.5>;
		#break

		#case (12)
			// DEATH 3: falling
			#declare AV_Arm_Left = <0, 0, 70>;
			#declare AV_Arm_Right = <0, 0, -70>;
			#declare AV_Head = <10, 0, 0>;
			#declare AV_Body = <68, 16, 0>;
			#declare V_Body_Offset = <0, 0.35, -0.6>;
		#break

		#case (13)
			// DEATH 4: hits the ground on head and belly, arms flung
			#declare AV_Arm_Left = <0, 0, 50>;
			#declare AV_Arm_Right = <0, 0, -50>;
			#declare AV_Wrist_Right = <-60, 0, 0>;
			#declare AV_Body = <82, 22, 0>;
			#declare V_Body_Offset = <0, 0.75, -0.3>;
		#break

		#case (14)
			// DEATH 5: lying on the back, head turned aside
			#declare AV_Arm_Left = <0, 0, 30>;
			#declare AV_Arm_Right = <0, 0, -30>;
			#declare AV_Wrist_Right = <-75, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <82, 25, 0>;
			#declare V_Body_Offset = <0, 0.75, -0.3>;
		#break
	#end
#end

#include "inc/Pose.inc"
