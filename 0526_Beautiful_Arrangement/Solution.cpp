#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

void combinate(int N, vector<int>& nums, int& cnt) {
    if (N <= 0) {
	++cnt;
	return;
    }

    for (int i = 0 ; i < N ; ++i) {
	if (nums.at(i) % N == 0 || N % nums.at(i) == 0) {
	    swap(nums.at(N-1), nums.at(i));
	    combinate(N-1, nums, cnt);
	    swap(nums.at(N-1), nums.at(i));
	}
    }
}

int Solution::countArrangement(int N) {
    vector<int> nums;
    int cnt(0);
    for (int i = 1 ; i <= N ; ++i) {
	nums.emplace_back(i);
    }
    combinate(N, nums, cnt);
    return cnt;
}
