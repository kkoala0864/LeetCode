#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int maxProfit(vector<int>& prices, int fee);
	int maxProfit2(vector<int>& prices, int fee);
	int maxProfit3(vector<int>& prices, int fee);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

