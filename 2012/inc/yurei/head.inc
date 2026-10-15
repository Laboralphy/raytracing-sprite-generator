#declare HeadBase = union {
	sphere {
		0
		1
		scale <0.7, 0.75, 0.7>
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
	cylinder {
		0
		0.1 * y
		0.7
		texture {
			NeckTexture
		}
		translate 0.4 * y
	}
	triangle {
		<-0.3, 0, -0.7>
		<0.3, 0, -0.7>
		<0, 0.4, -0.6>
		texture {
			NeckTexture
		}
		translate 0.4 * y
	}
}



