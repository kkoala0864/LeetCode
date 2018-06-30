#include <Solution.h>
#include <iostream>
#include <unordered_set>
using namespace std;

void permutation(vector<int>& nums, int idx, vector<vector<int>>& ret) {
    if (idx == nums.size() - 1) {
	ret.emplace_back(nums);
	return;
    }

    unordered_set<int> flag;
    for (int i = idx ; i < nums.size() ; ++i) {
	if (flag.find(nums.at(i)) != flag.end()) continue;
	swap(nums.at(idx), nums.at(i));
	permutation(nums, idx+1, ret);
	swap(nums.at(idx), nums.at(i));
	flag.emplace(nums.at(i));
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.empty()) return ret;

    permutation(nums, 0, ret);
    return ret;
}

void permutation2(vector<int> nums, int idx, vector<vector<int>>& ret) {
    if (idx == nums.size() - 1) {
	ret.emplace_back(nums);
	return;
    }

    for (int i = idx ; i < nums.size() ; ++i) {
	if (i != idx && nums.at(i) == nums.at(idx)) continue;
	swap(nums.at(idx), nums.at(i));
	permutation2(nums, idx+1, ret);
    }
}

vector<vector<int>> Solution::permuteUnique2(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.empty()) return ret;

    sort(nums.begin(), nums.end());
    permutation2(nums, 0, ret);
    return ret;
}
