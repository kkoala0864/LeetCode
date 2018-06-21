#include <Solution.h>
#include <iostream>
#include <algorithm>
using namespace std;

void Solution::wiggleSort(vector<int>& nums) {
    if (2 > nums.size()) return;
    sort(nums.begin(), nums.end());
    int start = 1;
    int end = nums.size() & 1 ? nums.size()-1 : nums.size()-2;
    while (start < end) {
	swap(nums.at(start), nums.at(end));
	start += 2;
	end -= 2;
    }
}

void Solution::wiggleSort2(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0 ; i < size-1 ; ++i) {
	if (i & 1) {
	    if (nums.at(i) < nums.at(i+1)) swap(nums.at(i), nums.at(i+1));
	} else {
	    if (nums.at(i) > nums.at(i+1)) swap(nums.at(i), nums.at(i+1));
	}
    }
}

