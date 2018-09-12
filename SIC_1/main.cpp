#include"all.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{

	ChangeWindowMode(true);

	SetGraphMode(WINDOW_X, WINDOW_Y, 32);

	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);



	//�σX�N���[���T�C�Y

	SetGraphMode(WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, 32);//�`��ł���ő�̉𑜓x��ݒ�

	int windowSIze = MAX_WINDOW_EXTEND_RATE;//�E�B���h�E�g�嗦�̏����l

	int tempScreen = MakeScreen(WINDOW_X, WINDOW_Y, TRUE);//�`��\�ȉ���ʂ��쐬



	SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);



	srand((unsigned)time(NULL));

	player *pl = new player();
	block *bl = new block();
	back *bk = new back();
	obstacle *ob = new obstacle();
	scene *se = new scene();
	ui *pui = new ui();
	mu = new music();

	//34�ǉ�
	warpblock *warp = new warpblock();
	scenegame *scgame = new scenegame();


	bool spaceFlg = false;
	int testback_1;
	int testback_2;
	double rad = 0;
	int rad_rand;

	testback_1 = LoadGraph("Data/Image/SIC_1_back_test1.png");
	testback_2 = LoadGraph("Data/Image/SIC1_back_test2.png");


	SetFontSize(128);
	int color = GetColor(0, 155, 250);




	while (ProcessMessage() != -1)

	{

		//�L�[��ԍX�V //KB = �L�[�{�[�h //JOY = �W���C�p�b�h //[]�Ɏw��̃L�[�̒萔�����Ďg��
		gpUpdateKey();
		se->timer++;
		//����ʂɕ`��
		SetDrawScreen(tempScreen);
		ClearDrawScreen();
		clsDx();

		//�T�C�Y�ύX
		if (KB[KEY_INPUT_F11] == 1)
		{
			windowSIze++;
			windowSIze = windowSIze % (MAX_WINDOW_EXTEND_RATE + 1);
			if (windowSIze == 0)windowSIze = 1;
			SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);
		}

		//�ʒu�ύX

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

			ob->directionMode = PL_RIGHTSIDE_MODE;

			bk->fx = 0;

			bk->x = 0;

			pl->Direction();

			ob->GetPos();

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

			ob->directionMode = PL_LEFTSIDE_MODE;

			bk->fx = 0;

			bk->x = 0;

			pl->Direction();

			ob->GetPos();

		}



		if (CheckHitKey(KEY_INPUT_5))

		{

			pl->changeDirectionStartFlg = true;

		}







		if (CheckHitKey(KEY_INPUT_7))
		{
			pl->hp = 0;
		}

		if (CheckHitKey(KEY_INPUT_9))
		{
			warp->existFlg = true;
		}

		if (se->playmode == TITLE&&pl->pos_x >= 256 && KB[KEY_INPUT_Z] == 1 || JOY[XINPUT_BUTTON_A] == 1)

		{
			doplaymode(se);
			pl->Direction();
		}



		if (se->playmode == PLAY && !pl->changeDirectionModeFlg)

		{
			bk->All(*se, *pl);
			pui->All(*pl);
			if (pl->hp <= 0)
			{
				doovermode(se);
			}
		}



		if (se->playmode == OVER)
		{
			bk->All(*se, *pl);
			pui->All(*pl);
			pl->All(*se);
			bk->Drawbackfront(*se, *pl);
			se->Overmode(se);
			if (se->retryFlg == true)//�S�ď���������

			{

				pl->hp = 3;

				for (int i = 0; i < 9; i++)

				{

					pl->parts_x[i] = 0;

					pl->parts_y[i] = 0;

					pl->y_prev[i] = 0;

					pl->expFlg[i] = false;

				}

				pl->expCnt = 0;

				bl->blockFlg = false;

				ob->obstacleFlg = false;

				se->overselect = 0;

				doplaymode(se);

				se->retryFlg = false;

				bl->blockSpawnCnt = -150;

				bl->GetPos();

				ob->obstacleSpawnCnt = -120;

			}



		}





		//printfDx("%d", bk->scrollspeedsetter);



		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			delete pl;
			delete bl;
			delete bk;
			delete se;
			delete ob;
			delete pui;
			delete mu;
			delete scgame;

			DxLib_End();

			exit(true);
		}





		if (CheckHitKey(KEY_INPUT_SPACE) && spaceFlg == false)

		{

			switch (pl->directionMode)

			{

			case BLOCK_RISE_MODE:

			case BLOCK_FALL_MODE:

				//�u���b�N

				bl->blockFlg = true;

				break;



			case PL_RIGHTSIDE_MODE:

			case PL_LEFTSIDE_MODE:

				//�����[�h�̏�Q��

				ob->obstacleFlg = true;

				break;

			}



			spaceFlg = true;

		}



		if (se->playmode == PLAY && !pl->changeDirectionModeFlg && bl->blockSpawnCnt != bl->blockSpawnLimit)

		{

			bl->blockSpawnCnt++;

		}



		if (se->playmode == PLAY && !bl->blockFlg && bl->blockSpawnCnt == bl->blockSpawnLimit && !pl->changeDirectionModeFlg)

		{

			bl->blockFlg = true;

		}



		if (se->playmode == PLAY && !pl->changeDirectionModeFlg && ob->obstacleSpawnCnt != ob->obstacleSpawnLimit)

		{

			ob->obstacleSpawnCnt++;

		}



		if (se->playmode == PLAY && !ob->obstacleFlg && ob->obstacleSpawnCnt == ob->obstacleSpawnLimit && !pl->changeDirectionModeFlg)

		{

			ob->obstacleFlg = true;

		}

		//34�ǉ�
		if (warp->warpSpawnCnt != warp->warpSpawnLimit && se->playmode == PLAY && !pl->warpFlg)
		{
			warp->warpSpawnCnt++;
		}
		else if (warp->warpSpawnCnt == warp->warpSpawnLimit)
		{
			warp->warpSpawnCnt = 0;
			warp->existFlg = true;
		}





		//�c�̓����蔻��

		//�S�̓I�ɋC�����������邵�Ȃ�ł����ɏ����Ă�́H���Ԃ���ΏC��

		switch (pl->directionMode)

		{

		case BLOCK_RISE_MODE:

			if (check_hit_pos_y_rise(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0)

			{

				if (checkHitBlock(pl->pos_x, bl->pos_x))

				{

					pl->hitFlg = true;

					pl->combo_lim = COMBO_LIMIT;

					pl->combo++;

					bl->nextBlockMargin = pl->pos_y - (bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT));

					if (bl->blockExistMode > 0)

					{

						bl->blockExistMode--;

						pl->acceleration--;



						pl->hitstopCnt = checkHitStop(bl->blockNumber, bl->blockExistMode);



					}



					if (pl->acceleration <= 0 && pl->hitstopFlg)

					{
						//�_���[�W��

						pl->combo_lim = 0;

						pl->hp--;

						pl->damageFlg = true;

					}

				}

			}

			//34�ǉ�
			if (check_hit_pos_y_warpblock(pl->pos_y, warp->pos_y))
			{
				if (checkHitWarp(pl->pos_x, warp->pos_x))
				{
					pl->warpFlg = true;
					warp->existFlg = false;
					warp->GetPos();
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



					if (pl->acceleration <= 0)
					{
						//�_���[�W��
						pl->acceleration = 0;
						pl->hp--;
						pl->damageFlg = true;
					}
				}
			}
			break;



		case PL_RIGHTSIDE_MODE:

			if (check_hit_pos_x_goright(pl->pos_x, ob->pos_x) && !pl->damageFlg && !pl->changeDirectionModeFlg)
			{
				if (checkHitObstacle(pl->pos_y, ob->pos_y))
				{
					pl->damageFlg = true;
					pl->hp--;
				}
			}

			//34�ǉ�
			if (warp->autoWarpLimit > 0)
			{
				warp->autoWarpLimit--;
			}
			else if (warp->autoWarpLimit == 0)
			{
				pl->warpFlg = true;
			}

			break;

		case PL_LEFTSIDE_MODE:

			if (check_hit_pos_x_goleft(pl->pos_x, ob->pos_x) && !pl->damageFlg && !pl->changeDirectionModeFlg)
			{
				if (checkHitObstacle(pl->pos_y, ob->pos_y))
				{
					pl->damageFlg = true;
					pl->hp--;
				}
			}

			//34�ǉ�
			if (warp->autoWarpLimit > 0)
			{
				warp->autoWarpLimit--;
			}
			else if (warp->autoWarpLimit == 0)
			{
				pl->warpFlg = true;
			}
			break;

		default:
			break;
		}



		if (pl->combo > 0 && pl->hitFlg)

		{

			pl->score += pl->combo * SCORE_INC;

		}



		if (pl->combo <= 0)

		{

			pl->score = 0;

		}



		if (!pl->changeDirectionModeFlg)

		{

			HitStop(*bl, *pl);

		}



		if (pl->hitstopFlg)

		{

			bk->HitStop(*se, *pl);

		}

		else if (!pl->changeDirectionModeFlg && (se->playmode == PLAY || se->playmode == TITLE))

		{

			if (bk->scrollspeed < SCROLL_SPEED)

			{

				bk->scrollspeed = SCROLL_SPEED;

			}

			bk->All(*se, *pl);

		}



		if (se->playmode == PLAY && !pl->changeDirectionModeFlg)

		{

			pl->hitstopCnt--;

			if (pl->changeDirectionModeCnt != pl->changeDirectionModeLimit)

			{

				pl->changeDirectionModeCnt++;

			}

		}


		if (se->playmode == PLAY && pl->warpFlg && bl->speed != 0 && !pl->hitstopFlg /*&& !bl->blockFlg && !ob->obstacleFlg*/)

		{

			if (bl->blockFlg != false && ob->obstacleFlg != false)

			{

				bl->blockFlg = false;

				ob->obstacleFlg = false;

			}

			switch (pl->directionMode)

			{

			case BLOCK_RISE_MODE:

			case BLOCK_FALL_MODE:
					changeDirectionMode(*bk, *pl, *se, *scgame);

					if (!pl->changeDirectionModeFlg)

					{

						bl->blockFlg = false;

						ob->obstacleFlg = false;

						pl->Direction();

						ob->obstacleSpawnCnt = -120;

						ob->directionMode = pl->directionMode;

						ob->GetPos();
						warp->existFlg = false;

				}
				break;



			case PL_RIGHTSIDE_MODE:

			case PL_LEFTSIDE_MODE:

				changeDirectionModeDown(*bk, *pl, *se);
				if (!pl->changeDirectionModeFlg)
				{
					bl->blockSpawnCnt = -120;
					ob->obstacleFlg = false;
					bl->GetPos();
					bl->blockFlg = false;
					ob->directionMode = pl->directionMode;
					ob->GetPos();

					//34�ǉ�
					warp->warpSpawnCnt = 0;
					warp->warpSpawnLimit = WARP_SPAWN_LIMIT;
					warp->autoWarpLimit = AUTO_WARP_LIMIT;
					warp->existFlg = false;
					warp->GetPos();
				}

				break;
			}
		}

		if (pl->combo > 0 && pl->hitFlg)
		{
			pl->score += pl->combo * SCORE_INC;
		}

		if (pl->combo_lim <= 0)
		{
			pl->combo = 0;
		}
		else
		{
			pl->combo_lim--;
		}
		pui->combo_by_pl = pl->combo;
		pui->combo_lim_by_pl = pl->combo_lim;
		pui->score_by_pl = pl->score;

		pl->hitFlg = false;



		//�u���b�N�t���O�Ǘ�

		if (bl->blockFlg && pl->directionMode == BLOCK_RISE_MODE)

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

					bl->blockSpawnCnt = 0;

					bl->blockSpawnLimit = getBlockSpawnLimit(bl->first, bl->second, bl->third, bl->fourth);

				}

				break;



			case BLOCK_FALL_MODE:

				if (bl->pos_y > WINDOW_Y - BLOCK_OUT_POS_Y)

				{

					bl->blockFlg = false;

					bl->GetPos();

					bl->blockSpawnCnt = 0;

					bl->blockSpawnLimit = getBlockSpawnLimit(bl->first, bl->second, bl->third, bl->fourth);

				}

				break;



			default:

				break;

			}

		}





		//��Q���t���O�Ǘ�

		if (ob->obstacleFlg && !pl->directionMode == BLOCK_RISE_MODE)

		{

			ob->Move();

			ob->View();

			switch (ob->directionMode)

			{

			case PL_RIGHTSIDE_MODE:

				if (ob->pos_x > WINDOW_X + OBSTACLE_WIDTH)

				{

					ob->obstacleFlg = false;

					ob->GetPos();

					ob->obstacleSpawnLimit = getObstacleSpawnLimit(ob->first, ob->second, ob->third, ob->fourth);

					ob->obstacleSpawnCnt = 0;

				}

				break;



			case PL_LEFTSIDE_MODE:

				if (ob->pos_x < OBSTACLE_WIDTH)

				{

					ob->obstacleFlg = false;

					ob->GetPos();

					ob->obstacleSpawnLimit = getObstacleSpawnLimit(ob->first, ob->second, ob->third, ob->fourth);

					ob->obstacleSpawnCnt = 0;

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

		//34�ǉ�
		if (warp->existFlg && pl->directionMode == BLOCK_RISE_MODE && !pl->warpFlg)
		{
			warp->All();
		}


		if (!pl->changeDirectionModeFlg && (se->playmode == PLAY || se->playmode == TITLE))

		{

			pl->All(*se);

			bk->Drawbackfront(*se, *pl);

		}



		//�������O��Ƃ��̊֌W�œ����ƍ��̂Ƃ��낿�傤�ǂ������ǁA������������ǂ��ɂ��Ȃ邩������Ȃ����A���邢�͂ǂ��ɂ��Ȃ�Ȃ���������Ȃ�



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
			else if (pl->invincibleFlg && !pl->damageFlg && !pl->changeDirectionModeFlg)
			{
				pl->invincibleFlg = false;
			}
			break;

		default:
			break;
		}

		//����ʂ�`��

		SetDrawScreen(DX_SCREEN_BACK);
		DrawExtendGraph(0, 0, WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, tempScreen, FALSE);

		ScreenFlip();
	}


	delete pl;
	delete bl;
	delete bk;
	delete ob;
	delete se;
	delete pui;
	delete mu;
	delete scgame;


	DxLib_End();

	return 0;

}