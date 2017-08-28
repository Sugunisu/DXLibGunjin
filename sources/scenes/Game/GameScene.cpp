#include "GameScene.h"
#include "../PassDatamap.h"


GameScene::GameScene(SceneChangeListner *sc_listner, PassDataMap *pdm) : SceneBase(sc_listner,pdm){
	type = pdm->get("VS_TYPE");
	VsType *vst = new VsType(type);
	
	gmgr = new GameMgr(vst);
}

void GameScene::update(){
	gmgr->run();
}

void GameScene::draw(){
}
