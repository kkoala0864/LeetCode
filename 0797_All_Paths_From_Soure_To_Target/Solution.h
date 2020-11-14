#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

