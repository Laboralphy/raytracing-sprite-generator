#switch (AnimationFrame)
	#case (0)
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmLeft = 70;
		#declare A_ForeArmLeft = 0;
		#declare A_ArmRight = 0;
		#declare A_ForeArmRight = 0;
		#declare OffsetBody = 0;
		#declare B_Raise_Shield = 1;
		#declare B_Strike_Weapon = 0;
	#break
	
	#case (1)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmLeft = 0;
		#declare A_ForeArmLeft = 90;
		#declare A_ArmRight = 80;
		#declare A_ForeArmRight = 40;
		#declare OffsetBody = -0.2;
		#declare B_Raise_Shield = 0;
		#declare B_Strike_Weapon = 0;
	#break

	#case (2)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmLeft = 0;
		#declare A_ForeArmLeft = 90;
		#declare A_ArmRight = 25;
		#declare A_ForeArmRight = 40;
		#declare OffsetBody = -0.2;
		#declare B_Raise_Shield = 0;
		#declare B_Strike_Weapon = 1;
	#break

	#case (3)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmRight = -20;
		#declare A_ForeArmRight = 10;
		#declare A_ArmLeft = 45;
		#declare A_ForeArmLeft = 90;
		#declare OffsetBody = -0.2;
		#declare B_Raise_Shield = 1;
		#declare B_Strike_Weapon = 0;
	#break

	#case (4)
		#declare A_LegLeft = 15;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = 10;
		#declare A_KneelRight = -20;
		#declare A_ArmRight = -5;
		#declare A_ForeArmRight = 5;
		#declare A_ArmLeft = 45;
		#declare A_ForeArmLeft = 90;
		#declare OffsetBody = 0;
		#declare B_Raise_Shield = 1;
		#declare B_Strike_Weapon = 0;
	#break

	#case (5)
		#declare A_LegLeft = -15;
		#declare A_KneelLeft = -35;
		#declare A_LegRight = 30;
		#declare A_KneelRight = -30;
		#declare A_ArmRight = 20;
		#declare A_ForeArmRight = 10;
		#declare A_ArmLeft = 45;
		#declare A_ForeArmLeft = 90;
		#declare OffsetBody = -0.2;
		#declare B_Raise_Shield = 1;
		#declare B_Strike_Weapon = 0;
	#break
#end
