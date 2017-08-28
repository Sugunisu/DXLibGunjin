#ifndef _VIEW_
#define _VIEW_


class View {
public:
	virtual void OnUpdate(){}
	virtual void OffUpdate(){}
	virtual void Draw(){}
	virtual bool IsOn(int x,int y){return false;}
	virtual bool IsShown(){return true;}
};

#endif
