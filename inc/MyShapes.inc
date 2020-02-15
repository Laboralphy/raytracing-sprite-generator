/*
	un demi tuyau aligné sur l'axe Y
	en paramètre :
	- N_Thickness : épaisseur du tuyau (rayon externe = 1)
*/
#macro CreateHalfPipe (N_Thickness)
	intersection {
		difference {
			cylinder {
				0,
				y
				1
			}
			cylinder {
				-y
				2 * y
				1 - N_Thickness
			}
		}
		box {
			-x
			1
		}
	}
#end

/*
	un quart de disque qui s'étend sur le secteur x+, y+, z+ 
*/
#macro CreateQuarterDisc ()
	#local Shaper = box {
		-y
		<1, 2, 1>
	}
	
	intersection {
		cylinder {
			0
			y
			1
		}
		object {
			Shaper
		}
	}
#end
