#include <vector>

using std::vector;
class Solution {
    public :
        Solution() {}
	int Brute(vector<int>& nums, int k);
	int subarraySum(vector<int>& nums, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

