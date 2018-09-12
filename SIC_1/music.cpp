#include "all.h"

void music::Playse(int i)
{
	PlaySoundMem(musics[i], DX_PLAYTYPE_BACK);
}

void music::Playbgm(int i)
{
	PlaySoundMem(musics[i], DX_PLAYTYPE_LOOP);
}