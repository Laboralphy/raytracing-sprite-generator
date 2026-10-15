/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/
/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/
/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/


#declare Hair = lathe {
	bezier_spline
	4
	<1, 0>
	<1, 1>
	<0.5, 1.2>
	<0, 1>
}

#declare Hair = difference {
	object {
		Hair
	}
	object {
		Hair
		translate <0, -0.2, -0.2>
	}
	scale <0.9, 2.3, 0.9>
	translate -0.4 * y
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
	translate 3.8 * y
}


