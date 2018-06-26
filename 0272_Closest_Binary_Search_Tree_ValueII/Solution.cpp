#include <Solution.h>
#include <utility>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const pair<double, int>& a, const pair<double, int>& b) {
	return a.first > b.first;
    }
};

void inorder(TreeNode* root, priority_queue<pair<double, int>, vector<pair<double, int>>, cmp>& diff, double target) {
    if (nullptr == root) return;
    double diffVal = target > root->val ? target - root->val : root->val - target;
    diff.emplace(diffVal, root->val);
    inorder(root->left, diff, target);
    inorder(root->right, diff, target);
}

vector<int> Solution::closestKValues(TreeNode* root, double target, int k) {
    vector<int> ret;
    if (nullptr == root) return ret;
    priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> diff;
    inorder(root, diff, target);
    for (int i = 0 ; i < k ; ++i) {
	ret.emplace_back(diff.top().second);
	diff.pop();
    }
    return ret;
}

