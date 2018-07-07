#include <Solution.h>
#include <iostream>

using namespace std;

string Solution::convertToTitle(int n) {
    string ret("");
    while (n) {
	n -= 1;
	string tmp(1,'A' + n%26);
	ret = tmp + ret;
	n/=26;
    }
    return ret;
}
