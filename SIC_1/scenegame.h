//void GameStart(back&, player&, scene&);


class scenegame
{
public:
	int scenegame_back_adjust;
	int scenegame_adjust_Flg;
	int scenegame_adjust_pos_y;
	int scenegame_adjust_ply;

	scenegame()
	{
		scenegame_back_adjust = 0;
		scenegame_adjust_Flg = false;
		scenegame_adjust_pos_y = 0;
		scenegame_adjust_ply = 0;
	}
};

void changeDirectionMode(back&, player&, scene&, scenegame&);
void changeDirectionModeDown(back&, player&, scene&);
