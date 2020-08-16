#include <Solution.h>
#include <iostream>

using std::endl;
using std::cout;

bool check(int minWeight, const vector<int>& weight, int D) {
	int localSum(0);
	for (const auto& iter : weight) {
		if ((localSum + iter) > minWeight) {
			localSum = iter;
			D -= 1;
		} else {
			localSum += iter;
		}
	}
	return D > 0;
}

int Solution::shipWithinDays(vector<int>& weights, int D) {
	int lowBound(0);
	int upperBound(0);

	for (const auto iter : weights) {
		lowBound = lowBound < iter ? iter : lowBound;
		upperBound += iter;
	}

	int mid(0);
	bool result(false);
	while ((upperBound - lowBound) > 1) {
		mid = (upperBound + lowBound) / 2;
		result = check(mid, weights, D);
		if (result) upperBound = mid;
		else lowBound = mid;
	}
	return check(lowBound, weights, D) ? lowBound : upperBound;
}

