#local O_Weapon_Shaft = cylinder {
	0
	<0, 1, 0>
	0.05
}

#local O_Weapon_Spike = cone {
	0
	0.1
	<0, 0.4, 0>
	0
}

#local O_Weapon_Three_Spikes = union {
	object {
		O_Weapon_Spike
	}
	object {
		O_Weapon_Spike
		rotate <90, 0, 0>
	}
	object {
		O_Weapon_Spike
		rotate <-90, 0, 0>
	}
	object {
		O_Weapon_Spike
		rotate <180, 0, 0>
	}
}


#local O_Weapon_Head = sphere {
	0
	0.2
}

#local O_Weapon_Spiked_Head = union {
	object {
		O_Weapon_Head
	}
	object {
		O_Weapon_Three_Spikes
	}
	object {
		O_Weapon_Three_Spikes
		rotate <45, 90, 0>
	}
	object {
		O_Weapon_Three_Spikes
		rotate <-45, 0, 0>
	}
}

#declare P_BodyPart_ArmorPart_Weapon = union {
	object {
		O_Weapon_Shaft
	}
	object {
		O_Weapon_Spiked_Head
		translate <0, 1, 0>
	}
	scale 1.33 * N_Wrist_Len
	texture {
		pigment {
			color rgb 0.05
		}
	}
}
