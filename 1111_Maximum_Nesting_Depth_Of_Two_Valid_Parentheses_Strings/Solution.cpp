#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

vector<int> Solution::maxDepthAfterSplit(string seq) {
	int cnt(-1);

	vector<int> ret;
	int size = seq.size();
	for (int i = 0 ; i < size ; ++i) {
		if (seq.at(i) == '(') {
			++cnt;
			ret.emplace_back(cnt%2);
		} else {
			ret.emplace_back(cnt%2);
			--cnt;
		}
	}
	return ret;
}
