#include <Solution.h>

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr) {
		return nullptr;
	}

	if (nullptr == p || nullptr == q) {
		return root;
	}

	TreeNode *iter = root;
	TreeNode *big = p->val > q->val ? p : q;
	TreeNode *small = big == p ? q : p;

	while (iter) {
		if (iter->val > big->val) {
			iter = iter->left;
		} else {
			if (iter->val < small->val) {
				iter = iter->right;
			} else {
				return iter;
			}
		}
	}
}
