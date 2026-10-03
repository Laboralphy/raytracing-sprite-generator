/*
	Poses of Jack-o'-lantern: see inc/Pose.inc, and the header of the
	assembly in inc/jack/Jack.inc for what each variable moves.
	Numbering: 0-2 FLOAT (the robe ripples), 3-5 MOVE, 6 ATTACK (fire; the
	recovery is a blend towards 0), 7 PAIN, 8-12 DEATH.
*/
#macro Pose_Define(N_Pose)
	// Jack's arms are neutral at 0 (the body's default is <0, 0, +-10>)
	#declare AV_Arm_Left = <0, 0, 0>;
	#declare AV_Arm_Right = <0, 0, 0>;

	#switch (N_Pose)
		#case (0)
			// FLOAT 1
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (1)
			// FLOAT 2
			#declare V_Pose_Extra = <0, 0, 1>;
		#break

		#case (2)
			// FLOAT 3
			#declare V_Pose_Extra = <0, 0, 2>;
		#break

		#case (3)
			// MOVE 1: gliding, leaning forward
			#declare AV_Body = <-8, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <10, 0, 0>;
			#declare V_Body_Offset = y * 0.05;
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (4)
			// MOVE 2
			#declare AV_Body = <-8, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 0>;
			#declare AV_Arm_Right = <15, 0, 0>;
			#declare V_Body_Offset = y * 0.12;
			#declare V_Pose_Extra = <0, 0, 1>;
		#break

		#case (5)
			// MOVE 3
			#declare AV_Body = <-8, 0, 0>;
			#declare AV_Arm_Left = <12, 0, 0>;
			#declare AV_Arm_Right = <5, 0, 0>;
			#declare V_Body_Offset = y * 0.08;
			#declare V_Pose_Extra = <0, 0, 2>;
		#break

		#case (6)
			// ATTACK: fire, lantern held out and kicking up a little (recoil), blazing
			#declare AV_Body = <3, 0, 0>;
			#declare AV_Head = <3, 0, 0>;
			#declare AV_Arm_Left = <40, 20, 0>;
			#declare V_Body_Offset = z * 0.2;
			#declare V_Pose_Extra = <0, -1.2, 0>;
		#break

		#case (7)
			// PAIN: thrown backward, flame flickering
			#declare AV_Body = <10, 0, 0>;
			#declare AV_Head = <15, 0, -15>;
			#declare AV_Arm_Left = <-10, 0, 20>;
			#declare AV_Arm_Right = <-10, 0, -20>;
			#declare V_Body_Offset = <0, 0.1, -0.35>;
			#declare V_Pose_Extra = <0, 0.5, 2>;
		#break

		#case (8)
			// DEATH 1: shudder, flame dying
			#declare AV_Body = <10, 0, 0>;
			#declare AV_Head = <20, 0, 15>;
			#declare AV_Arm_Left = <40, 0, 30>;
			#declare AV_Arm_Right = <40, 0, -30>;
			#declare V_Pose_Extra = <0.05, 0.5, 2>;
		#break

		#case (9)
			// DEATH 2: the robe starts to empty
			#declare AV_Head = <0, 0, 30>;
			#declare AV_Arm_Left = <30, 0, 20>;
			#declare AV_Arm_Right = <30, 0, -20>;
			#declare V_Pose_Extra = <0.3, 0.8, 1>;
		#break

		#case (10)
			// DEATH 3: collapsing, the pumpkin falls
			#declare AV_Head = <0, 0, 70>;
			#declare AV_Arm_Left = <20, 0, 10>;
			#declare AV_Arm_Right = <20, 0, -10>;
			#declare V_Pose_Extra = <0.6, 1, 0>;
		#break

		#case (11)
			// DEATH 4: on the ground
			#declare AV_Head = <0, 0, 100>;
			#declare AV_Arm_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <10, 0, 0>;
			#declare V_Pose_Extra = <0.9, 1, 0>;
		#break

		#case (12)
			// DEATH 5: empty robe, pumpkin rolled over, lantern out
			#declare AV_Head = <0, 0, 110>;
			#declare V_Pose_Extra = <1, 1, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
