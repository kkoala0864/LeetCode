#include <Solution.h>

int Solution::addDigits(int num) {
	if ( !num )
		return num;

	if ( num % 9 )
		return num % 9;
	else
		return 9;
}
