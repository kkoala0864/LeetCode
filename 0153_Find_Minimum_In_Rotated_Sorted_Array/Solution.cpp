#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::findMin(vector<int>& nums) {
    for (int i = 0 ; i < nums.size() - 1 ; ++i) {
	if (nums.at(i) > nums.at(i+1))
	    return nums.at(i+1);
    }
    return nums.at(0);
}
