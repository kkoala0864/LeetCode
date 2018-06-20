#include <Solution.h>
#include <iostream>

using namespace std;

void Solution::reverseWords(vector<char>& str) {

    if (str.empty()) return;
    int x = 0, y = str.size() -1;
    while (x < y) {
	swap(str.at(x++), str.at(y--));
    }
    int start(0);
    while (start < str.size()) {
	int end = start;
	while (end < str.size() && str.at(end) != ' ') {
	    ++end;
	}
	int i = start, j = end-1;
	while (i < j) {
	    swap(str.at(i++), str.at(j--));
	}
	start = end+1;
    }
}
