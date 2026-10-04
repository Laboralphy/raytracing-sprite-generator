#declare P_Head = sphere {
	<0, 0, 0>, 1
}

/*
	When the wizard dies (V_Pose_Extra.x = collapse of the robe, see
	inc/wizard/Wizard.inc), the head fades out during the first half.
*/
#declare N_Wizard_Fade = 0;
#ifdef (V_Pose_Extra)
	#declare N_Wizard_Fade = min(1, max(0, V_Pose_Extra.x * 2));
#end

#declare O_BlackMageHead = object {
	P_Head
	texture {
		pigment {
			image_map {
				png "png/face_blackmage.png"
				map_type 1
				#if (N_Wizard_Fade > 0)
					transmit all N_Wizard_Fade
				#end
			}
		}
	}
}
