#include <vector>


class Solution {
    public :
        Solution() {}
	std::vector<int> countBits(int num);
        void DebugPrint(std::vector<int> nums);
        virtual ~Solution() {}
    private :
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

