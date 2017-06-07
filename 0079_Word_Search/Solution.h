#include <vector>
#include <string>

class Solution {
    public :
        Solution() {}
	bool exist(std::vector<std::vector<char> >& board, std::string word);
	bool check(std::vector<std::vector<char> >& board, const std::string& strCmp, size_t i, size_t j);
    private :
	size_t m;
	size_t n;
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

