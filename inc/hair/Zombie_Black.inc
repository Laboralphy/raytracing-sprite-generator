#include "inc/hair/Cutter_Normal"

#declare O_Hair_Zombie_Black_Cutter_0 = box {
	<-10, 0, 0>
	<10, -20, 20>
	rotate x * 45
	scale <1, 1, 0.1>
}

#declare O_Hair_Zombie_Black_Cutter_1 = union {
	object {
		O_Hair_Zombie_Black_Cutter_0
		translate <0, 0, 0>
	}
	object {
		O_Hair_Zombie_Black_Cutter_0
		rotate y * 30
		translate <0, 0, 0>
	}
	object {
		O_Hair_Zombie_Black_Cutter_0
		rotate y * 75
		translate <0, 0, 0>
	}
	object {
		O_Hair_Zombie_Black_Cutter_0
		rotate y * 100
		translate <0, 0, 0>
	}
	object {
		O_Hair_Zombie_Black_Cutter_0
		rotate y * 133
		translate <0, 0, 0>
	}
}


#declare P_Hair_Zombie_Black = difference {
	sor {
		7
		<0.85, -1>
		<0.95, -0.2>
		<cos(radians(0)), 1 + sin(radians(0))>
		<cos(radians(30)), 1 + sin(radians(30))>
		<cos(radians(60)), 1 + sin(radians(60))>
		<cos(radians(90)), 1 + sin(radians(90))>
		<0, 2>
		sturm
		scale <0.575, 0.5, 0.575>
		translate <0, 0.1, 0>
	}
	union {
		object {
			P_Hair_Cutter_Normal
		}
		object {
			O_Hair_Zombie_Black_Cutter_1
			translate y * 1
		}
	}
}
