/*
 _             _                  
| | __ _ _ __ | |_ ___ _ __ _ __  
| |/ _` | '_ \| __/ _ \ '__| '_ \ 
| | (_| | | | | ||  __/ |  | | | |
|_|\__,_|_| |_|\__\___|_|  |_| |_|

	Lit brass lantern, hanging from the ceiling on a short chain.
	In the game, give it FX_LIGHT_SOURCE so that it is not darkened.
*/

#include "inc/Camera.inc"
#include "inc/props/Props.inc"
#include "inc/props/Chain.inc"
#include "inc/props/Lantern.inc"

#local N_Links = 4;
#local N_Link_Scale = 0.1;
#local N_Lantern_Scale = 0.22;
#local N_Length = Chain_Length(N_Links, N_Link_Scale);

#declare O_Hanging_Lantern = union {
	object {
		Chain(N_Links, N_Link_Scale)
	}
	object {
		O_Lantern
		scale N_Lantern_Scale
		// the ring hooks into the last link
		translate -y * (N_Length - N_Chain_Wire * N_Link_Scale + N_Lantern_Hook * N_Lantern_Scale)
	}
	translate y * N_Prop_Ceiling
}

object {
	O_Hanging_Lantern
	rotate y * N_Animation_Angle
}
