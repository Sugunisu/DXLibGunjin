#ifndef _DXNETWORK_H_
#define _DXNETWORK_H_

#include "DxLib.h"
#include <string>
#include <sstream>

using namespace std;

class DXNetwork{

  private:

   int NetHandle;
   IPDATA ip;
   int prt;
   bool asListner;

  public:
    DXNetwork(int port);
    DXNetwork(string ipstr,int port);
    void setIP(string ipstr);
    void setPort(int port){prt = port;}
    bool tryConnect();
    string getMessage();
    int sendMessage(string message);
    bool isDead();
    bool gotMessage();

};


#endif
