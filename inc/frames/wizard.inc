/*
	Poses of the wizard (blue and red): see inc/Pose.inc, and the header of
	the assembly in inc/wizard/Wizard.inc for what each variable moves.
	Numbering: 0-1 the 2 robe shapes (walking: morphed from one to the other,
	see V_Pose_Extra.z in inc/wizard/Wizard.inc), 2 ATTACK (fire; the recovery is a blend towards 0), 3 PAIN, 4-8 DEATH.
*/
#macro Pose_Define(N_Pose)
	// the wizard's arms are neutral at 0 (the body's default is <0, 0, +-10>)
	#declare AV_Arm_Left = <0, 0, 0>;
	#declare AV_Arm_Right = <0, 0, 0>;

	#switch (N_Pose)
		#case (0)
			// ROBE SHAPE 1
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (1)
			// ROBE SHAPE 2
			#declare V_Pose_Extra = <0, 0, 1>;
		#break

		#case (2)
			// ATTACK: fire, the wand kicks up a little (recoil), flash at the tip
			#declare AV_Body = <3, 0, 0>;
			#declare AV_Head = <3, 0, 0>;
			#declare AV_Arm_Right = <18, 0, 0>;
			#declare V_Pose_Extra = <0, 0.7, 0>;
		#break

		#case (3)
			// PAIN: thrown backward
			#declare AV_Body = <6, 0, 0>;
			#declare AV_Head = <8, 0, -12>;
			#declare AV_Arm_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <-15, 0, 0>;
			#declare V_Body_Offset = <0, 0.05, -0.3>;
			#declare V_Pose_Extra = <0, 0, 1>;
		#break

		#case (4)
			// DEATH 1: shudder
			#declare AV_Body = <8, 0, 0>;
			#declare AV_Head = <10, 0, 0>;
			#declare AV_Arm_Right = <40, 0, 0>;
			#declare AV_Arm_Left = <40, 0, 0>;
			#declare V_Pose_Extra = <0.05, 0, 1>;
		#break

		#case (5)
			// DEATH 2: the robe starts to sink, the head and the hands fade
						#declare AV_Arm_Right = <30, 0, 0>;
			#declare AV_Arm_Left = <30, 0, 0>;
			#declare V_Pose_Extra = <0.3, 0, 0>;
		#break

		#case (6)
			// DEATH 3: collapsing, the head and the hands fading out
						#declare AV_Arm_Right = <20, 0, 0>;
			#declare AV_Arm_Left = <20, 0, 0>;
			#declare V_Pose_Extra = <0.6, 0, 0>;
		#break

		#case (7)
			// DEATH 4: on the ground
						#declare AV_Arm_Right = <10, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 0>;
			#declare V_Pose_Extra = <0.9, 0, 0>;
		#break

		#case (8)
			// DEATH 5: empty robe, the hat lying on it
						#declare V_Pose_Extra = <1, 0, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
