#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::findDuplicate(vector<int>& nums) {
    int slow = nums.at(0), fast = nums.at(nums.at(0));
    while (slow != fast) {
	slow = nums.at(slow);
	fast = nums.at(nums.at(fast));
    }
    slow = 0;
    while (slow != fast) {
	slow = nums.at(slow);
	fast = nums.at(fast);
    }
    return slow;
}
