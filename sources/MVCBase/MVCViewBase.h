#ifndef _MVC_VIEW_BASE_H_
#define _MVC_VIEW_BASE_H_

class MVCControlerBase;

#include <vector>
#include "../formObject/OnClickListener.h"
#include "../formObject.h"
#include "../input/Mouse.h"
#include "MVCModelBase.h"
#include "../formObject/FormObject.h"

using namespace std;

class MVCViewBase: public OnClickListener{
  protected:
    MVCModelBase *mModel;
    MVCControlerBase *mControler;
    vector<FormObject *> views;

    //Button *mReadyButton;
    //CField *f;
    //CFieldView *fv;
    
    void addView(FormObject *v);

  public:
  	MVCViewBase(MVCModelBase *pmodel,MVCControlerBase *pctrlr);
    //PlayerView(CField *field,Player *pmodel,PlayerControler *pctrlr);
    void draw();
    virtual void OnClick(FormObject *view);

};

#endif
