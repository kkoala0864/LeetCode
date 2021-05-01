#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::vector;
using std::endl;
using std::cout;

int Solution::characterReplacement(string s, int k) {
	int start = 0;
	int size = s.size();
	int maxCount = INT_MIN;
	vector<int> count(26, 0);
	int ret = INT_MIN;
	for (int end = start ; end < size ; ++end) {
		++count[s[end] - 'A'];
		maxCount = max(maxCount, count[s[end] - 'A']);
		while ((end - start + 1) - maxCount > k) {
			--count[s[start] - 'A'];
			++start;
			int tempMaxCount = INT_MIN;
			for (const auto& iter : count) {
				tempMaxCount = max(tempMaxCount, iter);
			}
			maxCount = tempMaxCount;
		}
		ret = max(ret, (end - start + 1));
	}
	return ret;
}
