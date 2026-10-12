/*
	Poses of the giant wasp: see inc/Pose.inc, and the header of
	inc/wasp/Wasp.inc for what V_Pose_Extra moves (x: wing beat, y: abdomen
	curl, z: legs folded).
	Numbering: 0-1 IDLE (hovering, wings up and down), 2-5 FLY (nose down,
	wings beating, bobbing), 6-8 ATTACK (draws back curling the abdomen under,
	lunges and stings forward, recovers), 9 PAIN, 10-14 DEATH (falls, lands
	on its back, legs curling up).
*/
#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// IDLE 1: hovering, wings up
			#declare V_Pose_Extra = <45, 0, 0>;
		#break

		#case (1)
			// IDLE 2: wings down, a little lower
			#declare V_Pose_Extra = <-30, 5, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (2)
			// FLY 1: nose down, wings up
			#declare AV_Body = <-12, 0, 0>;
			#declare V_Pose_Extra = <50, 0, 0>;
			#declare V_Body_Offset = y * 0.05;
		#break

		#case (3)
			// FLY 2: wings level
			#declare AV_Body = <-12, 0, 0>;
			#declare V_Pose_Extra = <5, 3, 0>;
		#break

		#case (4)
			// FLY 3: wings down, dipping
			#declare AV_Body = <-12, 0, 0>;
			#declare V_Pose_Extra = <-35, 6, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		#case (5)
			// FLY 4: wings level, rising
			#declare AV_Body = <-12, 0, 0>;
			#declare V_Pose_Extra = <10, 3, 0>;
			#declare V_Body_Offset = y * -0.02;
		#break

		#case (6)
			// ATTACK 1: draws back, rearing, abdomen curling under
			#declare AV_Body = <15, 0, 0>;
			#declare AV_Head = <-10, 0, 0>;
			#declare V_Pose_Extra = <40, 55, 0>;
			#declare V_Body_Offset = <0, 0.15, 0.25>;
		#break

		#case (7)
			// ATTACK 2: lunges, the stinger thrust forward under the head
			#declare AV_Body = <-5, 0, 0>;
			#declare AV_Head = <15, 0, 0>;
			#declare V_Pose_Extra = <-30, 105, 0>;
			#declare V_Body_Offset = <0, -0.2, -0.45>;
		#break

		#case (8)
			// ATTACK 3: recovers
			#declare AV_Body = <-4, 0, 0>;
			#declare V_Pose_Extra = <20, 35, 0>;
			#declare V_Body_Offset = <0, -0.05, -0.1>;
		#break

		#case (9)
			// PAIN: knocked back and tilted, abdomen jerking up
			#declare AV_Body = <20, 0, 18>;
			#declare AV_Head = <15, 0, 0>;
			#declare V_Pose_Extra = <60, -20, 0.15>;
			#declare V_Body_Offset = <0, 0.1, 0.35>;
		#break

		#case (10)
			// DEATH 1: hit, rolling over, wings stopped
			#declare AV_Body = <15, 0, 40>;
			#declare V_Pose_Extra = <30, 30, 0.2>;
			#declare V_Body_Offset = y * -0.3;
		#break

		#case (11)
			// DEATH 2: falling, on its side
			#declare AV_Body = <10, 0, 100>;
			#declare V_Pose_Extra = <10, 10, 0.4>;
			#declare V_Body_Offset = y * -1.2;
		#break

		#case (12)
			// DEATH 3: hits the floor on its back
			#declare AV_Body = <0, 0, 170>;
			// on its back, a curl < 0 lays the abdomen down on the floor
			#declare V_Pose_Extra = <5, -25, 0.6>;
			#declare V_Body_Offset = y * -2.05;
		#break

		#case (13)
			// DEATH 4: legs kicking, curling up
			#declare AV_Body = <0, 0, 180>;
			#declare V_Pose_Extra = <5, -32, 0.8>;
			#declare V_Body_Offset = y * -2.1;
		#break

		#case (14)
			// DEATH 5: dead on its back, legs curled
			#declare AV_Body = <0, 0, 180>;
			#declare V_Pose_Extra = <5, -30, 1>;
			#declare V_Body_Offset = y * -2.1;
		#break
	#end
#end

#include "inc/Pose.inc"
