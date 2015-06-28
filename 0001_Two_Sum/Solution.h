#include <vector>


class Solution {
    public :
        Solution() {}
        std::vector<int> twoSum(std::vector<int>& nums, int target);
        void DebugPrint(std::vector<int> nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

