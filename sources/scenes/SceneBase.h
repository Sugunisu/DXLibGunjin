#ifndef _SCENE_BASE_
#define _SCENE_BASE_

#include "SceneChangeListner.h"
#include "PassDataMap.h"

//class SceneChangeListner;

class SceneBase{
	protected:
		SceneChangeListner* scl;
	public:
		SceneBase(SceneChangeListner* sc_listner,PassDataMap *pdm){scl = sc_listner;}
		virtual void update(){};
		virtual void draw(){};
};

#endif
