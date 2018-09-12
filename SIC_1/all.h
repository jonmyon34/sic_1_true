#pragma once

#include"DxLib.h"

#include<math.h>
#include<stdlib.h>
#include<time.h>


#define WINDOW_X 384//1280
//384が仕様
#define WINDOW_Y 216//736
//216が仕様
#define MAX_WINDOW_EXTEND_RATE 5




#define FLASHCNT_MAX 70

#define BACK_MARGIN 50
#define BACKSIDE_MARGIN 112

#define BLOCK_OUT_POS_Y -60
#define OBSTACLE_OUT_POS_X 60

#define WINDOW_CENTER_X (WINDOW_X / 2)
#define WINDOW_CENTER_Y (WINDOW_Y / 2)

#define EXIST_MIN_FALL_RANGE_X WINDOW_X/2 - BACKSIDE_MARGIN+40
#define EXIST_MAX_FALL_RANGE_X WINDOW_X/2 + BACKSIDE_MARGIN-60

#define EXIST_MIN_SIDE_RANGE_Y BACK_MARGIN
#define EXIST_MAX_SIDE_RANGE_Y BACK_MARGIN+96

#define BACK_WIDTH 224
#define BACK_HEIGHT 288

#define DIRECTION_CHANGE_MIN_RANGE 900

#define BACKPOS_X (WINDOW_CENTER_X - (BACK_WIDTH / 2))

#define COMBO_LIMIT 180
#define SCORE_INC 2

//#define WARP_BLOCK_WIDTH 16
//#define WARP_BLOCK_HEIGHT 16



#include"KBpreview.h"

#include"scene.h"
#include"player.h"
#include"back.h"
#include"block.h"
#include"obstacle.h"
#include"ui.h"
#include"scenegame.h"
#include"music.h"
#include"warpblock.h"