#include "Koma.h"

string koma::getKomaStr(){
	switch(rank){
	case 0:
		return "³΅";
	case 1:
		return "ε«";
	case 2:
		return "«";
	case 3:
		return "­«";
	case 4:
		return "ε²";
	case 5:
		return "²";
	case 6:
		return "­²";
	case 7:
		return "εΡ";
	case 8:
		return "Ρ";
	case 9:
		return "­Ρ";
	case 10:
		return "ΛΊ°·";
	case 11:
		return "ΐέΈ";
	case 12:
		return "RΊ";
	case 13:
		return "HΊ";
	case 14:
		return "½Κί²";
	case 15:
		return "n";
	case 16:
		return "Rψ";


	default:
		return "sΎ";

	}
}