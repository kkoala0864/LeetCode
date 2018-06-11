#include <string>
using std::string;

struct charactor {
    char element;
    int counter;
    bool operator < (const charactor& a) const {
	return counter < a.counter;
    }
};

class Solution {
    public :
        Solution() {}
	string frequencySort(string s);
	string frequencySort2(string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

