#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

