#ifndef _PLAYER_CONTROLER_H_
#define _PLAYER_CONTROLER_H_

#include "MVCModelBase.h"

class MVCViewBase;

class MVCControlerBase{

  protected:
   MVCModelBase *mModel;
   MVCViewBase *mView;

  public:
    MVCControlerBase(MVCModelBase  *model,MVCViewBase   *view);
    virtual void update();
};

#endif
