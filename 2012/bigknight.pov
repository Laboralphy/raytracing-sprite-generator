/****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ******/
/****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ******/
/****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ****** BIG KNIGHT ******/

// anim_walk 3
// anim_attack 2
// anim_explosion 3

#include "inc/anim.inc"


/******	TEXTURES ******	TEXTURES ******	TEXTURES ******	TEXTURES ******/
/******	TEXTURES ******	TEXTURES ******	TEXTURES ******	TEXTURES ******/
/******	TEXTURES ******	TEXTURES ******	TEXTURES ******	TEXTURES ******/


#include "metals.inc"
#include "colors.inc"
#include "woods.inc"


#declare HeadTexture = T_Chrome_1A

#declare ArmTexture = T_Chrome_2A;

#declare ShirtTexture = T_Chrome_2D;

#declare ShortTexture = T_Chrome_2A;

#declare FootTexture = T_Chrome_2D;

#declare HornTexture = T_Chrome_1A;
#declare HelmTexture = T_Chrome_2D;

#declare PaldronTexture = T_Chrome_3C;

#declare ShieldTexture = T_Wood25;

#declare KnifeBladeTexture = T_Chrome_5D;

#declare KnifeGuardTexture = T_Brass_1A;

#declare KnifeHandleTexture = texture {
	pigment {
		color rgb <0.2, 0.2, 0.2>
	}
}




#include "inc/knife_sword.inc"
#declare Weapon = Knife;
#include "inc/bigarmor.inc"
#include "inc/bigface.inc"

#declare Mob = union {
	object {
		Mob
	}
	object {
		Helm
		translate (3 + StepHeight) * y
	}
	object {
		Paldrons
		translate (1.75 + StepHeight) * y
	}
	object {
		Shield
		translate StepHeight * y
	}
	scale 0.8
}

#include "inc/camera.inc"
