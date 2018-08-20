#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::maxProduct(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size);
    int maxProduct(INT_MIN);
    for (int length = 0 ; length < size ; ++length) {
	for (int idx = 0 ; idx < (size - length) ; ++idx) {
	    if (0 == length) {
		dp.at(idx) = nums.at(idx);
	    } else {
		dp.at(idx) = nums.at(idx) * dp.at(idx+1);
	    }
	    maxProduct = max(maxProduct, dp.at(idx));
	}
    }
    return maxProduct;
}

int Solution::maxProduct2(vector<int>& nums) {
    int res = INT_MIN;
    int currMax = 1, currMin = 1;

    for (int n: nums) {
	if (n > 0) {
	    currMax = max(currMax * n, n);
	    currMin = min(currMin * n, n);
	} else {
	    int temp = currMax;
	    currMax = max(currMin * n, n);
	    currMin = min(temp * n, n);
	}
	res = max(currMax, res);
    }
    return res;
}
