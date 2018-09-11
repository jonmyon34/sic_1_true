#include"all.h"

void HitStop(block &bl, player &pl)
{
	if (pl.hitstopCnt > 0)
	{
		bl.speed = 0;
		pl.hitstopFlg = true;
	}
	else if(pl.hitstopFlg)
	{
		bl.speed = BLOCK_SPEED;
		pl.hitstopFlg = false;
	}
}

int getBlockRandPos_x()
{
	return EXIST_MIN_FALL_RANGE_X + rand() % (EXIST_MAX_FALL_RANGE_X - (EXIST_MIN_FALL_RANGE_X - 1));
}

int getBlockRandValue()
{
	return rand() % 6;
}

int getBlockNo(int first, int second)
{
	switch (first + second)
	{
	case 2:
	case 3:
		return 1;

	case 4:
	case 5:
		return 2;

	case 6:
	case 7:
		return 3;

	case 8:
	case 9:
	case 10:
		return 4;
	case 11:
	case 12:
		return 5;


	default:
		return 5;
	}
}


int getBlockSpawnLimit(int first,int second,int third,int fourth)
{
	first = rand() % (BLOCK_SPAWN_LIMIT / 4);
	second = rand() % (BLOCK_SPAWN_LIMIT / 4);
	third = rand() % (BLOCK_SPAWN_LIMIT / 4);
	fourth = rand() % (BLOCK_SPAWN_LIMIT / 4);

	return first + second + third + fourth;
}
