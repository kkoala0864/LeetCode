#include <Solution.h>
#include <iostream>

void combinate(vector<vector<int>>& res, vector<int> record, const vector<int>& nums, int idx) {
    if (idx == nums.size()) {
	res.emplace_back(record);
	return;
    }

    combinate(res, record, nums, idx+1);
    record.emplace_back(nums.at(idx));
    combinate(res, record, nums, idx+1);
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) return res;

    vector<int> record;
    combinate(res, record, nums, 0);
    return res;
}
