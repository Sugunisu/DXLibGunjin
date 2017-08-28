#ifndef _KOMA_
#define _KOMA_

#include<string>

using namespace std;

typedef int side;

#define WHITE 0
#define BLACK 1
#define NOTEAM -1

class koma{

  private:
    int rank;
    side team;

  public:
    koma(int r, side t){ rank = r; team = t;}
    int getRank(){return rank;}
    side getTeam(){return team;}
	void reverseTeam(){if(team==WHITE){team=BLACK;} else if(team==BLACK){team=WHITE;} }
    string getKomaStr();
};

#endif