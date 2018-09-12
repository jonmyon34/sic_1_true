
#define PL_WIDTH 28

#define PL_HEIGHT 28

#define PL_SPEED_MAX 6

#define PL_SPEED_INC 0.5



#define BLOCK_RISE_MODE 0

#define BLOCK_FALL_MODE 2



#define PL_RIGHTSIDE_MODE 1

#define PL_LEFTSIDE_MODE 3



//å¸Ç´Ç…ëŒÇµÇƒÇÃèâä˙à íu

#define PL_UP_FIRST_X WINDOW_X/2

#define PL_UP_FIRST_Y WINDOW_Y/3



#define PL_DOWN_FIRST_X WINDOW_X/2

#define PL_DOWN_FIRST_Y WINDOW_Y/3*2



#define PL_LEFT_FIRST_X WINDOW_X/4

#define PL_LEFT_FIRST_Y WINDOW_Y/2



#define PL_RIGHT_FIRST_X WINDOW_X/4*3

#define PL_RIGHT_FIRST_Y WINDOW_Y/2



#define PL_MAX_ACCELERATION 6



#define PL_HITSTOP_VAL 12



#define EXPLOSIVE_POWER 15

#define EXPLOSION_MARGIN 17

#define PL_PARTS_START 63



#define ACCELE_INC_TIME 60





bool check_hit_pos_y_rise(int, int, int, int);

bool check_hit_pos_y_fall(int, int, int, int);

bool check_hit_pos_x_goright(int, int);

bool check_hit_pos_x_goleft(int, int);

bool checkHitBlock(int, int);

bool checkHitObstacle(int, int);

int checkHitStop(int, int);

int direction_pl_pos_x(int);

int direction_pl_pos_y(int);

float sign(float n);

int getChangeDirectionModeLimit(int, int, int, int);





class player

{

public:

	int x, y, pos_x, pos_y, width, height;

	float speed_x;
	float speed_y;
	int fallVelocity;

	int acceleration;

	float targetSpeed_x;//Ç©ÇÌÇ‡Ç∆
	float targetSpeed_y;//Ç©ÇÌÇ‡Ç∆

	int direction_x;//Ç©ÇÌÇ‡Ç∆
	int direction_y;//Ç©ÇÌÇ‡Ç∆

	int accelerationTmp;



	int hp;



	int item;



	int anim_x, anim_y;



	bool hitFlg;

	bool damageFlg;

	bool changeDirectionModeFlg;

	bool changeDirectionStartFlg;



	int directionMode;

	int changeDirectionMode;

	int changeDirectionModeCnt;

	int changeDirectionModeLimit;

	bool invincibleFlg;



	int score;

	int combo;

	int combo_lim;



	int player_gh;

	int player_UP_gh;

	int player_gh_death;



	//éÄñSéûä÷òA



	int exp_gh;



	int player_gh_parts[18 * 6];

	int expCnt;

	int parts_x[9] = { 0 };

	double parts_y[9] = { 0 };

	bool expFlg[9] = { 0 };

	double y_temp[9] = { 0 };

	double y_prev[9] = { 0 };

	int exp_x;

	int rngvalue[9];



	int flashCnt;

	int acceleCnt;

	int animCnt;

	int hitstopCnt;



	bool plLiveFlg;
	bool hitstopFlg;
	bool warpFlg;


	int first, second, third, fourth;



	player()

	{

		x = WINDOW_X / 2;

		y = WINDOW_Y / 3;

		pos_x = WINDOW_X / 2;

		pos_y = 124;

		width = PL_WIDTH;

		height = PL_HEIGHT;



		speed_x = 0;
		speed_y = 0;

		acceleration = 1;

		targetSpeed_x = 0;//Ç©ÇÌÇ‡Ç∆
		direction_x = 0;//Ç©ÇÌÇ‡Ç∆
		targetSpeed_y = 0;//Ç©ÇÌÇ‡Ç∆
		direction_y = 0;//Ç©ÇÌÇ‡Ç∆

		accelerationTmp = 1;



		hp = 3;



		hitFlg = false;

		damageFlg = false;

		changeDirectionStartFlg = false;

		changeDirectionModeFlg = false;



		first = 0;

		second = 0;

		third = 0;

		fourth = 0;



		score = 0;

		combo = 0;

		combo_lim = 0;



		directionMode = 0;

		changeDirectionMode = 0;

		changeDirectionModeCnt = 0;

		changeDirectionModeLimit = getChangeDirectionModeLimit(first, second, third, fourth);

		invincibleFlg = false;



		hitstopFlg = false;
		warpFlg = false;



		for (int i = 0; i < 9; i++)

		{

			rngvalue[i] = rand() % 4 * 3;

		}







		player_gh = LoadGraph("Data/Image/player1.png");

		player_UP_gh = LoadGraph("Data/Image/player1_UP.png");

		player_gh_death = LoadGraph("Data/Image/Pl_ps.png");

		exp_gh = LoadGraph("Data/Image/effect1.png");



		anim_x = 0;

		anim_y = 0;



		flashCnt = 0;

		acceleCnt = 0;

		animCnt = 0;

		hitstopCnt = 0;



		expCnt = 0;

		exp_x = 0;



	}



