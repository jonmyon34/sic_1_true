#pragma once

class music
{
public:
	int musics[21];
	int se[59];
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

		se[0] = LoadSoundMem("Data/se/se_0.wav");
		se[1] = LoadSoundMem("Data/se/se_1.wav");
		se[2] = LoadSoundMem("Data/se/se_2.wav");
		se[3] = LoadSoundMem("Data/se/se_3.wav");
		se[4] = LoadSoundMem("Data/se/se_4.wav");
		se[5] = LoadSoundMem("Data/se/se_5.wav");
		se[6] = LoadSoundMem("Data/se/se_6.wav");
		se[7] = LoadSoundMem("Data/se/se_7.wav");
		se[8] = LoadSoundMem("Data/se/se_8.wav");
		se[9] = LoadSoundMem("Data/se/se_9.wav");

		se[10] = LoadSoundMem("Data/se/se_10.wav");
		se[11] = LoadSoundMem("Data/se/se_11.wav");
		se[12] = LoadSoundMem("Data/se/se_12.wav");
		se[13] = LoadSoundMem("Data/se/se_13.wav");
		se[14] = LoadSoundMem("Data/se/se_14.wav");
		se[15] = LoadSoundMem("Data/se/se_15.wav");
		se[16] = LoadSoundMem("Data/se/se_16.wav");
		se[17] = LoadSoundMem("Data/se/se_17.wav");
		se[18] = LoadSoundMem("Data/se/se_18.wav");
		se[19] = LoadSoundMem("Data/se/se_19.wav");

		se[20] = LoadSoundMem("Data/se/se_20.wav");
		se[21] = LoadSoundMem("Data/se/se_21.wav");
		se[22] = LoadSoundMem("Data/se/se_22.wav");
		se[23] = LoadSoundMem("Data/se/se_23.wav");
		se[24] = LoadSoundMem("Data/se/se_24.wav");
		se[25] = LoadSoundMem("Data/se/se_25.wav");
		se[26] = LoadSoundMem("Data/se/se_26.wav");
		se[27] = LoadSoundMem("Data/se/se_27.wav");
		se[28] = LoadSoundMem("Data/se/se_28.wav");
		se[29] = LoadSoundMem("Data/se/se_29.wav");

		se[30] = LoadSoundMem("Data/se/se_30.wav");
		se[31] = LoadSoundMem("Data/se/se_31.wav");
		se[32] = LoadSoundMem("Data/se/se_32.wav");
		se[33] = LoadSoundMem("Data/se/se_33.wav");
		se[34] = LoadSoundMem("Data/se/se_34.wav");
		se[35] = LoadSoundMem("Data/se/se_35.wav");
		se[36] = LoadSoundMem("Data/se/se_36.wav");
		se[37] = LoadSoundMem("Data/se/se_37.wav");
		se[38] = LoadSoundMem("Data/se/se_38.wav");
		se[39] = LoadSoundMem("Data/se/se_39.wav");

		se[40] = LoadSoundMem("Data/se/se_40.wav");
		se[41] = LoadSoundMem("Data/se/se_41.wav");
		se[42] = LoadSoundMem("Data/se/se_42.wav");
		se[43] = LoadSoundMem("Data/se/se_43.wav");
		se[44] = LoadSoundMem("Data/se/se_44.wav");
		se[45] = LoadSoundMem("Data/se/se_45.wav");
		se[46] = LoadSoundMem("Data/se/se_46.wav");
		se[47] = LoadSoundMem("Data/se/se_47.wav");
		se[48] = LoadSoundMem("Data/se/se_48.wav");
		se[49] = LoadSoundMem("Data/se/se_49.wav");

		se[50] = LoadSoundMem("Data/se/se_50.wav");
		se[51] = LoadSoundMem("Data/se/se_51.wav");
		se[52] = LoadSoundMem("Data/se/se_52.wav");
		se[53] = LoadSoundMem("Data/se/se_53.wav");
		se[54] = LoadSoundMem("Data/se/se_54.wav");
		se[55] = LoadSoundMem("Data/se/se_55.wav");
		se[56] = LoadSoundMem("Data/se/se_56.wav");
		se[57] = LoadSoundMem("Data/se/se_expl.wav");
		se[58] = LoadSoundMem("Data/se/se_score.wav");

		ChangeVolumeSoundMem(255, se[58]);
	}
	void Playse(int);
	void Playbgm(int);
};

extern music *mu;