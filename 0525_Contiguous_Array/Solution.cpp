#include <Solution.h>
#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;

int Solution::findMaxLength(vector<int>& nums) {
    if (nums.size() < 2) {
	return 0;
    }
    size_t sizeNums = nums.size();
    unordered_map<int, int> record;
    int count(0);
    int longestSize(0);
    for (size_t start = 0 ; start < sizeNums ; ++start) {
	count += nums[start] == 0 ? -1 : 1;
	if (0 != count && record[count] == 0) {
	    record[count] = start + 1;
	}
	if (0 == count) {
	    longestSize = start + 1;
	} else {
	    int localSize(0);
	    if (record[count] != start + 1) {
		localSize = start - record[count] + 1;
	    }
	    if (localSize > longestSize) {
		longestSize = localSize;
	    }
	}
    }
    return longestSize;
}

int Solution::findMaxLengthBrute(vector<int>& nums) {
    size_t sizeNums = nums.size();
    int gLongestSize(0);
    for (int i = 0 ; i < sizeNums ; ++i) {
	if (gLongestSize > (sizeNums - i + 1)) {
	    return gLongestSize;
	}
	int count(0);
	int localSize(0);
	for (int j = i ; j < sizeNums ; ++j) {
	    count += nums[j] == 0 ? -1 : 1;
	    if (count == 0) {
		localSize = j - i + 1;
	    }
	    if (localSize > gLongestSize) {
		gLongestSize = localSize;
	    }
	}
    }
}
