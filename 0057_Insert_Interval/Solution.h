#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

