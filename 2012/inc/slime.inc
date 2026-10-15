#switch (FrameIndex)
  #case (8)
    #declare SlimeColor = color rgb <1, 1, 1>;
    #declare FrameIndex = 0;
  #break
  #case (9)
    #declare FrameIndex = 0;
  #break
#end

#declare Slime = blob {
  threshold 0.111 * sin(FrameIndex * pi / 8) + 0.222

  sphere { 
    <0, 0, 0>
    1.666
    1
  }

  sphere { 
    <cos(0), sin(0), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(2 * pi / 6), sin(2 * pi / 6), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(4 * pi / 6), sin(4 * pi / 6), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(6 * pi / 6), sin(6 * pi / 6), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(8 * pi / 6), sin(8 * pi / 6), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(10 * pi / 6), sin(10 * pi / 6), 0>
    0.66
    0.5
  }

  sphere { 
    <cos(0) * cos(- 2 * pi / 6) , sin(0), sin(-2 * pi / 6)>
    0.66
    0.5
  }

  sphere { 
    <cos(0) * cos(- 4 * pi / 6) , sin(0), sin(- 4 * pi / 6)>
    0.66
    0.5
  }

  sphere { 
    <cos(0) * cos(2 * pi / 6) , sin(0), sin(2 * pi / 6)>
    0.66
    0.5
  }

  sphere { 
    <cos(0) * cos(4 * pi / 6) , sin(0), sin(4 * pi / 6)>
    0.66
    0.5
  }

  pigment {
    SlimeColor
  }
  finish { 
    Phong_Glossy 
  }
}
