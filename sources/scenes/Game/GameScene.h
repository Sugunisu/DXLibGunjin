#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "../SceneBase.h"
#include "../../VsType.h"

#include "GameMgr.h"

class GameScene : public SceneBase{
	private:
		int type;
		GameMgr *gmgr;
	public:
    	GameScene(SceneChangeListner* sc_listner,PassDataMap *pdm);
    	void update();
    	void draw();
};

#endif
