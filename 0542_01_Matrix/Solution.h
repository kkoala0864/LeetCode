#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);
	vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

