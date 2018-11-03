#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

