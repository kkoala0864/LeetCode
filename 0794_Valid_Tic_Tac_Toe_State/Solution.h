#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	bool validTicTacToe(vector<string>& board);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

