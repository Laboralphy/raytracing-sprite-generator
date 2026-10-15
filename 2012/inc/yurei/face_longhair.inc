/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/
/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/
/****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ****** YUREI FACE HAIR LONG ******/


#declare HairRadius = 1;
#declare HairFrange = 0.6;
#declare HairLength = 0.3;

#declare Hair = lathe {
	bezier_spline
	4
	<HairRadius + HairFrange, 0>
	<0, 0>
	<HairRadius + HairFrange, HairLength + HairRadius * 2>
	<0, HairLength + HairRadius * 2>
}

#declare Hair = difference {
	object {
		Hair
	}
	object {
		Hair
		scale <10, 2, 1.4>
		translate <0, -HairRadius * 3.25, -0.7>
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
	translate 3.8 * y
}


