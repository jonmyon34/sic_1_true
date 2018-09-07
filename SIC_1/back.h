#pragma once
#include "all.h"
#define SCROLL_SPEED 2
#define BACKSIDE_MARGIN  250 //‰æ–Ê‚Ì¶‰E•’²®

class back
{
public:
	int y;
	int scrollspeedsetter;
	int back_gh;
	back()
	{
		y = 0;
		scrollspeedsetter = 0;
		back_gh = LoadGraph("BG1.png");
	}
	void Draw();
	void Move(player);
	void All(player);
};