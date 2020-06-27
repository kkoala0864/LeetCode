#include <Solution.h>
#include <iostream>

void leaveSum(TreeNode* node, int deep, int &value, int& maxdeep) {
    if (nullptr == node) return;

    if (nullptr == node->left && nullptr == node->right) {
	maxdeep = deep;
	value = node->val;
	return;
    }

    int leftDeep = 0, rightDeep = 0, leftValue = 0, rightValue = 0;
    leaveSum(node->left, deep + 1, leftValue, leftDeep);
    leaveSum(node->right, deep + 1, rightValue, rightDeep);
    if (leftDeep > rightDeep) {
	value = leftValue;
	maxdeep = leftDeep;
    } else if (leftDeep < rightDeep) {
	value = rightValue;
	maxdeep = rightDeep;
    } else {
	value = leftValue + rightValue;
	maxdeep = leftDeep;
    }
}

int Solution::deepestLeavesSum(TreeNode* root) {
    int deep = 0, value = 0;
    leaveSum(root, 0, value, deep);
    return value;
}
