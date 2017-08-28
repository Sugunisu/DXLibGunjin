#ifndef _JUDGE_VIEW_H_
#define _JUDGE_VIEW_H_

#include "DxLib.h"
#include <stdlib.h>
#include "Field.h"

#include "FieldView.h"
#include "Player.h"
#include "Judge.h"
#include "TCPMessenger.h"

class JudgeView{

private:

	CField *gunjin;
	CFieldView *gunjinv;
    TCPMessenger *io1;
	TCPMessenger *io2;
	Judge *j;

	int state;

public:
	JudgeView();
	int update();
};
#endif