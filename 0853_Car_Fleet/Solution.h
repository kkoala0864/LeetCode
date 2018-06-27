#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int carFleet(int target, vector<int>& position, vector<int>& speed);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

