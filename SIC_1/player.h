
#define PL_WIDTH 28
#define PL_HEIGHT 28
#define PL_SPEED_MAX 9
#define PL_SPEED_INC 0.2

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

bool check_hit_pos_y_rise(int, int, int, int);
bool check_hit_pos_y_fall(int, int, int, int);
bool checkHitBlock(int, int);
int direction_pl_pos_x(int);
int direction_pl_pos_y(int);


class player
{
public:
	int x, y, pos_x, pos_y, width, height;
	float speed;
	int fallVelocity;
	int acceleration;

	int hp;

	int item;

	int anim_x, anim_y;

	bool hitFlg;
	bool damageFlg;

	int directionMode;
	bool invincibleFlg;

	int player_gh;
	int player_gh_death;

	int flashCnt;
	int acceleCnt;
	int animCnt;

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



		player_gh = LoadGraph("Data/Image/player1.png");
		player_gh_death = LoadGraph("Data/Image/Pl_ps.png");

		anim_x = 0;
		anim_y = 0;

		flashCnt = 0;
		acceleCnt = 0;
		animCnt = 0;

	}

	void Move()
	{

		switch (directionMode)
		{
		case BLOCK_RISE_MODE:
		case BLOCK_FALL_MODE:

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


		case PL_RIGHTSIDE_MODE:
		case PL_LEFTSIDE_MODE:

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
		if (hp > 0)
		{
			switch (damageFlg)
			{
			case false:
				if (acceleration == PL_MAX_ACCELERATION)
				{
					anim_x = (animCnt / 5) % 8;
					anim_y = PL_HEIGHT;
					animCnt++;
					DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
				}
				else
				{
					anim_x = (animCnt / 5) % 5;
					anim_y = 0;
					animCnt++;
					DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
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

			}
		}
		else
		{
			//éÄñSÇﬁÅ[Ç‘
			DrawRectGraph(pos_x, pos_y, 0, 0, PL_WIDTH, PL_HEIGHT, player_gh_death, true, false);
		}
	}

	void Accele()
	{
		if (acceleration < PL_MAX_ACCELERATION)
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

	void All()
	{
		Move();
		View();
		Accele();
	}



};



int direction_pl_pos_x(int);
int direction_pl_pos_y(int);

