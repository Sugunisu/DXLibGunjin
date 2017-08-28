#ifndef _TITLE_VIEW_H_
#define _TITLE_VIEW_H_

//#include "TitleModel.h"
//class TitleControler;
class TitleScene;
class TitleModel;

#include <vector>
#include "../../formObject/OnClickListener.h"
#include "../../formObject.h"
#include "../../input/Mouse.h"

#include "../../VsType.h"

using namespace std;

class TitleView: public OnClickListener{
  private:
    TitleModel *tm;
    TitleScene *tc;
    vector<View *> views;
    
    DXImage *mTitleImg;
    
    //TOP
    Button *mPlayButton;
    Button *mOptionButton;
    Button *mExitButton;
    
    //SELECT_PLAYMODE
    Button *mVsCPUButton;
    Button *mVsHostButton;
    Button *mVsGuestButton;
    Button *mVsJudgeButton;
    Button *mBackButton;

  public:
    TitleView(TitleModel *tmodel,TitleScene *tctrlr);
    void draw();
    void OnClick(View *view);

};

#endif
