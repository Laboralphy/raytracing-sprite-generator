/*
	Poses of an archer (the dummy, or any body based creature carrying
	inc/weapons/Weapon_Bow.inc in the left hand).
	See inc/Pose.inc, and inc/frames/zombie.inc for the angle conventions.
	V_Pose_Extra drives the bow: x = draw (0 to 1), y = arrow nocked (> 0.5),
	z = bow turned in the fist (0 to shoot, 90 to carry it).

	Shooting stance: the whole body turns sideways (AV_Body.y = 90), its left
	side towards the target (-z); the head turns back to the target, the left
	arm points at it, the right hand draws the string to the cheek.

	Numbering: 0 STAND, 1-4 ATTACK (1 aim, bow relaxed; 2 half draw; 3 full
	draw; 4 release), 5-7 WALK, 8 IDLE, 9 PAIN, 10-14 DEATH.
*/

// shooting stance, shared by the attack poses
#macro Archer_Stance()
	#declare AV_Body = <0, 90, 0>;
	#declare AV_Head = <0, -85, 0>;
	#declare AV_Thigh_Left = <0, 0, 12>;
	#declare AV_Shin_Left = <0, 0, -6>;
	#declare AV_Thigh_Right = <0, 0, -12>;
	#declare AV_Shin_Right = <0, 0, 6>;
	// bow arm: straight, pointing at the target
	#declare AV_Arm_Left = <18, 0, 94>;
	#declare AV_Wrist_Left = <0, 0, 0>;
	// back from the target: the stance, from the bow hand to the drawing
	// elbow, is then centred on the ground point (frame width)
	#declare V_Body_Offset = z * 0.45;
#end

