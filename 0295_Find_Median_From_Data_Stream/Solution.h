#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::greater;

class Solution {
    public :
        Solution() { _count = 0; };
	void addNum(int num);
	double findMedian();
    private :
	int _count;
	priority_queue<int, vector<int>, greater<int>> _minHeap;
	priority_queue<int> _maxHeap;
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

