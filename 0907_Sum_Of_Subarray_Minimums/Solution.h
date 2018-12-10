#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int sumSubarrayMins(vector<int>& A);
	int sumSubarrayMinsStack(vector<int>& A);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

