#include "PlayerControler.h"
#include "PlayerView.h"

PlayerControler::PlayerControler(CField *field,Messenger *io_1){
  io = io_1;
  pm = new Player(field,io_1);
  pv = new PlayerView(field,pm,this);
}

void PlayerControler::update(){
  pv -> draw();
  pm -> update();
}

void PlayerControler::readyListner(){
  pm -> ready();
}

void PlayerControler::sendMessage(string message){
	io->send(message);
}
string PlayerControler::getMessage(){
	return io->get();
}
bool PlayerControler::gotMessage(){
	return io->isSet();
}
