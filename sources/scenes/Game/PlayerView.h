#ifndef _PLAYER_VIEW_H_
#define _PLAYER_VIEW_H_

#include "Player.h"
class PlayerControler;

#include <vector>
#include "../../formObject/OnClickListener.h"
#include "../../formObject.h"
#include "../../input/Mouse.h"

using namespace std;

class PlayerView: public OnClickListener{
  private:
    Player *pm;
    PlayerControler *pc;
    vector<View *> views;

    Button *mReadyButton;
    CField *f;
    CFieldView *fv;

  public:
    PlayerView(CField *field,Player *pmodel,PlayerControler *pctrlr);
    void draw();
    void OnClick(View *view);

};

#endif
