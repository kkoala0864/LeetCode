#include <Solution.h>
#include <iostream>
#include <queue>
using namespace std;

int Solution::findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (const auto& idx : nums) {
	maxHeap.emplace(idx);
    }

    int ret(0);
    while (k-- > 0) {
	ret = maxHeap.top();
	maxHeap.pop();
    }
    return ret;
}
