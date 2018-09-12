#pragma once

class music
{
public:
	int musics[21];
	music()
	{
		musics[0] = LoadSoundMem("Data/music/mu0.wav");
		musics[1] = LoadSoundMem("Data/music/mu1.wav");
		musics[2] = LoadSoundMem("Data/music/mu2.wav");
		musics[3] = LoadSoundMem("Data/music/mu3.wav");
		musics[4] = LoadSoundMem("Data/music/mu4.wav");
		musics[5] = LoadSoundMem("Data/music/mu5.wav");
		musics[6] = LoadSoundMem("Data/music/mu6.wav");
		musics[7] = LoadSoundMem("Data/music/mu7.wav");
		musics[8] = LoadSoundMem("Data/music/mu8.wav");
		musics[9] = LoadSoundMem("Data/music/mu9.wav");
		musics[10] = LoadSoundMem("Data/music/mu10.wav");
		musics[11] = LoadSoundMem("Data/music/mu11.wav");
		musics[12] = LoadSoundMem("Data/music/mu12.wav");
		musics[13] = LoadSoundMem("Data/music/mu13.wav");
		musics[14] = LoadSoundMem("Data/music/mu14.wav");
		musics[15] = LoadSoundMem("Data/music/mu15.wav");
		musics[16] = LoadSoundMem("Data/music/mu16.wav");
		musics[17] = LoadSoundMem("Data/music/muCymbal0.wav");
		musics[18] = LoadSoundMem("Data/music/muCymbal1.wav");
		musics[19] = LoadSoundMem("Data/music/muCymbal2.wav");
		musics[20] = LoadSoundMem("Data/music/muCymbal3.wav");
	}
	void Playse(int);
	void Playbgm(int);
};