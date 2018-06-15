#include <Solution.h>
#include <iostream>

using namespace std;

int low_bnd(int start, int end, vector<int>& vec, int val) {
    while (end > start) {
	int mid = (start + end) / 2;
	if (vec.at(mid) > val) {
	    end = mid;
	} else if (vec.at(mid) < val) {
	    start = mid+1;
	} else {
	    return mid;
	}
    }
    return start;
}

int Solution::lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> ret;
    ret.emplace_back(nums.at(0));
    for (int i = 1 ; i < nums.size() ; ++i) {
	int cur = nums.at(i);
	int idx = low_bnd(0, ret.size(), ret, cur);
	if (idx == ret.size()) ret.emplace_back(cur);
	else ret.at(idx) = cur;
    }
    return ret.size();
}
