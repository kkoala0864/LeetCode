#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::findMaxLength(vector<int>& nums) {
    if (nums.size() < 2) {
	return 0;
    }
    int sizeNums = nums.size();
    vector<int> array(2 * sizeNums + 1);
    int count(sizeNums);
    int longestSize(0);
    for (size_t start = 0 ; start < sizeNums ; ++start) {
	count += nums[start] == 0 ? -1 : 1;
	if (sizeNums == count) {
	    longestSize = start + 1;
	} else {
	    if (array[count] != 0) {
		int localSize = start - array[count] + 1;
		longestSize = longestSize > localSize ? longestSize : localSize;
	    } else {
		array[count] = start + 1;
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
