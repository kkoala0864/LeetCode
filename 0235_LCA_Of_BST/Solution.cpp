#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool findNode(TreeNode *root, TreeNode* node) {
	if (nullptr == root || nullptr == node) {
		return false;
	}

	if (root == node) {
		return true;
	}

	return findNode(root->left, node) || findNode(root->right, node);
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr) {
		return nullptr;
	}

	if (nullptr == p || nullptr == q) {
		return root;
	}

	if (findNode(p, q)) {
		return p;
	}

	if (findNode(q, p)) {
		return q;
	}

	TreeNode *iter = root;
	while (iter) {
		if (findNode(iter->left, p)) {
			if (findNode(iter->left, q)) {
				iter = iter->left;
			} else {
				return iter;
			}
		} else {
			if (findNode(iter->right, q)) {
				iter = iter->right;
			} else {
				return iter;
			}
		}
	}
}
