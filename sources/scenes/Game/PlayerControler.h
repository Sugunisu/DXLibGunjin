#ifndef _PLAYER_CONTROLER_H_
#define _PLAYER_CONTROLER_H_

#include "../../Field.h"
#include "Player.h"

class PlayerView;

class PlayerControler{

  private:
   Player *pm;
   PlayerView *pv;
   Messenger *io;

  public:
    PlayerControler(CField *field,Messenger *io_1);
    void update();
    void readyListner();
    void sendMessage(string message);
    bool gotMessage();
    string getMessage();
};

#endif
