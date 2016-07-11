#include <Solution.h>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> Solution::countBits(int num) {
	vector<int> retVal;
	unsigned int PowerOfTwo = 0;
	while ( num > ( 1 << PowerOfTwo ) ) {
		++PowerOfTwo;
	}
	for ( unsigned int j = 0; j <= num ; ++j ) {
		unsigned int count = 0;
		unsigned int val = j;
		for ( unsigned int i = 0 ; i <= PowerOfTwo ; ++i ) {
			count += ( val >> i ) & 0x1;
		}
		retVal.push_back(count);
	}
	return retVal;
}

void Solution::DebugPrint(vector<int> nums) {
}
