#ifndef SCENE_CHANGE_LISTNER_H
#define SCENE_CHANGE_LISTNER_H

#include "Scenes.h"
#include "SceneBase.h"
#include "PassDataMap.h"

class SceneChangeListner{
	public:
		SceneChangeListner(){}
		virtual void SceneChange(scenes_t scene, PassDataMap *pdm){}
};

#endif
