#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

int Solution::nthUglyNumber(int n) {
	vector<int> result(1,1);
	int idx2(0), idx3(0), idx5(0);
	while (result.size() < n) {
		result.push_back(min(result[idx2] * 2, min(result[idx3] * 3, result[idx5] * 5)));
		if (result.back() == result[idx2] * 2) ++idx2;
		if (result.back() == result[idx3] * 3) ++idx3;
		if (result.back() == result[idx5] * 5) ++idx5;
	}
	return result.back();
}
