#define OBSTACLE_WIDTH 16
#define OBSTACLE_HEIGHT 16
#define OBSTACLE_SPEED 6

int getObstacleRandPos_y();
int getObstacleSpawnLimit(int, int, int, int);

class obstacle
{
public:
	int pos_x, pos_y, width, height;
	int speed;


	int obstacle_gh;
	int obstacle_re_gh;

	int directionMode;

	bool obstacleFlg;

	int anim_x;
	int animCnt;

	int obstacleSpawnCnt;
	int obstacleSpawnLimit;

	int first, second, third, fourth;

	obstacle()
	{
		pos_x = 0;
		pos_y = 0;
		width = OBSTACLE_WIDTH;
		height = OBSTACLE_HEIGHT;
		speed = OBSTACLE_SPEED;

		directionMode = PL_RIGHTSIDE_MODE;

		obstacle_gh = LoadGraph("Data/Image/chip1.png");
		obstacle_re_gh = LoadGraph("Data/Image/chip1_re.png");

		obstacleFlg = false;

		anim_x = 0;
		animCnt = 0;

		obstacleSpawnCnt = -120;
		obstacleSpawnLimit = getObstacleSpawnLimit(first, second, third, fourth);

		first = 0;
		second = 0;
		third = 0;
		fourth = 0;
	}

	void GetPos()
	{
		pos_y = getObstacleRandPos_y();
		
		switch (directionMode)
		{
		case PL_RIGHTSIDE_MODE:
			pos_x = 0 - OBSTACLE_WIDTH;
			break;

		case PL_LEFTSIDE_MODE:
			pos_x = WINDOW_X;
			break;

		default:
			break;
		}
	}

	void Move()
	{
		switch (directionMode)
		{
		case PL_RIGHTSIDE_MODE:
			pos_x += speed;
			break;

		case PL_LEFTSIDE_MODE:
			pos_x -= speed;
			break;

		default:
			break;
		}
	}

	void View()
	{
		anim_x = ((animCnt / 5) % 2);

		switch (directionMode)
		{
		case PL_RIGHTSIDE_MODE:
			switch ((animCnt / 5) % 2)
			{
			case 0:
				DrawRectGraph(pos_x, pos_y, 639 - (OBSTACLE_WIDTH*anim_x) - OBSTACLE_WIDTH, 32, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_re_gh, true, false);
				DrawRectGraph(pos_x, pos_y + OBSTACLE_HEIGHT, 639 - (OBSTACLE_WIDTH*anim_x) - OBSTACLE_WIDTH, 64, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_re_gh, true, false);
				break;

			case 1:
				DrawRectGraph(pos_x, pos_y, 639 - (OBSTACLE_WIDTH*anim_x) - OBSTACLE_WIDTH, 32, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_re_gh, true, false);
				DrawRectGraph(pos_x, pos_y + OBSTACLE_HEIGHT, 639 - (OBSTACLE_WIDTH*anim_x) - OBSTACLE_WIDTH, 64, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_re_gh, true, false);
				break;

			default:
				break;
			}
		case PL_LEFTSIDE_MODE:
			switch ((animCnt / 5) % 2)
			{
			case 0:
				DrawRectGraph(pos_x, pos_y, anim_x*OBSTACLE_WIDTH, 32, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_gh, true, false);
				DrawRectGraph(pos_x, pos_y + OBSTACLE_HEIGHT, OBSTACLE_WIDTH*anim_x, 64, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_gh, true, false);
				break;

			case 1:
				DrawRectGraph(pos_x, pos_y, OBSTACLE_WIDTH*anim_x, 32, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_gh, true, false);
				DrawRectGraph(pos_x, pos_y + OBSTACLE_HEIGHT, OBSTACLE_WIDTH*anim_x, 64, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_gh, true, false);
				break;

			default:
				break;
			}

			animCnt++;
		}
	}
};