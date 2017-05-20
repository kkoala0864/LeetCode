#include <Solution.h>
#include <iostream>
#include <iterator>

using namespace std;

/* xor x and y and traverse the binary format */
int Solution::hammingDistance(int x, int y) {
    int xorResult = x ^ y;
    unsigned int shift = 0;
    unsigned int count = 0;
    if (x == y) {
	return 0;
    }
    while (32 > shift) {
	if (xorResult & 0x1) {
	    ++count;
	}
	xorResult = xorResult >> 1;
	++shift;
    }

    return count;
}
