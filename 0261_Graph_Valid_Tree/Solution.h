#include <vector>
#include <utility>
using std::vector;
using std::pair;

class Solution {
    public :
        Solution() {}
	bool validTree(int n, vector<pair<int, int>>& edges);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

