#include "colors.inc"
#include "inc/Camera.inc"



#declare ShinLen = 3;
#declare ThighLen = 3;
#declare LegThickness = 1;
#declare LegShift = 0.1;

#declare AngleKneelLeft = 0;
#declare AngleLegLeft = <0, 0, 0>;

#declare AngleKneelRight = 0;
#declare AngleLegRight = <0, 0, 0>;


#declare LegLeft = blob {
	threshold 0.158
	sphere {
		0
		1.4
		1
	}
	cylinder { 
		0
		(-ThighLen) * y
		LegThickness
		1.2 
		translate -LegShift * x
	}
	cylinder { 
		0
		(-ShinLen) * y
		LegThickness * 0.95
		1.2
		rotate AngleKneelLeft * x
		translate <-LegShift, -ThighLen, 0>
	}
	rotate AngleLegLeft
	pigment { 
		Green 
	}
}

#declare LegRight = blob {
	threshold 0.158
	sphere {
		0
		1.4
		1
	}
	cylinder { 
		0
		(-ThighLen) * y
		LegThickness
		1.2 
		translate LegShift * x
	}
	cylinder { 
		0
		(-ShinLen) * y
		LegThickness * 0.95
		1.2
		rotate AngleKneelRight * x
		translate <LegShift, -ThighLen, 0>
	}
	rotate AngleLegRight
	pigment { 
		Green 
	}
}

#declare Legs = union {
	object {
		LegLeft
		translate <-1.1, 0, 0>
	}
	object {
		LegRight
		translate <1.1, 0, 0>
	}
}

#declare Torso = blob {
	threshold 0.5
	sphere {
		0
		3 
		2
		scale <1, 0.5, 0.5>
	}
	sphere {
		1.5 * y
		2.5
		2
		scale <1, 0.5, 0.5>
	}
	sphere {
		3 * y
		2.5
		2
		scale <1, 0.5, 0.5>
	}
	sphere {
		4.5 * y
		2
		2
		scale <1, 0.5, 0.5>
	}
	pigment {
		Blue
	}
}

union {
	object {
		Legs
	}
	object {
		Torso
	}
	scale 0.5
	rotate AnimationAngle * y
}
