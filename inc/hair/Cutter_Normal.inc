// permet de faire onduler un peu la coupe
#declare P_Hair_Ondulator = union {
	cone {
		<0, 0, 0>
		0
		<0, 0, -2>
		0.9
	}
	cone {
		<0, 0.25, 0>
		0
		<0, 0.25, -2>
		0.8
	}
	cone {
		<0, 0.5, 0>
		0
		<0, 0.5, -2>
		0.7
	}
	cone {
		<0, 0.75, 0>
		0
		<0, 0.75, -2>
		0.55
	}
}

// Hair cutter normal

#declare P_Hair_Cutter_Normal = union {
	prism {
		linear_spline
		-10
		1
		3
		<0, 0>
		<1.5, -2>
		<-1.5, -2>
	}
	object {
		P_Hair_Ondulator
		rotate <0, 30, 0>
	}
	object {
		P_Hair_Ondulator
		rotate <0, -30, 0>
	}
}