#macro Pose_Define(N_Pose)
	// bow carried, limbs along the forearm, no arrow
	#declare V_Pose_Extra = <0, 0, 90>;

	#switch (N_Pose)
		#case (0)
			// STAND
			#declare AV_Arm_Left = <10, 0, 10>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -10>;
			#declare AV_Wrist_Right = <15, 0, 0>;
		#break

		#case (1)
			// ATTACK 1: aim, bow raised, arrow nocked, string at rest
			Archer_Stance()
			#declare AV_Arm_Right = <90, -40, 0>;
			#declare AV_Wrist_Right = <0, 0, 20>;
			#declare V_Pose_Extra = <0, 1, 0>;
		#break

		#case (2)
			// ATTACK 2: half draw
			Archer_Stance()
			#declare AV_Arm_Right = <90, -50, 0>;
			#declare AV_Wrist_Right = <0, 0, 45>;
			#declare V_Pose_Extra = <0.5, 1, 0>;
		#break

		#case (3)
			// ATTACK 3: full draw, string at the cheek
			Archer_Stance()
			#declare AV_Arm_Right = <80, 40, -10>;
			#declare AV_Wrist_Right = <0, 0, 145>;
			#declare V_Pose_Extra = <1, 1, 0>;
		#break

		#case (4)
			// ATTACK 4: release, the arrow is gone, the hand flies back
			Archer_Stance()
			#declare AV_Arm_Right = <0, 30, -110>;
			#declare AV_Wrist_Right = <20, 0, 150>;
			#declare V_Pose_Extra = <0, 0, 0>;
		#break

		#case (5)
			// WALK 1: left leg forward, right arm forward
			#declare AV_Thigh_Left = <30, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <-15, 0, 0>;
			#declare AV_Shin_Right = <-35, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 10>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <20, 0, -10>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (6)
			// WALK 2: passing
			#declare AV_Thigh_Left = <15, 0, 0>;
			#declare AV_Shin_Left = <-30, 0, 0>;
			#declare AV_Thigh_Right = <10, 0, 0>;
			#declare AV_Shin_Right = <-20, 0, 0>;
			#declare AV_Arm_Left = <5, 0, 10>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <0, 0, -10>;
			#declare AV_Wrist_Right = <15, 0, 0>;
		#break

		#case (7)
			// WALK 3: right leg forward, left arm forward
			#declare AV_Thigh_Left = <-15, 0, 0>;
			#declare AV_Shin_Left = <-35, 0, 0>;
			#declare AV_Thigh_Right = <30, 0, 0>;
			#declare AV_Shin_Right = <-30, 0, 0>;
			#declare AV_Arm_Left = <20, 0, 10>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <-25, 0, -10>;
			#declare AV_Wrist_Right = <15, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (8)
			// IDLE: weight on one leg, head turned
			#declare AV_Thigh_Left = <5, 0, 0>;
			#declare AV_Shin_Left = <-8, 0, 0>;
			#declare AV_Arm_Left = <15, 0, 12>;
			#declare AV_Wrist_Left = <25, 0, 0>;
			#declare AV_Arm_Right = <-5, 0, -12>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <-3, 5, 3>;
			#declare AV_Head = <5, 15, 0>;
			#declare V_Body_Offset = y * -0.02;
		#break

		#case (9)
			// PAIN: thrown backward, arms flung out
			#declare AV_Thigh_Left = <-10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <15, 0, 0>;
			#declare AV_Shin_Right = <-25, 0, 0>;
			#declare AV_Arm_Left = <20, 0, 15>;
			#declare AV_Wrist_Left = <20, 0, 0>;
			#declare AV_Arm_Right = <30, 0, -45>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <18, 0, -5>;
			#declare AV_Head = <25, -10, 0>;
			#declare V_Body_Offset = y * -0.08;
		#break

		/*
			Death: as the knight (see inc/frames/knight.inc), falling backward
			onto the back, rendered from a three-quarter view. The bow stays
			in the left hand, along the forearm, and falls flat with it.
		*/
		#case (10)
			// DEATH 1: hit, head snapping back, arms flung forward
			#declare AV_Thigh_Left = <10, 0, 0>;
			#declare AV_Shin_Left = <-20, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, 0>;
			#declare AV_Shin_Right = <-15, 0, 0>;
			#declare AV_Arm_Left = <10, 0, 25>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <60, 0, -35>;
			#declare AV_Wrist_Right = <40, 0, 0>;
			#declare AV_Torso = <20, 0, 0>;
			#declare AV_Head = <30, 0, 0>;
			#declare V_Body_Offset = y * -0.1;
		#break

		#case (11)
			// DEATH 2: tipping backward, knees giving way
			#declare AV_Thigh_Left = <35, 0, 0>;
			#declare AV_Shin_Left = <-55, 0, 0>;
			#declare AV_Thigh_Right = <25, 0, 0>;
			#declare AV_Shin_Right = <-45, 0, 0>;
			#declare AV_Arm_Left = <45, 0, 25>;
			#declare AV_Wrist_Left = <10, 0, 0>;
			#declare AV_Arm_Right = <100, 0, -40>;
			#declare AV_Wrist_Right = <20, 0, 0>;
			#declare AV_Torso = <6, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <25, 0, 0>;
			#declare V_Body_Offset = <0, -0.35, -0.4>;
		#break

		#case (12)
			// DEATH 3: falling on the back
			#declare AV_Thigh_Left = <50, 0, 0>;
			#declare AV_Shin_Left = <-70, 0, 0>;
			#declare AV_Thigh_Right = <40, 0, 0>;
			#declare AV_Shin_Right = <-60, 0, 0>;
			#declare AV_Arm_Left = <55, 0, 30>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <130, 0, -45>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Torso = <5, 0, 0>;
			#declare AV_Head = <15, 0, 0>;
			#declare AV_Body = <60, 8, 0>;
			#declare V_Body_Offset = <0, -0.45, -1.6>;
		#break

		#case (13)
			// DEATH 4: hitting the ground, knees up
			#declare AV_Thigh_Left = <65, 0, 5>;
			#declare AV_Shin_Left = <-90, 0, 0>;
			#declare AV_Thigh_Right = <55, 0, -5>;
			#declare AV_Shin_Right = <-80, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 25>; // flat on the ground (x ~ 0, z = spread), bow along the body
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -70>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Head = <5, 0, 0>;
			#declare AV_Body = <88, 18, 0>;
			#declare V_Body_Offset = <0, 0.1, -1.6>;
		#break

		#case (14)
			// DEATH 5: lying on the back, arms and legs fallen flat, head turned aside
			#declare AV_Thigh_Left = <8, 0, 8>;
			#declare AV_Shin_Left = <-12, 0, 0>;
			#declare AV_Thigh_Right = <5, 0, -6>;
			#declare AV_Shin_Right = <-10, 0, 0>;
			#declare AV_Arm_Left = <-10, 0, 18>;
			#declare AV_Wrist_Left = <0, 0, 0>;
			#declare AV_Arm_Right = <-10, 0, -35>;
			#declare AV_Wrist_Right = <0, 0, 0>;
			#declare AV_Head = <0, 35, 0>;
			#declare AV_Body = <90, 20, 0>;
			#declare V_Body_Offset = <0, 0.3, -1.4>;
		#break
	#end
#end

#include "inc/Pose.inc"
