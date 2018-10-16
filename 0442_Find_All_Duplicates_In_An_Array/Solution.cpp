#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<int> Solution::findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (int i = 0 ; i < nums.size() ; ++i) {
	int idx = abs(nums.at(i)) - 1;
	if (nums.at(idx) < 0) res.emplace_back(idx + 1);
	nums[idx] = -nums[idx];
    }
    return res;
}
