#pragma once



#define GAUGEPOS_Y   WINDOW_Y - 110

#define GAUGESPEED 3 //7?

#define ACCMAXCNT 60

#define COMBO_RESULT 32


class ui

{

public:
	int ui_gh, ui_gh2;
	int ui_anim_gh;
	int ui_anim_gh2;
	int font_gh;
	int score_pos_x, score_pos_y;
	int combo_pos_x, combo_pos_y;
	int gauge_pos_x, gauge_pos_y;//ゲージ
	int gauge_frame_pos_x, gauge_frame_pos_y;//ゲージ枠
	int anim_x, anim2_x, anim2_y;
	int animCnt;
	int anim2Cnt;
	int accmaxCnt;
	int preaccelaration;
	bool gaugeFlg;

	int combo_by_pl;
	int score_by_pl;
	int combo_lim_by_pl;
	int score_tmp;
	int combo_tmp;
	int combo_tmp2;
	int combo_result;
	bool combo_flg;
	ui()

	{

		preaccelaration = 0;

		gaugeFlg = false;

		score_pos_x = 0, score_pos_y = 0;
		combo_pos_x = 0, combo_pos_y = 0;
		gauge_pos_x = gauge_pos_y = 0;
		gauge_frame_pos_x = gauge_frame_pos_y = 0;

		anim_x = 0;

		anim2_x = 0;

		anim2_y = 0;

		animCnt = 0;

		accmaxCnt = 0;

		combo_tmp = 0;
		combo_by_pl = 0;
		score_by_pl = 0;
		combo_lim_by_pl = 0;
		combo_result = 0;
		combo_tmp2 = 0;

		score_tmp = 0;
		combo_flg = false;

		ui_gh = LoadGraph("Data/Image/UI_gravity.png");

		ui_gh2 = LoadGraph("Data/Image/UI_score.png");

		ui_anim_gh = LoadGraph("Data/Image/UI_gravity_gauge.png");

		ui_anim_gh2 = LoadGraph("Data/Image/UI_gravity_graph.png");

		font_gh = LoadFontDataToHandle("Data/Font/NishikiFont.dft");
	}

	void Drawacc(player);

	void Move();

	void All(player);

};