#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
    public :
        Solution() {}
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix);
	vector<pair<int, int>> pacificAtlanticBFS(vector<vector<int>>& matrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

