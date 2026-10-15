#if (FrameIndex = 0)
  #declare JumpHeight = 0;
#else
  #declare JumpHeight = 0.333 * sin((FrameIndex - 1) * 30) + 2;
#end
