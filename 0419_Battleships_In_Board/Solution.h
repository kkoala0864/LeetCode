#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int countBattleships(vector<vector<char>>& board);
	int countBattleships2(vector<vector<char>>& board);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

