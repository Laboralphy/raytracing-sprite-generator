/*
                                 _                                  _
 ___ _   _  ___ ___ _   _| |__  _   _ ___    ___ ___  ___| |_ _   _ _ __ ___   ___
/ __| | | |/ __/ __| | | | '_ \| | | / __|  / __/ _ \/ __| __| | | | '_ ` _ \ / _ \
\__ \ |_| | (_| (__| |_| | |_) | |_| \__ \ | (_| (_) \__ \ |_| |_| | | | | | |  __/
|___/\__,_|\___\___|\__,_|_.__/ \__,_|___/  \___\___/|___/\__|\__,_|_| |_| |_|\___|

	Dress of the succubus: same cut as Witch_Costume_Blue_Skirt (its bodice
	O_FemaleShirt_Base is reused), bodice of glossy red leather, no sleeves,
	small closed demon wings on the back (Wings_Demon_Closed), pleated skirt
	cut high on each side.
*/

#include "inc/armors/Witch_Costume_Blue_Skirt.inc"
#include "inc/armors/Wings_Demon_Closed.inc"

// no sleeves
#undef P_BodyPart_ArmorPart_Shoulder

#ifndef (T_Succubus_Leather)
	#declare T_Succubus_Leather = texture {
		pigment { color rgb <0.6, 0.04, 0.06> }
		normal { bumps 0.15 scale 0.03 }
		finish {
			ambient 0.1
			diffuse 0.6
			specular 0.8
			roughness 0.008
			reflection 0.05
		}
	}
#end
#ifndef (C_Succubus_Skirt)
	#declare C_Succubus_Skirt = color rgb <0.45, 0.02, 0.06>;
#end
#ifndef (T_Succubus_Skirt)
	#declare T_Succubus_Skirt = texture {
		pigment {
			radial
			color_map {
				[0 C_Succubus_Skirt]
				[0.5 C_Succubus_Skirt * 0.5]
				[1 C_Succubus_Skirt]
			}
			frequency 16
		}
		finish { specular 0.15 roughness 0.05 }
	}
#end



/*
 _               _ _
| |__   ___   __| (_) ___ ___
| '_ \ / _ \ / _` | |/ __/ _ \
| |_) | (_) | (_| | | (_|  __/
|_.__/ \___/ \__,_|_|\___\___|

*/

#declare O_Succubus_Bodice = difference {
	object { O_FemaleShirt_Base }
	cylinder {
		<0, 1.5 * N_Torso_Len, 2>
		<0, 1.2 * N_Torso_Len, -10>
		N_Shoulder_Len / 2.5
	}
	// sleeveless: the shoulders are bare
	#local O_Shoulder_Cut = sphere {
		0, 1
		scale <N_Shoulder_Len * 0.3, N_Torso_Len * 0.4, N_Shoulder_Len>
		translate <N_Shoulder_Len * 0.62, N_Torso_Len * 1.08, 0>
	}
	object { O_Shoulder_Cut }
	object { O_Shoulder_Cut scale <-1, 1, 1> }
	texture { T_Succubus_Leather }
}

#declare P_BodyPart_ArmorPart_Chest = union {
	object { O_Succubus_Bodice }
	object { O_Wings_Demon_Closed }
}



/*
     _    _      _
 ___| | _(_)_ __| |_
/ __| |/ / | '__| __|
\__ \   <| | |  | |_
|___/_|\_\_|_|   \__|

	Same profile as O_Skirt_Blue, a shell (the legs show through the cuts),
	cut in an arch on each side.
*/

#ifndef (N_Succubus_Slit_Height)
	#declare N_Succubus_Slit_Height = 0.5; // height of the side cuts, from the hem
#end
#ifndef (N_Succubus_Slit_Width)
	#declare N_Succubus_Slit_Width = 0.25; // half width, along z
#end
#ifndef (N_Succubus_Slit_Angle)
	// cuts brought forward from the sides, else the arms hide them
	#declare N_Succubus_Slit_Angle = 30;
#end

#local N_Hem = -0.9 * 0.9 + 0.1; // the first point of the sor is a control point

#local O_Succubus_Skirt_Shape = sor {
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

#local O_Succubus_Slit = sphere {
	0, 1
	scale <0.6, N_Succubus_Slit_Height, N_Succubus_Slit_Width>
	translate <0.75, N_Hem, 0>
	rotate y * N_Succubus_Slit_Angle
}

#declare O_Succubus_Skirt = difference {
	object { O_Succubus_Skirt_Shape }
	object { O_Succubus_Skirt_Shape scale <0.94, 1.1, 0.94> }
	object { O_Succubus_Slit }
	object { O_Succubus_Slit scale <-1, 1, 1> }
	texture { T_Succubus_Skirt }
}

#declare P_BodyPart_ArmorPart_Skirt = O_Succubus_Skirt;
