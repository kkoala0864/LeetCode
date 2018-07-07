#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int retIdx(1);

    for (int i = 1 ; i < nums.size() ; ++i) {
	if (nums.at(i) != nums.at(i-1)) {
	    nums.at(retIdx) = nums.at(i);
	    ++retIdx;
	}
    }
    return retIdx;
}
