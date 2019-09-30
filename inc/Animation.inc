/* clock = dff */

#declare AnimationDirection = int(clock / 100);
#declare AnimationFrame = mod(clock, 100);
#declare AnimationAngle = AnimationDirection * 45;

