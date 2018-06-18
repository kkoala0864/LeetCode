#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

string Solution::decodeString(string s) {
    if (s.empty()) return s;
    stack<int> times;
    string ret;
    for (int i = 0 ; i < s.size() ;) {
	if (s.at(i) >= '0' && s.at(i) <= '9') {
	    string time;
	    while (s.at(i) >= '0' && s.at(i) <= '9') {
		time.push_back(s.at(i++));
	    }
	    times.push(stoi(time));
	} else if (s.at(i) == '[') {
	     string repeat;
	     int count(1);
	     ++i;
	     while (count > 0) {
		 if (s.at(i) == '[')
		     ++count;
		 else if (s.at(i) == ']')
		     --count;
		 if (count > 0)
		     repeat.push_back(s.at(i));
		 ++i;
	     }
	     repeat = decodeString(repeat);
	     int repTime = times.top(); times.pop();
	     while (repTime-- > 0) {
		 ret.append(repeat);
	     }
	} else {
	    ret.push_back(s.at(i));
	    ++i;
	}
    }
    if (!times.empty()) {
	string repStr = ret;
	int repTime = times.top();
	while (repTime-- > 1)
	    ret.append(repStr);
    }
    return ret;
}
