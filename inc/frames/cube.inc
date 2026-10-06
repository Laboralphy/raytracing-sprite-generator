/*
	Poses of the evil cube: see inc/Pose.inc, and the header of
	inc/cube/Cube.inc for what V_Pose_Extra moves.
	Numbering: 0-1 IDLE, 2-5 WALK (one roll of a quarter turn, jerky: rest,
	lift, tumble, fall; the next rest is the next face), 6-7 ATTACK (white
	hot; the recovery is a blend towards 0), 8 PAIN, 9-14 DEATH.

	The walk compensates the roll with V_Body_Offset.z = N_Cube_Size * roll:
	the cube stays centred in the frame, the engine moves it forward.
*/
#ifndef (N_Cube_Size)
	#declare N_Cube_Size = 2.2;
#end

#macro Pose_Define(N_Pose)
	#switch (N_Pose)
		#case (0)
			// IDLE 1: glowing red
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (1)
			// IDLE 2: the glow breathes, darker
			#declare V_Pose_Extra = <0, -0.35, 0>;
		#break

		#case (2)
			// WALK 1: rest
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (3)
			// WALK 2: lifts its back on the front edge, heating up with the effort
			#declare V_Pose_Extra = <0.1, 0.1, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.1;
		#break

		#case (4)
			// WALK 3: on the edge
			#declare V_Pose_Extra = <0.5, 0.15, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.5;
		#break

		#case (5)
			// WALK 4: falls on the next face
			#declare V_Pose_Extra = <0.85, 0.05, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.85;
		#break

		#case (6)
			// ATTACK 1: rocks back on its back edge, heating up
			#declare V_Pose_Extra = <-0.12, 0.4, 0>;
			#declare V_Body_Offset = z * 0.1;
		#break

		#case (7)
			// ATTACK 2: lunges on its front edge, white hot
			#declare V_Pose_Extra = <0.15, 1, 0>;
			#declare V_Body_Offset = z * -0.4;
		#break

		#case (8)
			// PAIN: knocked back on its back edge, the glow sputters
			#declare AV_Body = <0, 0, 5>;
			#declare V_Pose_Extra = <-0.15, -0.6, 0>;
			#declare V_Body_Offset = z * 0.25;
		#break

		#case (9)
			// DEATH 1: overheats and shudders
			#declare AV_Body = <0, 0, 4>;
			#declare V_Pose_Extra = <-0.06, 1, 0>;
		#break

		#case (10)
			// DEATH 2: topples forward
			#declare V_Pose_Extra = <0.2, 0.6, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.2;
		#break

		#case (11)
			// DEATH 3: on its edge, cooling
			#declare V_Pose_Extra = <0.55, 0, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.55;
		#break

		#case (12)
			// DEATH 4: falling face down
			#declare V_Pose_Extra = <0.9, -0.4, 0>;
			#declare V_Body_Offset = z * N_Cube_Size * 0.9;
		#break

		#case (13)
			// DEATH 5: face down, the face on top now looks forward, embers
			#declare V_Pose_Extra = <1, -0.7, 0>;
			#declare V_Body_Offset = z * N_Cube_Size;
		#break

		#case (14)
			// DEATH 6: cold
			#declare V_Pose_Extra = <1, -1, 0>;
			#declare V_Body_Offset = z * N_Cube_Size;
		#break
	#end
#end

#include "inc/Pose.inc"
