// shield arm by default

#switch (N_Animation_Frame)
	#case (0)
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmLeft = 0;
		#declare A_WristLeft = 0;
		#declare A_ArmRight = 0;
		#declare A_WristRight = 0;
		#declare N_OffsetBody = 0;
	#break
	
	#case (1)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmLeft = -20;
		#declare A_WristLeft = 0;
		#declare A_ArmRight = 50;
		#declare A_WristRight = 40;
		#declare N_OffsetBody = -0.1;
	#break

	#case (2)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmRight = -20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = 20;
		#declare A_WristLeft = 10;
		#declare N_OffsetBody = -0.1;
	#break

	#case (3)
		#declare A_LegLeft = 15;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = 10;
		#declare A_KneelRight = -20;
		#declare A_ArmRight = -5;
		#declare A_WristRight = 5;
		#declare A_ArmLeft = 5;
		#declare A_WristLeft = 5;
		#declare N_OffsetBody = 0;
	#break

	#case (4)
		#declare A_LegLeft = -15;
		#declare A_KneelLeft = -35;
		#declare A_LegRight = 30;
		#declare A_KneelRight = -30;
		#declare A_ArmRight = 20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = -20;
		#declare A_WristLeft = 10;
		#declare N_OffsetBody = -0.1;
	#break
#end

#declare AV_Thigh_Left = <A_LegLeft, 0, 0>;
#declare AV_Shin_Left = <A_KneelLeft, 0, 0>;

#declare AV_Thigh_Right = <A_LegRight, 0, 0>;
#declare AV_Shin_Right = <A_KneelRight, 0, 0>;

#declare AV_Arm_Right = <A_ArmRight, 0, -10>;
#declare AV_Wrist_Right = <A_WristRight, 0, 0>;

#declare AV_Arm_Left = <A_ArmLeft, 0, 10>;
#declare AV_Wrist_Left = <A_WristLeft, 0, 0>;
