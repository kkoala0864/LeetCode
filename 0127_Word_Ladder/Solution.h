#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

