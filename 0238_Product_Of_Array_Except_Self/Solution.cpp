#include <Solution.h>
#include <iostream>

using namespace std;

vector<int> Solution::productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return vector<int>();

    long long int total(1);
    int zeroCnt(0);
    for (const auto& idx : nums) {
	if (idx != 0)
	    total *= idx;
	else
	    ++zeroCnt;
    }

    vector<int> ret;
    for (const auto& idx : nums) {
	if (zeroCnt > 1) {
	    ret.emplace_back(0);
	} else if (zeroCnt == 1) {
	    if (idx != 0)
		ret.emplace_back(0);
	    else
		ret.emplace_back(total);
	} else {
	    ret.emplace_back(total/idx);
	}
    }
    return ret;
}
