#define BLOCK_WIDTH 16
#define BLOCK_HEIGHT 16

int getBlockRandPos_x();
int getBlockRandValue();
int getBlockNo(int, int);

class block
{
public:
	int pos_x, pos_y, width, height;
	int speed;

	int block_gh;

	bool block_break_Anm_Flg;

	int blockRandFirst;
	int blockRandSecond;


	int blockNumber;

	//struct blockExistFlg
	//{
	//	bool block1;
	//	bool block2;
	//	bool block3;
	//	bool block4;
	//	bool block5;
	//	bool block6;
	//};

	bool blockExistFlg;

	int blockExistMode;
	bool blockFlg;

	block()
	{
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y;

		width = BLOCK_WIDTH;
		height = BLOCK_HEIGHT;

		speed = 12;

		block_gh = LoadGraph("chip1.png");

		block_break_Anm_Flg = false;

		blockRandFirst = getBlockRandValue();
		blockRandSecond = getBlockRandValue();

		blockNumber = getBlockNo(blockRandFirst, blockRandSecond);
		blockExistMode = blockNumber;

		blockExistFlg = false;

		blockFlg = false;
	}

	void ReStart()
	{
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y;
	}

	void GetPos()
	{
		pos_x = getBlockRandPos_x();
		pos_y = WINDOW_Y;

		blockRandFirst = getBlockRandValue();
		blockRandSecond = getBlockRandValue();

		blockNumber = getBlockNo(blockRandFirst, blockRandSecond);
		blockExistMode = blockNumber;
		blockExistFlg = true;
	}

	void Move()
	{
		pos_y = pos_y - speed;
	}

	void ExistCheck()
	{
		if (blockExistMode <= 0)
		{
			blockExistFlg = false;
		}
	}

	void View()
	{
		
		for (int i = 0; i < blockNumber; i++)
		{
			if (blockNumber - blockExistMode < i)
			{
				//DrawExtendGraph(pos_x, (pos_y + i*height), pos_x + width, (pos_y + i*height) + height, block_gh, true);
				DrawRectGraph(pos_x, (pos_y + i*height), 0, 0, PL_WIDTH, PL_HEIGHT, block_gh, true, false);
			}
		}
	}
};

