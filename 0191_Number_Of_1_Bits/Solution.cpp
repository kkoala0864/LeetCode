#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::hammingWeight(uint32_t n) {
    int cnt(0);
    uint32_t mask(1);
    while (mask) {
	if (n & mask) cnt += 1;
	mask = mask << 1;
    }
    return cnt;
}
