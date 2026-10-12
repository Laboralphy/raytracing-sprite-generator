/*
  ____        _     _
 / ___| _ __ (_) __| | ___ _ __
 \___ \| '_ \| |/ _` |/ _ \ '__|
  ___) | |_) | | (_| |  __/ |
 |____/| .__/|_|\__,_|\___|_|
       |_|

	Giant spider, about the mass of a goblin: hairy dark brown body, a big
	abdomen with pale chevrons, eight banded legs (knees above the body),
	eight eyes (the two big front ones glowing red), chelicerae with curved
	fangs, two pedipalps. Head towards -z, standing on the floor (y = 0).

	Posed by inc/frames/spider.inc:
		V_Pose_Extra.x    walking phase, degrees (0 to 360): the legs move in
		                  two alternating groups of four (L1 R2 L3 R4 / R1 L2
		                  R3 L4), each lifted while it swings forward
		V_Pose_Extra.y    attack (0 to 1): front legs raised, fangs open
		V_Pose_Extra.z    legs curled (0: standing, 1: curled up, dead)
		AV_Body           whole spider, around the centre of the
		                  cephalothorax (x > 0: rearing up, z = 180: on its back)
		V_Body_Offset     moves the whole spider

	Colours (declare them before the include to make a variant):
		C_Spider_Body     body and legs (dark brown)
		C_Spider_Band     light bands of the legs
		C_Spider_Mark     chevrons on the abdomen
		C_Spider_Eye      the glowing eyes
		C_Spider_Fang     fangs
	N_Spider_Hue_Shift (degrees, default 0) turns the hue of all of them.
	N_Spider_Scale scales the whole spider (1 by default).
*/

#ifndef (N_Spider_Scale)
	#declare N_Spider_Scale = 1;
#end

#ifndef (C_Spider_Body)
	#declare C_Spider_Body = color rgb <0.055, 0.032, 0.02>;
#end
#ifndef (C_Spider_Band)
	#declare C_Spider_Band = color rgb <0.5, 0.33, 0.16>;
#end
#ifndef (C_Spider_Mark)
	#declare C_Spider_Mark = color rgb <0.62, 0.48, 0.3>;
#end
#ifndef (C_Spider_Eye)
	#declare C_Spider_Eye = color rgb <0.9, 0.05, 0.02>;
#end
#ifndef (C_Spider_Fang)
	#declare C_Spider_Fang = color rgb <0.05, 0.03, 0.02>;
#end

#ifndef (N_Spider_Hue_Shift)
	#declare N_Spider_Hue_Shift = 0;
#end
// a colour with its hue turned by N_Spider_Hue_Shift (colors.inc, via inc/Camera.inc)
#macro Spider_Hue(C)
	#local C_Out = C;
	#if (N_Spider_Hue_Shift != 0)
		#local V_HSV = CRGB2HSV(C);
		#local C_Out = CHSV2RGB(<mod(V_HSV.x + N_Spider_Hue_Shift + 360, 360), V_HSV.y, V_HSV.z>);
	#end
	C_Out
#end
#local C_Body = Spider_Hue(C_Spider_Body);
#local C_Band = Spider_Hue(C_Spider_Band);
#local C_Mark = Spider_Hue(C_Spider_Mark);
#local C_Eye = Spider_Hue(C_Spider_Eye);
#local C_Fang = Spider_Hue(C_Spider_Fang);

// hairy body: mottled, with a fine bumpy normal
#declare T_Spider_Body = texture {
	pigment {
		granite
		color_map {
			[0 C_Body]
			[0.7 C_Body * 1.25]
			[1 C_Body * 0.6]
		}
		scale 0.4
	}
	normal {
		bumps 0.4
		scale 0.015
	}
	finish {
		ambient 0.08
		diffuse 0.6
		specular 0.25
		roughness 0.05
	}
}

#declare T_Spider_Eye = texture {
	pigment {
		color C_Eye
	}
	finish {
		ambient 0.7
		diffuse 0.3
		specular 1
		roughness 0.003
	}
}

#declare T_Spider_Small_Eye = texture {
	pigment {
		color rgb 0.01
	}
	finish {
		ambient 0.1
		specular 1
		roughness 0.003
	}
}