	void Move()

	{



		switch (directionMode)

		{

		case BLOCK_RISE_MODE:

		case BLOCK_FALL_MODE:

			targetSpeed_x = 0;//Ç©ÇÌÇ‡Ç∆
			targetSpeed_y = 0;//Ç©ÇÌÇ‡Ç∆

			if (CheckHitKey(KEY_INPUT_LEFT))
			{

				targetSpeed_x += -PL_SPEED_MAX;

			}

			if (CheckHitKey(KEY_INPUT_RIGHT))
			{

				targetSpeed_x += PL_SPEED_MAX;

			}

			if (CheckHitKey(KEY_INPUT_UP))
			{
				if (pos_y > 32)
				{
					targetSpeed_y += -PL_SPEED_MAX;
				}
			}
			if (CheckHitKey(KEY_INPUT_DOWN))
			{
				if (pos_y < WINDOW_CENTER_Y + 46)
				{
					targetSpeed_y += PL_SPEED_MAX;
				}
			}

			//Controller
			if (inputJoy.ThumbLX < 0)
			{

				targetSpeed_x += -PL_SPEED_MAX * fabsf((inputJoy.ThumbLX / 32767.f));

			}

			if (inputJoy.ThumbLX > 0)
			{

				targetSpeed_x += PL_SPEED_MAX * fabsf((inputJoy.ThumbLX / 32767.f));

			}

			if (inputJoy.ThumbLY > 0)
			{
				if (pos_y > 32)
				{
					targetSpeed_y += -PL_SPEED_MAX * fabsf((inputJoy.ThumbLY / 32767.f));
				}
			}
			if (inputJoy.ThumbLY < 0)
			{
				if (pos_y < WINDOW_CENTER_Y + 46)
				{
					targetSpeed_y += PL_SPEED_MAX * fabsf((inputJoy.ThumbLY / 32767.f));
				}
			}

			printfDx("\nspeed %.2f , %.2f\n", speed_x, speed_y);
			printfDx("\nthumb %.2f , %.2f\n", (inputJoy.ThumbLX / 32767.f), (inputJoy.ThumbLY / 32767.f));

			//Ç©ÇÌÇ‡Ç∆x
			direction_x = sign(targetSpeed_x - speed_x);
			speed_x += PL_SPEED_INC * direction_x;

			if (sign(targetSpeed_x - speed_x) != direction_x)speed_x = targetSpeed_x;
			pos_x += (int)speed_x;

			//Ç©ÇÌÇ‡Ç∆y
			direction_y = sign(targetSpeed_y - speed_y);
			speed_y += PL_SPEED_INC * direction_y;

			if (sign(targetSpeed_y - speed_y) != direction_y)speed_y = targetSpeed_y;
			pos_y += (int)speed_y;

			if (pos_x < WINDOW_CENTER_X - (BACK_WIDTH / 2) + 16)
			{
				pos_x = WINDOW_CENTER_X - (BACK_WIDTH / 2) + 16;
			}
			if (pos_x > WINDOW_CENTER_X + ((BACK_WIDTH / 2) - 42))
			{
				pos_x = WINDOW_CENTER_X + ((BACK_WIDTH / 2) - 42);
			}

			if (pos_y < 0)
			{
				pos_y = 0;
			}
			if (pos_y > WINDOW_CENTER_Y + 46 + 16)
			{
				pos_y = WINDOW_CENTER_Y + 46 + 16;
			}

			printfDx("\nposy : %d\n", pos_y);

			break;





		case PL_RIGHTSIDE_MODE:

		case PL_LEFTSIDE_MODE:



			if (CheckHitKey(KEY_INPUT_UP))

			{

				if (speed_x < PL_SPEED_MAX)

				{

					speed_x += PL_SPEED_INC;

				}



				pos_y = pos_y - speed_x;

			}



			if (CheckHitKey(KEY_INPUT_DOWN))

			{

				if (speed_x < PL_SPEED_MAX)

				{

					speed_x += PL_SPEED_INC;

				}



				pos_y = pos_y + speed_x;

			}



			if (!CheckHitKey(KEY_INPUT_UP) && !CheckHitKey(KEY_INPUT_DOWN))

			{

				speed_x = 0;

			}





			break;





		default:

			break;

		}





	}



