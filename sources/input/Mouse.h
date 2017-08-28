#ifndef _MOUSE_
#define _MOUSE_

#include "../utility/Singleton.h"

class Mouse : public Singleton<Mouse> {

	Mouse();
	friend Singleton<Mouse>;

public:
	bool Update();
	int GetPressingCount(int keyCode);
	int GetReleasingCount(int keyCode);
	int GetX();
	int GetY();
	const static int LEFT   = 0;
	const static int RIGHT  = 1;
	const static int MIDDLE = 2;

private:
	const static int BUTTON_NUM = 8;
	int mKeyPressingCount [BUTTON_NUM];
	int mKeyReleasingCount[BUTTON_NUM];
	int mX, mY;

	bool IsAvailableCode(int keyCode);
};

#endif