#ifndef _MESSENGER_H_
#define _MESSENGER_H_

#include <string>

using namespace std;

class Messenger{

protected:
        bool setFlag;
	string mes;

public:
	Messenger();
	virtual int send(string message);
	virtual int setMessage(string message);
	virtual string get();
	virtual bool isSet(){return setFlag;}
	virtual bool tryConnect(){return true;}
	virtual void setCounterpartMessenger(Messenger* mess){}
};

#endif
