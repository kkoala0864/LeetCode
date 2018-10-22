#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
using std::min;
void combinate(vector<vector<int>>& res, vector<int>& record, int k, int n) {
    if (record.size() == k) {
	int sum(0);
	for (const auto& val : record) {
	    sum += val;
	    if (sum > n) return;
	}
	if (sum == n) {
	    res.emplace_back(record);
	}
	return;
    }

    for (int i = record.back() + 1; i < min(10,n) ; ++i) {
	record.emplace_back(i);
	combinate(res, record, k, n);
	record.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum3(int k, int n) {
    vector<vector<int>> res;
    if (n < k) return res;
    vector<int> record;
    for (int i = 1 ; i < min(10, n-3) ; ++i) {
	record.emplace_back(i);
	combinate(res, record, k, n);
	record.pop_back();
    }
    return res;
}
