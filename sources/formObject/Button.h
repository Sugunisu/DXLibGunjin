#ifndef _BUTTON_
#define _BUTTON_

#include "View.h"
#include "OnClickListener.h"

class Button : public View {

public:
	Button(int x, int y, int w, int h, const char* str);
	void OnUpdate();
	void OffUpdate();
	void Draw();
	void SetOnClickListener(OnClickListener* listener);
    bool IsOn(int x,int y);
    
    void Activate(){enable=true;}
    void Inactivate(){enable=false;}
    
    void Hide(){visible=false;}
    void Show(){visible=true;}
    bool IsShown(){return visible;}


private:
	int mX, mY, mW, mH;
	const char *mStr;
	bool IsPressed;
	OnClickListener* mListener; 
	bool enable;
	bool visible;

};

#endif
