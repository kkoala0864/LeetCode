#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3) return ret;
    sort(nums.begin(), nums.end());

    for (int first(0) ; first < nums.size() ; ++first) {
	while (first > 0 && first < nums.size() && nums.at(first-1) == nums.at(first)) ++first;
	if (first == nums.size()) break;
	int left = first + 1, right = nums.size() - 1;
	int target = -nums.at(first);
	while (left < right) {
	    if (target == (nums.at(left) + nums.at(right))) {
		vector<int> ins = {nums.at(first), nums.at(left), nums.at(right)};
		ret.emplace_back(ins);
		--right;
		++left;
		while (right >= 0 && nums.at(right+1) == nums.at(right)) --right;
		while (left < nums.size() && nums.at(left-1) == nums.at(left)) ++left;
	    } else if (target < (nums.at(left) + nums.at(right))) {
		--right;
	    } else {
		++left;
	    }
	}
    }
    return ret;
}
