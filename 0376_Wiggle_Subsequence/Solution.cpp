#include <Solution.h>
#include <iostream>

using std::max;

int Solution::wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;

    int p(1), q(1);
    for (int i = 1 ; i < nums.size() ; ++i) {
	int diff = nums.at(i) - nums.at(i-1);
	if (diff > 0) p = q + 1;
	else if (diff < 0) q = p + 1;
    }
    return max(p, q);
}
