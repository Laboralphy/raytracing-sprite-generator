/*
	Shield of the dark knight: the heater shape of Weapon_Crossed_Shield, in
	blackened iron with a rim, a demon skull in relief on the front: bone
	cranium, red glowing eye sockets, nasal hole, fanged jaw, curved horns.
	Same frame as Weapon_Crossed_Shield (front towards -z, then scaled and
	placed for the shield slot of the left forearm).

	Textures overridable: T_Shield_Iron, T_Shield_Bone, T_Shield_Horn,
	C_Shield_Eyes.
*/

#ifndef (T_Shield_Iron)
	#ifdef (T_Dark_Armor)
		#declare T_Shield_Iron = texture { T_Dark_Armor scale 0.6 }
	#else
		#declare T_Shield_Iron = texture {
			pigment { color rgb <0.12, 0.12, 0.14> }
			finish { specular 0.6 roughness 0.02 metallic }
		}
	#end
#end
#ifndef (T_Shield_Bone)
	#declare T_Shield_Bone = texture {
		pigment {
			bozo
			color_map {
				[0 color rgb <0.78, 0.72, 0.6>]
				[1 color rgb <0.6, 0.53, 0.42>]
			}
			scale 0.15
		}
		finish { ambient 0.12 diffuse 0.7 specular 0.3 roughness 0.03 }
	}
#end
#ifndef (T_Shield_Horn)
	#declare T_Shield_Horn = texture {
		pigment { color rgb <0.08, 0.05, 0.05> }
		finish { specular 0.6 roughness 0.01 }
	}
#end
#ifndef (C_Shield_Eyes)
	#declare C_Shield_Eyes = color rgb <1, 0.15, 0.05>;
#end

#local O_Shield_Base = prism {
	linear_spline
	0, 0.25, 6,
	<-1, 1>, <1, 1>, <1, -1>, <0, -1.5>, <-1, -1>, <-1, 1>
	rotate <-90, 0, 0>
}

// rim: the base minus a thinner, smaller copy on the front
#local O_Shield_Body = difference {
	object { O_Shield_Base }
	object {
		O_Shield_Base
		scale <0.88, 0.88, 1>
		translate <0, -0.03, -0.08>
	}
}

/*
	demon skull, centred at <0, 0.1>, its back sunk into the plate (z = -0.17)
*/
#local N_Skull_Z = -0.17;

#local O_Skull_Socket = sphere {
	0, 0.16
	scale <1.2, 0.9, 1>
}

#local O_Skull_Bone = difference {
	union {
		// cranium
		sphere {
			0, 0.5
			scale <1, 0.95, 0.4>
			translate <0, 0.22, N_Skull_Z>
		}
		// cheekbones and upper jaw
		sphere {
			0, 0.36
			scale <1, 0.7, 0.4>
			translate <0, -0.1, N_Skull_Z>
		}
		// lower jaw
		box {
			<-0.24, -0.5, N_Skull_Z>, <0.24, -0.3, N_Skull_Z - 0.13>
		}
	}
	// eye sockets, slanted: angry
	object { O_Skull_Socket rotate z * -20 translate <0.2, 0.12, N_Skull_Z - 0.2> }
	object { O_Skull_Socket rotate z * 20 translate <-0.2, 0.12, N_Skull_Z - 0.2> }
	// nasal hole, an inverted triangle
	prism {
		linear_spline
		-1, 1, 4
		<-0.07, -0.02>, <0.07, -0.02>, <0, -0.18>, <-0.07, -0.02>
		rotate x * -90
		translate z * N_Skull_Z
	}
	// mouth
	box { <-0.2, -0.33, N_Skull_Z - 0.3>, <0.2, -0.28, N_Skull_Z + 0.05> }
	texture { T_Shield_Bone }
}

#local O_Skull_Teeth = union {
	#local I = 0;
	#while (I < 6)
		#local N_X = -0.175 + I * 0.07;
		#if (I = 1 | I = 4)
			// fangs
			cone { <N_X, -0.24, 0>, 0.035, <N_X, -0.42, 0>, 0 }
		#else
			cone { <N_X, -0.27, 0>, 0.03, <N_X, -0.34, 0>, 0 }
		#end
		#local I = I + 1;
	#end
	translate z * (N_Skull_Z - 0.12)
	texture { T_Shield_Bone }
}

#local O_Skull_Eyes = union {
	sphere { <0.2, 0.12, N_Skull_Z - 0.1>, 0.11 }
	sphere { <-0.2, 0.12, N_Skull_Z - 0.1>, 0.11 }
	texture {
		pigment { C_Shield_Eyes }
		finish { ambient 1 diffuse 0 }
	}
}

// left horn of the skull, from the temple, curving out and up
#local O_Skull_Horn = sphere_sweep {
	b_spline
	5
	<0.25, 0.3, 0>, 0.1
	<0.38, 0.45, 0>, 0.09
	<0.62, 0.55, 0>, 0.06
	<0.78, 0.85, 0>, 0.02
	<0.75, 0.98, 0>, 0
	translate z * (N_Skull_Z - 0.08)
	texture { T_Shield_Horn }
}

#declare P_BodyPart_ArmorPart_Shield = union {
	object {
		O_Shield_Body
		texture { T_Shield_Iron }
	}
	union {
		object { O_Skull_Bone }
		object { O_Skull_Teeth }
		object { O_Skull_Eyes }
		object { O_Skull_Horn }
		object { O_Skull_Horn scale <-1, 1, 1> }
		translate y * -0.05
	}
	scale 0.72
	translate <0.25, -0.25, 0>
}
