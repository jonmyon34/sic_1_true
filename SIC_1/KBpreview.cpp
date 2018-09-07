#include"ALL.h"

int KB[256] = { 0 };
int JOY[26] = { 0 };
XINPUT_STATE inputJoy;

int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	GetJoypadXInputState(DX_INPUT_PAD1, &inputJoy);

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			KB[i]++;     // 加算
		}
		else {              // 押されていなければ
			KB[i] = 0;   // 0にする
		}
	}
	for (int j = 0; j < 16; j++) {
		if (inputJoy.Buttons[j] != 0) { // i番のキーコードに対応するボタンが押されていたら
			JOY[j]++;     // 加算
		}
		else {              // 押されていなければ
			JOY[j] = 0;   // 0にする
		}
	}

	/*Lスティック入力*/
	if (inputJoy.ThumbLX > 0)				// Lスティックが右に倒されていたら
		JOY[XINPUT_THUMB_L_RIGHT]++;	// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_L_RIGHT] = 0;  // 0にする

	if (inputJoy.ThumbLX < 0)				// Lスティックが左に倒されていたら
		JOY[XINPUT_THUMB_L_LEFT]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_L_LEFT] = 0;   // 0にする

	if (inputJoy.ThumbLY > 0)				// Lスティックが上に倒されていたら
		JOY[XINPUT_THUMB_L_UP]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_L_UP] = 0;		// 0にする

	if (inputJoy.ThumbLY < 0)				// Lスティックが下に倒されていたら
		JOY[XINPUT_THUMB_L_DOWN]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_L_DOWN] = 0;   // 0にする

										/*Rスティック入力*/
	if (inputJoy.ThumbLX > 0)				// Rスティックが右に倒されていたら
		JOY[XINPUT_THUMB_R_RIGHT]++;	// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_R_RIGHT] = 0;  // 0にする

	if (inputJoy.ThumbLX < 0)				// Rスティックが左に倒されていたら
		JOY[XINPUT_THUMB_R_LEFT]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_R_LEFT] = 0;   // 0にする

	if (inputJoy.ThumbLY > 0)				// Rスティックが上に倒されていたら
		JOY[XINPUT_THUMB_R_UP]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_R_UP] = 0;		// 0にする

	if (inputJoy.ThumbLY < 0)				// Rスティックが下に倒されていたら
		JOY[XINPUT_THUMB_R_DOWN]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_THUMB_R_DOWN] = 0;   // 0にする

										/*トリガー入力*/
	if (inputJoy.LeftTrigger != 0)			// Lトリガーが押されていたら
		JOY[XINPUT_LEFT_TRIGGER]++;		// 加算
	else								// 押されていなければ
		JOY[XINPUT_LEFT_TRIGGER] = 0;	// 0にする

	if (inputJoy.RightTrigger != 0)		// Rトリガーが押されていたら
		JOY[XINPUT_RIGHT_TRIGGER]++;	// 加算
	else								// 押されていなければ
		JOY[XINPUT_RIGHT_TRIGGER] = 0;	// 0にする


	return 0;
}

