#include <vector>
#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
        std::vector<int> twoSum(std::vector<int>& nums, int target);
	int strStr(string haystack, string needle);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

