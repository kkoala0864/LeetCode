#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::containsDuplicate(vector<int>& nums) {
	unordered_map<int, bool> hash;
	for (auto& iter : nums) {
		if (hash.find(iter) != hash.end() && hash[iter]) {
			return true;
		} else {
			hash[iter] = true;
		}
	}
	return false;
}
