#include "Koma.h"

string koma::getKomaStr(){
	switch(rank){
	case 0:
		return "����";
	case 1:
		return "�叫";
	case 2:
		return "����";
	case 3:
		return "����";
	case 4:
		return "�卲";
	case 5:
		return "����";
	case 6:
		return "����";
	case 7:
		return "���";
	case 8:
		return "����";
	case 9:
		return "����";
	case 10:
		return "˺��";
	case 11:
		return "�ݸ";
	case 12:
		return "�R��";
	case 13:
		return "�H��";
	case 14:
		return "��߲";
	case 15:
		return "�n��";
	case 16:
		return "�R��";


	default:
		return "�s��";

	}
}