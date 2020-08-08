#include <Solution.h>
#include <iostream>

TreeNode* traverse(TreeNode* node, int& maxDepth, int depth) {
	if (nullptr == node) return nullptr;
	if (nullptr == node->left && nullptr == node->right) {
		maxDepth = depth > maxDepth ? depth : maxDepth;
	}

	int leftMaxDepth(depth);
	int rightMaxDepth(depth);

	TreeNode* left = traverse(node->left, leftMaxDepth, depth+1);
	TreeNode* right = traverse(node->right, rightMaxDepth, depth+1);

	maxDepth = leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth;
	if (leftMaxDepth == rightMaxDepth) {
		return node;
	} else if (leftMaxDepth > rightMaxDepth) {
		return left;
	} else {
		return right;
	}
}

TreeNode* Solution::lcaDeepestLeaves(TreeNode* root) {
	if (nullptr == root) {
		return root;
	}

	int maxDepth(0);
	return traverse(root, maxDepth, 1);
}
