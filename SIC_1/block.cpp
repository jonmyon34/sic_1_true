#include"all.h"

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
		return 4;

	case 10:
	case 11:
		return 5;

	case 12:
		return 6;

	default:
		return false;
	}
}