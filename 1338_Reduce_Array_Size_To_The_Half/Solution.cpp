#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

int Solution::minSetSize(vector<int>& arr) {
	int max(0);
	unordered_map<int, int> record;
	for (const auto iter : arr) {
		++record[iter];
		max = record[iter] > max ? record[iter] : max;
	}
	vector<int> count(max+1, 0);
	int size = arr.size() >> 1;
	for (const auto iter : record) {
		++count.at(iter.second);
	}
	int ret(0);
	for (int i = max ; i > 0 ; --i) {
		while (count.at(i) > 0) {
			size -= i;
			--count.at(i);
			++ret;
			if (size <= 0) {
				return ret;
			}
		}
		if (size <= 0) {
			return ret;
		}
	}
	return ret;
}

