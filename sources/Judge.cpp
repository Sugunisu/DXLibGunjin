#include "Judge.h"
#include "TCPMessenger.h"
#include "DxLib.h"

#include <sstream>
#include <string>


  int battleTable[15][15]={
    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,1},
    {2,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,2,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,2,2,1,0,0,0,0,0,2,2,0,0,0,1},
    {2,2,2,2,1,0,0,0,0,2,2,0,0,0,1},
    {2,2,2,2,2,1,0,0,0,2,2,0,0,0,1},
    {2,2,2,2,2,2,1,0,0,2,2,0,0,0,1},
    {2,2,2,2,2,2,2,1,0,2,2,0,0,0,1},
    {2,2,2,2,2,2,2,2,1,2,2,0,0,0,1},
    {2,2,2,0,0,0,0,0,0,1,0,0,0,0,0},
    {2,2,2,0,0,0,0,0,0,2,1,0,0,0,1},
    {2,2,2,2,2,2,2,2,2,2,2,1,0,0,1},
    {2,2,2,2,2,2,2,2,2,2,2,2,1,0,0},
    {0,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
    {1,1,1,1,1,1,1,1,1,2,1,1,2,1,1},
  };

int battle(int atk, int def){
    return battleTable[atk-1][def-1];
}

string intToStr(int loc){
  if(loc<0||loc>46) return "XX";
  string ret="";

  if (loc>43) loc+=2;
  else if(loc>2) loc+=1;

  ret+=('A'+(loc%6));
  ret+=('1'+(int)(loc/6));

  return ret;
}

Judge::Judge(CField *field, Messenger *io_1, Messenger *io_2) : Participant(field){
ready1=false; ready2=false;
 io1=io_1; io2=io_2;
}



void Judge::update(){
  switch(prg){
    case PROGRESS_SETKOMA :

      //player1
      if(io1->isSet()){

        string buf = io1->get();
        DrawString(460,300,buf.c_str(),GetColor(0xff,0xff,0x00));
        stringstream ss(buf);

        for(int i=0;i<23;i++){
          int buf2;
          ss >> buf2;
          getline(ss,buf,'-');
          f->add(intToStr(i+23),new koma(buf2,WHITE));
        }
        if(!ready2){
          f->reverse();
        }
        ready1 = true;
      }

      if(io2->isSet()){

        string buf = io2->get();
        DrawString(460,300,buf.c_str(),GetColor(0x00,0xff,0x00));
        stringstream ss(buf);

        for(int i=0;i<23;i++){
          int buf2;
        
          ss >> buf2;
          getline(ss,buf,'-');
          f->add(intToStr(i+23),new koma(buf2,WHITE));
          

        }
          f->reverse();
        

        ready2 = true;
      }

      if(ready1&&ready2){
        //todo:‚±‚±‚Íƒ‰ƒ“ƒ_ƒ€‚É‚·‚é
        io1->send("W");
        io2->send("B");
        turn=0;
        prg = PROGRESS_BATTLE;
      }
    break;
    case PROGRESS_BATTLE :
DrawString(460,300,"OK!",GetColor(0xff,0xff,0xff));

      if(((turn%2==0)&&io1->isSet())||((turn%2==1)&&io2->isSet())){
        string buf;
        if(io1->isSet()){buf=io1->get();}
        else if(io2->isSet()){buf=io2->get();}
        string src = buf.substr(0,2);
        string dst = buf.substr(2,2);

        //No Battle
        if(f->getRank(dst)==0){
          f->move(src,dst);
          io1->send(buf);
          io2->send(buf);
        }

        // Battled
        else{
          
          int result = battle(f->getRank(src),f->getRank(dst));

          stringstream ss;
          string s1,s2;


          // Win Challenger
          if(result==0){

              string win = turn%2?"B":"W";
              koma *k;
              k=f->remove(dst);
              f->move(src,dst);
              ss << buf << win << k->getRank();
              ss >> s1;
              ss.clear();
              ss << buf << win;
              ss >> s2;
          }

          // Draw
          else if(result==1){
              koma *k1;
              koma *k2;
              k1=f->remove(src);
              k2=f->remove(dst);
              ss << buf << "D" << k2->getRank();
              ss >> s1;
			  ss.clear();
              ss << buf << "D" << k1->getRank();
              ss >> s2;
          }

          // Lose Challenger
          else if(result==2){
              string win = turn%2?"W":"B";
              koma *k;
              k=f->remove(src);
              ss << buf << win << k->getRank();
              ss >> s1;
			  ss.clear();
              ss << buf << win;
              ss >> s2;
          }
              if(turn%2==0){
                io1->send(s1);
                io2->send(s2);
              }
              else if(turn%2==1){
                io2->send(s2);
                io1->send(s1);
              }
        }
        turn++;
      }
      
    break;
    
    case PROGRESS_END :
        //todo:‚±‚±‚ÍŠû•ˆ‚ð‘—‚é
    break;
    
  }
}
