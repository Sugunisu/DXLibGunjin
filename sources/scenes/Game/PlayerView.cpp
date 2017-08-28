#include "PlayerView.h"
#include "PlayerControler.h"

#include <string>
#include "DxLib.h"


string getOpponent2(string s){
	string ret="";
	if(s=="C1"){return "C8";}
	if(s=="C8"){return "C1";}
	ret+='F'- (s[0]-'A');
	ret+='8'- (s[1]-'1');
	return ret;
}


PlayerView::PlayerView(CField *field,Player *pmodel,PlayerControler *pctrlr){
  pm = pmodel;
  pc = pctrlr;

  f  = field;
  fv = new CFieldView(20,20,field);
  fv->changeInputStyle(IS_EXCHANGE);

  mReadyButton = new Button(460,40,100,50,"€”õŠ®—¹");
  mReadyButton->SetOnClickListener(this);
  views.push_back(mReadyButton);

}

void PlayerView::draw(){

    
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
    if(fv->update()){
    	string buf=fv->getMove();
    	if(!pm->isWhite()){
    		buf = getOpponent2(buf.substr(0,2))+getOpponent2(buf.substr(2,2));
    		//DrawString(460,200,"OK",GetColor(0xff,0xff,0xff)); 
    	}
    	pc->sendMessage(buf);
	}
    fv->draw();
    
    switch (pm->nowState()){
	case PROGRESS_SETKOMA:
		
	break;
	case PROGRESS_BATTLE:
		if((pm->getTurn()%2==0 && pm->isWhite() )||(pm->getTurn()%2==1 && !pm->isWhite() )){
			DrawString(460,10,"‚ ‚È‚½‚Ì”Ô‚Å‚·",GetColor(0xff,0x0f,0x0f));
			fv->changeInputStyle(IS_MOVE);
		}
		else{
			DrawString(460,10,"‘ŠŽè‚Ì”Ô‚Å‚·",GetColor(0xff,0x0f,0x0f));
			fv->changeInputStyle(IS_UNENABLE);
		}		
	break;
	
	/*
	static string s="a";
	
	if(pc->gotMessage()){	
		s=pc->getMessage();	
	}
	
    DrawString(460,100,s.c_str(),GetColor(0xff,0xff,0xff));
    */
	}
	
}

void PlayerView::OnClick(View* view){

	if(view==mReadyButton){
	  pc -> readyListner();
	  mReadyButton->Inactivate();
	}
/*
	else if(xxxx){
	  pc -> xxxListner();
	}
*/

}
