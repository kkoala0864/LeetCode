#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::maxSubArray(vector<int>& nums) {
    int size = nums.size();
    if (1 == size) return nums.at(0);
    int MaxVal(INT_MIN);
    int negCheck(0);
    for (; negCheck < size ; ++negCheck) {
	if (nums.at(negCheck) > 0) break;
	MaxVal = max(MaxVal, nums.at(negCheck));
    }
    if (negCheck == size) return MaxVal;

    int MaxSum(0);
    int localSum(0);
    for (int i = negCheck ; i < size ; ++i) {
	localSum += nums.at(i);
	if (localSum < 0) localSum = 0;
	MaxSum = max(MaxSum, localSum);
    }
    return MaxSum;
}
