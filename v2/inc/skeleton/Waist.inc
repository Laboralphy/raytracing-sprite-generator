#declare N_Skel_BoneRing_Radius_Int = 0.5;
#declare N_Skel_BoneRing_Radius_Ext = 0.8;
#declare N_Skel_BoneRing_Radius_Border = 0.2;



#declare P_Skel_BoneRing_Ext = object {
	torus {
		N_Skel_BoneRing_Radius_Ext, N_Skel_BoneRing_Radius_Border
	}
}

#declare P_Skel_BoneRing_Int = object {
	torus {
		N_Skel_BoneRing_Radius_Int, N_Skel_BoneRing_Radius_Border
	}
}

#declare P_Skel_BoneRing_Flat = difference {
	cylinder {
		<0, -N_Skel_BoneRing_Radius_Border, 0>
		<0, N_Skel_BoneRing_Radius_Border, 0>
		N_Skel_BoneRing_Radius_Ext
	}
	cylinder {
		<0, -1, 0>
		<0, 1, 0>
		N_Skel_BoneRing_Radius_Int
	}
}

#declare P_Skel_BoneRing_One = union {
	object {
		P_Skel_BoneRing_Ext
	}
	object {
		P_Skel_BoneRing_Int
	}
	object {
		P_Skel_BoneRing_Flat
	}
	scale <1, 1, 0.8>
	rotate <90, 0, 45>
}

#declare P_Skel_BoneRings_Upper = union {
	object {
		P_Skel_BoneRing_One
		scale <-1, 1, 1>
		translate <-N_Skel_BoneRing_Radius_Ext * 0.75, N_Skel_BoneRing_Radius_Ext, 0>
	}
	object {
		P_Skel_BoneRing_One
		translate <N_Skel_BoneRing_Radius_Ext * 0.75, N_Skel_BoneRing_Radius_Ext, 0>
	}
}

#declare P_Skel_BoneRings_Lower = object {
	P_Skel_BoneRings_Upper
	scale <0.6, -0.6, 1>
	translate y * 0.2
}

#declare P_Skel_Waist = union {
	object {
		P_Skel_BoneRings_Upper
	}
	object {
		P_Skel_BoneRings_Lower
	}
	scale <1, 0.9, 1>
}
