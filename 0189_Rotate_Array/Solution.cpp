#include <Solution.h>
#include <iostream>

using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (end >= start) {
	swap(nums.at(end), nums.at(start));
	++start;
	--end;
    }
}

void Solution::rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = k % size;
    if (k == 0) return;
    reverse(nums, 0, size - 1 - k);
    reverse(nums, size-k, size -1);
    reverse(nums, 0, size-1);
}
