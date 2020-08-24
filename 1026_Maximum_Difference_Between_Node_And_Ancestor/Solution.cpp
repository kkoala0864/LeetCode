#include <Solution.h>
#include <iostream>
#include <stdlib.h>

using std::max;
using std::min;

void iterate(TreeNode* node, int& minVal, int& maxVal, int& ret) {
	if (nullptr == node) return;

	int leftMin(INT_MAX), leftMax(INT_MIN), rightMin(INT_MAX), rightMax(INT_MIN), leftRet(INT_MIN), rightRet(INT_MIN);

	if (node->left) {
		iterate(node->left, leftMin, leftMax, ret);
		leftRet = max(abs(node->val - leftMin), abs(node->val - leftMax));
	}
	if (node->right) {
		iterate(node->right, rightMin, rightMax, ret);
		rightRet = max(abs(node->val - rightMin), abs(node->val - rightMax));
	}
	ret = max({leftRet, rightRet, ret});

	minVal = min({leftMin, rightMin, node->val});
	maxVal = max({leftMax, rightMax, node->val});
}

int Solution::maxAncestorDiff(TreeNode* root) {
	int ret(0);
	int minVal(INT_MAX), maxVal(INT_MIN);
	iterate(root, minVal, maxVal, ret);
	return ret;
}
