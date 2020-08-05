#include <Solution.h>
#include <iostream>

void count(TreeNode* node, TreeNode* parent, int& ret, int pathMax) {
	if (nullptr == node) {
		return;
	}

	if (node->val >= pathMax) {
		++ret;
		pathMax = node->val;
	}

	count(node->left, node, ret, pathMax);
	count(node->right, node, ret, pathMax);
}

int Solution::goodNodes(TreeNode* root) {
	int ret(0);
	count(root->left, root, ret, root->val);
	count(root->right, root, ret, root->val);
	return ret + 1;
}
