#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

int Solution::kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (const auto& row : matrix) {
	for (const auto& element : row) {
	    minHeap.emplace(element);
	}
    }

    while (k-- > 0) {
	minHeap.pop();
    }
    return minHeap.top();
}
