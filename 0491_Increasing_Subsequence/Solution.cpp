#include <Solution.h>
#include <iostream>
#include <unordered_set>
using namespace std;

void helpF(const vector<int>& nums, int idx, vector<int>& res, vector<vector<int>>& ret) {
    if (res.size() > 1) ret.emplace_back(res);
    unordered_set<int> hash;
    for (int i = idx ; i < nums.size() ; ++i) {
	if ((!res.empty() && nums.at(i) < res.back()) || hash.find(nums.at(i)) != hash.end()) continue;
	res.emplace_back(nums.at(i));
	hash.emplace(nums.at(i));
	helpF(nums, i+1, res, ret);
	res.pop_back();
    }
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> res;
    helpF(nums, 0, res, ret);
    return ret;
}

