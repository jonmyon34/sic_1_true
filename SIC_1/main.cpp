#include"all.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	player *pl = new player();
	block *bl = new block();

	bool spaceFlg = false;
	int testback;
	double rad = 0;
	int rad_rand;
	testback = LoadGraph("SIC_1_back_test1.png");


	SetFontSize(128);
	int color = GetColor(0, 155, 250);



	srand((unsigned)time(NULL));


	while (ProcessMessage() != -1)
	{
		DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback, true, false);


		printfDx("%d", pl->acceleration);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			delete pl;
			delete bl;

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


			//ブロック
			bl->blockFlg = true;


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
			if (check_hit_pos_y_fall(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0)
			{
				if (checkHitBlock(pl->pos_x, bl->pos_x))
				{
					pl->hitFlg = true;
					bl->nextBlockMargin = pl->pos_y - bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT);
					if (bl->blockExistMode > 0)
					{
						bl->blockExistMode--;
						pl->acceleration--;
					}

					if (pl->acceleration <= 0)
					{
						pl->hp--;
						pl->damageFlg = true;
					}
				}
			}
			break;


		default:
			break;
		}


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

			default:
				break;
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



		//位置変更
		if (CheckHitKey(KEY_INPUT_0))
		{
			pl->directionMode = BLOCK_RISE_MODE;
			bl->directionMode = BLOCK_RISE_MODE;
			pl->Direction();
		}

		if (CheckHitKey(KEY_INPUT_2))
		{
			pl->directionMode = BLOCK_FALL_MODE;
			bl->directionMode = BLOCK_FALL_MODE;
			pl->Direction();
		}

		ScreenFlip();
		ClearDrawScreen();
	}


	delete pl;
	delete bl;


	DxLib_End();

	return 0;
}