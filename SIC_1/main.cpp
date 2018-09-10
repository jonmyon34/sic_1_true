#include"all.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//可変スクリーンサイズ
	SetGraphMode(WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, 32);//描画できる最大の解像度を設定
	int windowSIze = MAX_WINDOW_EXTEND_RATE;//ウィンドウ拡大率の初期値
	int tempScreen = MakeScreen(WINDOW_X, WINDOW_Y, TRUE);//描画可能な仮画面を作成

	SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);


	player *pl = new player();
	player ppl;
	block *bl = new block();
	back *bk = new back();
	obstacle *ob = new obstacle();
	scene *se = new scene();

	bool spaceFlg = false;
	int testback_1;
	int testback_2;
	double rad = 0;
	int rad_rand;

	testback_1 = LoadGraph("Data/Image/SIC_1_back_test1.png");
	testback_2 = LoadGraph("Data/Image/SIC1_back_test2.png");

	SetFontSize(128);
	int color = GetColor(0, 155, 250);



	srand((unsigned)time(NULL));


	while (ProcessMessage() != -1)
	{
		//キー状態更新 //KB = キーボード //JOY = ジョイパッド //[]に指定のキーの定数を入れて使う
		gpUpdateKey();

		//仮画面に描画
		SetDrawScreen(tempScreen);

		//todo
		//

		//サイズ変更
		if (KB[KEY_INPUT_F11] == 1)
		{
			windowSIze++;
			windowSIze = windowSIze % (MAX_WINDOW_EXTEND_RATE + 1);
			if (windowSIze == 0)windowSIze = 1;
			SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);
		}


		switch (pl->directionMode)
		{
		case BLOCK_RISE_MODE:
		case BLOCK_FALL_MODE:
			DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback_1, true, false);
			break;

		case PL_RIGHTSIDE_MODE:
		case PL_LEFTSIDE_MODE:
			DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback_2, true, false);
			break;

		default:
			break;
		}


		//位置変更
		if (CheckHitKey(KEY_INPUT_0))
		{
			pl->directionMode = BLOCK_RISE_MODE;
			bl->directionMode = BLOCK_RISE_MODE;
			bk->y = 0;
			pl->Direction();
			bl->GetPos();
		}

		if (CheckHitKey(KEY_INPUT_1))
		{
			pl->directionMode = PL_RIGHTSIDE_MODE;
			bk->fx = 0;
			bk->x = 0;
			pl->Direction();
		}

		if (CheckHitKey(KEY_INPUT_2))
		{
			pl->directionMode = BLOCK_FALL_MODE;
			bl->directionMode = BLOCK_FALL_MODE;
			bk->y = 0;
			pl->Direction();
			bl->GetPos();
		}

		if (CheckHitKey(KEY_INPUT_3))
		{
			pl->directionMode = PL_LEFTSIDE_MODE;
			bk->fx = 0;
			bk->x = 0;
			pl->Direction();
		}

		if (CheckHitKey(KEY_INPUT_7))
		{
			pl->hp = 0;
		}

		if (se->playmode == TITLE&&pl->pos_x >= 800)
		{
			doplaymode(se);
		}

		if (se->playmode == PLAY)
		{
			pl->All();
			bk->All(*se, *pl);
		}


		printfDx("%d", bk->scrollspeedsetter);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			delete pl;
			delete bl;
			delete bk;
			delete se;
			delete ob;

			exit(true);

		}


		if (CheckHitKey(KEY_INPUT_SPACE) && spaceFlg == false)
		{
			//初期位置調整
			//pl->directionMode++;
			//rad_rand = rand() % 4;
			//rad = (DX_PI / 2)* rad_rand;
			//pl->pos_x = direction_pl_pos_x(rad_rand);
			//pl->pos_y = direction_pl_pos_y(rad_rand);

			switch (pl->directionMode)
			{
			case BLOCK_RISE_MODE:
			case BLOCK_FALL_MODE:
				//ブロック
				bl->blockFlg = true;

			case PL_RIGHTSIDE_MODE:
			case PL_LEFTSIDE_MODE:
				//横モードの障害物
				ob->obstacleFlg = true;
			}


			spaceFlg = true;
		}


		//縦の当たり判定
		//全体的に気持ち悪すぎるしなんでここに書いてんの？時間あれば修正
		switch (pl->directionMode)
		{
		case BLOCK_RISE_MODE:
			if (check_hit_pos_y_rise(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0)
			{
				if (checkHitBlock(pl->pos_x, bl->pos_x))
				{
					pl->hitFlg = true;
					bl->nextBlockMargin = pl->pos_y - (bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT));
					if (bl->blockExistMode > 0)
					{
						bl->blockExistMode--;
						pl->acceleration--;

						pl->hitstopCnt = checkHitStop(bl->blockNumber, bl->blockExistMode);

					}

					if (pl->acceleration <= 0)
					{
						pl->hp--;
						pl->damageFlg = true;
					}

				}
			}
			break;

		case BLOCK_FALL_MODE:
			if (check_hit_pos_y_fall(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0 && !pl->damageFlg)
			{
				if (checkHitBlock(pl->pos_x, bl->pos_x))
				{
					pl->hitFlg = true;
					bl->nextBlockMargin = pl->pos_y - bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT);
					if (bl->blockExistMode > 0)
					{
						bl->blockExistMode--;
						pl->acceleration--;

						pl->hitstopCnt = checkHitStop(bl->blockNumber, bl->blockExistMode);

					}

					if (pl->acceleration <= 0 )
					{
						pl->acceleration = 0;
						pl->hp--;
						pl->damageFlg = true;
					}
				}
			}
			break;

		case PL_RIGHTSIDE_MODE:
			if (check_hit_pos_x_goright(pl->pos_x, ob->pos_x) && !pl->damageFlg)
			{
				if (checkHitObsacle(pl->pos_y, ob->pos_y))
				{
					pl->damageFlg = true;
					pl->hp--;
				}
			}


		default:
			break;
		}

		//背景
		HitStop(*bl, *pl);

		if (pl->hitstopFlg)
		{
			bk->HitStop(*se, *pl);
		}
		else
		{
			if (bk->scrollspeed < SCROLL_SPEED)
			{
				bk->scrollspeed = SCROLL_SPEED;
			}
			bk->All(*se, *pl);
		}

		pl->hitstopCnt--;



		//ブロックフラグ管理
		if (bl->blockFlg)
		{
			bl->Move();
			bl->ExistCheck();
			bl->View();
			switch (bl->directionMode)
			{
			case BLOCK_RISE_MODE:
				if (bl->pos_y < BLOCK_OUT_POS_Y)
				{
					bl->blockFlg = false;
					bl->GetPos();
				}
				break;

			case BLOCK_FALL_MODE:
				if (bl->pos_y > WINDOW_Y - BLOCK_OUT_POS_Y)
				{
					bl->blockFlg = false;
					bl->GetPos();
				}
				break;

			default:
				break;
			}
		}


		//障害物フラグ管理
		if (ob->obstacleFlg)
		{
			ob->Move();
			ob->View();
			switch (ob->directionMode)
			{
			case PL_RIGHTSIDE_MODE:
				if (ob->pos_x > WINDOW_X + OBSTACLE_OUT_POS_X)
				{
					ob->obstacleFlg = false;
					ob->GetPos();
				}
				break;

			case PL_LEFTSIDE_MODE:
				if (ob->pos_x < -OBSTACLE_OUT_POS_X)
				{
					ob->obstacleFlg = false;
					ob->GetPos();
				}
			}
			
		}


		switch (bl->directionMode)
		{
		case BLOCK_RISE_MODE:
			if (pl->hitFlg && pl->pos_y < bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) && !pl->invincibleFlg)
			{
				pl->invincibleFlg = true;
			}
			else if (pl->invincibleFlg && !pl->damageFlg)
			{
				pl->invincibleFlg = false;
			}
			break;

		case BLOCK_FALL_MODE:
			if (pl->hitFlg && pl->pos_y > bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) + BLOCK_HEIGHT && !pl->invincibleFlg)
			{
				pl->invincibleFlg = true;
			}
			else if (pl->invincibleFlg && !pl->damageFlg)
			{
				pl->invincibleFlg = false;
			}
			break;

		default:
			break;
		}


		if (!CheckHitKey(KEY_INPUT_SPACE))
		{
			spaceFlg = false;
		}


		pl->All();
		bk->Drawbackfront(*se, *pl);


		//動いた前後とかの関係で二回やると今のところちょうどいいけど、もしかしたらどうにかなるかもしれないし、あるいはどうにもならないかもしれない

		switch (bl->directionMode)
		{
		case BLOCK_RISE_MODE:
			if (pl->hitFlg && pl->pos_y < bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) && !pl->invincibleFlg)
			{
				pl->invincibleFlg = true;
			}
			else if (pl->invincibleFlg && !pl->damageFlg)
			{
				pl->invincibleFlg = false;
			}
			break;

		case BLOCK_FALL_MODE:
			if (pl->hitFlg && pl->pos_y > bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) + BLOCK_HEIGHT && !pl->invincibleFlg)
			{
				pl->invincibleFlg = true;
			}
			else if (pl->invincibleFlg && !pl->damageFlg)
			{
				pl->invincibleFlg = false;
			}
			break;

		default:
			break;
		}




		//仮画面を描画
		SetDrawScreen(DX_SCREEN_BACK);
		DrawExtendGraph(0, 0, WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, tempScreen, FALSE);

		ScreenFlip();
		ClearDrawScreen();
	}


	delete pl;
	delete bl;
	delete bk;
	delete ob;
	delete se;


	DxLib_End();

	return 0;
}