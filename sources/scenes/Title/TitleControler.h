#ifndef _TITLE_CONTROLER_H_
#define _TITLE_CONTROLER_H_

//#include "TitleModel.h"
#include "../../VsType.h"

class TitleModel;
class TitleView;

class TitleControler{

  private:
   TitleModel *tm;
   TitleView *tv;

  public:
    TitleControler();
    void update();
    void startGame(tVsType type);
};

#endif
