#include <Solution.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Solution::simplifyPath(string path) {
    vector<string> stack;

    for (int i = 0 ; i < path.size() ;) {
	if (path.at(i) == '/') {
	    int start = ++i;
	    while (i < path.size() && path.at(i) != '/') {
		++i;
	    }
	    if (i - start > 0) {
		string location = path.substr(start, i - start);
		if (location == "..") {
		    if (!stack.empty()) {
			stack.pop_back(); continue;
		    }
		} else if (location == ".") {
		    continue;
		} else {
		    stack.emplace_back(location);
		}
	    }
	}
    }
    if (stack.empty()) return "/";
    string ret;
    for (const auto idx : stack) {
	ret += "/";
	ret += idx;
    }
    return ret;
}
