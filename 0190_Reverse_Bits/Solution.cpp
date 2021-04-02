#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

uint32_t Solution::reverseBits(uint32_t n) {
	uint32_t ret = 0;
	for (int i = 0 ; i < 31 ; ++i) {
		if (n & 1) {
			ret += 1;
		}
		n = n >> 1;
		ret = ret << 1;
	}
	if (n & 1) {
		ret += 1;
	}
	return ret;
}
