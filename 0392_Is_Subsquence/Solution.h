#include <string>
using std::string;

class Solution {
    public :
        Solution() {}
	bool isSubsequence(string s, string t);
	bool isSubsequence2(string s, string t);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

