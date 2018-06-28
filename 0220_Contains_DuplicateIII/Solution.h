#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
	bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

