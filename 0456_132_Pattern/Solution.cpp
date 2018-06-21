#include <Solution.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct node {
    int val;
    int min;
    node(int value) : val(value), min(INT_MAX) {}
};

bool Solution::find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    vector<node*> st;
    node* first = new node(nums.at(0));
    first->min = first->val;
    st.emplace_back(first);
    for (int i = 1 ; i < nums.size() ; ++i) {
	if (nums.at(i) == st.back()->val) {
	    continue;
	}
	for (int j = st.size() - 1 ; j >= 0 ; --j) {
	    if (nums.at(i) < st.at(j)->val) {
		if (nums.at(i) > st.at(j)->min) {
		    return true;
		}
	    }
	}
	node* one = new node(nums.at(i));
	one->min = st.back()->val < st.back()->min ? st.back()->val : st.back()->min;
	st.emplace_back(one);
    }
    return false;
}


bool Solution::find132pattern2(vector<int>& a) {
    int n = a.size();
    int s2 = INT_MIN;
    stack<int> st;
    for(int i = n-1 ; i >= 0 ; i--)
    {
	if (a[i] < s2)
	    return 1;
	while (!st.empty() && a[i] > st.top()) {
	    s2 = st.top();
	    st.pop();
	}
	st.push(a[i]);
    }
    return 0;
}
