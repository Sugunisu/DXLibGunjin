#include "TitleControler.h"
#include "TitleView.h"
#include "DxLib.h"

TitleControler::TitleControler(){
  //tm = new TitleModel();
  tm = NULL;
  tv = new TitleView(tm,this);
}

void TitleControler::update(){
  tv -> draw();
  //tm -> update();
}

void TitleControler::startGame(tVsType type){
	
}

