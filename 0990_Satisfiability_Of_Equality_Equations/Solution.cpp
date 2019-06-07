#include <Solution.h>
#include <iostream>

char find(vector<char> parent, int input) {
    return parent[input] == '\0' ? (char)input+'a' : find(parent, parent[input]-'a');
}

bool Solution::equationsPossible(vector<string>& equations) {
    vector<char> parent(26, '\0');
    for (const auto equation : equations) {
	if (equation[1] == '=') {
	    char left = find(parent, equation[0]-'a');
	    char right = find(parent, equation[3]-'a');
	    if (left != right) {
		parent[right-'a'] = left;
	    }
	}
    }

    for (const auto equation : equations) {
	if (equation[1] == '!') {
	    char left = find(parent, equation[0]-'a');
	    char right = find(parent, equation[3]-'a');
	    if (('\0' == left) && ('\0' == right)) continue;
	    if (left == right) return false;
	}
    }
    return true;
}
