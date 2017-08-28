#include "Player.h"
#include "PlayerView.h"
#include "DxLib.h"

class PlayerController{

  private:
    Player *p;
    PlayerView *pv;
    Field *f;
    FieldView *fv

  public:

    PlayerController(){
      f  =  new Field();
      f  -> initialize();
      fv =  new FieldView(f);

      p  =  new Player(f);
      pv =  new PlayerView(p);

    }
    int readyListener(){
      p->ready();
      pv->ready();
    }
    int exchangeListner(string src, string dst){
      p->
    };
}