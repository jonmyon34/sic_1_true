#pragma once
#include "all.h"
#define SCROLL_SPEED 1

#define BACKSIDE_WIDTH 224
#define DOORPOS_Y 176
#define DOOR_LEFT_WIDTH 32
#define DOOR_RIGHT_WIDTH 23
#define DOOR_HEIGHT 83
#define EDGE_WIDTH 16
#define WINDOW_Y_RECT WINDOW_Y/288
#define WINDOW_X_RECT (WINDOW_X - BACKSIDE_MARGIN*2)/224

class back
{
public:
	int x, y;
	double fx, fy;
	int scrollspeed;
	int scrollspeedsetter;
	int playback_gh, titleback_gh, playbackedge_gh;
	int changeModeMargin_gh;
	int playbackside_gh[2];//[0]が遠景[1]が近景
	int door_gh;

	int temp_y, temp_x, temp_fy, temp_fx;

	int anim_x;
	int animCnt;

	int changeDirectionMode_x;
	int changeDirectionMode_y;

	bool doorFlg;//ドア開けるフラグ

	back()
	{
		x = 0;
		fx = 0;
		y = 0;
		fy = 0;
		scrollspeed = SCROLL_SPEED;
		scrollspeedsetter = 0;

		temp_x = 0;
		temp_y = 0;
		temp_fx = 0;
		temp_fy = 0;

		anim_x = 0;
		animCnt = 0;
		doorFlg = false;
		titleback_gh = LoadGraph("Data/Image/SIC_1_back_test1.png");
		LoadDivGraph("Data/Image/BG3.png", 2, 2, 1, 112, 144, playbackside_gh);
		playback_gh = LoadGraph("Data/Image/BG1_A.png");
		playbackedge_gh = LoadGraph("Data/Image/BG1_B.png");
		changeModeMargin_gh = LoadGraph("Data/Image/clear_1.png");
		door_gh = LoadGraph("Data/Image/door.png");

		changeDirectionMode_x = 0;
		changeDirectionMode_y = -60;
	}
	void Drawback(scene, player);
	void Drawbackfront(scene, player);
	void Drawdoor(player);
	void Move(player);
	void All(scene, player);
	void HitStop(scene, player);
	void StopView();
};