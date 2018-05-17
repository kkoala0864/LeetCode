#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::strStr(string haystack, string needle) {

	if (needle.empty()) return 0;

	int m = haystack.size(), n = needle.size();
	if (haystack.empty() || (m < n)) return -1;

	int i(0), j(0);
	while (i < m && j < n) {
		if (haystack.at(i) == needle.at(j)) {
			++i;
			++j;
		} else {
			i -= j - 1;
			j = 0;
		}
	}
	if (j < n) {
		return -1;
	} else {
		return i - n;
	}
}
