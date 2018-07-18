#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int findTargetSumWays(vector<int>& nums, int S);
	int findTargetSumWaysDP(vector<int>& nums, int S);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

