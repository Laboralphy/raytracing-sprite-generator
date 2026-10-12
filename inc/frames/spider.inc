/*
	Poses of the giant spider: see inc/Pose.inc, and the header of
	inc/spider/Spider.inc for what V_Pose_Extra moves (x: walking phase,
	y: attack, z: legs curled).
	Numbering: 0-1 IDLE (breathing), 2-5 WALK (a quarter of the gait cycle
	per frame), 6-8 ATTACK (rears up, front legs raised, fangs open; lunges
	and bites; recovers), 9 PAIN, 10-14 DEATH (rears, flips onto its back,
	legs curling up).
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// IDLE 1
		#break

		#case (1)
			// IDLE 2: body a little lower, front legs stirring
			#declare V_Pose_Extra = <0, 0.08, 0>;
			#declare V_Body_Offset = y * -0.04;
		#break

		#case (2)
			// WALK 1
			#declare V_Pose_Extra = <45, 0, 0>;
		#break

		#case (3)
			// WALK 2
			#declare V_Pose_Extra = <135, 0, 0>;
			#declare V_Body_Offset = y * 0.03;
		#break

		#case (4)
			// WALK 3
			#declare V_Pose_Extra = <225, 0, 0>;
		#break

		#case (5)
			// WALK 4
			#declare V_Pose_Extra = <315, 0, 0>;
			#declare V_Body_Offset = y * 0.03;
		#break

		#case (6)
			// ATTACK 1: rears up, front legs raised, fangs open
			#declare AV_Body = <18, 0, 0>;
			#declare V_Pose_Extra = <0, 1, 0>;
			#declare V_Body_Offset = <0, 0.3, 0.2>;
		#break

		#case (7)
			// ATTACK 2: lunges and bites
			#declare AV_Body = <-12, 0, 0>;
			#declare V_Pose_Extra = <0, 0.3, 0>;
			#declare V_Body_Offset = <0, -0.1, -0.45>;
		#break

		#case (8)
			// ATTACK 3: recovers
			#declare AV_Body = <-3, 0, 0>;
			#declare V_Pose_Extra = <0, 0.15, 0>;
			#declare V_Body_Offset = z * -0.15;
		#break

		#case (9)
			// PAIN: knocked back, tilted, legs flinching
			#declare AV_Body = <12, 0, 10>;
			#declare V_Pose_Extra = <0, 0.4, 0.25>;
			#declare V_Body_Offset = <0, 0.1, 0.3>;
		#break

		#case (10)
			// DEATH 1: rears up, shuddering
			#declare AV_Body = <25, 0, 0>;
			#declare V_Pose_Extra = <0, 0.7, 0.2>;
			#declare V_Body_Offset = y * 0.2;
		#break

		#case (11)
			// DEATH 2: rolling over
			#declare AV_Body = <15, 0, 90>;
			#declare V_Pose_Extra = <0, 0.3, 0.45>;
			#declare V_Body_Offset = y * 0.1;
		#break

		#case (12)
			// DEATH 3: on its back
			#declare AV_Body = <0, 0, 175>;
			#declare V_Pose_Extra = <0, 0, 0.65>;
			#declare V_Body_Offset = y * 0.05;
		#break

		#case (13)
			// DEATH 4: legs curling
			#declare AV_Body = <0, 0, 180>;
			#declare V_Pose_Extra = <0, 0, 0.85>;
		#break

		#case (14)
			// DEATH 5: dead, legs curled up
			#declare AV_Body = <0, 0, 180>;
			#declare V_Pose_Extra = <0, 0, 1>;
		#break
	#end
#end

#include "inc/Pose.inc"
