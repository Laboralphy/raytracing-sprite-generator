/* clock = dff */

#declare MODE_DEV = int(clock / 1000);
#declare AnimationDirection = mod(int(clock / 100), 10);
#declare AnimationFrame = mod(clock, 100);
#declare AnimationAngle = AnimationDirection * 45;
