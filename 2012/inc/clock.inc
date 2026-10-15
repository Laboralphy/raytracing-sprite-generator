// clock parameters

#declare AngleIndex = floor(clock / 100);
#declare FrameIndex = mod(clock, 100);
#declare CameraAngle = 45 * AngleIndex;
#declare BGColor = color rgb <0.5, 0.5, 0.5>;
#declare ShadowDiscColor = color rgb <0.666, 0.666, 0.666>;


background {
  BGColor 
}


