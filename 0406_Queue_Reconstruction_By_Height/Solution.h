#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
    public :
        Solution() {}
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

