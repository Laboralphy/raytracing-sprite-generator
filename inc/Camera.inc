#declare CameraHeight = 2;


camera {
	location <0, CameraHeight, -20>
	look_at  <0, CameraHeight,  0>
    right x * 1.3333
}

light_source { 
	<2, 4, -20> color White
}
