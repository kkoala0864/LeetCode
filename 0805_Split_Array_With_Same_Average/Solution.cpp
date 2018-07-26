#include <Solution.h>
#include <iostream>
#include <cmath>

using namespace std;

bool check(vector<int>& A, int count, int idx, const double& average, int curSum) {
    if (count >= A.size()) return false;
    double targetSum = count * average;
    for (int i = idx+1 ; i < A.size() ; ++i) {
	if (abs((curSum + A.at(i)) - targetSum) < 0.0001) {
	    return true;
	}
	else if (curSum + A.at(i) < targetSum) {
	    if (check(A, count + 1, i, average, curSum + A.at(i))) {
		return true;
	    }
	} else {
	    break;
	}
    }
    return false;
}

bool Solution::splitArraySameAverage(vector<int>& A) {
    if (A.empty()) return true;
    sort(A.begin(), A.end());
    int sum(0);
    for (const int& val : A) {
	sum += val;
    }
    double average = (double)sum / (double)A.size();

    for (int i = 0 ; i < A.size() ; ++i) {
	if (abs(A.at(i) - average) < 0.00001) return true;
	else if (check(A, 2, i, average, A.at(i))) {
	    return true;
	}
	else break;
    }
    return false;
}
