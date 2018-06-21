#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<string> topKFrequent(vector<string>& words, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

