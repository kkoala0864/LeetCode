#include <Solution.h>
#include <iostream>

using namespace std;

void Solution::sortColors(vector<int>& nums) {
    vector<int> cnt(3, 0);

    for (int i = 0 ; i < nums.size() ; ++i) {
	++cnt.at(nums.at(i));
    }

    int numsIdx(0);
    for (int i = 0 ; i < 3 ; ++i) {
	for (int j = 0 ; j < cnt.at(0) ; ++j) {
	    nums.at(numsIdx++) = i;
	}
    }
}

