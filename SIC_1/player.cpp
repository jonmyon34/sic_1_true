#include"all.h"

bool checkHitPosY(int pl_pos_y, int bl_pos_y, int blockNumber, int blockExistMode)
{
	if (pl_pos_y + PL_WIDTH >= bl_pos_y + (blockNumber - blockExistMode)*BLOCK_HEIGHT&&	pl_pos_y < bl_pos_y + (blockNumber - blockExistMode + 1)*BLOCK_HEIGHT)
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

int direction_pl_pos_x(int rad_rand)
{
	switch (rad_rand)
	{
	case 0:
		return PL_UP_FIRST_X;

	case 1:
		return PL_LEFT_FIRST_X;

	case 2:
		return PL_DOWN_FIRST_X;

	case 3:
		return PL_RIGHT_FIRST_X;

	default:
		break;
	}
}

int direction_pl_pos_y(int rad_rand)
{
	switch (rad_rand)
	{
	case 0:
		return PL_UP_FIRST_Y;

	case 1:
		return PL_LEFT_FIRST_Y;

	case 2:
		return PL_DOWN_FIRST_Y;

	case 3:
		return PL_RIGHT_FIRST_Y;

	default:
		break;
	}
}


void invincible()
{

}