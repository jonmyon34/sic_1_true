#include "ALL.h"

void back::Drawback(scene se, player pl)
{
	if (se.playmode == TITLE)//タイトル画面背景
	{
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, 0,//左上
			WINDOW_X - BACKSIDE_MARGIN, 0,//右上
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y,//右下
			0 + BACKSIDE_MARGIN, WINDOW_Y,//左下
			titleback_gh, false);
	}

	if (se.playmode == PLAY)//プレイ画面背景
	{
		switch (pl.directionMode)
		{
		case 0://下から上
			if (y < -WINDOW_Y)y = 0;
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, y,//左上
				WINDOW_X - BACKSIDE_MARGIN, y,//右上
				WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,//右下
				0 + BACKSIDE_MARGIN, WINDOW_Y + y,//左下
				playback_gh, false);
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y * 2 + y,
				0 + BACKSIDE_MARGIN, WINDOW_Y * 2 + y,
				playback_gh, false);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;
			Drawdoor();
			y -= /*scrollspeed + scrollspeedsetter;*/1;//テスト用変更
			break;
		case 2://上から下
			if (y > WINDOW_Y)y = 0;
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, y,//左上
				WINDOW_X - BACKSIDE_MARGIN, y,//右上
				WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,//右下
				0 + BACKSIDE_MARGIN, WINDOW_Y + y,//左下
				playback_gh, false);
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, -WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, -WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, y,
				0 + BACKSIDE_MARGIN, y,
				playback_gh, false);
			Drawdoor();
			y += scrollspeed + scrollspeedsetter;
			break;
		case 1://左から右
			if (x > WINDOW_X)x = 0;
			DrawModiGraph(
				x, BACK_MARGIN,//左上
				WINDOW_X + x, BACK_MARGIN,//右上
				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//右下
				x, WINDOW_Y - BACK_MARGIN,//左下
				playbackside_gh[0], false);
			DrawModiGraph(
				-WINDOW_X + x, BACK_MARGIN,
				x, BACK_MARGIN,
				x, WINDOW_Y - BACK_MARGIN,
				-WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
				playbackside_gh[0], false);
			x += SCROLL_SPEED + scrollspeedsetter;
			break;
		case 3://右から左
			if (x < -WINDOW_X)x = 0;
			DrawModiGraph(
				x, BACK_MARGIN,//左上
				WINDOW_X + x, BACK_MARGIN,//右上
				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//右下
				x, WINDOW_Y - BACK_MARGIN,//左下
				playbackside_gh[0], false);
			DrawModiGraph(
				WINDOW_X + x, BACK_MARGIN,
				WINDOW_X * 2 + x, BACK_MARGIN,
				WINDOW_X * 2 + x, WINDOW_Y - BACK_MARGIN,
				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
				playbackside_gh[0], false);
			x -= SCROLL_SPEED + scrollspeedsetter;
			break;
		}
	}
}

void back::Drawbackfront(scene se, player pl)
{
	if (se.playmode == PLAY)//プレイ画面背景
	{
		switch (pl.directionMode)
		{
		case 1://左から右
			if (fx > WINDOW_X)fx = 0;
			DrawModiGraph(
				fx, BACK_MARGIN,//左上
				WINDOW_X + fx, BACK_MARGIN,//右上
				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//右下
				fx, WINDOW_Y - BACK_MARGIN,//左下
				playbackside_gh[1], true);
			DrawModiGraph(
				-WINDOW_X + fx, BACK_MARGIN,
				fx, BACK_MARGIN,
				fx, WINDOW_Y - BACK_MARGIN,
				-WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
				playbackside_gh[1], true);
			fx += (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;
		case 3://右から左
			if (fx < -WINDOW_X)fx = 0;
			DrawModiGraph(
				fx, BACK_MARGIN,//左上
				WINDOW_X + fx, BACK_MARGIN,//右上
				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//右下
				fx, WINDOW_Y - BACK_MARGIN,//左下
				playbackside_gh[1], true);
			DrawModiGraph(
				WINDOW_X + fx, BACK_MARGIN,
				WINDOW_X * 2 + fx, BACK_MARGIN,
				WINDOW_X * 2 + fx, WINDOW_Y - BACK_MARGIN,
				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
				playbackside_gh[1], true);
			fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;
		}
	}
}

void back::Drawdoor()
{
	switch (doorFlg)
	{
	case false:
		anim_x = 0;
		DrawRectExtendGraph(BACKSIDE_MARGIN, y + DOORPOS_Y, BACKSIDE_MARGIN + 150, DOORPOS_Y + y + 250, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectExtendGraph(BACKSIDE_MARGIN, y + DOORPOS_Y + WINDOW_Y, BACKSIDE_MARGIN + 150, DOORPOS_Y + y + 250 + WINDOW_Y, anim_x * 32, 96, 32, 96, door_gh, true);
		break;
	case true:
		anim_x = (animCnt / 30) % 5;
		animCnt++;
		DrawRectExtendGraph(BACKSIDE_MARGIN, y + DOORPOS_Y, BACKSIDE_MARGIN + 150, DOORPOS_Y + y + 250, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectExtendGraph(BACKSIDE_MARGIN, y + DOORPOS_Y + WINDOW_Y, BACKSIDE_MARGIN + 150, DOORPOS_Y + y + 250 + WINDOW_Y, anim_x * 32, 96, 32, 96, door_gh, true);
		break;
	}
}

void back::Move(player pl)
{
	switch (pl.acceleration)
	{
	case 0:
		scrollspeedsetter = 0;
		break;
	case 1:
		scrollspeedsetter = 1;
		break;
	case 2:
		scrollspeedsetter = 2;
		break;
	case 3:
		scrollspeedsetter = 3;
		break;
	default:
		scrollspeedsetter = 3;
		break;
	}
}

void back::All(scene se, player pl)
{
	Move(pl);
	Drawback(se, pl);
}

void back::HitStop(scene se, player pl)
{
	scrollspeed = 0;
	scrollspeedsetter = 0;
	Drawback(se, pl);
}