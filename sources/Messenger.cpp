#include "Messenger.h"

Messenger::Messenger(){
	mes="";
	setFlag=false;
}

int Messenger::send(string message){
  return 0;
}

string Messenger::get(){
  setFlag=false;
  return mes;
}


int Messenger::setMessage(string message){
	if(setFlag){
      return -1;
    }
	mes = message;
	setFlag=true;
	return 0;
}
