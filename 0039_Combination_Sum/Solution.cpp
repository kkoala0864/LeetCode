#include <Solution.h>
#include <iostream>

void help(vector<int>& candidates, vector<int>& record, int target, vector<vector<int>>& res, int begin) {
    if (0 == target) {
	res.emplace_back(record);
    }
    for (int i = begin ; i < candidates.size() ; ++i) {
	if (candidates.at(i) <= target) {
	    record.emplace_back(candidates.at(i));
	    help(candidates, record, target - candidates.at(i), res, i);
	    record.pop_back();
	}
    }
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if (candidates.empty()) return res;
    vector<int> record;
    help(candidates, record, target, res, 0);
    return res;
}

