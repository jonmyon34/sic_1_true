#define WARP_BLOCK_WIDTH 32
#define WARP_BLOCK_HEIGHT 32

#define WARP_BLOCK_SPEED 7

#define WARP_SPAWN_LIMIT 600
#define AUTO_WARP_LIMIT 420


int getWarpBlockRandPos_x();

class warpblock
{
public:
	int pos_x, pos_y, width, height;
	int warpblock_gh;
	float speed;

	int warpSpawnCnt;
	int warpSpawnLimit;

	int autoWarpLimit;

	bool existFlg;

	warpblock()
	{
		pos_x = getWarpBlockRandPos_x();
		pos_y = WINDOW_Y;
		width = WARP_BLOCK_WIDTH;
		height = WARP_BLOCK_HEIGHT;
		warpblock_gh = LoadGraph("Data/Image/Ps_pl.png");
		speed = WARP_BLOCK_SPEED;

		warpSpawnCnt = 0;
		warpSpawnLimit = WARP_SPAWN_LIMIT;

		autoWarpLimit = AUTO_WARP_LIMIT;

		existFlg = false;
	}

	void GetPos()
	{
		pos_x = getWarpBlockRandPos_x();
		pos_y = WINDOW_Y;
	}

	void Move()
	{
		pos_y -= speed;

		if (pos_y < -60)
		{
			existFlg = false;
			GetPos();
		}
	}

	void View()
	{
		DrawGraph(pos_x, pos_y, warpblock_gh, true);
	}

	void All()
	{
		Move();
		View();
	}
};