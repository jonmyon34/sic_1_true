#include "all.h"

void doplaymode(scene *se)//終了するときに各所でmainのポインタseを渡してplaymodeを書き換えてください。
{
	se->playmode = PLAY;
}

void dotitlemode(scene *se)
{
	se->playmode = TITLE;
}

void doclearmode(scene *se)
{
	se->playmode = CLEAR;
}

void doovermode(scene *se)
{
	se->playmode = OVER;
}