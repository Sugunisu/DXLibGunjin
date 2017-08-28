#include "Koma.h"

string koma::getKomaStr(){
	switch(rank){
	case 0:
		return "–³‚µ";
	case 1:
		return "‘å«";
	case 2:
		return "’†«";
	case 3:
		return "­«";
	case 4:
		return "‘å²";
	case 5:
		return "’†²";
	case 6:
		return "­²";
	case 7:
		return "‘åˆÑ";
	case 8:
		return "’†ˆÑ";
	case 9:
		return "­ˆÑ";
	case 10:
		return "Ëº°·";
	case 11:
		return "Àİ¸";
	case 12:
		return "‹R•º";
	case 13:
		return "H•º";
	case 14:
		return "½Êß²";
	case 15:
		return "’n—‹";
	case 16:
		return "ŒRŠø";


	default:
		return "•s–¾";

	}
}