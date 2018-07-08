#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::romanToInt(string s) {
    int size = s.size();
    int idx(0);
    int retVal(0);
    while (idx < size) {
	    switch (s.at(idx)) {
		case 'I' :
		    retVal += 1;
		    break;
		case 'V' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'I') retVal += 3;
		    else retVal += 5;
		    break;
		case 'X' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'I') retVal += 8;
		    else retVal += 10;
		    break;
		case 'L' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'X') retVal += 30;
		    else retVal += 50;
		    break;
		case 'C' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'X') retVal += 80;
		    else retVal += 100;
		    break;
		case 'D' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'C') retVal += 300;
		    else retVal += 500;
		    break;
		case 'M' :
		    if ((idx-1 >= 0) && s.at(idx-1) == 'C') retVal += 800;
		    else retVal += 1000;
		    break;
		default :
		    ;
	    }
	++idx;
    }
    return retVal;
}
