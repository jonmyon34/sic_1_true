#pragma once
#define GAUGEPOS_Y  288-144
#define GAUGESPEED 3 //7?
#define ACCMAXCNT 60

class ui
{
public:
	int ui_gh, ui_gh2;
	int ui_anim_gh;
	int ui_anim_gh2;
	int anim_x, anim2_x, anim2_y;
	int animCnt;
	int accmaxCnt;
	int preaccelaration;
	bool gaugeFlg;
	ui()
	{
		preaccelaration = 0;
		gaugeFlg = false;
		anim_x = 0;
		anim2_x = 0;
		anim2_y = 0;
		animCnt = 0;
		accmaxCnt = 0;
		ui_gh = LoadGraph("Data/Image/UI_gravity.png");
		ui_gh2 = LoadGraph("Data/Image/UI_score.png");
		ui_anim_gh = LoadGraph("Data/Image/UI_gravity_gauge.png");
		ui_anim_gh2 = LoadGraph("Data/Image/UI_gravity_graph.png");
	}
	void Drawacc(player);
	void Move();
	void All(player);
};