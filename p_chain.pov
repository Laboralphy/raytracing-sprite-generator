/*
      _           _       
  ___| |__   __ _(_)_ __  
 / __| '_ \ / _` | | '_ \ 
| (__| | | | (_| | | | | |
 \___|_| |_|\__,_|_|_| |_|

	Iron chain hanging from the ceiling, with a hook.
*/

#include "colors.inc"
#include "inc/Camera.inc"
#include "inc/props/Props.inc"
#include "inc/props/Chain.inc"

#local N_Links = 10;
#local N_Link_Scale = 0.1;
#local N_Length = Chain_Length(N_Links, N_Link_Scale);

#declare O_Hanging_Chain = union {
	object {
		Chain(N_Links, N_Link_Scale)
	}
	// hook, hanging from the last link
	union {
		cylinder { 0, -0.3 * y, N_Chain_Wire * N_Link_Scale }
		intersection {
			torus { 0.15, N_Chain_Wire * N_Link_Scale rotate x * 90 }
			plane { y, 0 }
			translate <0.15, -0.3, 0>
		}
		sphere { <0.3, -0.3, 0>, N_Chain_Wire * N_Link_Scale }
		texture { T_Chain_Iron }
		translate -y * (N_Length - 0.05)
	}
	translate y * N_Prop_Ceiling
}

object {
	O_Hanging_Chain
	rotate y * N_Animation_Angle
}
