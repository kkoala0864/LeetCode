#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations);
	int minRefuelStopsDP(int target, int startFuel, vector<vector<int>>& stations);
	int minRefuelStopsPQ(int target, int startFuel, vector<vector<int>>& stations);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

