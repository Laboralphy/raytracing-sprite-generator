/****** ANIMATION VARIABLES ******/

/* 

clock format : DAF
D = Direction (0 - 7)
A = Animation type (0, 1)
F = Animation frame number (0 - 9)
*/

#declare ANIM_TYPE_WALK = 0; 
#declare ANIM_TYPE_ATTACK = 1; 

#declare ANIM_DIRECTION = div(clock, 1000);
#declare ANIM_TYPE = mod(div(clock, 100), 10);
#declare ANIM_FRAME = mod(clock, 10);