#local N_Walk = V_Pose_Extra.x;
#local N_Attack = V_Pose_Extra.y;
#local N_Curl = V_Pose_Extra.z;

// height of the centre of the cephalothorax
#local N_H = 0.85;



//   _
//  | |    ___  __ _ ___
//  | |   / _ \/ _` / __|
//  | |__|  __/ (_| \__ \
//  |_____\___|\__, |___/
//             |___/

/*
	One leg, left side (+x), from its hip (origin), in the vertical plane
	x-y: up to the knee, down to the ankle, the foot on the floor (the hip
	is N_H above it); curled (N_Curl), it folds under the belly, so that the
	legs point up once the spider lies on its back. N_Len: length factor; N_Lift: raised while walking;
	N_Raise: raised for the attack (front legs).
	Light bands at the joints.
*/
#macro Spider_Leg(N_Len, N_Lift, N_Raise)
	#local N_Stand = 1 - N_Curl;
	#local V_Knee = (<0.72, 0.62 + 0.2 * N_Lift, 0> * N_Len * (1 - N_Raise) + <0.55, 0.95, 0> * N_Raise) * N_Stand + <0.42, -0.3, 0> * N_Curl;
	#local V_Ankle = (<1.38, -0.3 + 0.35 * N_Lift, 0> * N_Len * (1 - N_Raise) + <1.05, 1.35, 0> * N_Raise) * N_Stand + <0.3, -0.62, 0> * N_Curl;
	#local V_Foot = (<1.62, -N_H + 0.3 * N_Lift, 0> * (1 - N_Raise) + <1.3, 1.15, 0> * N_Raise) * N_Stand + <0.08, -0.55, 0> * N_Curl;
	#local V_Foot = <V_Foot.x * (N_Stand * N_Len + N_Curl), V_Foot.y, 0>;
	union {
		sphere_sweep {
			linear_spline
			4,
			<0, 0, 0>, 0.085
			V_Knee, 0.075
			V_Ankle, 0.055
			V_Foot, 0.025
			texture {
				T_Spider_Body
			}
		}
		// light bands at the knee and the ankle
		sphere {
			V_Knee, 0.085
			texture {
				pigment {
					color C_Band
				}
				normal {
					bumps 0.5
					scale 0.015
				}
			}
		}
		sphere {
			V_Ankle, 0.065
			texture {
				pigment {
					color C_Band
				}
				normal {
					bumps 0.5
					scale 0.015
				}
			}
		}
	}
#end

// angles of the legs from the side (+x), towards the front (> 0)
#local A_Leg_Angle = array[4] { 52, 18, -16, -48 }
#local A_Leg_Len = array[4] { 1.12, 1, 0.95, 1.08 }
// how much each leg rises for the attack
#local A_Leg_Raise = array[4] { 1, 0.35, 0, 0 }

/*
	The four legs of one side. N_Group: 0 for the left side, 1 for the right
	one (legs 0 and 2 of the left side walk with legs 1 and 3 of the right).
*/
#macro Spider_Legs(N_Group)
	union {
		#local I = 0;
		#while (I < 4)
			#local N_Sign = (mod(I + N_Group, 2) = 0 ? 1 : -1);
			#local N_Swing = 14 * sin(radians(N_Walk)) * N_Sign;
			#local N_Lift = max(0, cos(radians(N_Walk)) * N_Sign);
			#if (N_Walk = 0)
				#local N_Swing = 0;
				#local N_Lift = 0;
			#end
			object {
				Spider_Leg(A_Leg_Len[I], N_Lift, N_Attack * A_Leg_Raise[I])
				rotate y * (A_Leg_Angle[I] + N_Swing)
				translate <0.3 * cos(radians(A_Leg_Angle[I])), 0, -0.36 * sin(radians(A_Leg_Angle[I]))>
			}
			#local I = I + 1;
		#end
	}
#end



//   _   _                    _
//  | | | | ___  __ _  __| |
//  | |_| |/ _ \/ _` |/ _` |
//  |  _  |  __/ (_| | (_| |
//  |_| |_|\___|\__,_|\__,_|

