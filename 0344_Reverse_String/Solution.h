#include <string>


class Solution {
    public :
        Solution() {}
	std::string reverseString(std::string s);
        void DebugPrint(std::string nums);
        virtual ~Solution() {}
    private :
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

