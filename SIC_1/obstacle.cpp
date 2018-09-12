#include"all.h"

int getObstacleRandPos_y()
{
	return EXIST_MIN_SIDE_RANGE_Y + rand() % (EXIST_MAX_SIDE_RANGE_Y - (EXIST_MIN_SIDE_RANGE_Y - 1)-32);
}

int getObstacleSpawnLimit(int first, int second, int third, int fourth)
{
	first = rand() % (BLOCK_SPAWN_LIMIT / 4);
	second = rand() % (BLOCK_SPAWN_LIMIT / 4);
	third = rand() % (BLOCK_SPAWN_LIMIT / 4);
	fourth = rand() % (BLOCK_SPAWN_LIMIT / 4);

	return first + second + third + fourth;
}