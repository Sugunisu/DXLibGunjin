#include "Player.h"
#include "DxLib.h"
#include <sstream>

string getOpponent(string s){
	string ret="";
	if(s=="C1"){return "C8";}
	if(s=="C8"){return "C1";}
	ret+='F'- (s[0]-'A');
	ret+='8'- (s[1]-'1');
	return ret;
}

Player::Player(CField *field,Messenger *io_1) : Participant(field){
  //fv=fieldv;
  src="XX";
  dst="XX";
  is_ready=false;
  is_sent =false;
  is_white=false;
  io=io_1;
}

string iToStr(int loc){
  if(loc<0||loc>46) return "XX";
  string ret="";

  if (loc>43) loc+=2;
  else if(loc>2) loc+=1;

  ret+=('A'+(loc%6));
  ret+=('1'+(int)(loc/6));

  return ret;
}

void Player::update(){
  switch(prg){
    case PROGRESS_SETKOMA :
      if(is_ready&&!is_sent){
        string buf="";
        for(int i=0;i<23;i++){
        	stringstream ss;
        	string buf2;
        	ss << f->getRank(iToStr(i+23));
        	ss >> buf2;
          buf+= buf2;
          if(i!=22) buf+="-";
        }
        io->send(buf);
        is_sent = true;
	  }
	  else if(is_sent){
    	if(io->isSet()){
    	
        string buf = io->get();
        if(buf=="W"){
        	is_white = true;
		}
		else if(buf=="B"){
			is_white = false;
		}
		
		f->initializeOpponent();
		
        prg = PROGRESS_BATTLE;
      }
  }
    break;
    case PROGRESS_BATTLE :
    	static string buf="";
    	static string buf2="";
    	static string buf3="";
    	DrawString(460,100,buf.c_str(),GetColor(0xff,0xff,0xff));
    	DrawString(460,120,buf2.c_str(),GetColor(0xff,0xff,0xff));
    	DrawString(460,140,buf3.c_str(),GetColor(0xff,0xff,0xff));
    	if(io->isSet()){
		
			if((turn%2==1 && is_white)||(turn%2==0 && !is_white)){
				//string buf;
				buf = io->get();
				
				
				string src = buf.substr(0,2);
				string dst = buf.substr(2,2);
				
				if(!is_white){
					src = getOpponent(src);
					dst = getOpponent(dst);
				}
				buf2 = src;
				
				if(buf.size()>4){
					string winners=buf.substr(4,1);
					buf3 = winners;
					
					if((winners=="W" && is_white) ||
					   (winners=="B" && !is_white)){
					   	f->remove(src);
					}else if((winners=="B" && is_white) ||
					         (winners=="W" && !is_white)){
					    f->remove(dst);
					   	f->move(src,dst);
					}else if(winners=="D"){
						f->remove(src);
						f->remove(dst);
					}
					
					   	
				}
				
			}
			
 			else if((turn%2==0 && is_white)||(turn%2==1 && !is_white)){
				//string buf;
				buf = io->get();
				string src = buf.substr(0,2);
				string dst = buf.substr(2,2);
				if(!is_white){
					src = getOpponent(src);
					dst = getOpponent(dst);
				}
				if(buf.size()>4){
					string winners=buf.substr(4,1);
					if((winners=="W" && is_white) ||
					   (winners=="B" && !is_white)){
					   	f->remove(dst);
					   	f->move(src,dst);
					   	
					}else if((winners=="B" && is_white) ||
					         (winners=="W" && !is_white)){
					    f->remove(src);
					}else if(winners=="D"){
						f->remove(src);
						f->remove(dst);
					}
					         	
				}
			}
			
			turn++;
		}
    break;
    case PROGRESS_END :
    break;

  }
}
