#include <vector>


class Solution {
    public :
        Solution() {}
        int maxProfit(std::vector<int>& prices);
        int maxProfit_greedy(std::vector<int>& prices);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

