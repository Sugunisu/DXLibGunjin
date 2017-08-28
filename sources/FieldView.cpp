#include "dxlib.h"
#include "FieldView.h"
#include "input/Mouse.h"

CFieldView::CFieldView(int x, int y, CField *field_p){
  mx = x;
  my = y;
  f = field_p;
  img_board = LoadGraph("img/board.png",FALSE); 
  LoadDivGraph( "img/koma.png" , 44 , 4 , 11 , 64 , 32 , img_koma );
  hide_flag[WHITE] = true;
  hide_flag[BLACK] = false;
  selectFlag=false;
  selectArea="XX";
  is=IS_UNENABLE;
}

void CFieldView::draw(){

  //-----------------------
  // BOARD
  //-----------------------

  DrawGraph(mx,my,img_board,TRUE);

  //-----------------------
  // KOMA
  //-----------------------

  for(int i = 0;i<46;i++){
    string locs="";
    int offX=mx+COORDINATE_W;
    int offY=my+COORDINATE_H;
    int loci=i;

    if (i>43) loci=i+2;
    else if(i>2) loci=i+1;
    locs+=('A'+(loci%6));
    locs+=('1'+(int)(loci/6));

    offX += (loci%6)*KOMA_W;
    offY += (loci/6)*KOMA_H;  
    
    // ***** HQ *****
    if(i==2||i==43){ offX += KOMA_W/2; }

    // ***** Player's Region *****
    if(i>=23){ offY += RIVER_H; }
    
    //draw

    if(f->getTeam(locs)==BLACK)
      DrawGraph(offX, offY, img_koma[f->getRank(locs)+20],TRUE);
    else
      DrawGraph(offX, offY, img_koma[f->getRank(locs)],TRUE);
    
  }
  
  //-----------------------
  // SELECT
  //-----------------------
	 
  if(selectArea[0]>='A'&&selectArea[0]<='F'&&
     selectArea[1]>='1'&&selectArea[1]<='8'&& selectFlag){
    int offX=mx+COORDINATE_W;
    int offY=my+COORDINATE_H;
    offX += (selectArea[0]-'A')*KOMA_W;
    offY += (selectArea[1]-'1')*KOMA_H;
    if(selectArea[1]>'4'){ offY += RIVER_H; }
    if(selectArea=="C1"||selectArea=="C8"){
      DrawBox( offX, offY, offX+(KOMA_W*2), offY+KOMA_H, GetColor( 255,0,0 ), FALSE );
    }else{
      DrawBox( offX, offY, offX+KOMA_W, offY+KOMA_H, GetColor( 255,0,0 ), FALSE );
    }
  }

}

int CFieldView::select(string sa){
  selectArea=sa;
  return 0;
}

bool CFieldView::update(){
	
    int x = Mouse::Instance()->GetX();
    int y = Mouse::Instance()->GetY();
    string str = this->cordToStr(x,y);
    
	switch(is){
		case IS_UNENABLE:
		break;
		case IS_EXCHANGE:
    		DrawFormatString(460,150,GetColor(0xff,0xff,0xff),"(%d,%d),%s",x,y, str.c_str() );
    		if(Mouse::Instance()->GetPressingCount(Mouse::LEFT)==1 && str!="XX"){
    			if(!selectFlag){
    				selectArea=str;
    				selectFlag=true;
				}
				else{
					f->exchange(selectArea,str);
					selectArea+=str;
    				selectFlag=false;
    				return true;
				}
			}			
		break;
		
		case IS_MOVE:
			
    		DrawFormatString(460,150,GetColor(0xff,0xff,0xff),"(%d,%d),%s",x,y, str.c_str() );
    		if(Mouse::Instance()->GetPressingCount(Mouse::LEFT)==1 && str!="XX"){
    			
    			if(!selectFlag){
    				selectArea=str;
    				selectFlag=true;
				}
				else{
					if(selectArea==str){
						selectFlag=false;
					}
					else{
					
						f->move(selectArea,str);
						selectArea+=str;
    					selectFlag=false;
    					return true;
    				}
				}
				
			}
					
		break;				
	}
	return false;
}

string CFieldView::cordToStr(int x,int y){
  string locs;
 
  x-=mx+COORDINATE_W;
  y-=my+COORDINATE_H;
  
  // ***** Illegal input
  if(x<0 || x>(KOMA_W*6) || y<0 || y>(KOMA_H*8) + RIVER_H) 
     return "XX";

  // ***** Player's Region *****
  if(y>(KOMA_H*4)){ y -= RIVER_H; }

  x /= KOMA_W;
  y /= KOMA_H; 
    
  // ***** HQ *****
  if(x==3&&(y==0||y==7)){ x--; }

  locs+=('A'+x);
  locs+=('1'+y);
    
  return locs;
  
}
