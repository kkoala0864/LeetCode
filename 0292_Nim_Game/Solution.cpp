#include <Solution.h>
#include <iostream>

bool Solution::canWinNim (int n) {
	if ( n % 4 ) {
		return true;
	} else {
		return false;
	}
}

void Solution::DebugPrint() {
	std::cout << "This is 0292 Debug Print Function" << std::endl;
}
