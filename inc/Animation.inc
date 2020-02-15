/* clock = dff */

#declare MODE_DEV = int(clock / 1000);
#declare N_Animation_Direction = mod(int(clock / 100), 10);
#declare N_Animation_Frame = mod(clock, 100);
#declare N_Animation_Angle = N_Animation_Direction * 45;
