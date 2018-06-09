#include <vector>
#include <utility>
using std::pair;
using std::vector;


class Solution {
    public :
        Solution() {}
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
	bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

