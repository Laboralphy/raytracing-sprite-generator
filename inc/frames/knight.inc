// shield arm by default
#declare AV_Arm_Left = <80, 0, 10>;
#declare AV_Wrist_Left = <0, 0, -80>;

#switch (N_Animation_Frame)
	#case (0)
		// STAND
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmRight = -20;
		#declare A_WristRight = 45;
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = 0;
		#declare B_Strike_Weapon = 0;

		#declare AV_Arm_Right = <A_ArmRight, 0, -10>;
	#break
	
	#case (1)
		// ATTACK 1
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		
		#declare A_ArmRight = 130;
		#declare A_WristRight = 40;
		
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.1;
		#declare B_Strike_Weapon = 0;

		#declare AV_Arm_Left = <80, -40, 10>;
		#declare AV_Wrist_Left = <0, 0, -80>;

		#declare AV_Arm_Right = <A_ArmRight, 20, 20>;
	#break

	#case (2)
		// ATTACK 2
		#declare A_LegLeft = 40;
		#declare A_KneelLeft = -40;
		#declare A_LegRight = -30;
		#declare A_KneelRight = -30;
		#declare A_ArmRight = 15;
		#declare A_WristRight = 45;
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.2;
		#declare B_Strike_Weapon = 1;

		#declare AV_Arm_Left = <80, -45, 10>;
		#declare AV_Wrist_Left = <0, 0, -80>;

		#declare AV_Arm_Right = <A_ArmRight, 0, 0>;
	#break

	#case (3)
		// WALK 1
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmRight = -20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.1;
		#declare B_Strike_Weapon = 0;

		#declare AV_Arm_Right = <A_ArmRight, 0, -10>;
	#break

	#case (4)
		// WALK 2
		#declare A_LegLeft = 15;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = 10;
		#declare A_KneelRight = -20;
		#declare A_ArmRight = -5;
		#declare A_WristRight = 5;
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = 0;
		#declare B_Strike_Weapon = 0;

		#declare AV_Arm_Right = <A_ArmRight, 0, -10>;
	#break

	#case (5)
		// WALK 3
		#declare A_LegLeft = -15;
		#declare A_KneelLeft = -35;
		#declare A_LegRight = 30;
		#declare A_KneelRight = -30;
		#declare A_ArmRight = 20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = 0; // arm with shield
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.1;
		#declare B_Strike_Weapon = 0;

		#declare AV_Arm_Right = <A_ArmRight, 0, -10>;
	#break
#end

#declare AV_Thigh_Left = <A_LegLeft, 0, 0>;
#declare AV_Shin_Left = <A_KneelLeft, 0, 0>;

#declare AV_Thigh_Right = <A_LegRight, 0, 0>;
#declare AV_Shin_Right = <A_KneelRight, 0, 0>;

#declare AV_Wrist_Right = <A_WristRight, 0, 0>;


