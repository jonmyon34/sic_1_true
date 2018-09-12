#include"all.h"

int getWarpBlockRandPos_x()
{
	return EXIST_MIN_FALL_RANGE_X + rand() % (EXIST_MAX_FALL_RANGE_X - (EXIST_MIN_FALL_RANGE_X - 1));
}
