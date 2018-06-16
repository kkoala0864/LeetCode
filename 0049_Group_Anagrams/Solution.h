#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<vector<string>> groupAnagrams(vector<string>& strs);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

