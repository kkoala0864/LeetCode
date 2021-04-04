#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
bool Solution::isAnagram(string s, string t) {
	if (s.length() != t.length()) return false;
	vector<int> hash(26, 0);
	for (const auto& iter : s) {
		++hash[iter-'a'];
	}
	for (const auto& iter : t) {
		--hash[iter-'a'];
		if (hash[iter-'a'] < 0) {
			return false;
		}
	}
	return true;
}
