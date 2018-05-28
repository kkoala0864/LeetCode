#include <Solution.h>
#include <iostream>
#include <list>
#include <utility>

using namespace std;

int Solution::minDepth(TreeNode* root) {
    if (nullptr == root) {
	return 0;
    }

    list<pair<TreeNode*, int>> traverse;
    traverse.push_back(make_pair(root, 1));

    while (!traverse.empty()) {
	TreeNode* iter = traverse.front().first;
	int depth = traverse.front().second;
	if (nullptr == iter->left && nullptr == iter->right) {
	    return depth;
	} else {
	    if (nullptr != iter->left) {
		traverse.push_back(make_pair(iter->left, depth+1));
	    }
	    if (nullptr != iter->right) {
		traverse.push_back(make_pair(iter->right, depth+1));
	    }
	    traverse.pop_front();
	}
    }
    return 0;
}
