/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/
/****** WITCH ****** WITCH ****** WITCH ****** WITCH ****** WITCH ******/

#include "inc/warlock_hat.inc"

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
	translate 1.5 * y
}


#declare Skirt = cone {
	0
	0.9
	0.7 * y
	0.5
	texture {
		SkirtTexture
	}
}

#declare Skirt = lathe {
	bezier_spline
	4
	<0.8, 0>
	<1, -0.2>
	<0.7, 0.7>
	<0.4, 0.9>
	texture {
		SkirtTexture
	}
}


#declare Arm = object {
	Arm
	texture {
		ArmTexture
	}
	scale <0.7, 1, 0.5>
}


#declare HeadBase = sphere {
	0
	1
	scale <0.7, 0.75, 0.7>
}


#declare HairRadius = 1;
#declare HairFrange = 0.6;
#declare HairLength = 0.3;
#declare HairHeight = 1.7;

#declare Hair = lathe {
	bezier_spline
	4
	<HairRadius + HairFrange, 0>
	<0, 0>
	<HairRadius + HairFrange, HairLength + HairRadius * HairHeight>
	<0, HairLength + HairRadius * HairHeight>
}

#declare Hair = difference {
	object {
		Hair
	}
	object {
		Hair
		scale <10, 2, 1.3>
		translate <0, -HairRadius * 2.55, -0.7>
	}
}


#declare Head = union {
	object { 
		HeadBase
		texture {
			HeadTexture
		}
	}
	object {
		Hair
		texture {
			HairTexture
		}
		translate -1.2 * y
	}
	cylinder {
		0
		0.3 * y
		0.25
		texture {
			NeckTexture
		}
		translate -y
	}
}

#declare Leg = object {
	Leg
	texture {
		LegTexture
	}
}	

#declare Body = union {
	object {
		Chest
	}
	object {
		Skirt
		translate 0.8 * y
	}
	object {
		Leg
		rotate LegRotation * x
		translate <-0.375, 1, 0>
	}
	object {
		Leg
		rotate -LegRotation * x
		translate <0.375, 1, 0>
	}
	/* 
	Arm angle : 90 -o-
	135 /o\
	45 \o/
	*/
	object {
		Arm
		rotate -LegRotation * x
		rotate -135 * z
		translate <0.5, 2.25, 0>
	}
	object {
		Arm
		rotate LegRotation * x
		rotate 135 * z
		translate <-0.5, 2.25, 0>
	}
}

#declare Mob = union {
	object {
		Body
	}
	object {
		Head
		translate 3.3 * y
	}
	object {
		Hat
		scale 0.714
		translate 3.75 * y
	}
	scale 0.6
	translate <0, Hop / 2 + 0.25, 0>
}
