#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int findMaxLength(vector<int>& nums);
	int findMaxLengthBrute(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

