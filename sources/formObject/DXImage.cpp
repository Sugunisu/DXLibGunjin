#include <DxLib.h>
#include "DXImage.h"

DXImage::DXImage(int x, int y, int w, int h, const char* str) : 
 mListener(NULL)
,IsPressed(false)
{
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	mFileName = str;
	mImgHandle = LoadGraph(str);
	enable = true;
	visible = true;
}

void DXImage::OnUpdate(){
	if(Mouse::Instance()->GetPressingCount(Mouse::LEFT)==0 || !enable || !visible){
		IsPressed = false;
	}
	else{
		mListener->OnClick(this);
		IsPressed = true;
	}
}

void DXImage::OffUpdate(){
	IsPressed = false;
}

void DXImage::Draw(){
	
	if(visible){
	
		DrawGraph(mX, mY, mImgHandle,TRUE);		 
	}
	
	
}

void DXImage::SetOnClickListener(OnClickListener* listener){
	mListener = listener;
}

bool DXImage::IsOn(int x,int y){
	return (mX<=x && x<=mX+mW && mY<=y && y<=mY+mH);
}
