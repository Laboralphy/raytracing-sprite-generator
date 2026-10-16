/*
          _
__      _(_)_ __   __ _ ___
\ \ /\ / / | '_ \ / _` / __|
 \ V  V /| | | | | (_| \__ \
  \_/\_/ |_|_| |_|\__, |___/
                  |___/

	A pair of small demon (bat) wings, closed, folded against the back: a bone
	rising from the shoulder blade to a knuckle above the shoulder, the
	membrane hanging from it down to the waist, its lower edge scalloped
	between the finger tips.
	In the torso frame (y = 0 at the hips, N_Torso_Len at the shoulders, back
	towards +z): add O_Wings_Demon_Closed to P_BodyPart_ArmorPart_Chest.
	Lying on the back (AV_Body.x towards 90), they are flattened against the
	back, else they would go through the ground.
*/

#include "inc/body/BodyMetrics.inc"

#ifndef (N_Wings_Size)
	#declare N_Wings_Size = 2.2;
#end
#ifndef (N_Wings_Spread)
	#declare N_Wings_Spread = 15; // degrees, the lower part of each wing out to the side
#end
#ifndef (T_Wing_Membrane)
	#declare T_Wing_Membrane = texture {
		pigment { color rgb <0.12, 0.01, 0.04> }
		finish { ambient 0.1 diffuse 0.45 specular 0.15 roughness 0.05 }
	}
#end
#ifndef (T_Wing_Bone)
	#declare T_Wing_Bone = texture {
		pigment { color rgb <0.08, 0.03, 0.03> }
		finish { ambient 0.1 diffuse 0.6 specular 0.6 roughness 0.01 }
	}
#end

#local N_Wing_Bone = 0.035;

// left wing (+x), knuckle at the origin, in the x-y plane
#local O_Wing_Demon_Left = union {
	prism {
		linear_sweep
		linear_spline
		-0.012, 0.012
		11
		<0, 0>, <0.16, -0.2>, <0.2, -0.72>, <0.1, -0.6>, <0.04, -0.82>,
		<-0.04, -0.64>, <-0.16, -0.76>, <-0.16, -0.5>, <-0.2, -0.3>,
		<-0.1, -0.08>, <0, 0>
		rotate x * -90
		texture { T_Wing_Membrane }
	}
	// outer bone (forearm folded down) and fingers
	sphere_sweep {
		linear_spline
		3
		<0, 0, 0>, N_Wing_Bone
		<0.16, -0.2, 0>, N_Wing_Bone * 0.8
		<0.2, -0.72, 0>, N_Wing_Bone * 0.3
		texture { T_Wing_Bone }
	}
	cone {
		<0, 0, 0>, N_Wing_Bone * 0.6
		<0.04, -0.82, 0>, N_Wing_Bone * 0.2
		texture { T_Wing_Bone }
	}
	// claw on the knuckle
	cone {
		<0, 0, 0>, N_Wing_Bone
		<-0.03, 0.09, 0>, 0
		texture { T_Wing_Bone }
	}
}

#ifdef (AV_Body)
	#local N_Wings_Flatten = 1 - 0.7 * min(max(AV_Body.x / 90, 0), 1);
#else
	#local N_Wings_Flatten = 1;
#end

#local N_Back = N_Shoulder_Len * 0.65 / 2 * 1.05; // the back of the bodice

#local O_Wing_Placed = union {
	object {
		O_Wing_Demon_Left
		scale N_Wings_Size
		rotate z * N_Wings_Spread
		rotate y * 20 // outer edge forward: hugs the back
		translate <N_Shoulder_Len * 0.55, N_Torso_Len * 1.7, N_Back + 0.2 * N_Wings_Flatten>
	}
	// the bone, from the shoulder blade to the knuckle
	cylinder {
		<N_Shoulder_Len * 0.1, N_Torso_Len * 0.8, N_Back - 0.02>
		<N_Shoulder_Len * 0.55, N_Torso_Len * 1.7, N_Back + 0.2 * N_Wings_Flatten>
		N_Wing_Bone * N_Wings_Size
		texture { T_Wing_Bone }
	}
}

#declare O_Wings_Demon_Closed = union {
	object { O_Wing_Placed }
	object { O_Wing_Placed scale <-1, 1, 1> }
}
