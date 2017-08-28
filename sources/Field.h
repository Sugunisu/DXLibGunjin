#ifndef _FIELD_
#define _FIELD_

#include <string>
#include "Koma.h"

using namespace std;

class CField{

  private:
    koma *pKomas[46];
    int komanum[2];

  public:
    void initialize();
    string intToStr(int loc);
    int strToInt(string loc);
    
    CField();
    void clear();
    int add(string loc, koma *p);
    koma* remove(string loc);
    void initializeOpponent();
    int move(string sloc ,string tloc);
    int exchange(string sloc,string tloc);
    int reverse();
    int getRank(string loc);
    side getTeam(string loc);
    int getKomaNum(side team){return komanum[team];}
};

#endif
