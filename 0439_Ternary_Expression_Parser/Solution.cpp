#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

string Solution::parseTernary(string expression) {
    stack<char> SeqStack;
    stack<char> falStack;
    int size = expression.size();
    for (int i = 0 ; i < size ; ++i) {
	if (expression.at(i) != ':')
	    SeqStack.push(expression.at(i));
    }

    while (SeqStack.size() > 1) {
	falStack.push(SeqStack.top()); SeqStack.pop();
	char truePart = SeqStack.top(); SeqStack.pop();
	while (SeqStack.top() != '?') {
	    falStack.push(truePart);
	    truePart = SeqStack.top(); SeqStack.pop();
	}
	SeqStack.pop();
	char falsePart = falStack.top(); falStack.pop();
	char decide = SeqStack.top(); SeqStack.pop();
	if (decide == 'T') {
	    SeqStack.push(truePart);
	} else {
	    SeqStack.push(falsePart);
	}
	if (!falStack.empty()) {
	    SeqStack.push(falStack.top()); falStack.pop();
	}
    }
    string ret(1, SeqStack.top());
    return ret;
}

string Solution::parseTernary(string expression) {
    int n = expression.size();
    if(n == 1 || expression[1] != '?') return expression;
    int count = 0;
    int i;
    for(i = 2; i < n; i++){
	if(expression[i] == '?') ++count;
	else if(expression[i] == ':'){
	    if(count == 0) break;
	    --count;
	}
    }
    if(expression[0] == 'T') return parseTernary(expression.substr(2, i - 2));
    return parseTernary(expression.substr(i + 1));
}
