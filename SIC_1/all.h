#pragma once

#include"DxLib.h"

#include<stdlib.h>
#include<time.h>


#define WINDOW_X 384//1280
//384が仕様
#define WINDOW_Y 216//736
//216が仕様
#define MAX_WINDOW_EXTEND_RATE 5




#define FLASHCNT_MAX 70


#define BLOCK_OUT_POS_Y -60
#define OBSTACLE_OUT_POS_X 60

#define EXIST_MIN_FALL_RANGE_X WINDOW_X/4
#define EXIST_MAX_FALL_RANGE_X WINDOW_X/4*3

#define EXIST_MIN_SIDE_RANGE_Y WINDOW_Y/4
#define EXIST_MAX_SIDE_RANGE_Y WINDOW_Y/4*3

#define BACK_MARGIN 50
#define BACKSIDE_MARGIN 250


#include"KBpreview.h"

#include"scene.h"
#include"player.h"
#include"back.h"
#include"block.h"
#include"obstacle.h"