#include <Solution.h>
#include <iostream>

void generate(vector<string>& res, string record, int left, int right, const int n) {
    if (left == n) {
	while (left > right++) {
	    record.push_back(')');
	}
	res.emplace_back(record);
	return;
    }

    string leftAppend(record);
    leftAppend.push_back('(');
    generate(res, leftAppend, left+1, right, n);

    if (left > right) {
	string rightAppend(record);
	rightAppend.push_back(')');
	generate(res, rightAppend, left, right+1, n);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> res;
    string record;
    record.push_back('(');
    generate(res, record, 1, 0, n);
    return res;
}
