#include <Solution.h>
#include <iostream>

using namespace std;

TreeNode* Solution::insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
	return new TreeNode(val);
    }

    TreeNode* iter = root;
    TreeNode* parent = nullptr;
    while (iter) {
	parent = iter;
	if (iter->val > val) {
	    iter = iter->left;
	} else {
	    iter = iter->right;
	}
    }
    if (parent->val > val) {
	parent->left = new TreeNode(val);
    } else {
	parent->right = new TreeNode(val);
    }
    return root;
}
