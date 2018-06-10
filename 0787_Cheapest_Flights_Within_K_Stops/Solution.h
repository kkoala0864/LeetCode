#include <vector>
using std::vector;


class Solution {
    public :
        Solution() {}
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

