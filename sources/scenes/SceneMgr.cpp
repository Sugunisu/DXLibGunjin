#include "SceneMgr.h"

#include "Title/TitleScene.h"
#include "Game/GameScene.h"

SceneMgr::SceneMgr(){
	PassDataMap *pdm = new PassDataMap();
	nowScene = new TitleScene(this, pdm);
	nowSceneID = SCENE_TITLE;
}

void SceneMgr::update(){
	nowScene -> update();
	nowScene -> draw();
}

void SceneMgr::SceneChange(scenes_t scene, PassDataMap *pdm){
	switch(scene){
		case SCENE_TITLE :
			nowScene = new TitleScene(this, pdm);
		break;
		case SCENE_SETTING :
		break;
		case SCENE_GAME :
			nowScene = new GameScene(this, pdm);
		break;
	}
	nowSceneID = scene;
}
