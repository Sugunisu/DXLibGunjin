#include "MVCViewBase.h"
#include "MVCControlerBase.h"

#include "DxLib.h"

MVCViewBase::MVCViewBase(MVCModelBase *pmodel,MVCControlerBase *pctrlr){
  mModel = pmodel;
  mControler = pctrlr;

}

void MVCViewBase::draw(){

    Mouse::Instance()->Update();
    int x = Mouse::Instance()->GetX();
    int y = Mouse::Instance()->GetY();
    View *onView=NULL;
    for(int i=0;i<views.size();i++){
      views[i]->Draw();
      if(views[i]->IsOn(x,y)){
        onView=views[i];
      }
    }

    for(int i=0;i<views.size();i++){
      if(onView==views[i]){
        views[i]->OnUpdate();
      }else{
        views[i]->OffUpdate();
      }
    }
}

void MVCViewBase::OnClick(FormObject *view){}

void MVCViewBase::addView(FormObject *v){
  v->SetOnClickListener(this);
  views.push_back(v);	
};
