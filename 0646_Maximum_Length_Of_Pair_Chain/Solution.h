#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int findLongestChain(vector<vector<int>>& pairs);
	int findLongestChainII(vector<vector<int>>& pairs);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

