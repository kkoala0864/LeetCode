#include <vector>
#include <utility>
#include <queue>
using std::vector;
using std::pair;
using std::priority_queue;

class Solution {
    public :
        Solution() {}
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

