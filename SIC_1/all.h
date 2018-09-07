#pragma once

#include"DxLib.h"

#include<stdlib.h>
#include<time.h>


#define WINDOW_X 1280
#define WINDOW_Y 736



#define FLASHCNT_MAX 70


#define BLOCK_OUT_POS_Y -60
#define OBSTACLE_OUT_POS_X 60

#define EXIST_MIN_FALL_RANGE_X WINDOW_X/4
#define EXIST_MAX_FALL_RANGE_X WINDOW_X/4*3

#define EXIST_MIN_SIDE_RANGE_Y WINDOW_Y/4
#define EXIST_MAX_SIDE_RANGE_Y WINDOW_Y/4*3




#include"player.h"
#include"back.h"
#include"block.h"
#include"obstacle.h"