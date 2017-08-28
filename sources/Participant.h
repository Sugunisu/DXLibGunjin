#ifndef _PARTICIPANT_
#define _PARTICIPANT_

#include "Field.h"
#include "Messenger.h"

typedef enum progress{
  PROGRESS_SETKOMA=0,
  PROGRESS_BATTLE=1,
  PROGRESS_END=2
} progress;

class Participant{

  protected:
    progress prg;
    CField *f;


  public:
    Participant(CField *field){prg=PROGRESS_SETKOMA; f=field;}
    void start(){prg=PROGRESS_BATTLE;}
    void end(){prg=PROGRESS_END;}
    progress nowState(){return prg;}
    virtual void update(){};
    
};

#endif