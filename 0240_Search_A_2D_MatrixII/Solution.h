#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool searchMatrix(vector<vector<int>>& matrix, int target);
	bool searchMatrix2(vector<vector<int>>& matrix, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

