#include <string>
using std::string;

class Solution {
    public :
        Solution() {}
	string longestPalindrome(string s);
	string longestPalindromeDP(string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

