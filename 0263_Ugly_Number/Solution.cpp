#include <Solution.h>
#include <iostream>
#include <cmath>
using namespace std;
bool Solution::isUgly(int num) {
	if (1 == num)
		return true;
	if (0 >= num)
		return false;
	for ( int i = 5 ; i > 1 && num ; --i ) {
		while ( 0 == num % i ) {
			num /= i;
		}
	}
	return 1 == num;

}

