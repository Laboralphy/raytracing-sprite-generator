/* clock = dff */

#declare MODE_DEV = int(clock / 1000);
#declare N_Animation_Direction = mod(int(clock / 100), 10);
#declare N_Animation_Frame = mod(clock, 100);
#declare N_Animation_Angle = N_Animation_Direction * 45;

/*
	Pose to render, read by inc/Pose.inc: N_Pose_From, blended towards N_Pose_To
	by N_Pose_Blend (0 = From, 1 = To). Given on the command line, for example:
		povray ... Declare=N_Pose_From=3 Declare=N_Pose_To=4 Declare=N_Pose_Blend=0.5
	By default, the pose is the frame number in clock, as before.
*/
#ifndef (N_Pose_From)
	#declare N_Pose_From = N_Animation_Frame;
#end
#ifndef (N_Pose_To)
	#declare N_Pose_To = N_Pose_From;
#end
#ifndef (N_Pose_Blend)
	#declare N_Pose_Blend = 0;
#end
