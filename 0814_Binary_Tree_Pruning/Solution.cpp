#include <Solution.h>
#include <iostream>

using namespace std;

bool hasOne(TreeNode*& root) {
    if (!root) return false;
    bool left = hasOne(root->left);
    bool right = hasOne(root->right);
    if (left || right) {
	return true;
    } else {
	if (root->val == 0) {
	    delete(root);
	    root = nullptr;
	    return false;
	} else {
	    return true;
	}
    }
}

TreeNode* Solution::pruneTree(TreeNode* root) {
    hasOne(root);
    return root;
}
