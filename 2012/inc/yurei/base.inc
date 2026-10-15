/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/

#declare Breasts = blob {
	threshold 0.333

	sphere { 
		0
		1
		1
	}

	sphere {
		<0.222, 0, -0.4>
		0.5
		1
	}

	sphere {
		<-0.222, 0, -0.4>
		0.5
		1
	}
	scale <1, 0.8, 0.8>
}


#declare ChestVolume = sor {
	7
	<0.5, -0.5>
	<0.5, 0>
	<0.4, 0.3>
	<0.5, 0.7>
	<0.4, 0.85>
	<0.3, 1>
	<0, 1.3>
	open
}


#declare Chest = union {
	object {
		ChestVolume
	}
	object {
		Breasts
		scale 0.75
		translate <0, 0.7 , -0.1>
	}
	texture {
		ShirtTexture
	}
	translate 2 * y
}




#declare Arm = object {
	Arm
	texture {
		ArmTexture
	}
	scale <0.7, 1, 0.5>
}


#declare Mob = union {
	object {
		Head
	}
	object {
		Chest
	}
	object {
		Lower
	}
	/* 
	Arm angle : 90 -o-
	135 /o\
	45 \o/
	*/
	object {
		Arm
		rotate -155 * z
		translate <0.5, 2.75, 0>
	}
	object {
		Arm
		rotate 155 * z
		translate <-0.5, 2.75, 0>
	}
	scale 0.7
}


#declare Shadow = sphere {
	1000*y
	0.1
	pigment {
		color rgb 0
	}
}
