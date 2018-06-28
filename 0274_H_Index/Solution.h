#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int hIndex(vector<int>& citations);
	int hIndex2(vector<int>& citations);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

