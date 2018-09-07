#pragma once

enum { TITLE, PLAY, CLEAR, OVER };

class scene
{
public:
	int playmode;
	scene()
	{
		playmode = TITLE;
	}
};

void doplaymode(scene*);//mode
void dotitlemode(scene*);
void doclearmode(scene*);
void doovermode(scene*);