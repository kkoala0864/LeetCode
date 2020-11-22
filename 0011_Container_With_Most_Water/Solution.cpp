#include <Solution.h>
#include <iostream>
#include <limits>
#include <algorithm>

using std::min;
using std::max;

int Solution::maxArea(vector<int>& height) {
	int maxVal = INT_MIN;
	int i = 0, j = height.size() - 1;
	while ( i < j ) {
		maxVal = max(maxVal, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j]) {
			++i;
		} else if (height[i] >= height[j]) {
			--j;
		}
	}
	return maxVal;
}

