#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

vector<int> Solution::dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    vector<int> ret(size, 0);
    if (size) {
	stack<int> wait;
	for (int i = 0 ; i < size ; ++i) {
	    while (!wait.empty() && temperatures.at(i) > temperatures.at(wait.top())) {
		ret.at(wait.top()) = i - wait.top();
		wait.pop();
	    }
	    wait.push(i);
	}
    }
    return ret;
}
