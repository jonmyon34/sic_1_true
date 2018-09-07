#define OBSTACLE_WIDTH 16
#define OBSTACLE_HEIGHT 16
#define OBSTACLE_SPEED 15

int getObstacleRandPos_y();

class obstacle
{
public:
	int pos_x, pos_y, width, height;
	int speed;


	int obstacle_gh;

	int directionMode;

	bool obstacleFlg;

	obstacle()
	{
		pos_x = 0;
		pos_y = WINDOW_Y / 2;;
		width = OBSTACLE_WIDTH;
		height = OBSTACLE_HEIGHT;
		speed = OBSTACLE_SPEED;

		directionMode = PL_RIGHTSIDE_MODE;

		obstacle_gh = LoadGraph("Data/Image/chip1.png");

		obstacleFlg = false;
	}

	void GetPos()
	{
		pos_x = getObstacleRandPos_y();
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
		DrawRectGraph(pos_x, pos_y, 0, 0, OBSTACLE_WIDTH, OBSTACLE_HEIGHT, obstacle_gh, true, false);
	}
};