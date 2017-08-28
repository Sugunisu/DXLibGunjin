#include "TitleView.h"
#include "TitleScene.h" 
//#include "TitleControler.h"

#include <string>
#include "DxLib.h"

TitleView::TitleView(TitleModel *tmodel,TitleScene *tctrlr){
	tm = tmodel;
	tc = tctrlr;
	mTitleImg = new DXImage(10,20,320,240,"img/title.png");
	mPlayButton = new Button(140,360,100,30,"対局");
	mOptionButton = new Button(270,360,100,30,"設定");
	mExitButton = new Button(400,360,100,30,"終了");
	
	mVsCPUButton = new Button(75,360,100,30,"CPU対戦");
	mVsHostButton = new Button(205,360,100,30,"ホスト");
    mVsGuestButton = new Button(335,360,100,30,"ゲスト");
    mVsJudgeButton = new Button(465,360,100,30,"審判ホスト");
    mBackButton = new Button(255,400,130,20,"戻る");
    
  mPlayButton->SetOnClickListener(this);
  mOptionButton->SetOnClickListener(this);
  mExitButton->SetOnClickListener(this);
  mVsCPUButton->SetOnClickListener(this);
  mVsHostButton->SetOnClickListener(this);
  mVsGuestButton->SetOnClickListener(this);
  mVsJudgeButton->SetOnClickListener(this);
  mBackButton->SetOnClickListener(this);
  
  mVsCPUButton->Hide();
  mVsHostButton->Hide();
  mVsGuestButton->Hide();
  mVsJudgeButton->Hide();
  mBackButton->Hide();
  
  //unimplemented
  mVsCPUButton->Inactivate();
  mVsJudgeButton->Inactivate();
  mOptionButton->Inactivate();
  
  views.push_back(mTitleImg);
  views.push_back(mPlayButton);
  views.push_back(mOptionButton);
  views.push_back(mExitButton);
  views.push_back(mVsCPUButton);
  views.push_back(mVsHostButton);
  views.push_back(mVsGuestButton);
  views.push_back(mVsJudgeButton);
  views.push_back(mBackButton);

}

void TitleView::draw(){

    int x = Mouse::Instance()->GetX();
    int y = Mouse::Instance()->GetY();
    View *onView=NULL;
    
    
    for(int i=0;i<views.size();i++){
      views[i]->Draw();
      if(views[i]->IsOn(x,y) && views[i]->IsShown() ){
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

void TitleView::OnClick(View* view){

	if(view==mPlayButton){
	
		mPlayButton->Hide();
		mOptionButton->Hide();
		mExitButton->Hide();
	  
		mVsCPUButton->Show();
  		mVsHostButton->Show();
  		mVsGuestButton->Show();
		mVsJudgeButton->Show();
		mBackButton->Show();
	}
	
	if(view==mExitButton){
	  DxLib_End();
	}
	
	if(view==mBackButton){
		mPlayButton->Show();
		mOptionButton->Show();
		mExitButton->Show();
	  
  		mVsCPUButton->Hide();
		mVsHostButton->Hide();
		mVsGuestButton->Hide();
		mVsJudgeButton->Hide();
		mBackButton->Hide();
	}
	
	if(view==mVsCPUButton){
		//tc -> startGame(VST_COMPUTER);
	}
	if(view==mVsHostButton){
		tc -> startGame(VST_HOST);
	}
	if(view==mVsGuestButton){
		tc -> startGame(VST_GUEST);
	}
	if(view==mVsJudgeButton){
		//tc -> startGame(VST_JUDGE);
	}
/*
	else if(xxxx){
	  pc -> xxxListner();
	}
*/

}
