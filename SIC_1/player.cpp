#include"all.h"

bool check_hit_pos_y_rise(int pl_pos_y, int bl_pos_y, int blockNumber, int blockExistMode)
{
	if (pl_pos_y + PL_HEIGHT >= bl_pos_y + (blockNumber - blockExistMode)*BLOCK_HEIGHT&&	pl_pos_y <= bl_pos_y + (blockNumber - blockExistMode + 1)*BLOCK_HEIGHT)
	{
		return true;
	}
	return false;
}

bool check_hit_pos_y_warpblock(int pl_pos_y, int wp_pos_y)
{
	if (pl_pos_y + PL_HEIGHT > wp_pos_y && pl_pos_y < wp_pos_y + BLOCK_HEIGHT)
	{
		return true;
	}
	return false;
}

bool check_hit_pos_y_fall(int pl_pos_y, int bl_pos_y, int blockNumber, int blockExistMode)
{
	if (pl_pos_y + PL_HEIGHT >= bl_pos_y - ((blockNumber - blockExistMode)*BLOCK_HEIGHT) && pl_pos_y <= bl_pos_y - ((blockNumber - blockExistMode)* BLOCK_HEIGHT) + BLOCK_HEIGHT)
	{
		return true;
	}
	return false;
}

bool check_hit_pos_x_goright(int pl_pos_x,int ob_pos_x)
{
	if (pl_pos_x + PL_WIDTH > ob_pos_x && pl_pos_x < ob_pos_x + OBSTACLE_WIDTH)
	{
		return true;
	}
	return false;
}

bool check_hit_pos_x_goleft(int pl_pos_x, int ob_pos_x)
{
	if (pl_pos_x + PL_WIDTH > ob_pos_x && pl_pos_x < ob_pos_x + OBSTACLE_WIDTH)
	{
		return true;
	}
	return false;
}

bool checkHitBlock(int pl_pos_x, int bl_pos_x)
{
	if (pl_pos_x + PL_WIDTH > bl_pos_x && bl_pos_x + BLOCK_WIDTH > pl_pos_x)
	{
		return true;
	}

	return false;
}

bool checkHitObstacle(int pl_pos_y, int ob_pos_y)
{
	if (pl_pos_y + PL_HEIGHT > ob_pos_y && ob_pos_y + OBSTACLE_HEIGHT*2 > pl_pos_y)
	{
		return true;
	}

	return false;
}

bool checkHitWarp(int pl_pos_x, int wp_pos_x)
{
	if (pl_pos_x + PL_WIDTH > wp_pos_x && pl_pos_x < wp_pos_x + WARP_BLOCK_HEIGHT)
	{
		return true;
	}
	return false;
}

void checkBreakBlock(int blNumber,int acceleration)
{

}

int checkHitStop(int blockNumber, int blockExistMode)
{
	if (blockNumber - blockExistMode == 1)
	{
		return PL_HITSTOP_VAL;
	}
	else //if (blockNumber - blockExistMode == 2)
	{
		return PL_HITSTOP_VAL / 2;
	}

	//else if (blockNumber - blockExistMode == 3)
	//{
	//	return PL_HITSTOP_VAL / 4;
	//}
	//else
	//{
	//	return PL_HITSTOP_VAL / 6;
	//}
}

void checkHitEnemy()
{

}

int direction_pl_pos_x(int directionMode)
{
	switch (directionMode)
	{
	case 0:
		return PL_UP_FIRST_X;

	case 1:
		return PL_RIGHT_FIRST_X;

	case 2:
		return PL_DOWN_FIRST_X;

	case 3:
		return PL_LEFT_FIRST_X;

	default:
		break;
	}

	return false;
}

int direction_pl_pos_y(int directionMode)
{
	switch (directionMode)
	{
	case 0:
		return PL_UP_FIRST_Y;

	case 1:
		return PL_RIGHT_FIRST_Y;

	case 2:
		return PL_DOWN_FIRST_Y;

	case 3:
		return PL_LEFT_FIRST_Y;

	default:
		break;
	}

	return false;
}


int getChangeDirectionModeLimit(int first, int second, int third, int fourth)
{
	first = rand() % (BLOCK_SPAWN_LIMIT / 4);
	second = rand() % (BLOCK_SPAWN_LIMIT / 4);
	third = rand() % (BLOCK_SPAWN_LIMIT / 4);
	fourth = rand() % (BLOCK_SPAWN_LIMIT / 4);

	return DIRECTION_CHANGE_MIN_RANGE + (first + second + third + fourth);
}

float sign(float n)
{
	if (n > 0) return 1.0f;
	else if (n < 0) return -1.0f;
	else return 0.f;
}