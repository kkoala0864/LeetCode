#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> spiralOrder(vector<vector<int>>& matrix);
	vector<int> spiralOrder2(vector<vector<int>>& matrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

