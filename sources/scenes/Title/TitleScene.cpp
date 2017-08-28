#include "TitleScene.h"
#include "TitleView.h"
#include <DxLib.h>

TitleScene::TitleScene(SceneChangeListner *sc_listner, PassDataMap *pdm) : SceneBase(sc_listner,pdm)
{
  tm = NULL;
  tv = new TitleView(tm,this);	
}

void TitleScene::update()
{
	
}

void TitleScene::draw()
{
    tv->draw();
}

void TitleScene::startGame(tVsType type){
	PassDataMap *pdm = new PassDataMap();
	pdm->set("VS_TYPE", type);
	scl->SceneChange( SCENE_GAME, pdm );
}