	void View()

	{

		if (hp > 0)

		{

			switch (damageFlg)

			{

			case false:

				switch (directionMode)
				{
				case BLOCK_RISE_MODE:
					DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
					break;
				case PL_RIGHTSIDE_MODE:
					DrawRectRotaGraph(pos_x, pos_y+10, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*0.5, player_gh, true, false);
					break;
				case BLOCK_FALL_MODE:
					DrawRectGraph(pos_x, pos_y, 503 - PL_WIDTH - (anim_x*PL_WIDTH), 167 - PL_HEIGHT * 2, PL_WIDTH, PL_HEIGHT, player_UP_gh, true, false);
					break;
				case PL_LEFTSIDE_MODE:
					DrawRectRotaGraph(pos_x, pos_y+10, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*1.5, player_gh, true, false);
					break;
				default:
					break;
				}

				break;



			case true:

				if (((flashCnt / 10) % 2) && flashCnt < FLASHCNT_MAX)

				{

					anim_x = (animCnt / 5) % 4;

					anim_y = PL_HEIGHT * 2;

					animCnt++;

					DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

					flashCnt++;

				}

				else if (flashCnt >= FLASHCNT_MAX)

				{

					damageFlg = false;

					invincibleFlg = false;

					flashCnt = 0;

				}

				else

				{

					flashCnt++;

				}

				break;

			}

		}

		else

		{

			//éÄñSÇﬁÅ[Ç‘



			LoadDivGraph("Data/Image/player1.png", 18 * 6, 18, 6, PL_WIDTH, PL_HEIGHT, player_gh_parts);

			DrawRectGraph(pos_x - EXPLOSION_MARGIN, pos_y - EXPLOSION_MARGIN, exp_x * 64, 0, 64, 64, exp_gh, true);



			expCnt++;

			exp_x = expCnt / 3;



			for (int i = 0; i < 9; i++)

			{

				switch (i % 2)

				{

				case 1:

					parts_x[i] += expCnt / 20;

					break;



				case 0:

					parts_x[i] -= expCnt / 20;

					break;

				}



				if (expFlg[i] == false)



				{

					y_prev[i] = parts_y[i];

					parts_y[i] = parts_y[i] - (rngvalue[i]);//EXPLOSIVE_POWER

					expFlg[i] = true;

				}

				else

				{

					y_temp[i] = parts_y[i];

					parts_y[i] += (parts_y[i] - y_prev[i]) + 0.35;

					y_prev[i] = y_temp[i];

				}

				DrawRotaGraph(pos_x + parts_x[i], pos_y + parts_y[i], 1, expCnt / 3, player_gh_parts[PL_PARTS_START + i], true);

			}

		}

	}



	void StopView()

	{

		DrawRectGraph(pos_x, pos_y, 0, 0, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

	}



	void Accele(scene se)

	{

		if (acceleration < PL_MAX_ACCELERATION && se.playmode == PLAY)

		{

			if (acceleCnt >= ACCELE_INC_TIME)

			{

				acceleration++;

				acceleCnt = 0;

			}

			else

			{

				acceleCnt++;

			}

		}

		//if (hitFlg && !invincibleFlg)

		//{

		//	acceleration--;

		//	invincibleFlg = true;

		//}

	}



	void Direction()

	{

		pos_x = direction_pl_pos_x(directionMode);

		pos_y = direction_pl_pos_y(directionMode);

	}



	void All(scene se)

	{

		Move();

		View();

		Accele(se);

	}







};







int direction_pl_pos_x(int);

int direction_pl_pos_y(int);

//34í«â¡
bool check_hit_pos_y_warpblock(int, int);
bool checkHitWarp(int, int);

