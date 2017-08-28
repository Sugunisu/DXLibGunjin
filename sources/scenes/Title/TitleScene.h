#ifndef _TITLE_SCENE_H_
#define _TITLE_SCENE_H_

#include "../SceneBase.h"
#include "../PassDataMap.h"

#include "../../VsType.h"

//#include "TitleModel.h"

class TitleModel;
class TitleView;

class TitleScene : public SceneBase{
	private:
		TitleModel *tm;
		TitleView *tv;
		
	public:
    	TitleScene(SceneChangeListner* sc_listner,PassDataMap *pdm);
    	void update();
    	void draw();
    	void startGame(tVsType type);
};

#endif
