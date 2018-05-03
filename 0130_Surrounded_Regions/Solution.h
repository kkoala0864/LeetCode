#include <vector>


class Solution {
    public :
        Solution() {}
	void solve(std::vector<std::vector<char> >& board);
	void solve2(std::vector<std::vector<char> >& board);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

