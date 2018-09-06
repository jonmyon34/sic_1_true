
#define PL_WIDTH 28
#define PL_HEIGHT 28
#define PL_SPEED_MAX 9
#define PL_SPEED_INC 0.2


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

bool checkHitBlock(int, int);


class player
{
public:
	int x, y, pos_x, pos_y, width, height;
	float speed;
	int fallVelocity;
	int acceleration;

	int hp;

	int item;

	bool hitFlg;
	bool damageFlg;

	int directionMode;
	bool invincibleFlg;

	int player_gh;

	int flashCnt;
	int acceleCnt;

	bool plLiveFlg;

	player()
	{
		x = WINDOW_X / 2;
		y = WINDOW_Y / 3;
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y / 3;
		width = PL_WIDTH;
		height = PL_HEIGHT;

		speed = 0;
		acceleration = 1;

		hp = 3;

		hitFlg = false;
		damageFlg = false;
		directionMode = 0;
		invincibleFlg = false;


		player_gh = LoadGraph("player1.png");

		flashCnt = 0;
		acceleCnt = 0;

	}

	void Move()
	{

		switch (directionMode % 2)
		{
		case 0:

			if (CheckHitKey(KEY_INPUT_LEFT))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_x = pos_x - speed;
			}

			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_x = pos_x + speed;
			}

			if (!CheckHitKey(KEY_INPUT_RIGHT) && !CheckHitKey(KEY_INPUT_LEFT))
			{
				speed = 0;
			}


			break;


		case 1:

			if (CheckHitKey(KEY_INPUT_UP))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_y = pos_y - speed;
			}

			if (CheckHitKey(KEY_INPUT_DOWN))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_y = pos_y + speed;
			}

			if (!CheckHitKey(KEY_INPUT_UP) && !CheckHitKey(KEY_INPUT_DOWN))
			{
				speed = 0;
			}


			break;


		default:
			break;
		}

	}

	void View()
	{
		switch (damageFlg)
		{
		case false:
		DrawRectGraph(pos_x, pos_y, 0, 0, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
		break;

		case true:
			if (((flashCnt / 10) % 2)&&flashCnt<FLASHCNT_MAX)
			{
				DrawRectGraph(pos_x, pos_y, 0, 0, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
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

		}
	}

	void Accele()
	{
		if (acceleCnt >= 120)
		{
			acceleration++;
			acceleCnt = 0;
		}
		else
		{
			acceleCnt++;
		}

		if (hitFlg && !invincibleFlg)
		{
			acceleration--;
			invincibleFlg = true;
		}
	}

	void All()
	{
		Move();
		View();
		Accele();
	}



};



int direction_pl_pos_x(int);
int direction_pl_pos_y(int);

