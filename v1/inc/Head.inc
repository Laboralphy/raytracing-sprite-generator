#declare P_Head = sphere {
	<0, 0, 0>, 1
}

#declare O_BlackMageHead = object {
	P_Head
	texture {
		pigment {
			image_map {
				png "png/w_black_face.png"
				map_type 1
			}
		}
	}
}
