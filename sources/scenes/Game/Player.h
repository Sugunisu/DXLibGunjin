#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Participant.h"
#include "../../FieldView.h"

class Player : public Participant{

  private:
   CFieldView *fv;
   string src,dst;
   bool is_ready;
   int turn;
   bool is_white;
   bool is_sent;
   Messenger *io;

  public:
    Player(CField *field,Messenger *io_1);
    void update();
    void ready(){is_ready=true;}
    bool isReady(){return is_ready;}
    bool isWhite(){return is_white;}
    int  getTurn(){return turn;}
    
};

#endif
