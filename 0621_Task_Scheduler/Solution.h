#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int leastInterval(vector<char>& tasks, int n);
	int leastInterval2(vector<char>& tasks, int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

