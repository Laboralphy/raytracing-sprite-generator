/*
	Poses of the slime: see inc/Pose.inc, and the header of
	inc/slime/Slime.inc for what V_Pose_Extra and AV_Thigh_Left move.
	Numbering: 0-1 IDLE, 2-5 WALK (the pseudopods ripple a quarter turn per
	frame), 6-8 ATTACK (rears up, spits, settles), 9 PAIN, 10-15 DEATH
	(collapses like a flan, wobbles, ends as a puddle).
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// IDLE 1
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (1)
			// IDLE 2: swells a little
			#declare V_Pose_Extra = <0.07, 0, 0>;
		#break

		#case (2)
			// WALK 1
			#declare AV_Thigh_Left = <0, 1, 0>;
			#declare V_Pose_Extra = <0.04, 0, 0>;
		#break

		#case (3)
			// WALK 2
			#declare AV_Thigh_Left = <90, 1, 0>;
			#declare AV_Body = <-4, 0, 0>;
			#declare V_Pose_Extra = <-0.04, 0, 0>;
		#break

		#case (4)
			// WALK 3
			#declare AV_Thigh_Left = <180, 1, 0>;
			#declare V_Pose_Extra = <0.04, 0, 0>;
		#break

		#case (5)
			// WALK 4
			#declare AV_Thigh_Left = <270, 1, 0>;
			#declare AV_Body = <-4, 0, 0>;
			#declare V_Pose_Extra = <-0.04, 0, 0>;
		#break

		#case (6)
			// ATTACK 1: rears up, leaning back
			#declare AV_Thigh_Left = <0, 0, -0.1>;
			#declare AV_Body = <8, 0, 0>;
			#declare V_Pose_Extra = <0.2, 0, 0>;
		#break

		#case (7)
			// ATTACK 2: spits, thrown forward
			#declare AV_Body = <-10, 0, 0>;
			#declare V_Body_Offset = z * -0.1;
			#declare V_Pose_Extra = <-0.15, 0, 0.7>;
		#break

		#case (8)
			// ATTACK 3: settles back
			#declare AV_Body = <-3, 0, 0>;
			#declare V_Pose_Extra = <-0.08, 0, 0>;
		#break

		#case (9)
			// PAIN: squashed and knocked aside
			#declare AV_Thigh_Left = <0, 0, -0.15>;
			#declare AV_Body = <6, 0, 8>;
			#declare V_Body_Offset = z * 0.2;
			#declare V_Pose_Extra = <-0.25, 0, 0>;
		#break

		#case (10)
			// DEATH 1: shudders and stretches up
			#declare AV_Thigh_Left = <0, 0, -0.3>;
			#declare V_Pose_Extra = <0.25, 0, 0>;
		#break

		#case (11)
			// DEATH 2: sags
			#declare AV_Thigh_Left = <0, 0, -0.3>;
			#declare V_Pose_Extra = <-0.3, 0, 0>;
		#break

		#case (12)
			// DEATH 3: crushed flat
			#declare AV_Thigh_Left = <0, 0, -0.35>;
			#declare V_Pose_Extra = <-0.75, 0, 0>;
		#break

		#case (13)
			// DEATH 4: wobbles back up
			#declare AV_Thigh_Left = <0, 0, -0.35>;
			#declare V_Pose_Extra = <-0.55, 0, 0>;
		#break

		#case (14)
			// DEATH 5: settles
			#declare AV_Thigh_Left = <0, 0, -0.35>;
			#declare V_Pose_Extra = <-0.72, 0, 0>;
		#break

		#case (15)
			// DEATH 6: puddle
			#declare AV_Thigh_Left = <0, 0, -0.35>;
			#declare V_Pose_Extra = <-0.7, 0, 0>;
		#break
	#end
#end

#include "inc/Pose.inc"
