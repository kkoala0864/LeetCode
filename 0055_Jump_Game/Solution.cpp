#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::canJump(vector<int>& nums) {
    if (nums.empty()) return true;
    int i = 0;
    for (int reach = 0 ; i < nums.size() && i <= reach ; ++i) {
	reach = max(i+nums.at(i), reach);
    }
    return i == nums.size();
}
