#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::findPeakElement(vector<int>& nums) {
    if (nums.empty()) {
	return -1;
    }

    for (int i = 1 ; i < nums.size() ; ++i) {
	if (nums.at(i) < nums.at(i-1)) {
	    return i;
	}
    }
    return 0;
}

