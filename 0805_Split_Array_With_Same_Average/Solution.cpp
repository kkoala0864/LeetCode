#include <Solution.h>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <numeric>

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

bool Solution::splitArraySameAverageTLE(vector<int>& A) {
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

// totalSum / n == A_Sum / k == B_Sum / (n-k)
// totalSum * k / n = A_Sum
// A_Sum must be an integer => (totalSum * k) % n == 0
//
// sum[i][j] = sum of A[0 ~ i] of j element
// sum[i][j] = sum[i-1][j] join sum[i][j-1] + A[i]
bool Solution::splitArraySameAverage(vector<int>& A) {
    int n = A.size(), m = n/2;
    int totalSum = accumulate(A.begin(), A.end(), 0);
    bool isPossible = false;
    for (int i = 1 ; i <= m && !isPossible; ++i)
	if (totalSum*i % n == 0) isPossible = true;
    if (!isPossible) return false;

    vector<unordered_set<int>> sums(m + 1);
    sums[0].emplace(0);
    for (const int& num : A) {
	for (int i = m ; i >= 1 ; --i) {
	    for (const int& t : sums[i-1]) {
		sums[i].emplace(t + num);
	    }
	}
    }
    for (int i = 1 ; i <= m ; ++i) {
	if (totalSum * i % n == 0 && sums[i].find(totalSum * i / n) != sums[i].end()) {
	    return true;
	}
    }
    return false;
}

bool kSum(vector<int>& A, int start, int k, int target, int len){
    if (k == 0) return target == 0;
    if (k * A[start] < target || k * A[len-1] > target) return false;
    for (int i = start ; i <= len-k ; ++i) {
	if (A[i] <= target && kSum(A, i+1, k-1, target-A[i], len)) return true;
    }
    return false;
}

bool Solution::splitArraySameAverageFast(vector<int>& A) {
    int len = A.size(), total = 0, k;
    sort(A.rbegin(),A.rend()); //reverse, hard to think, but improve performance
    for (k = 0 ; k < len ; k++) total += A[k];
    for (k = 1 ; k <= len/2 ; ++k) {
	if (total*k%len == 0 && kSum(A, 0, k, total*k/len, len)) return true;
    }
    return false;
}

