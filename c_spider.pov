/*
  ____        _     _
 / ___| _ __ (_) __| | ___ _ __
 \___ \| '_ \| |/ _` |/ _ \ '__|
  ___) | |_) | | (_| |  __/ |
 |____/| .__/|_|\__,_|\___|_|
       |_|

	Giant spider, the mass of a goblin. See inc/spider/Spider.inc.
*/
#include "inc/Camera.inc"
#include "inc/frames/spider.inc"
#include "inc/spider/Spider.inc"

object {
	O_Spider_Posed
	rotate y * N_Animation_Angle
}
