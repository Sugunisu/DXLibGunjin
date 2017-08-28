/*
#include "DxLib.h"

#include <sstream>
#include <string>
#include <fstream>
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


//CField f;
int state = 1;

class DXNetwork{

  private:

   int NetHandle;
   IPDATA ip;
   int prt;
   bool asListner;

  public:
    DXNetwork(int port);
    DXNetwork(string ipstr,int port);
    bool tryConnect();
    string getMessage();
    int sendMessage(string message);
    bool isDead();
    bool gotMessage();

};


DXNetwork::DXNetwork(int port){
  prt = port;
  asListner=true;
  PreparationListenNetWork( prt ) ;
}

bool DXNetwork::tryConnect(){

    if(asListner){
      NetHandle = GetNewAcceptNetWork() ;
      if( NetHandle == -1 ) return false ;
      StopListenNetWork() ;
      GetNetWorkIP( NetHandle , &ip ) ;
   }else{
      NetHandle = ConnectNetWork( ip, prt ) ;
      if( NetHandle == -1 ) return false ;
   }

   return true;

}

string DXNetwork::getMessage(){

  char StrBuf[ 256 ] ={0};
  int StrLength;

  if( GetNetWorkDataLength( NetHandle ) > sizeof( int ) ){

    // Packet Length
    NetWorkRecvToPeek( NetHandle , &StrLength , 4 ) ;

    if( StrLength + 4 <= GetNetWorkDataLength( NetHandle ) ){
      NetWorkRecv( NetHandle , &StrLength , 4 ) ;
      NetWorkRecv( NetHandle , StrBuf , StrLength ) ;
      //DrawString( 0 , 0 , StrBuf , GetColor( 255 , 255 , 255 ) ) ;
    }

  }

  return string(StrBuf);
}

int DXNetwork::sendMessage(string message){
  int StrLength = lstrlen( message.c_str() ); 
  if (StrLength>0){
    NetWorkSend( NetHandle , &StrLength , sizeof( int ) ) ;
    NetWorkSend( NetHandle , message.c_str() , StrLength ) ;
  }
  return 0;
}

bool DXNetwork::isDead(){
   return  NetHandle == GetLostNetWork() ;
}

DXNetwork::DXNetwork(string ipstr,int port){
  prt = port;
  stringstream ss(ipstr);   
  int d[4];
  char c;
  ss  >> d[0] >> c >> d[1] >> c >> d[2] >> c >> d[3];
  ip.d1=d[0];
  ip.d2=d[1];
  ip.d3=d[2];
  ip.d4=d[3];
}

bool DXNetwork::gotMessage(){
  return GetNetWorkDataLength( NetHandle ) > sizeof(int);
}

int init(){
    SetDoubleStartValidFlag( TRUE );
    ChangeWindowMode(TRUE);

    if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }

    SetDrawScreen( DX_SCREEN_BACK ) ;
    return 0;
}



int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    string mess;
    IPDATA Ip ;
    int state = 0;
    DXNetwork* dxnw;

    if(init()!=0) return -1;

    while(!ProcessMessage()&&(CheckHitKey( KEY_INPUT_ESCAPE )==0)){
	ClearDrawScreen();
      if(state==0){
        DrawString( 0 , 0 , "Zで通信待ち, XでローカルIPへ接続" , GetColor( 255 , 255 , 255 ) ) ;
        if(CheckHitKey( KEY_INPUT_Z )==1){
          dxnw = new DXNetwork(4274);
          state=1;
        }
        if(CheckHitKey( KEY_INPUT_X )==1){
          dxnw = new DXNetwork("192.168.0.50",4274);
          state=1;
        }
      }
      else if(state==1){
        DrawString( 0 , 0 , "通信中..." , GetColor( 255 , 255 , 255 ) ) ;        
        if(dxnw->tryConnect()) state=2;
      }
      else if(state==2){
         if(dxnw->gotMessage()){





         }

         DrawString( 0 , 0 , mess.c_str() , GetColor( 255 , 255 , 255 ) ) ;
        if(dxnw->isDead()) state=0;
      }
        ScreenFlip();
    }

    DxLib_End() ;    // ＤＸライブラリ使用の終了処理

    return 0 ;    // ソフトの終了
}
*/