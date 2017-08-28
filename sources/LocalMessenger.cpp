#include "LocalMessenger.h"

LocalMessenger::LocalMessenger(){
	mes="";
	setFlag=false;
}

string LocalMessenger::get(){
  setFlag=false;
  return mes;
}

void LocalMessenger::setCounterpartMessenger(Messenger* mess){
	counterMess=mess;
}

int LocalMessenger::send(string message){
  if(setFlag){
    return -1;
  }
  counterMess->setMessage(message);
  return 0;
}
