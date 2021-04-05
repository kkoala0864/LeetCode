#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void Solution::addNum(int num) {
	++_count;
	_maxHeap.emplace(num);
	_minHeap.emplace(_maxHeap.top());
	_maxHeap.pop();
	if (_minHeap.size() - _maxHeap.size() > 1) {
		_maxHeap.emplace(_minHeap.top());
		_minHeap.pop();
	}
}

double Solution::findMedian() {
	if (_count & 1) {
		return _minHeap.top();
	} else {
		return (_maxHeap.top() + _minHeap.top()) * 0.5;
	}
}


