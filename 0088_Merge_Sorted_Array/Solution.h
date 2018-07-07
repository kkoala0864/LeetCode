#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

