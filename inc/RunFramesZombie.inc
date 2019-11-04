#switch (AnimationFrame)
	#case (0)
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmLeft = 0;
		#declare A_ForeArmLeft = 0;
		#declare A_ArmRight = 0;
		#declare A_ForeArmRight = 0;
		#declare A_Hand = <0, 0, 0>;
		#declare OffsetBody = 0;
	#break
	
	#case (1)
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmLeft = 100;
		#declare A_ForeArmLeft = 0;
		#declare A_ArmRight = 70;
		#declare A_ForeArmRight = 0;
		#declare OffsetBody = 0;
		#declare A_Hand = <70, 30, 90>;
	#break

	#case (2)
		#declare A_LegLeft = 0;
		#declare A_KneelLeft = 0;
		#declare A_LegRight = 0;
		#declare A_KneelRight = 0;
		#declare A_ArmLeft = 70;
		#declare A_ForeArmLeft = 0;
		#declare A_ArmRight = 100;
		#declare A_ForeArmRight = 0;
		#declare OffsetBody = 0;
		#declare A_Hand = <70, 30, 90>;
	#break

	#case (3)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmRight = 90;
		#declare A_ForeArmRight = 0;
		#declare A_ArmLeft = 95;
		#declare A_ForeArmLeft = 0;
		#declare OffsetBody = -0.2;
		#declare A_Hand = <70, 0, 90>;
	#break

	#case (4)
		#declare A_LegLeft = 15;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = 10;
		#declare A_KneelRight = -20;
		#declare A_ArmRight = 87;
		#declare A_ForeArmRight = 0;
		#declare A_ArmLeft = 86;
		#declare A_ForeArmLeft = 0;
		#declare OffsetBody = 0;
		#declare A_Hand = <70, 0, 90>;
	#break

	#case (5)
		#declare A_LegLeft = -15;
		#declare A_KneelLeft = -35;
		#declare A_LegRight = 30;
		#declare A_KneelRight = -30;
		#declare A_ArmRight = 85;
		#declare A_ForeArmRight = 0;
		#declare A_ArmLeft = 90;
		#declare A_ForeArmLeft = 0;
		#declare OffsetBody = -0.2;
		#declare A_Hand = <70, 0, 90>;
	#break
#end
