#include"all.h"

bool check_hit_pos_y_rise(int pl_pos_y, int bl_pos_y, int blockNumber, int blockExistMode)
{
	if (pl_pos_y + PL_HEIGHT >= bl_pos_y + (blockNumber - blockExistMode)*BLOCK_HEIGHT&&	pl_pos_y <= bl_pos_y + (blockNumber - blockExistMode + 1)*BLOCK_HEIGHT)
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

bool check_hit_pos_x_goright(int pl_pos_x,int bl_pos_x)
{
	if (pl_pos_x + PL_WIDTH >= bl_pos_x && pl_pos_x <= bl_pos_x + BLOCK_WIDTH)
	{
		return true;
	}
	return false;
}

bool check_hit_pos_x_goleft(int pl_pos_x, int bl_pos_y)
{
	if (pl_pos_x <= bl_pos_y + BLOCK_WIDTH && pl_pos_x + PL_WIDTH >= bl_pos_y)
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

void checkBreakBlock(int blNumber,int acceleration)
{

}

bool checkHitStop(int acceleration, int block)
{
	if (acceleration == 0 && block == true)
	{
		return true;
	}

	return false;
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


void invincible()
{

}