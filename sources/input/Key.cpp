#include "Key.h"
#include <DxLib.h>

Key::Key()
{
    memset(mKeyPressingCount,  0, sizeof(mKeyPressingCount) );
    memset(mKeyReleasingCount, 0, sizeof(mKeyReleasingCount));
}


bool Key::Update(){
	char nowInput[KEY_NUM];
	GetHitKeyStateAll(nowInput);
    for(int i=0; i<KEY_NUM; i++){ 
        if(nowInput[i]&0x01){               // key pressed
            if(mKeyReleasingCount[i] > 0){
                mKeyReleasingCount[i] = 0;
            }
            mKeyPressingCount[i]++;
        } else {                            // key released
            if(mKeyPressingCount[i] > 0){
                mKeyPressingCount[i] = 0;
            }
            mKeyReleasingCount[i]++;         
        }
    }
    return true;
}


int Key::GetPressingCount(int keyCode){
	
    if(!Key::IsAvailableCode(keyCode)){
        return -1;
    }
	
    return mKeyPressingCount[keyCode];
}


int Key::GetReleasingCount(int keyCode){
    if(!Key::IsAvailableCode(keyCode)){
        return -1;
    }
    return mKeyReleasingCount[keyCode];
}


bool Key::IsAvailableCode(int keyCode){
    if(0<=keyCode && keyCode<KEY_NUM){
        return true;
    }
    return false;
}


