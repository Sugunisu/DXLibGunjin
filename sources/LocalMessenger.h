#ifndef _LOCAL_MESSENGER_H_
#define _LOCAL_MESSENGER_H_

#include "Messenger.h"
#include <string>

using namespace std;

class LocalMessenger :public Messenger{

private:
    Messenger *counterMess;

public:
	LocalMessenger();
	void setCounterpartMessenger(Messenger* mess);
	int send(string message);
	string get();
	bool isSet(){return setFlag;}
	bool tryConnect(){return true;}
};

#endif
