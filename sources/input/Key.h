#pragma once

#include "../utility/Singleton.h"

class Key : public Singleton<Key> {

	Key();
	friend Singleton<Key>;

public:
	bool Update();
	int GetPressingCount(int keyCode);
	int GetReleasingCount(int keyCode);

private:
	const static int KEY_NUM = 256;
	int mKeyPressingCount [KEY_NUM];
	int mKeyReleasingCount[KEY_NUM];

	bool IsAvailableCode(int keyCode);
};