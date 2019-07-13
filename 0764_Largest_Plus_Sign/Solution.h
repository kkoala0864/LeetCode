#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines);
	int orderOfLargestPlusSignDP(int N, vector<vector<int>>& mines);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

