#include <Solution.h>
#include <iostream>
#include <list>
using namespace std;

int Solution::findBottomLeftValue(TreeNode* root) {
    if (nullptr == root) {
	return -1;
    }

    list<pair<TreeNode*, int>> traverse;
    traverse.emplace_back(make_pair(root, 1));

    while (!traverse.empty()) {
	list<int> level;
	int depth = traverse.front().second;
	while (!traverse.empty() && depth == traverse.front().second) {
	    TreeNode* iter = traverse.front().first;
	    traverse.pop_front();
	    level.emplace_back(iter->val);
	    if (iter->left)
		traverse.push_back(make_pair(iter->left, depth + 1));
	    if (iter->right)
		traverse.push_back(make_pair(iter->right, depth + 1));
	    if (traverse.empty()) {
		return level.front();
	    }
	}
    }
}
