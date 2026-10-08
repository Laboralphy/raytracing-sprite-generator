/*
	Tombstones of old mossy stone. Origin on the ground, the face towards -z.
	Tombstone_Round(N_Text): a slab with a rounded top, an engraved text.
	Tombstone_Cross(): a stone cross.
*/

#declare T_Tomb_Stone = texture {
	pigment {
		granite
		color_map {
			[0 color rgb <0.45, 0.45, 0.43>]
			[0.6 color rgb <0.36, 0.36, 0.35>]
			[1 color rgb <0.25, 0.25, 0.25>]
		}
		scale 0.6
	}
	normal {
		granite 0.4
		scale 0.15
	}
	finish {
		ambient 0
		diffuse 0.7
	}
}
// moss in the lower part
texture {
	pigment {
		bozo
		turbulence 0.8
		color_map {
			[0 rgbt <0.12, 0.2, 0.06, 0>]
			[0.35 rgbt <0.15, 0.22, 0.08, 0.3>]
			[0.5 rgbt <0, 0, 0, 1>]
			[1 rgbt <0, 0, 0, 1>]
		}
		scale 0.25
	}
	finish {
		ambient 0
		diffuse 0.6
	}
}

#macro Tombstone_Round(N_Text)
	difference {
		union {
			box { <-0.5, 0, -0.1>, <0.5, 1.1, 0.1> }
			cylinder { <0, 1.1, -0.1>, <0, 1.1, 0.1>, 0.5 }
		}
		text {
			ttf "timrom.ttf" N_Text 1, 0
			scale 0.28
			translate <-0.04 * strlen(N_Text) * 2.2, 1.05, -0.12>
		}
		// a chipped corner
		sphere { <0.45, 1.35, -0.1>, 0.14 }
		texture { T_Tomb_Stone }
	}
#end

#macro Tombstone_Cross()
	union {
		box { <-0.32, 0, -0.18>, <0.32, 0.18, 0.18> }
		box { <-0.08, 0.18, -0.08>, <0.08, 1.6, 0.08> }
		box { <-0.42, 1.05, -0.08>, <0.42, 1.21, 0.08> }
		texture { T_Tomb_Stone }
	}
#end
