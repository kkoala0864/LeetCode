#include <Solution.h>
#include <iostream>
#include <cmath>
#include <unordered_map>
using std::unordered_map;

int Solution::longestConsecutive(vector<int>& nums) {
	unordered_map<int, bool> map;
	for (const auto& iter : nums) {
		map[iter] = true;
	}

	int maxLen = 0;
	for (const auto& iter : nums) {
		int cnt(1);
		int idx = iter;
		while (map[--idx]) {
			map[idx] = false;
			cnt += 1;
		}
		idx = iter;
		while (map[++idx]) {
			map[idx] = false;
			cnt += 1;
		}
		maxLen = maxLen > cnt ? maxLen : cnt;
	}
	return maxLen;
}
