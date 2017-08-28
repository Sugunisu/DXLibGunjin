#include "MVCControlerBase.h"
#include "MVCViewBase.h"

MVCControlerBase::MVCControlerBase(MVCModelBase  *model,MVCViewBase   *view){
	mModel = model;
	mView = view;
}

void MVCControlerBase::update(){
	mView->draw();
}
