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
int changeModeRightLeft()
{
	switch (rand() % 4)
	{
	case 0:
	case 2:
		return PL_RIGHTSIDE_MODE;
		break;

	case 1:
	case 3:
		return PL_LEFTSIDE_MODE;
		break;

	default:
		break;
	}
}

void changeDirectionMode(back &bk, player &pl,scene &se,scenegame &sgm)
{
	if (!pl.changeDirectionModeFlg)
	{
		pl.changeDirectionModeFlg = true;
		bk.doorFlg = true;
		bk.animCnt = 0;
		bk.scrollspeed = 0;
		bk.scrollspeedsetter = 0;
		pl.changeDirectionMode = changeModeRightLeft();
		bk.changeDirectionMode = pl.changeDirectionMode;
		sgm.scenegame_adjust_Flg = true;
		sgm.scenegame_adjust_pos_y = bk.y;
		sgm.scenegame_adjust_ply = pl.pos_y;
	}

	if (bk.animCnt < 180)
	{
		bk.anim_x = (bk.animCnt / 30) % 6;
		bk.animCnt++;
		if (sgm.scenegame_adjust_pos_y > 0 && sgm.scenegame_adjust_Flg)
		{
			if (sgm.scenegame_adjust_pos_y + DOORPOS_Y - 20 - sgm.scenegame_adjust_ply > 0 && sgm.scenegame_adjust_Flg)
			{
				pl.pos_y += 1;
			}
			else if (sgm.scenegame_adjust_pos_y + DOORPOS_Y - 20 - sgm.scenegame_adjust_ply < 0 && sgm.scenegame_adjust_Flg)
			{
				pl.pos_y -= 1;
			}
			else
			{
				sgm.scenegame_adjust_Flg = false;
			}
		}
		else if(sgm.scenegame_adjust_pos_y<=0 && sgm.scenegame_adjust_Flg)
		{
			if (sgm.scenegame_adjust_pos_y+WINDOW_Y + DOORPOS_Y - 20 - sgm.scenegame_adjust_ply > 0 && sgm.scenegame_adjust_Flg)
			{
				pl.pos_y += 1;
			}
			else if (sgm.scenegame_adjust_pos_y +WINDOW_Y+ DOORPOS_Y - 20 - sgm.scenegame_adjust_ply < 0 && sgm.scenegame_adjust_Flg)
			{
				pl.pos_y -= 1;
			}
			else
			{
				sgm.scenegame_adjust_Flg = false;
			}

		}
		bk.StopViewDoor();
		bk.StopView();
		pl.StopView();

	}

	if (bk.animCnt == 180)
	{
		bk.doorFlg = false;
		bk.animCnt = 360;
	}

	if (bk.animCnt == 360)
	{
		switch (pl.changeDirectionMode)
		{
		case PL_RIGHTSIDE_MODE:
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + bk.y - 1, bk.anim_x * 32, 96, 32, 96, bk.door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + bk.y - 1, bk.anim_x * 32, 96, 32, 96, bk.door_gh, true);

			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + bk.y, 0 * 32, 0, 32, 96, bk.door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + bk.y, 0 * 32, 0, 32, 96, bk.door_gh, true);

			break;

		case PL_LEFTSIDE_MODE:
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + bk.y, bk.anim_x * 32, 0, 32, 96, bk.door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + bk.y, bk.anim_x * 32, 0, 32, 96, bk.door_gh, true);

			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + bk.y - 1, 0 * 32, 96, 32, 96, bk.door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + bk.y - 1, 0 * 32, 96, 32, 96, bk.door_gh, true);
			break;
		}

		bk.StopView();
		pl.StopView();

		switch (pl.changeDirectionMode)
		{
		case PL_RIGHTSIDE_MODE:	//プレイヤーが右側
			if (pl.speed_x < PL_SPEED_MAX)
			{
				pl.speed_x += PL_SPEED_INC*2;
			}

			pl.pos_x = pl.pos_x - pl.speed_x;
			break;

		case PL_LEFTSIDE_MODE:	//プレイヤーが左側
			if (pl.speed_x < PL_SPEED_MAX)
			{
				pl.speed_x += PL_SPEED_INC*2;
			}

			pl.pos_x = pl.pos_x + pl.speed_x;
			break;

		default:
			break;
		}
	}

	if (bk.animCnt == 360 && (pl.pos_x<-60 || pl.pos_x>WINDOW_X + 60))
	{
		bk.doorFlg = false;
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
		pl.warpFlg = false;
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
		DrawRectGraph(bk.changeDirectionMode_x - BACKSIDE_MARGIN, bk.changeDirectionMode_y, 112, 0, BACKSIDE_MARGIN, BACK_HEIGHT, bk.playback_gh, true, false);
		DrawRectGraph(bk.changeDirectionMode_x - BACKSIDE_MARGIN, 40 - bk.changeDirectionMode_y, 112, 0, BACKSIDE_MARGIN, BACK_HEIGHT, bk.playback_gh, true, false);

		if (bk.changeDirectionMode_x < BACKSIDE_MARGIN)
		{
			bk.changeDirectionMode_x++;
		}

		if (bk.changeDirectionMode_x == BACKSIDE_MARGIN)
		{
			if (pl.speed_x < PL_SPEED_MAX)
			{
				pl.speed_x += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x - pl.speed_x;
		}
		break;

	case PL_LEFTSIDE_MODE:
		DrawRectGraph(WINDOW_X-bk.changeDirectionMode_x, bk.changeDirectionMode_y, 0, 0, BACKSIDE_MARGIN, BACK_HEIGHT, bk.playback_gh, true, false);
		DrawRectGraph(WINDOW_X-bk.changeDirectionMode_x , 40 - bk.changeDirectionMode_y, 0, 0, BACKSIDE_MARGIN, BACK_HEIGHT, bk.playback_gh, true, false);
	
		if (bk.changeDirectionMode_x < BACKSIDE_MARGIN)
		{
			bk.changeDirectionMode_x++;
		}

		if (bk.changeDirectionMode_x == BACKSIDE_MARGIN)
		{
			if (pl.speed_x < PL_SPEED_MAX)
			{
				pl.speed_x += PL_SPEED_INC;
			}

			pl.pos_x = pl.pos_x + pl.speed_x;
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
			pl.warpFlg = false;
			pl.directionMode = BLOCK_RISE_MODE;
			pl.Direction();
	}

}