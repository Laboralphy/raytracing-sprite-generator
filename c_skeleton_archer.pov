/*


Skeleton archer: bow (inc/weapons/Weapon_Bow.inc), archer poses
(inc/frames/archer.inc), quiver on the back.

*/

#include "inc/Camera.inc"
#include "inc/frames/archer.inc"
#declare C_Skin = color rgb <0.8, 0.8, 0.6>;

#declare T_Skin_Bones = texture {
	pigment {
		C_Skin
	}
}


#declare T_BodyPart_Face = texture {
	pigment {
		image_map {
			png "png/skull_face_blue_eyes.png"
			map_type 2
		}
		scale <1, 2, 1>
		translate <0, -0.6, -0.25>
	}
}

#declare T_BodyPart_Skin = T_Skin_Bones

#include "inc/skeleton/Body.inc"
#include "inc/skeleton/Waist"
#include "inc/skeleton/Skull"
#include "inc/skeleton/Shin_1"


#include "inc/weapons/Weapon_Bow"

/*
	Quiver on the back (+z), slanting: its mouth above the right shoulder
	(-x), on the side of the drawing hand. Leather tube, thin metal rings at
	both ends, a few arrows sticking out.
*/
#declare N_Quiver_Len = 1.1;
#declare N_Quiver_Radius = 0.13;

#declare T_Quiver_Leather = texture {
	pigment {
		bozo
		color_map {
			[0 color rgb <0.35, 0.18, 0.07>]
			[1 color rgb <0.25, 0.12, 0.04>]
		}
		scale 0.08
	}
	finish {
		specular 0.2
		roughness 0.05
	}
}

#declare T_Quiver_Metal = texture {
	pigment {
		color rgb <0.6, 0.55, 0.45>
	}
	finish {
		specular 0.8
		roughness 0.01
		metallic
	}
}

#declare O_Quiver_Arrow = union {
	cylinder {
		<0, N_Quiver_Len - 0.3, 0>, <0, N_Quiver_Len + 0.22, 0>, 0.02
		texture {
			T_Arrow_Shaft
		}
	}
	box {
		<-0.05, N_Quiver_Len + 0.05, -0.004>, <0.05, N_Quiver_Len + 0.2, 0.004>
		texture {
			T_Arrow_Fletching
		}
	}
	box {
		<-0.004, N_Quiver_Len + 0.05, -0.05>, <0.004, N_Quiver_Len + 0.2, 0.05>
		texture {
			T_Arrow_Fletching
		}
	}
}

// along +y from its bottom (origin)
#declare O_Quiver = union {
	cylinder {
		0, <0, N_Quiver_Len, 0>, N_Quiver_Radius
		texture {
			T_Quiver_Leather
		}
	}
	torus {
		N_Quiver_Radius, 0.025
		texture {
			T_Quiver_Metal
		}
	}
	torus {
		N_Quiver_Radius, 0.025
		translate y * N_Quiver_Len
		texture {
			T_Quiver_Metal
		}
	}
	object {
		O_Quiver_Arrow
		translate <0.05, 0, 0.04>
	}
	object {
		O_Quiver_Arrow
		rotate y * 50
		translate <-0.05, 0.04, 0.03>
	}
	object {
		O_Quiver_Arrow
		rotate y * 20
		translate <0, -0.03, -0.06>
	}
}

#declare P_BodyPart_Torso_Replace = union {
	object {
		O_Skel_Spine
	}
	object {
		P_Skel_Waist
		scale 0.25
	}
	object {
		O_Quiver
		rotate z * 35
		translate <0.35, 0.4, 0.36>
	}
	texture { T_BodyPart_Skin }
}


/*
	Horned cap (inc/armors/Helm_Horned_Cap.inc: leather, iron frame, ivory
	horns), in the frame of the skull (before the scale N_Head_Size), the eye
	sockets left free. It tells the archer from the sword skeleton.
*/
#include "inc/armors/Helm_Horned_Cap.inc"

#declare V_Cerveliere_Centre = <0, 0.62, -0.25>;
#declare V_Cerveliere_Radii = <1.1, 1, 1.14>;

#declare O_Cerveliere = object {
	O_Helm_Horned_Cap
	scale V_Cerveliere_Radii
	// tilted: lower at the back of the head
	rotate x * 14
	translate V_Cerveliere_Centre
}

#declare P_BodyPart_Head_Replace = union {
	object {
		O_Skel_Skull
	}
	object {
		O_Cerveliere
	}
	#ifdef (T_BodyPart_Skin)
		texture {
			T_BodyPart_Skin
		}
	#end
	#ifdef (T_BodyPart_Face) 
		texture {
			T_BodyPart_Face
		}
	#end
	scale N_Head_Size
}

#include "inc/armors/MaleShirt_Ripped_Dirty_Brownish"
#include "inc/skeleton/Leg"
#include "inc/skeleton/Wrist_1"
#include "inc/body/BodyParts.inc"

#declare O_Character_1 = object {
	O_BodyPart_Armored_Body_M
}

object {
	O_Character_1
	rotate y * N_Animation_Angle
}
