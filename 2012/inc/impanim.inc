// impAnim : requires clock.inc


#switch (FrameIndex)

  // Walk 1
  #case (0)
    #declare LegRotation = 33;
    #declare JumpHeight = 0.2;
    #declare AttackFrame = 0;
  #break

  // Stand
  #case (1)
    #declare LegRotation = 0;
    #declare JumpHeight = 0;
    #declare AttackFrame = 0;
  #break

  // Walk 2
  #case (2)
    #declare LegRotation = -33;
    #declare JumpHeight = 0.2;
    #declare AttackFrame = 0;
  #break

  // Attack 1
  #case (3) 
    #declare LegRotation = 0;
    #declare JumpHeight = 0;
    #declare AttackFrame = 1;
  #break

  // Attack 2
  #case (4) 
    #declare LegRotation = 0;
    #declare JumpHeight = 0;
    #declare AttackFrame = 2;
  #break

  // Attack 3
  #case (5) 
    #declare LegRotation = 0;
    #declare JumpHeight = 0;
    #declare AttackFrame = 3;
  #break
#end  

