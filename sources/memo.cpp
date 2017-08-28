/*
#include <iostream>
#include <sstream>
#include "Field.h"
#include "Koma.h"
using namespace std;

int table[16][16]={
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

int turn=0;

int battle(int atk, int def){
    return table[atk-1][def-1];
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


CField f;
int state = 1;

int main(){

  while(state!=0){
    if(state==1){
      string buf;
      cin >> buf;

      stringstream ss(buf);
      for(int i=0;i<23;i++){
        int buf2;
        
        ss >> buf2;
        getline(ss,buf,'-');
        f.add(intToStr(i+23),new koma(buf2,0));
      }
      f.reverse();
      cin >> buf;
      stringstream ss2(buf);
      for(int i=0;i<23;i++){
        int buf2;
        ss2 >> buf2;
        getline(ss2,buf,'-');
        f.add(intToStr(i+23),new koma(buf2,1));
      }
      cout << "W" << endl;
      cout << "B" << endl;
      turn=0;
      state = 2;
    }

    if(state==2){
      string buf;
      if(cin >> buf){
      string src = buf.substr(0,2),dst = buf.substr(2,2);
      cout << src << "->" << dst << endl;
      if(f.getRank(dst)==0){
          f.move(src,dst);
          cout << buf << endl;
          cout << buf << endl;
      }
      else{
          
          int result = battle(f.getRank(src),f.getRank(dst));
          cout << result<<endl;
          if(result==0){
              string win = turn%2?"B":"W";
              koma *k;
              k=f.remove(dst);
              f.move(src,dst);
              cout << buf+win<< k->getRank() << endl;
              cout << buf+win << endl;
          }
          else if(result==1){
              koma *k1;
              koma *k2;
              k1=f.remove(src);
              k2=f.remove(dst);
              cout << buf+"D" << k2->getRank() << endl;
              cout << buf+"D" << k1->getRank() << endl;
          }
          else if(result==2){
              string win = turn%2?"W":"B";
              koma *k;
              k=f.remove(src);
              cout << buf+win << k->getRank() << endl;
              cout << buf+win << endl;
          }
      }
      turn++;
      }else{
      state=0;
      }
    }
   
  
  }
}
*/