/*

                                                   _
  __ _ _   _  ___  ___ _ __     ___ ___  ___| |_ _   _ _ __ ___   ___
 / _` | | | |/ _ \/ _ \ '_ \   / __/ _ \/ __| __| | | | '_ ` _ \ / _ \
| (_| | |_| |  __/  __/ | | | | (_| (_) \__ \ |_| |_| | | | | | |  __/
 \__, |\__,_|\___|\___|_| |_|  \___\___/|___/\__|\__,_|_| |_| |_|\___|
    |_|

	Dress of the witch queen: same cut as Witch_Costume_Blue_Skirt (its
	bodice O_FemaleShirt_Base is reused), the colour fades from blue on the
	shoulders to dark gray at the hem, gold lattice on the bodice, gold trims
	(neckline, sleeves, hem), the skirt is cut in an arch at the front.

	The gradient is given in the torso frame (y = 0 at the hips, N_Torso_Len
	at the shoulders); the skirt is placed N_Torso_Len / 4 higher by the body.
*/

#include "inc/armors/Witch_Costume_Blue_Skirt.inc"

#ifndef (C_Queen_Dress_Top)
	#declare C_Queen_Dress_Top = color rgb <0.1, 0.18, 0.85>;
#end
#ifndef (C_Queen_Dress_Bottom)
	#declare C_Queen_Dress_Bottom = color rgb <0.13, 0.13, 0.15>;
#end
#ifndef (T_Queen_Gold)
	#declare T_Queen_Gold = texture {
		pigment { color rgb <0.9, 0.68, 0.2> }
		finish {
			ambient 0.15
			diffuse 0.6
			specular 0.9
			roughness 0.01
			metallic
			reflection 0.15
		}
	}
#end
// torso heights where the fade starts (blue) and ends (dark gray)
#ifndef (N_Queen_Fade_Top)
	#declare N_Queen_Fade_Top = N_Torso_Len * 0.6;
#end
#ifndef (N_Queen_Fade_Bottom)
	#declare N_Queen_Fade_Bottom = -N_Torso_Len * 0.3;
#end

// macros give texture bodies: use them in texture { } or texture_map entries
#macro Queen_Fabric(C)
	pigment {
		radial
		color_map {
			[0 C]
			[0.5 C * 0.5]
			[1 C]
		}
		frequency 16
	}
#end

// fade from top to bottom, given in the frame where the torso starts at N_Y0
#macro Queen_Fade(N_Y0)
	function {
		min(max((y + N_Y0 - N_Queen_Fade_Bottom) / (N_Queen_Fade_Top - N_Queen_Fade_Bottom), 0), 1)
	}
	texture_map {
		[0 Queen_Fabric(C_Queen_Dress_Bottom)]
		[1 Queen_Fabric(C_Queen_Dress_Top)]
	}
#end



/*
 _               _ _
| |__   ___   __| (_) ___ ___
| '_ \ / _ \ / _` | |/ __/ _ \
| |_) | (_) | (_| | | (_|  __/
|_.__/ \___/ \__,_|_|\___\___|

*/

#local N_Lattice = N_Torso_Len * 0.4; // size of a diamond
#local N_Lattice_Line = 0.06; // line width, in fraction of a diamond
#local N_Lattice_Dot = 0.12;

#local F_Lattice_D = function (A) { abs(A - floor(A + 0.5)) }
#local F_Lattice_U = function (X, Y) { F_Lattice_D((X + Y) / N_Lattice) }
#local F_Lattice_V = function (X, Y) { F_Lattice_D((X - Y) / N_Lattice) }

#declare T_Queen_Bodice = texture {
	function {
		select(
			min(F_Lattice_U(x, y), F_Lattice_V(x, y)) - N_Lattice_Line,
			1,
			select(
				pow(0.5 - F_Lattice_U(x, y), 2) + pow(0.5 - F_Lattice_V(x, y), 2) - pow(N_Lattice_Dot, 2),
				1,
				0
			)
		)
	}
	texture_map {
		[0.5 Queen_Fade(0)]
		[0.5 T_Queen_Gold]
	}
	translate x * N_Lattice / 2
}

#local N_Neckline_Radius = N_Shoulder_Len / 2.5;

