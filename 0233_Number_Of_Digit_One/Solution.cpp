#include <Solution.h>
#include <cmath>

int Solution::countDigitOne(int n) {
	if (n < 0) return 0;

	unsigned long int ret(0);
	int index(0);

	while (n/pow(10, index) >= 1) {
		unsigned long int base = pow(10 ,index);
		int cur_loc = (n / base) % 10;
		unsigned long int iter(0);
		if (0 == cur_loc) {
			iter = (n / (base * 10)) * base;
		} else if (1 == cur_loc) {
			iter = ((n / (base * 10)) * base) + (n % base + 1);
		} else {
			iter = ((n / (base * 10)) + 1) * base;
		}
		ret += iter;
		++index;
	}
	return ret;
}
