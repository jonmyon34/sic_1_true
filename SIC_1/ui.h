#pragma once
#define GAUGEPOS_Y  288-144

class ui
{
public:
	int ui_gh, ui_gh2;
	ui()
	{
		ui_gh = LoadGraph("Data/Image/UI_gravity.png");
		ui_gh2 = LoadGraph("Data/Image/UI_score.png");
	}
	void Draw();
	void View();
	void All();
};