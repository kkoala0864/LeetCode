#include <Solution.h>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int Solution::Brute(vector<int>& nums, int k) {
    if (nums.empty()) {
	return 0;
    }

    size_t sizeNums = nums.size();

    int retCnt(0);

    for (size_t start = 0 ; start < sizeNums ; ++start) {
	int localSum(0);
	for (size_t end = start ; end < sizeNums ; ++end) {
	    localSum += nums.at(end);
	    if (localSum == k)
		++retCnt;
	}
    }
    return retCnt;
}

int Solution::subarraySum(vector<int>& nums, int k) {

    unordered_map <int, int> map;

    int sum = 0;
    map[0] = 1;
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
	sum+=nums[i];
	int find_v = sum - k;
	if (map.find(find_v) != map.end()) {
	    ret += map[find_v];
	}

	// sum+=nums[i];
	map[sum]++;
    }

    return ret;
}

