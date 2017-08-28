#include "DXNetwork.h"
#include "DxLib.h"

DXNetwork::DXNetwork(int port){
  prt = port;
  asListner=true;
}

DXNetwork::DXNetwork(string ipstr,int port){
	this->setIP(ipstr);
	this->setPort(port);
}

void DXNetwork::setIP(string ipstr){
  stringstream ss(ipstr);   
  int d[4];
  char c;
  ss  >> d[0] >> c >> d[1] >> c >> d[2] >> c >> d[3];
  ip.d1=d[0];
  ip.d2=d[1];
  ip.d3=d[2];
  ip.d4=d[3];	
}

bool DXNetwork::tryConnect(){

    if(asListner){
      PreparationListenNetWork( prt ) ;
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
    NetWorkSend( NetHandle , (void *)message.c_str() , StrLength ) ;
  }
  return 0;
}

bool DXNetwork::isDead(){
   return  NetHandle == GetLostNetWork() ;
}

bool DXNetwork::gotMessage(){
  return GetNetWorkDataLength( NetHandle ) > sizeof(int);
}