#local O_Neckline_Cutter = cylinder {
	<0, 1.5 * N_Torso_Len, 2>
	<0, 1.2 * N_Torso_Len, -10>
	N_Neckline_Radius
}

#declare O_Queen_Bodice = union {
	difference {
		object { O_FemaleShirt_Base }
		object { O_Neckline_Cutter }
		texture { T_Queen_Bodice }
	}
	// gold trim around the neckline
	difference {
		intersection {
			object {
				O_FemaleShirt_Base
				translate <0, -N_Torso_Len / 2, 0>
				scale 1.03
				translate <0, N_Torso_Len / 2, 0>
			}
			cylinder {
				<0, 1.5 * N_Torso_Len, 2>
				<0, 1.2 * N_Torso_Len, -10>
				N_Neckline_Radius + 0.05
			}
		}
		object { O_Neckline_Cutter }
		texture { T_Queen_Gold }
	}
}

#declare P_BodyPart_ArmorPart_Chest = O_Queen_Bodice;



/*
     _    _      _
 ___| | _(_)_ __| |_
/ __| |/ / | '__| __|
\__ \   <| | |  | |_
|___/_|\_\_|_|   \__|

	Same profile as O_Skirt_Blue, cut in an arch at the front, gold hem.
*/

#ifndef (N_Queen_Slit_Height)
	#declare N_Queen_Slit_Height = 0.4; // height of the front cut, from the hem
#end
#ifndef (N_Queen_Slit_Width)
	#declare N_Queen_Slit_Width = 0.22;
#end

#local N_Hem = -0.9 * 0.9 + 0.1; // the first point of the sor is a control point

#local O_Queen_Skirt_Shape = sor {
	6
	<1, -1>
	<0.7, -0.9>
	<0.65, -0.8>
	<0.6, -0.5>
	<0.4, -0.1>
	<0, 0>
	sturm
	scale <1, 0.9, 1.2>
	scale V_BodyPart_Torso_Scale
	translate 0.1 * y
}

// a shell, so that the legs show through the slit
#local O_Queen_Skirt_Shell = difference {
	object { O_Queen_Skirt_Shape }
	object { O_Queen_Skirt_Shape scale <0.94, 1.1, 0.94> }
}

#local O_Queen_Slit = sphere {
	0, 1
	scale <N_Queen_Slit_Width, N_Queen_Slit_Height, 0.6>
	translate <0, N_Hem, -0.8>
}

#declare O_Queen_Skirt = union {
	difference {
		object { O_Queen_Skirt_Shell }
		object { O_Queen_Slit }
		texture { Queen_Fade(N_Torso_Len / 4) }
	}
	// gold hem
	difference {
		intersection {
			object {
				O_Queen_Skirt_Shape
				translate y * -N_Hem
				scale <1.02, 1, 1.02>
				translate y * N_Hem
			}
			plane { y, N_Hem + 0.06 }
		}
		object { O_Queen_Skirt_Shape scale <0.94, 1.1, 0.94> }
		object { O_Queen_Slit }
		texture { T_Queen_Gold }
	}
}

#declare P_BodyPart_ArmorPart_Skirt = O_Queen_Skirt;



/*
     _                 _     _
 ___| |__   ___  _   _| | __| | ___ _ __ ___
/ __| '_ \ / _ \| | | | |/ _` |/ _ \ '__/ __|
\__ \ | | | (_) | |_| | | (_| |  __/ |  \__ \
|___/_| |_|\___/ \__,_|_|\___,_|\___|_|  |___/

*/

#declare P_BodyPart_ArmorPart_Shoulder = union {
	union {
		sphere {
			<0, N_Arm_Len, 0>
			N_Arm_Thickness * 2.1
		}
		cylinder {
			<0, N_Arm_Len, 0>
			<0, N_Arm_Len * 0.5, 0>
			N_Arm_Thickness * 1.5
		}
		texture { Queen_Fabric(C_Queen_Dress_Top) }
	}
	torus {
		N_Arm_Thickness * 1.5
		N_Arm_Thickness * 0.3
		translate <0, N_Arm_Len * 0.5, 0>
		texture { T_Queen_Gold }
	}
}