// one chelicera with its fang, left side, from the front of the head
#local O_Spider_Chelicera = union {
	sphere {
		0, 1
		scale <0.1, 0.14, 0.1>
		texture {
			T_Spider_Body
		}
	}
	// fang: curved down and in, opening outward with the attack
	sphere_sweep {
		linear_spline
		3,
		<0.02, -0.1, -0.03>, 0.035
		<0.05, -0.22, -0.08>, 0.022
		<-0.02, -0.3, -0.06>, 0.006
		rotate z * 25 * N_Attack
		texture {
			pigment {
				color C_Fang
			}
			finish {
				specular 1
				roughness 0.005
			}
		}
	}
}

// one pedipalp, left side: a short leg reaching forward
#local O_Spider_Palp = sphere_sweep {
	linear_spline
	3,
	<0, 0, 0>, 0.05
	<0.12, 0.12, -0.2>, 0.045
	<0.1, -0.15, -0.35>, 0.04
	rotate x * -20 * N_Attack
	texture {
		T_Spider_Body
	}
}



//      _                           _     _
//     / \   ___ ___  ___ _ __ ___ | |__ | |_   _
//    / _ \ / __/ __|/ _ \ '_ ` _ \| '_ \| | | | |
//   / ___ \\__ \__ \  __/ | | | | | |_) | | |_| |
//  /_/   \_\___/___/\___|_| |_| |_|_.__/|_|\__, |
//                                          |___/

#declare O_Spider_Posed = object {
	union {
		// cephalothorax
		sphere {
			0, 1
			scale <0.42, 0.28, 0.5>
			texture {
				T_Spider_Body
			}
		}
		// eyes: two big glowing ones in front, two medium above, four small on the sides
		#local I = -1;
		#while (I <= 1)
			sphere {
				<0.08 * I, 0.17, -0.44>, 0.065
				texture {
					T_Spider_Eye
				}
			}
			sphere {
				<0.16 * I, 0.2, -0.36>, 0.045
				texture {
					T_Spider_Eye
				}
			}
			sphere {
				<0.22 * I, 0.14, -0.38>, 0.03
				texture {
					T_Spider_Small_Eye
				}
			}
			sphere {
				<0.26 * I, 0.16, -0.28>, 0.028
				texture {
					T_Spider_Small_Eye
				}
			}
			#local I = I + 2;
		#end
		object {
			O_Spider_Chelicera
			translate <0.1, -0.06, -0.48>
		}
		object {
			O_Spider_Chelicera
			scale <-1, 1, 1>
			translate <-0.1, -0.06, -0.48>
		}
		object {
			O_Spider_Palp
			translate <0.16, -0.08, -0.4>
		}
		object {
			O_Spider_Palp
			scale <-1, 1, 1>
			translate <-0.16, -0.08, -0.4>
		}
		// waist (pedicel)
		cylinder {
			<0, 0.02, 0.4>, <0, 0.12, 0.62>, 0.1
			texture {
				T_Spider_Body
			}
		}
		// abdomen, with pale chevrons along the top and spinnerets at the back
		union {
			sphere {
				0, 1
				scale <0.68, 0.56, 0.82>
				texture {
					T_Spider_Body
				}
			}
			#local I = 0;
			#while (I < 4)
				#local N_Z = -0.45 + I * 0.3;
				#local N_Y = sqrt(max(0, 1 - pow(N_Z / 0.82, 2))) * 0.56;
				#local N_W = 0.42 - I * 0.07;
				#local J = -1;
				#while (J <= 1)
					sphere {
						0, 1
						scale <N_W / 2, 0.035, 0.075>
						rotate y * 35 * J
						translate <N_W / 2.2 * J, N_Y - 0.01, N_Z>
						texture {
							pigment {
								color C_Mark
							}
							normal {
								bumps 0.5
								scale 0.015
							}
						}
					}
					#local J = J + 2;
				#end
				#local I = I + 1;
			#end
			cone {
				<0, -0.05, 0.75>, 0.08, <0, -0.1, 0.92>, 0.03
				texture {
					T_Spider_Body
				}
			}
			rotate x * -12
			translate <0, 0.28, 1.25>
		}
		object {
			Spider_Legs(0)
		}
		object {
			Spider_Legs(1)
			scale <-1, 1, 1>
		}
		rotate AV_Body
		translate y * N_H
	}
	translate V_Body_Offset
	scale N_Spider_Scale
}
