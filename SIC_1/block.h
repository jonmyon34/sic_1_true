#define BLOCK_WIDTH 16
#define BLOCK_HEIGHT 16

#define BLOCK_SPEED 6

#define BLOCK_SPAWN_LIMIT 120

int getBlockRandPos_x();
int getBlockRandValue();
int getBlockNo(int, int);
int getBlockSpawnLimit(int, int, int, int);



class block
{
public:
	int pos_x, pos_y, width, height;
	int speed;

	int block_gh;
	int blockef_gh;

	bool block_break_Anm_Flg;

	int blockRandFirst;
	int blockRandSecond;

	int nextBlockMargin;

	int blockNumber;

	int anim_x;
	int animCnt;

	int blockSpawnCnt;
	int blockSpawnLimit;
	bool blockExistFlg;

	int blockExistMode;
	int directionMode;

	bool blockFlg;


	int first, second, third, fourth;

	block()
	{
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y;

		width = BLOCK_WIDTH;
		height = BLOCK_HEIGHT;

		speed = BLOCK_SPEED;

		block_gh = LoadGraph("Data/Image/chip1.png");
		blockef_gh = LoadGraph("Data/Image/effect2.png");

		block_break_Anm_Flg = false;

		blockRandFirst = getBlockRandValue();
		blockRandSecond = getBlockRandValue();

		blockNumber = getBlockNo(blockRandFirst, blockRandSecond);
		blockExistMode = blockNumber;
		directionMode = BLOCK_RISE_MODE;

		anim_x = 0;
		animCnt = 0;

		nextBlockMargin = 0;

		blockSpawnCnt = -150;
		blockSpawnLimit = getBlockSpawnLimit(first, second, third, fourth);
		blockExistFlg = false;

		blockFlg = false;

		first = 0;
		second = 0;
		third = 0;
		fourth = 0;
	}

	void GetPos()
	{
		pos_x = getBlockRandPos_x();

		switch (directionMode)
		{
		case BLOCK_RISE_MODE:
			pos_y = WINDOW_Y;
			break;

		case BLOCK_FALL_MODE:
			pos_y = 0 - BLOCK_HEIGHT;
			break;

		default:
			pos_y = WINDOW_Y;
			break;
		}

		blockRandFirst = getBlockRandValue();
		blockRandSecond = getBlockRandValue();

		blockNumber = getBlockNo(blockRandFirst, blockRandSecond);
		blockExistMode = blockNumber;
		blockExistFlg = true;
	}

	void Move()
	{
		switch (directionMode)
		{
		case BLOCK_RISE_MODE:
			pos_y -= speed;
			nextBlockMargin -= speed;
			break;

		case BLOCK_FALL_MODE:
			pos_y += speed;
			nextBlockMargin -= speed;
			break;

		default:
			break;
		}
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
			if (blockNumber - blockExistMode <= i)
			{
				//DrawExtendGraph(pos_x, (pos_y + i*height), pos_x + width, (pos_y + i*height) + height, block_gh, true);

				if (directionMode == BLOCK_RISE_MODE)	//下から上へ
				{
					DrawRectGraph(pos_x, (pos_y + i*height), 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT, block_gh, true, false);
					if (speed == 0)
					{
						animCnt++;
						anim_x = animCnt / 25 % 4;
						switch (anim_x)
						{
						case 0:
							DrawRectGraph(pos_x, (pos_y + i*height), anim_x * 32, 32, 32, 32, blockef_gh, true, false);
							break;
						case 1:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y + i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;
						case 2:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y + i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;
						case 3:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y + i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;//break無し乗算で表示?
						}
					}
				}
				else if (directionMode == BLOCK_FALL_MODE)	//上から下へ
				{
					DrawRectGraph(pos_x, (pos_y - i*height), 0, 0, BLOCK_WIDTH, BLOCK_HEIGHT, block_gh, true, false);
					if (speed == 0)
					{
						animCnt++;
						anim_x = animCnt / 25 % 4;
						switch (anim_x)
						{
						case 0:
							DrawRectGraph(pos_x, (pos_y - i*height), anim_x * 32, 32, 32, 32, blockef_gh, true, false);
							break;
						case 1:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y - i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;
						case 2:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y - i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;
						case 3:
							for (int i = anim_x; i >= 0; i--)
							{
								DrawRectGraph(pos_x, (pos_y - i*height), (anim_x - i) * 32, 32, 32, 32, blockef_gh, true, false);
							}
							break;//break無し乗算で表示?
						}
					}
				}
			}
			else
			{
				//ここに壊れた時のアニメーション
			}
		}
	}


};

void HitStop(block&, player&);
