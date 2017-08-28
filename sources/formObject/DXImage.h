#ifndef _DX_IMAGE_
#define _DX_IMAGE_

#include "View.h"
#include "OnClickListener.h"

class DXImage : public View {

public:
	DXImage(int x, int y, int w, int h, const char* imgFileName);
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
	const char *mFileName;
	int mImgHandle;
	bool IsPressed;
	OnClickListener* mListener; 
	bool enable;
	bool visible;

};

#endif
