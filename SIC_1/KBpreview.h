#ifndef _KB_PREVIEW_H_
#define _KB_PREVIEW_H_

#define XINPUT_THUMB_L_RIGHT (16)
#define XINPUT_THUMB_L_LEFT (17)
#define XINPUT_THUMB_L_UP (18)
#define XINPUT_THUMB_L_DOWN (19)
#define XINPUT_THUMB_R_RIGHT (20)
#define XINPUT_THUMB_R_LEFT (21)
#define XINPUT_THUMB_R_UP (22)
#define XINPUT_THUMB_R_DOWN (23)
#define XINPUT_LEFT_TRIGGER (24)
#define XINPUT_RIGHT_TRIGGER (25)

extern int KB[256];
extern int JOY[26];
extern XINPUT_STATE inputJoy;

int gpUpdateKey();

#endif // !_KB_PREVIEW_H_

