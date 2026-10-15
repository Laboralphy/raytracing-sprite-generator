/****** CAMERA ******/
#ifndef (CAMERA_DISTANCE)
	#declare CAMERA_DISTANCE = 12;
#end
#ifndef (CAMERA_HEIGHT)
	#declare CAMERA_HEIGHT = 2.1;
#end
#ifndef (SHADOW_SIZE)
	#declare SHADOW_SIZE = 1;
#end
#ifndef (SHADOW_Y)
	#declare SHADOW_Y = 0;
#end

light_source {
	<0, CAMERA_HEIGHT, -CAMERA_DISTANCE>
	rgb <1, 1, 1>
}

background {
	<0.5, 0.5, 0.5>
}

camera {
	location <0, CAMERA_HEIGHT, -CAMERA_DISTANCE>
	sky y
	look_at <0, CAMERA_HEIGHT, 0>
}

#ifdef (Shadow)
	object {
		Shadow
	}
#else
	disc {
		<0, SHADOW_Y, 0>
		y
		SHADOW_SIZE
		pigment {
			color rgbt <0, 0, 0, 0.5>
		}
	}
#end

#ifdef (Mob) 
	object {
		Mob
		rotate y * ANIM_DIRECTION * 45
	}
#end
