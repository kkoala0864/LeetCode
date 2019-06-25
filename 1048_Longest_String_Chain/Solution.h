#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	int longestStrChain(vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

