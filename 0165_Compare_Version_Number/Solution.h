#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	int compareVersion(string version1, string version2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

