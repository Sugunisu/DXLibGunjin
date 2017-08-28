#ifndef _SCENE_MGR_
#define _SCENE_MGR_

#include "SceneBase.h"
#include "SceneChangeListner.h"
#include "Scenes.h"

class SceneMgr : public SceneChangeListner{
	private:
		SceneBase *nowScene;
		scenes_t nowSceneID;
	 
	public:
		SceneMgr();
		void update();
		void SceneChange(scenes_t scene, PassDataMap *pdm);
};

#endif
