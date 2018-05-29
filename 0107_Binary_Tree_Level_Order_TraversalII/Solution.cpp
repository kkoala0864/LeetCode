#include <Solution.h>
#include <iostream>
#include <list>
using namespace std;

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    vector<vector<int>> order;
    if (nullptr == root) {
	return order;
    }
    list<pair<TreeNode*, int>> traverse;
    traverse.emplace_back(make_pair(root, 1));
    while (!traverse.empty()) {
	int depth = traverse.front().second;
	vector<int> local;
	while (!traverse.empty() && depth == traverse.front().second) {
	    TreeNode* iter = traverse.front().first;
	    traverse.pop_front();
	    if (iter->left) {
		traverse.emplace_back(iter->left, depth + 1);
	    }
	    if (iter->right) {
		traverse.emplace_back(iter->right, depth + 1);
	    }
	    local.emplace_back(iter->val);
	}
	order.push_back(local);
    }
    return vector<vector<int>>(order.rbegin(), order.rend());
}

