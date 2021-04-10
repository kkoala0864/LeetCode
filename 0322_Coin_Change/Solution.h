#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int coinChange(vector<int>& coins, int amount);
	int coinChangeRecur(vector<int>& coins, int amount);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

