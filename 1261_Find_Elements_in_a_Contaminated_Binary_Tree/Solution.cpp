#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void recur(TreeNode* node, TreeNode* iter, int val) {
	if (!node) return;
	if (node->left) {
		iter->left = node->left;
		node->left->val = 2 * val + 1;
		recur(node->left, iter->left, 2 * val + 1);
	}
	if (node->right) {
		iter->right = node->right;
		node->right->val = 2 * val + 2;
		recur(node->right, iter->right, 2 * val + 2);
	}
}

void Solution::FindElements(TreeNode* root) {
	if (!root) return;
	TreeRoot = new TreeNode(0);
	recur(root, TreeRoot, 0);
}

bool Solution::find(int target) {
	if (0 == target) {
		FindIter = TreeRoot;
		return true;
	}
	int one = (target - 1) % 2;
	int two = (target - 2) % 2;
	bool ret = true;
	if (!one) {
		ret = find((target - 1) / 2);
		if (ret && FindIter->left) {
			FindIter = FindIter->left;
		} else {
			return false;
		}
	} else {
		ret = find((target - 2) / 2);
		if (ret && FindIter->right) {
			FindIter = FindIter->right;
		} else {
			return false;
		}
	}
	return ret;
}
