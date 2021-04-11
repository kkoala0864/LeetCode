#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

int Solution::getSum(int a, int b) {
	int resultXor = a ^ b;
	int resultAnd = a & b;
	while (resultAnd != 0) {
		int tmpA = resultXor;
		int tmpB = resultAnd << 1;
		resultXor = tmpA ^ tmpB;
		resultAnd = tmpA & tmpB;
	}
	return resultXor;
}
