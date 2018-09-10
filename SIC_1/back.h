#pragma once
#include "all.h"
#define SCROLL_SPEED 2
#define DOORPOS_Y 445

class back
{
public:
	int x, y;
	double fx, fy;
	int scrollspeed;
	int scrollspeedsetter;
	int playback_gh, titleback_gh;
	int playbackside_gh[2];//[0]が遠景[1]が近景
	int door_gh;

	int anim_x;
	int animCnt;

	bool doorFlg;//ドア開けるフラグ

	back()
	{
		x = 0;
		fx = 0;
		y = 0;
		fy = 0;
		scrollspeed = SCROLL_SPEED;
		scrollspeedsetter = 0;
		anim_x = 0;
		animCnt = 0;
		doorFlg = false;
		titleback_gh = LoadGraph("Data/Image/SIC_1_back_test1.png");
		LoadDivGraph("Data/Image/BG3.png", 2, 2, 1, 112, 96, playbackside_gh);
		playback_gh = LoadGraph("Data/Image/BG1.png");
		door_gh = LoadGraph("Data/Image/door.png");
	}
	void Drawback(scene, player);
	void Drawbackfront(scene, player);
	void Drawdoor();
	void Move(player);
	void All(scene, player);
	void HitStop(scene, player);
};