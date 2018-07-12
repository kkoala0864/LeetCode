#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string numberToWords(int num);
	string numberToWords2(int num);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

