#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int search(vector<int>& nums, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

