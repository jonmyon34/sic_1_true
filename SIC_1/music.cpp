#include "all.h"

music *mu;

void music::Playse(int i)
{
	PlaySoundMem(se[i], DX_PLAYTYPE_BACK);
}

void music::Playbgm(int i)
{
	PlaySoundMem(musics[i], DX_PLAYTYPE_BACK);
}