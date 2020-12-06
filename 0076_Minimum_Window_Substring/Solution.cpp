#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>

using std::unordered_map;

bool isInGoldenMap(const unordered_map<char, int>& goldenMap, const char checkChar) {
	return goldenMap.find(checkChar) != goldenMap.end();
}

string Solution::minWindow(string s, string t) {
	string retStr;
	int minSize = INT_MAX;
	int count = t.size(), sSize = s.size();
	unordered_map<char, int> goldenMap;
	for (const auto& iter : t) ++goldenMap[iter];

	int left = 0;
	while (left < sSize && !isInGoldenMap(goldenMap, s[left])) {
		++left;
	}

	int pivot = left - 1;
	while (pivot < sSize && left < sSize) {
		if (count > 0) {
			++pivot;
			if (pivot < sSize && isInGoldenMap(goldenMap, s[pivot])) {
				--goldenMap[s[pivot]];
				if (goldenMap[s[pivot]] >= 0) --count;
			}
		} else {
			if (0 == count &&
			    isInGoldenMap(goldenMap, s[left]) &&
			    isInGoldenMap(goldenMap, s[pivot])) {
				int size = pivot - left + 1;
				if (minSize > size) {
					minSize = size;
					retStr = s.substr(left, size);
				}
			}
			if (left < sSize && isInGoldenMap(goldenMap, s[left])) {
				++goldenMap[s[left]];
				if (goldenMap[s[left]] > 0) ++count;
			}
			++left;
		}
	}
	return retStr;
}
