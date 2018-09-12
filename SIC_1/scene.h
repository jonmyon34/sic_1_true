#pragma once

enum { TITLE, PLAY, CLEAR, OVER };

class scene
{
public:
	int playmode;
	int over_gh, over_gh_title, over_gh_retry;
	int overselect;
	int timer;
	bool retryFlg;
	bool titleFlg;
	scene()
	{
		retryFlg = false;
		titleFlg = false;
		timer = 0;
		playmode = TITLE;
		overselect = 0;
		over_gh = LoadGraph("Data/Image/gameover_font.png");
		over_gh_retry = LoadGraph("Data/Image/retry_font.png");
		over_gh_title = LoadGraph("Data/Image/title_font.png");
	}
	void Overmode(scene*);
	void Drawover();
	void Overselect(scene*);
};

void doplaymode(scene*);
void dotitlemode(scene*);
void doclearmode(scene*);
void doovermode(scene*);