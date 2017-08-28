#include "../../TCPMessenger.h"
#include "../../LocalMessenger.h"
#include "../../Koma.h"
#include "../../Field.h"
#include "../../FieldView.h"
#include "../../Judge.h"
#include "Player.h"
#include "../../VsType.h"
#include "PlayerControler.h"

enum tGameManagerState{
  GMS_INPUT,
  GMS_CONNECT,
  GMS_GAME
};

class GameMgr{
private:
	Player *p,*p2;
	Messenger *io_a1,*io_a2,*io_b1,*io_b2;
	Judge  *j;
	CField *f,*f2,*fj;
	CFieldView *fv;
	VsType *vt;
	tGameManagerState state;

	string src,dst;
	bool SelectFlag;
        PlayerControler *pc;

public:
	GameMgr(VsType *t);
	//int reset();
	int run();

};
