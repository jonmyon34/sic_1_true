#include "all.h"

void ui::Drawacc(player pl)
{
	preaccelaration = pl.acceleration - 1;
	if (pl.hp > 0)
	{
		animCnt++;//??
		if (pl.directionMode == 0 || pl.directionMode == 2)
		{
			DrawRectGraph(0, GAUGEPOS_Y, 0, 0, 112, 110, ui_gh, true);
			DrawGraph(0, 0, ui_gh2, true);
			switch (pl.acceleration)
			{
			case 0:
				accmaxCnt = 0;
				break;
			case 1:
				anim_x = animCnt / GAUGESPEED % 10;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				for (int i = 1; i <= pl.acceleration; i++)
				{
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 2:
				anim_x = animCnt / GAUGESPEED % 10;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				DrawRectGraph(20, 157 + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 3:
				anim_x = animCnt / GAUGESPEED % 10;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				DrawRectGraph(20, 157 + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 4:
				anim_x = animCnt / GAUGESPEED % 10;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				DrawRectGraph(20, 157 + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 5:
				anim_x = animCnt / GAUGESPEED % 10;
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				DrawRectGraph(20, 157 + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				}
				accmaxCnt = 0;
				break;
			case 6:
				anim2_x = animCnt / 10 % 6;
				anim2_y = pl.acceleration - 1;
				DrawRectGraph(1, 138 + 16 * pl.acceleration, anim2_x * 16, preaccelaration * 16, 16, 16, ui_anim_gh2, true);
				accmaxCnt++;
				anim_x = animCnt / GAUGESPEED % 10;
				if (accmaxCnt > ACCMAXCNT)
				{
					anim_x = 10;
				}
				DrawRectGraph(20, 157 + 16 * (pl.acceleration - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
				for (int i = 1; i <= preaccelaration; i++)
				{
					anim_x = 9;
					if (accmaxCnt > ACCMAXCNT)anim_x = 10;
					DrawRectGraph(20, 157 + 16 * (i - 1), anim_x * 32, 16, 32, 16, ui_anim_gh, true);
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