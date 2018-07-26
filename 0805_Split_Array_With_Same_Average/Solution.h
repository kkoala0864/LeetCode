#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	bool splitArraySameAverageTLE(vector<int>& A);
	bool splitArraySameAverageFast(vector<int>& A);
	bool splitArraySameAverage(vector<int>& A);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

