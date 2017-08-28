#ifndef _JUDGE_
#define _JUDGE_

#include "Participant.h"
#include "Messenger.h"

class Judge : public Participant{

  private:
   string src,dst;
   int turn;
   bool ready1,ready2;
   Messenger *io1, *io2;

  public:
    Judge(CField *field, Messenger *io_1, Messenger *io_2);
    void update();

};

#endif