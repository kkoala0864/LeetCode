#include <Solution.h>
#include <iostream>

using namespace std;


int Solution::titleToNumber(string s) {
    if (s.empty()) return 0;
    int ret(0);
    for (int i = 0 ; i < s.size() ; ++i) {
	ret = ret*26 + (s.at(i) - 'A' + 1);
    }
    return ret;
}
