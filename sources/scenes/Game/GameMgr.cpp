#include "GameMgr.h"
#include "Dxlib.h"

GameMgr::GameMgr(VsType *t){

        vt = t;
	switch(vt->getVsType()){

        case VST_COMPUTER:
        	//unimplemented
        break;

        case VST_HOST:
    		f  = new CField();
			f->initialize();
			fj = new CField();
			io_a1 = new LocalMessenger();
			io_a2 = new LocalMessenger();
			io_b1 = new TCPMessenger(4274);
			
			io_a1->setCounterpartMessenger(io_a2);
			io_a2->setCounterpartMessenger(io_a1);
        	
			pc = new PlayerControler(f,io_a1);
        	j = new Judge(fj,io_a2,io_b1);
        break;

        case VST_GUEST:
			f  = new CField();
			f->initialize();
			io_a1 = new TCPMessenger("192.168.0.4",4274);
        	pc = new PlayerControler(f,io_a1);
        break;

        case VST_JUDGE:
			fj = new CField();
			io_a1 = new TCPMessenger(4274);
    	    io_b1 = new TCPMessenger(4274);
			j  = new Judge(fj,io_a1,io_b1);
        break;
	}
	state = GMS_INPUT;
}

int GameMgr::run(){
	switch(state){
		case GMS_INPUT :
			switch(vt->getVsType()){
				case VST_COMPUTER:
					// NO_INPUT
				break;
				case VST_HOST:
					DrawString(460,100,"Connecting as HOST...",GetColor(0xff,0xff,0xff)); 
					if(io_b1->tryConnect()){
						state=GMS_GAME;
					}
				break;
				
				case VST_GUEST:
					DrawString(460,100,"Connecting as GUEST...",GetColor(0xff,0xff,0xff)); 
					if(io_a1->tryConnect()){	
						state=GMS_GAME;
					}
				break;
				
				case VST_JUDGE:
					
				break;
			}
			state = GMS_CONNECT;
		break;
		case GMS_CONNECT :
			switch(vt->getVsType()){
				case VST_COMPUTER:
					// NO_NETWORK
				break;
				case VST_HOST:
					DrawString(460,100,"Connecting as HOST...",GetColor(0xff,0xff,0xff)); 
					if(io_b1->tryConnect()){
						state=GMS_GAME;
					}
				break;
				
				case VST_GUEST:
					DrawString(460,100,"Connecting as GUEST...",GetColor(0xff,0xff,0xff)); 
					if(io_a1->tryConnect()){	
						state=GMS_GAME;
					}
				break;
				
				case VST_JUDGE:
					//unimplemented
				break;
			}
		break;
		case GMS_GAME :
			switch(vt->getVsType()){
				case VST_COMPUTER:
					//unimplemented
				break;
				case VST_HOST:
					j->update();
					pc->update();
				break;
				case VST_GUEST:
					pc->update();
				break;
				case VST_JUDGE:
					//unimplemented
				break;
			}
		break;
	}


	return 0;

}
