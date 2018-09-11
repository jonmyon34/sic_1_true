#include"all.h"

void back::Drawback(scene se, player pl)

{
	if (se.playmode == TITLE)//タイトル画面背景
	{
		DrawGraph(0 + BACKSIDE_MARGIN, 0, titleback_gh, false);
	}

	if (se.playmode == PLAY || se.playmode == OVER)//プレイ画面背景
	{
		if (se.playmode == OVER)y = temp_y;
		if (se.playmode == OVER)x = temp_x;
		switch (pl.directionMode)
		{
		case 0://下から上
			if (y < -360)y = 0;
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playback_gh, true);
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playback_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;
			Drawdoor(pl);
			y -= scrollspeed /*+ scrollspeedsetter*/;//テスト用変更
			break;

		case 2://上から下
			if (y > 360)y = 0;
			DrawGraph(BACKSIDE_MARGIN, y, playback_gh, true);
			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y, playback_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;
			Drawdoor(pl);
			y += scrollspeed /*+ scrollspeedsetter*/;
			break;

		//case 1://左から右
		//	if (x > WINDOW_X)x = 0;
		//	DrawModiGraph(
		//		x, BACK_MARGIN,//左上
		//		WINDOW_X + x, BACK_MARGIN,//右上
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//右下
		//		x, WINDOW_Y - BACK_MARGIN,//左下
		//		playbackside_gh[0], false);
		//	DrawModiGraph(
		//		-WINDOW_X + x, BACK_MARGIN,
		//		x, BACK_MARGIN,
		//		x, WINDOW_Y - BACK_MARGIN,
		//		-WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[0], false);
		//	x += SCROLL_SPEED + scrollspeedsetter;
		//	break;

		//case 3://右から左
		//	if (x < -WINDOW_X)x = 0;
		//	DrawModiGraph(
		//		x, BACK_MARGIN,//左上
		//		WINDOW_X + x, BACK_MARGIN,//右上
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//右下
		//		x, WINDOW_Y - BACK_MARGIN,//左下
		//		playbackside_gh[0], false);
		//	DrawModiGraph(
		//		WINDOW_X + x, BACK_MARGIN,
		//		WINDOW_X * 2 + x, BACK_MARGIN,
		//		WINDOW_X * 2 + x, WINDOW_Y - BACK_MARGIN,
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[0], false);
		//	x -= SCROLL_SPEED + scrollspeedsetter;
		//	break;

		case 1://左から右
			if (x > WINDOW_X)x = 0;
			DrawGraph(x, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(-WINDOW_X + x, BACK_MARGIN, playbackside_gh[0], true);
			x += SCROLL_SPEED + scrollspeedsetter;
			break;

		case 3://右から左
			if (x < -WINDOW_X)x = 0;
			DrawGraph(x, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(WINDOW_X + x, BACK_MARGIN, playbackside_gh[0], true);
			x -= SCROLL_SPEED + scrollspeedsetter;
			break;
		}

		if (se.playmode == PLAY)temp_y = y;//死亡時点で画面止める（縦）
		if (se.playmode == PLAY)temp_x = x;
	}
}



void back::Drawbackfront(scene se, player pl)
{
	if (se.playmode == PLAY)//プレイ画面背景
	{
		switch (pl.directionMode)
		{
		case 0:
			if (y < -WINDOW_Y)y = 0;
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playbackedge_gh, true);
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playbackedge_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;//テスト
			//Drawdoor(pl);
			y -= scrollspeed + scrollspeedsetter;//テスト用変更
			break;

		case 2:
			if (y > WINDOW_Y)y = 0;
			DrawGraph(BACKSIDE_MARGIN, y, playbackedge_gh, true);
			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y, playbackedge_gh, true);
			//Drawdoor(pl);
			y += scrollspeed + scrollspeedsetter;
			break;

		//case 1://左から右
		//	if (fx > WINDOW_X)fx = 0;
		//	DrawModiGraph(
		//		fx, BACK_MARGIN,//左上
		//		WINDOW_X + fx, BACK_MARGIN,//右上
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//右下
		//		fx, WINDOW_Y - BACK_MARGIN,//左下
		//		playbackside_gh[1], true);
		//	DrawModiGraph(
		//		-WINDOW_X + fx, BACK_MARGIN,
		//		fx, BACK_MARGIN,
		//		fx, WINDOW_Y - BACK_MARGIN,
		//		-WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[1], true);
		//	fx += (SCROLL_SPEED + scrollspeedsetter*0.8);
		//	break;

		//case 3://右から左
		//	if (fx < -WINDOW_X)fx = 0;
		//	DrawModiGraph(
		//		fx, BACK_MARGIN,//左上
		//		WINDOW_X + fx, BACK_MARGIN,//右上
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//右下
		//		fx, WINDOW_Y - BACK_MARGIN,//左下
		//		playbackside_gh[1], true);
		//	DrawModiGraph(
		//		WINDOW_X + fx, BACK_MARGIN,
		//		WINDOW_X * 2 + fx, BACK_MARGIN,
		//		WINDOW_X * 2 + fx, WINDOW_Y - BACK_MARGIN,
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[1], true);
		//	fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);
		//	break;

		case 1://左から右
			if (fx > WINDOW_X)fx = 0;
			DrawGraph(fx, BACK_MARGIN, playbackside_gh[1], true);
			DrawGraph(-WINDOW_X + fx, BACK_MARGIN, playbackside_gh[1], true);
			fx += (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;

		case 3://右から左
			if (fx < -WINDOW_X)fx = 0;
			DrawGraph(fx, BACK_MARGIN, playbackside_gh[1], true);
			DrawGraph(WINDOW_X + fx, BACK_MARGIN, playbackside_gh[1], true);
			fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;

		}
		if (se.playmode == PLAY)temp_x = x;
	}
}



void back::Drawdoor(player pl)
{
	switch (doorFlg)
	{
	case false:
		anim_x = 0;
		//case0の分
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		//case2の分
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		break;

	case true:
		anim_x = (animCnt / 30) % 6;
		animCnt++;
		switch (pl.directionMode)
		{
		case 0:
			//左の扉が開く描画
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
			//右の扉が開く描画
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			break;
		case 2:
			//左の扉が開く描画
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			//右の扉が開く描画
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			break;
		}
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

void back::StopView()
{
	DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playback_gh, true);
	DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playback_gh, true);
}