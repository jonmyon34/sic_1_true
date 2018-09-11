#include"all.h"

//void GameStart(back &bk, player &pl, scene &se)
//{
//	while (ProcessMessage() != -1 && se.playmode == TITLE)
//	{
//		bk.Drawback(se, pl);
//		pl.All();
//
//		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
//		{
//			exit(true);
//		}
//		ScreenFlip();
//		ClearDrawScreen();
//	}
//}

void changeDirectionMode(back &bk, player &pl,scene &se)
{
	if (!pl.changeDirectionModeFlg)
	{
		pl.changeDirectionModeFlg = true;
		bk.doorFlg = true;
		bk.animCnt = 0;
		bk.scrollspeed = 0;
		bk.scrollspeedsetter = 0;
	}

	if (bk.animCnt < 180)
	{
		bk.Drawback(se, pl);
		pl.StopView();
	}

	if (bk.animCnt == 180)
	{
		bk.doorFlg = false;
		bk.animCnt = 360;
		pl.changeDirectionMode = PL_RIGHTSIDE_MODE;
	}

	if (bk.animCnt == 360)
	{
		bk.StopView();
		pl.StopView();

		switch (pl.changeDirectionMode)
		{
		case PL_RIGHTSIDE_MODE:	//プレイヤーが右側
			if (pl.speed < PL_SPEED_MAX)
			{
				pl.speed += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x - pl.speed;
			break;

		case PL_LEFTSIDE_MODE:	//プレイヤーが左側
			if (pl.speed < PL_SPEED_MAX)
			{
				pl.speed += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x + pl.speed;
			break;

		default:
			break;
		}
	}

	if (bk.animCnt == 360 && (pl.pos_x<-60 || pl.pos_x>WINDOW_X + 60))
	{
		bk.animCnt = 0;
		pl.changeDirectionModeFlg = false;
		pl.changeDirectionStartFlg = false;
		bk.scrollspeed = SCROLL_SPEED;

		switch (pl.changeDirectionMode)
		{
		case PL_RIGHTSIDE_MODE:
			pl.directionMode = PL_RIGHTSIDE_MODE;
			break;

		case PL_LEFTSIDE_MODE:
			pl.directionMode = PL_LEFTSIDE_MODE;
			break;

		default:
			break;
		}
	}

	if (bk.animCnt == 0)
	{
		while (bk.animCnt < 60)
		{
			DrawGraph(0, 0, bk.changeModeMargin_gh, true);
			bk.animCnt++;
			ScreenFlip();
			ClearDrawScreen();
		}
		bk.animCnt = 0;
		pl.changeDirectionModeCnt = 0;
	}
}

void changeDirectionModeDown(back &bk, player &pl, scene &se)
{
	if (!pl.changeDirectionModeFlg)
	{
		pl.changeDirectionModeFlg = true;
		bk.changeDirectionMode_x = 0;
		bk.animCnt = 0;
		bk.scrollspeed = 1;
		bk.scrollspeedsetter = 0;
	}

	bk.Drawback(se, pl);
	pl.StopView();
	bk.Drawbackfront(se, pl);
	
	switch (pl.directionMode)
	{
	case PL_RIGHTSIDE_MODE:
		DrawRectGraph(bk.changeDirectionMode_x - BACKSIDE_MARGIN, bk.changeDirectionMode_y, 112, 0, BACKSIDE_MARGIN, WINDOW_Y, bk.playback_gh, true, false);
		DrawRectGraph(bk.changeDirectionMode_x - BACKSIDE_MARGIN, 150 - bk.changeDirectionMode_y, 112, 0, BACKSIDE_MARGIN, WINDOW_Y, bk.playback_gh, true, false);

		if (bk.changeDirectionMode_x < BACKSIDE_MARGIN)
		{
			bk.changeDirectionMode_x++;
		}

		if (bk.changeDirectionMode_x == BACKSIDE_MARGIN)
		{
			if (pl.speed < PL_SPEED_MAX)
			{
				pl.speed += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x - pl.speed;
		}
		break;

	case PL_LEFTSIDE_MODE:
		DrawRectGraph(WINDOW_X-bk.changeDirectionMode_x, bk.changeDirectionMode_y, 0, 0, BACKSIDE_MARGIN, WINDOW_Y, bk.playback_gh, true, false);
		DrawRectGraph(WINDOW_X-bk.changeDirectionMode_x , 150 - bk.changeDirectionMode_y, 0, 0, BACKSIDE_MARGIN, WINDOW_Y, bk.playback_gh, true, false);
	
		if (bk.changeDirectionMode_x < BACKSIDE_MARGIN)
		{
			bk.changeDirectionMode_x++;
		}

		if (bk.changeDirectionMode_x == BACKSIDE_MARGIN)
		{
			if (pl.speed < PL_SPEED_MAX)
			{
				pl.speed += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x + pl.speed;
		}
		break;
	
	default:
		break;
	}

	if (pl.pos_x<0 - PL_WIDTH || pl.pos_x>WINDOW_X)
	{
			while (bk.animCnt < 60)
			{
				DrawGraph(0, 0, bk.changeModeMargin_gh, true);
				bk.animCnt++;
				ScreenFlip();
				ClearDrawScreen();
			}
			pl.changeDirectionModeFlg = false;
			pl.changeDirectionStartFlg = false;
			pl.changeDirectionModeCnt = 0;
			bk.animCnt = 0;
			pl.directionMode = BLOCK_RISE_MODE;
			pl.Direction();
	}

}