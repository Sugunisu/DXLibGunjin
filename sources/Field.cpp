#include "Field.h"



CField::CField(){
  this->clear();
}

void CField::clear(){
  for(int i=0;i<46;i++) pKomas[i] = NULL;
  komanum[0]=0;
  komanum[1]=0;
}

void CField::initializeOpponent(){
	this->add("A1",new koma(17,BLACK));
	this->add("B1",new koma(17,BLACK));
	this->add("C1",new koma(17,BLACK));

	this->add("E1",new koma(17,BLACK));
	this->add("F1",new koma(17,BLACK));
	this->add("A2",new koma(17,BLACK));
	this->add("B2",new koma(17,BLACK));
	this->add("C2",new koma(17,BLACK));
	this->add("D2",new koma(17,BLACK));
	this->add("E2",new koma(17,BLACK));
	this->add("F2",new koma(17,BLACK));
	
	this->add("A3",new koma(17,BLACK));
	this->add("B3",new koma(17,BLACK));
	this->add("C3",new koma(17,BLACK));
	this->add("D3",new koma(17,BLACK));
	this->add("E3",new koma(17,BLACK));
	this->add("F3",new koma(17,BLACK));
	this->add("A4",new koma(17,BLACK));
	this->add("B4",new koma(17,BLACK));
	this->add("C4",new koma(17,BLACK));
	this->add("D4",new koma(17,BLACK));
	this->add("E4",new koma(17,BLACK));
	this->add("F4",new koma(17,BLACK));

}

void CField::initialize(){
  this->clear();
  	this->add("A5",new koma(1,WHITE));
	this->add("B5",new koma(2,WHITE));
	this->add("C5",new koma(3,WHITE));
	this->add("D5",new koma(4,WHITE));
	this->add("E5",new koma(5,WHITE));
	this->add("F5",new koma(6,WHITE));
	this->add("A6",new koma(7,WHITE));
	this->add("B6",new koma(7,WHITE));
	this->add("C6",new koma(8,WHITE));
	this->add("D6",new koma(8,WHITE));
	this->add("E6",new koma(9,WHITE));
	this->add("F6",new koma(9,WHITE));

	this->add("A7",new koma(10,WHITE));
	this->add("B7",new koma(10,WHITE));
	this->add("C7",new koma(11,WHITE));
	this->add("D7",new koma(11,WHITE));
	this->add("E7",new koma(12,WHITE));
	this->add("F7",new koma(13,WHITE));

	this->add("A8",new koma(13,WHITE));
	this->add("B8",new koma(14,WHITE));
	this->add("C8",new koma(15,WHITE));
	this->add("E8",new koma(15,WHITE));
	this->add("F8",new koma(16,WHITE));
}

string CField::intToStr(int loc){
  if(loc<0||loc>46) return "XX";
  string ret="";

  if (loc>43) loc+=2;
  else if(loc>2) loc+=1;

  ret+=('A'+(loc%6));
  ret+=('1'+(int)(loc/6));

  return ret;
}

int CField::strToInt(string loc){
  int ret;
  if(loc[0]<'A'||loc[0]>'F'||loc[1]<'1'||loc[1]>'8') return -1;
  ret= ((loc[1]-'1')*6)+(loc[0]-'A');

  if (ret>44) ret-=2;
  else if(ret>2) ret-=1;

  return ret;
}

int CField::add(string loc, koma *p){

  if(pKomas[strToInt(loc)]!=NULL) return -1;
  pKomas[strToInt(loc)]=p;
  komanum[p->getTeam()]++;
  return 0;
}

koma* CField::remove(string loc){
  koma *ret;
  ret = pKomas[strToInt(loc)];
  komanum[ret->getTeam()]--;
  pKomas[strToInt(loc)]=NULL;
  return ret;
}

int CField::move(string sloc ,string tloc){
  if((pKomas[strToInt(sloc)]==NULL)||(pKomas[strToInt(tloc)]!=NULL)) return -1;

  pKomas[strToInt(tloc)] = pKomas[strToInt(sloc)];
  pKomas[strToInt(sloc)]=NULL;

  return 0;
}

int CField::exchange(string sloc,string tloc){
  koma *buf;
  //if((pKomas[strToInt(sloc)]==NULL)||(pKomas[strToInt(tloc)]==NULL)) return -1;
  buf = pKomas[strToInt(tloc)];
  pKomas[strToInt(tloc)] = pKomas[strToInt(sloc)];
  pKomas[strToInt(sloc)] = buf;

  return 0;
}

int CField::reverse(){
  for(int i=0;i<23;i++){
    if(pKomas[i]!=NULL){
      pKomas[i]->reverseTeam();
    }
    this->exchange(intToStr(i),intToStr(45-i));
    if(pKomas[i]!=NULL){
      pKomas[i]->reverseTeam();
    }
  }
  return 0;
}

int CField::getRank(string loc){
	int i=strToInt(loc);
	if(pKomas[i]!=NULL)
		return pKomas[i]->getRank();
	else
		return 0;
}

int CField::getTeam(string loc){
	int i=strToInt(loc);
  if(pKomas[i]!=NULL)
    return pKomas[i]->getTeam();
  else
    return NOTEAM;
}
