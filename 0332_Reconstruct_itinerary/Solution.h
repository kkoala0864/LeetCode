#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::pair;

class Solution {
    public :
        Solution() {}
	vector<string> findItinerary(vector<pair<string, string>> tickets);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

