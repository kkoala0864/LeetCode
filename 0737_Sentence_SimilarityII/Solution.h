#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::pair;

class Solution {
    public :
        Solution() {}
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

