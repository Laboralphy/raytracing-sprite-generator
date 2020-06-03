// shield arm by default

#local A_Attack_Wrist_Angle = 60;

#switch (N_Animation_Frame)
	#case (0)
		// STAND
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmRight = 0;
		#declare A_WristRight = 0;
		#declare A_ArmLeft = 0;
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.1;
	#break
	
	#case (1)
		// ATTACK 1
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		
		#declare A_ArmRight = 0;
		#declare A_WristRight = 90;
		
		#declare A_ArmLeft = 20;
		#declare A_WristLeft = 10;
		#declare N_OffsetBody = -0.2;
		#declare B_Strike_Weapon = 0;
	#break

	#case (2)
		// ATTACK 2
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -05;
		#declare A_KneelRight = -45;
		
		#declare A_ArmRight = 90;
		#declare A_WristRight = 0;
    #local A_Attack_Wrist_Angle = 0;

		#declare A_ArmLeft = 0;
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.2;

    #declare N_OffsetBody = -0.2;
		#declare B_Strike_Weapon = 1;

	#break

	#case (3)
		// WALK 1
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
    
		#declare A_ArmRight = 20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = -20;
		#declare A_WristLeft = 10;
		#declare N_OffsetBody = -0.2;

	#break

	#case (4)
		// WALK 2
		#declare A_LegLeft = 15;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = 10;
		#declare A_KneelRight = -20;
    
		#declare A_ArmRight = 5;
		#declare A_WristRight = 5;
		#declare A_ArmLeft = -5;
		#declare A_WristLeft = 5;
		#declare N_OffsetBody = -0.1;
	#break

	#case (5)
		// WALK 3
		#declare A_LegLeft = -15;
		#declare A_KneelLeft = -35;
		#declare A_LegRight = 30;
		#declare A_KneelRight = -30;
    
		#declare A_ArmRight = -20;
		#declare A_WristRight = 10;
		#declare A_ArmLeft = 15;
		#declare A_WristLeft = 0;
		#declare N_OffsetBody = -0.2;
	#break
#end


#declare AV_Thigh_Left = <A_LegLeft, -10, 30>;
#declare AV_Shin_Left = <A_KneelLeft, 0, -45>;

#declare AV_Thigh_Right = <A_LegRight,  -10, -30>;
#declare AV_Shin_Right = <A_KneelRight, 0, 45>;

#declare AV_Arm_Right = <A_ArmRight, 0, -50>;
#declare AV_Wrist_Right = <A_WristRight, 0, A_Attack_Wrist_Angle>;

#declare AV_Arm_Left = <A_ArmLeft, 0, 50>;
#declare AV_Wrist_Left = <A_WristLeft, 0, -60>;
