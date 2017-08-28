#ifndef _FIELD_VIEW_
#define _FIELD_VIEW_

#include "Field.h"

typedef enum inputStyle{
  IS_UNENABLE=0,
  IS_EXCHANGE=1,
  IS_MOVE=2
} inputStyle_t;

class CFieldView{
  private:
    int img_koma[44];
    int img_board;
    bool hide_flag[2];
    CField *f;
    
    inputStyle_t is;
    
    int mx,my;
    string selectArea;
    bool selectFlag;

    static const int KOMA_W = 64;
    static const int KOMA_H = 32;
    static const int RIVER_H = 16;
    static const int COORDINATE_W = 16;
    static const int COORDINATE_H = 16;
    //static const int BOARD_MARGIN_L = 0;
    //static const int BOARD_MARGIN_T = 0;


  public:
    CFieldView(int x, int y, CField *field_p);
    void draw();
    bool update();
    int select(string sa);
    string getSelectArea(){return selectArea;}
    bool getSelectFlag(){return selectFlag;}
    void setSelctFlag(bool flag){selectFlag=flag;} 
    string cordToStr(int x,int y);
    void changeInputStyle(inputStyle_t style){is=style;}
    string getMove(){return selectArea;}
};

#endif
