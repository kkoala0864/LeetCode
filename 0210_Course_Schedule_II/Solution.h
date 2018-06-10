#include <vector>
#include <utility>
using std::vector;
using std::pair;

class Solution {
    public :
        Solution() {}
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

