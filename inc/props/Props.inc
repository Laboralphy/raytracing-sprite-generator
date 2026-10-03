/*
	Shared by the props (p_*.pov).

	The sprite frame is as high as a wall in raycaster-386 (96 px = 6 POV
	units with the default frame of tools/sprites.py), and its bottom is
	0.1 unit below the floor (frame.baseline). A prop hanging from the
	ceiling starts at N_Prop_Ceiling.
*/

#ifndef (N_Prop_Ceiling)
	#declare N_Prop_Ceiling = 6 - 0.1;
#end
