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
		#declare OffsetBody = 0;
	#break
	
	#case (1)
		#declare A_LegLeft = 30;
		#declare A_KneelLeft = -30;
		#declare A_LegRight = -15;
		#declare A_KneelRight = -35;
		#declare A_ArmLeft = -20;
		#declare A_ForeArmLeft = 0;
		#declare A_ArmRight = 50;
		#declare A_ForeArmRight = 40;
		#declare OffsetBody = -0.2;
	#break

#end
