#include"all.h"

int getObstacleRandPos_y()
{
	return EXIST_MIN_SIDE_RANGE_Y + rand() % (EXIST_MAX_SIDE_RANGE_Y - (EXIST_MIN_SIDE_RANGE_Y - 1));
}