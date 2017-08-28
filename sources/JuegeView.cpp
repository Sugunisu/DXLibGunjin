#include "JudgeView.h"
        

JudgeView::JudgeView(){
    gunjin = new CField();
    gunjinv = new CFieldView(10,10,gunjin);
    io1 = new TCPMessenger(4274);
    io2 = new TCPMessenger(4274);
    
    j = new Judge(gunjin,io1,io2);

    state=0;
}

int JudgeView::update(){

      if(state==0){
        if(io1->tryConnect()) state=1;
		DrawBox( 420 , 0 , 600 , 32 , GetColor(0,0,0) , TRUE ) ;
        DrawString( 420 , 0 , "Ú‘±’†...(0/2)" , GetColor(255,255,255) ) ;
      }
      else if(state==1){
        if(io2->tryConnect()) state=2;
				DrawBox( 420 , 0 , 600 , 32 , GetColor(0,0,0) , TRUE ) ;
        DrawString( 420 , 0 , "Ú‘±’†...(1/2)" , GetColor(255,255,255) ) ;
      }
      else{

        DrawBox( 420 , 0 , 600 , 32 , GetColor(0,0,0) , TRUE ) ;
        DrawString( 420 , 0 , "‡’†" , GetColor(255,255,255) ) ;

        j->update();

        gunjinv->draw();
        ScreenFlip();
      }
    return 0;
}
