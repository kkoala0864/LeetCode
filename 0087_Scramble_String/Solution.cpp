#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::isScramble(string s1, string s2) {
    if (s1 == s2) {
	return true;
    }

    size_t size = s1.size();
    if (1 == size) {
	return false;
    }

    int count(0);
    for (size_t i = 0 ; i < (size - 1) ; ++i) {
	count += s1.at(i) - 'a';
	count -= s2.at(i) - 'a';
	if (count != 0) {
	    continue;
	}
	if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && isScramble(s1.substr(i+1), s2.substr(i+1))) {
	    return true;
	}
    }

    count = 0;
    for (size_t i = 0 ; i < (size - 1) ; ++i) {
	count += s1.at(i) - 'a';
	count -= s2.at(size - i - 1) - 'a';
	if (count != 0) {
	    continue;
	}
	if (isScramble(s1.substr(0, i+1), s2.substr(size-i-1)) && isScramble(s1.substr(i+1), s2.substr(0 , size-i-1))) {
	    return true;
	}
    }

    return false;
}
