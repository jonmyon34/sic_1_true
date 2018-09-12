#include "all.h"

void ui::Drawacc(player pl)
{

	if (pl.hp > 0)
	{
		animCnt++;//??

		if (pl.acceleration - 1 > preaccelaration)anim2Cnt = 0;
		if (animCnt % 4 && anim2Cnt < 5)anim2Cnt++;
		preaccelaration = pl.acceleration - 1;

		if (pl.directionMode == 0 || pl.directionMode == 2)
		{
			score_pos_x = score_pos_y = 0;
			combo_pos_x = 0, combo_pos_y = 16;

			gauge_frame_pos_x = 0, gauge_frame_pos_y = GAUGEPOS_Y;

			DrawRectGraph(gauge_frame_pos_x, gauge_frame_pos_y, 0, 0, 112, 110, ui_gh, true);

			//スコア
			if (score_tmp < score_by_pl)
			{
				mu->Playse(58);
				score_tmp += 1 + (combo_by_pl*0.5);
			}
			if (score_tmp > score_by_pl)
			{
				score_tmp = score_by_pl;
			}


			DrawRectGraph(
				score_pos_x, score_pos_y,
				0, 0,
				80, 16,
				ui_gh2, true);
			DrawFormatStringToHandle(score_pos_x + 77 - GetDrawFormatStringWidthToHandle(font_gh, "%7d", score_tmp),
				score_pos_y + 5, GetColor(255, 255, 255), font_gh,
				"%7d", score_tmp);


			if (combo_tmp != combo_by_pl && combo_by_pl == 0 && combo_lim_by_pl == 0)
			{
				if (combo_flg == false)
				{
					mu->Playse(55);//k
					combo_tmp2 = combo_tmp;
					combo_result = COMBO_RESULT;
					combo_flg = true;
				}
			}

			if (combo_flg = true)
			{
				combo_result += 2;
				if (combo_result > 255)
				{
					combo_flg = false;
				}

			}

			printfDx("cmb %d , %d %d", combo_by_pl, combo_tmp, combo_tmp2);
			combo_tmp = combo_by_pl;

			if (combo_flg == false)
			{
				DrawRectGraph(		//コンボ
					combo_pos_x, combo_pos_y,
					0, 16,
					80, 16,
					ui_gh2, true);
				DrawFormatStringToHandle(combo_pos_x + 77 - GetDrawFormatStringWidthToHandle(font_gh, "%7d", combo_by_pl),
					combo_pos_y + 5, GetColor(255, 255, 255), font_gh,
					"%7d", combo_by_pl);
			}
			else
			{
				DrawRectGraph(		//コンボ
					combo_pos_x, combo_pos_y,
					0, 16,
					80, 16,
					ui_gh2, true);
				DrawFormatStringToHandle(combo_pos_x + 77 - GetDrawFormatStringWidthToHandle(font_gh, "%7d", combo_tmp2),
					combo_pos_y + 5, GetColor(255, combo_result, combo_result), font_gh,
					"%7d", combo_tmp2);
			}

			DrawRectGraph(
				combo_pos_x, combo_pos_y + 16,
				0, 32,
				(float)80 * ((float)combo_lim_by_pl / (float)COMBO_LIMIT), 4,
				ui_gh2, true);
			/*printfDx("acc: %d\n", pl.acceleration);*/

			switch (pl.acceleration)
			{
			case 0:
				for (int i = 1; i <= 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (i - 1), 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 1:
				anim_x = animCnt / GAUGESPEED % 10; if (anim_x == 0)anim_x = 1;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= pl.acceleration; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				for (int i = pl.acceleration; i < 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * i, 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 2:
				anim_x = animCnt / GAUGESPEED % 10; if (anim_x == 0)anim_x = 1;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * 0, anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration - 1), anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 0; i < preaccelaration - 1; i++)
				{
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * i, 5 * 16, i * 16, 16, 16, ui_anim_gh2, true);
				}
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
				}
				for (int i = pl.acceleration; i < 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * i, 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 3:
				anim_x = animCnt / GAUGESPEED % 10; if (anim_x == 0)anim_x = 1;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration - 1), anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 0; i < preaccelaration - 1; i++)
				{
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * i, 5 * 16, i * 16, 16, 16, ui_anim_gh2, true);
				}
				DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
				}
				for (int i = pl.acceleration; i < 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * i, 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 4:
				anim_x = animCnt / GAUGESPEED % 10; if (anim_x == 0)anim_x = 1;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration - 1), anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 0; i < preaccelaration - 1; i++)
				{
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * i, 5 * 16, i * 16, 16, 16, ui_anim_gh2, true);
				}
				DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
				}
				for (int i = pl.acceleration; i < 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * i, 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 5:
				anim_x = animCnt / GAUGESPEED % 10; if (anim_x == 0)anim_x = 1;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration - 1), anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 0; i < preaccelaration - 1; i++)
				{
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * i, 5 * 16, i * 16, 16, 16, ui_anim_gh2, true);
				}
				DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
				}
				for (int i = pl.acceleration; i < 6; i++)
				{
					DrawRectGraph(gauge_pos_x, gauge_pos_y + 16 * i, 0, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 6:
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				gauge_pos_x = gauge_frame_pos_x + 20, gauge_pos_y = gauge_frame_pos_y + 12;

				DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration - 1), anim2Cnt * 16, (preaccelaration - 1) * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 0; i < preaccelaration - 1; i++)
				{
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * i, 5 * 16, i * 16, 16, 16, ui_anim_gh2, true);
				}
				accmaxCnt++;
				anim_x = animCnt / GAUGESPEED % 10;
				if (accmaxCnt > ACCMAXCNT)
				{
					anim_x = 10;
					DrawRectGraph(gauge_frame_pos_x + 1, (gauge_pos_y - 2) + 16 * (preaccelaration), anim2Cnt * 16, (preaccelaration) * 16, 16, 16, ui_anim_gh2, true);
				}
				DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * preaccelaration), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * preaccelaration), (anim_x + 1) * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					if (accmaxCnt > ACCMAXCNT)anim_x = 10;
					DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
					if (accmaxCnt > ACCMAXCNT)DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 1) * 32, 16, 32, 16, ui_anim_gh, true);
					if (accmaxCnt > ACCMAXCNT)
					{
						DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
					}
					else
					{
						for (int i = 1; i < preaccelaration; i++)
						{
							DrawRectGraph(gauge_pos_x, gauge_pos_y + (16 * (i - 1)), (anim_x + 2) * 32, 16, 32, 16, ui_anim_gh, true);
						}
					}
				}
				break;
			}
		}
		if (pl.directionMode == 1 || pl.directionMode == 3)
		{
			DrawGraph(0, 0, ui_gh2, true);
			/*DrawRectGraph(0, 254, 0, 110, 112, 34, ui_gh, true);*/ //仮想ゲージ表示しない
		}
	}
}

void ui::Move()
{

}

void ui::All(player pl)
{
	Drawacc(pl);
}