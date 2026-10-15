#include "inc/clock.inc"


#declare CameraY = 4;
#declare CubeSize = 2.88;

/* Cube texturé qui se déplace en 'roulant' (rotation sur X de face en face)*/


// Les 4 faces du cubes
#declare Img1 = "textures/face_t1.png";
#declare Img2 = "textures/face_t2.png";
#declare Img3 = "textures/face_t3.png";
#declare Img4 = "textures/face_t4.png";

#while (FrameIndex >= 4)
  #declare ImgRoll = Img1 
  #declare Img1 = Img2
  #declare Img2 = Img3
  #declare Img3 = Img4
  #declare Img4 = ImgRoll
  #declare FrameIndex = FrameIndex - 4;
#end

// Une face du cube
// c'est un prisme triangle tourné à 90°
#declare CubeFace = prism {
  linear_spline
  -0.5
  0.5
  4
  <0, 0>
  <-0.5, -0.5>
  <0.5, -0.5>
  <0, 0>
  rotate z * 90
}

// chaque face reçois sa texture
#declare Face1 = object {
  CubeFace
  pigment {
    image_map {
      png Img1
      map_type 0
    }
    translate <-0.5, 0.5, 0>
  }
}

#declare Face2 = object {
  CubeFace
  pigment {
    image_map {
      png Img2
      map_type 0
    }
    translate <-0.5, 0.5, 0>
  }
}

#declare Face3 = object {
  CubeFace
  pigment {
    image_map {
      png Img3
      map_type 0
    }
    translate <-0.5, 0.5, 0>
  }
}

#declare Face4 = object {
  CubeFace
  pigment {
    image_map {
      png Img4
      map_type 0
    }
    translate <-0.5, 0.5, 0>
  }
}

// le cube est assemblé avedc ses 4 faces texturées
// les autres coté des prismes constituent les face non texturées du cube
// Le cube est translaté de manière a rendre facile la rotation
#declare PreRollingCube = union {
  object {
    Face1
  }
  object {
    Face2
    rotate 90 * x
  }
  object {
    Face3
    rotate 180 * x
  }
  object {
    Face4
    rotate -90 * x
  }
  translate <0, 0.5, 0.5>
  scale CubeSize
}


#declare RollingAngle = 0;
#declare RollingOffset = 0;


#switch (FrameIndex)
  #case (1)
    #declare RollingAngle = 22.5;
    #declare RollingOffset = 0.375;
  #break

  #case (2)
    #declare RollingAngle = 45;
    #declare RollingOffset = 0.705;
  #break

  #case (3)
    #declare RollingAngle = 67.5;
    #declare RollingOffset = 0.920;
  #break
#end

#declare RollingOffset = 1.75 * RollingOffset;

#declare RollingCube = object {
  PreRollingCube
  rotate -RollingAngle * x
  translate z * RollingOffset * CubeSize
}

#declare Cube = object {
  RollingCube
  translate -(1 + RollingOffset) * 0.5 * CubeSize * z
}

camera {
  location <0, CameraY, -22>
  look_at <0, CameraY, 0>
}

light_source {
  <0, CameraY, -20>
  color <1, 1, 1>
}

object {
  Cube
  rotate CameraAngle * y
}

box {
  <-CubeSize, 0, -CubeSize>
  <CubeSize, -0.1, CubeSize>
  scale 0.5
  rotate CameraAngle * y
  pigment {
    ShadowDiscColor
  }
}

