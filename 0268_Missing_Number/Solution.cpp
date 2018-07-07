#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::missingNumber(vector<int>& nums) {
    int size = nums.size();
    int Summary = (1 + size) * size / 2;
    for (int i = 0 ; i < size ; ++i) {
	Summary -= nums.at(i);
    }
    return Summary;
}
