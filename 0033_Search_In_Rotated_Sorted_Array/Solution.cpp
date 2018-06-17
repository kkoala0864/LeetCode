#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;

    int size = nums.size();
    int shift(0);
    for (int i = 1 ; i < size ; ++i) {
	if (nums.at(i) < nums.at(i-1))
	    shift = i;
    }

    int start(0), end(size-1);
    while (start <= end) {
	int mid = start + ((end - start) >> 1);
	if (nums.at((mid + shift) % size) > target) {
	    end = mid - 1;
	} else if (nums.at((mid + shift) % size) < target) {
	    start = mid + 1;
	} else {
	    return (mid + shift) % size;
	}
    }
    return -1;
}

