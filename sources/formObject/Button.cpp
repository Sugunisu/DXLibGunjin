#include <DxLib.h>
#include "Button.h"

Button::Button(int x, int y, int w, int h, const char* str) : 
 mListener(NULL)
,IsPressed(false)
{
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	mStr = str;
	enable = true;
	visible = true;
}

void Button::OnUpdate(){
	if(!enable || !visible){
		IsPressed = false;
	}
	else if(Mouse::Instance()->GetPressingCount(Mouse::LEFT)==0){
		if(IsPressed==true){
			mListener->OnClick(this);
		}
		IsPressed = false;
	}
	else{
		IsPressed = true;
	}
}

void Button::OffUpdate(){
	IsPressed = false;
}

void Button::Draw(){
	
	int sub=1;
	
	if(IsPressed && enable){
		sub = 3;
	}
	int strW = GetDrawStringWidth(mStr, strlen(mStr));

	if(visible){
		
		DrawBox(mX, mY, mX+mW, mY+mH, GetColor(0xa0,0xa0,0xa0),TRUE);
		DrawBox(mX+sub, mY+sub, mX+mW+sub-4, mY+mH+sub-4, GetColor(0xc0,0xc0,0xc0),TRUE);
		int strX = mX+mW/2-strW/2;
		int strY = mY+mH/2-DEFAULT_FONT_SIZE/2;
		if(enable){
			DrawString(strX,strY,mStr,GetColor(0,0,0));
		}
		else{
			DrawString(strX,strY,mStr,GetColor(0x90,0x90,0x90));
		}
			 
	}
	
	
}

void Button::SetOnClickListener(OnClickListener* listener){
	mListener = listener;
}

bool Button::IsOn(int x,int y){
	return (mX<=x && x<=mX+mW && mY<=y && y<=mY+mH);
}
