#include <Solution.h>
#include <iostream>
void evenSum(TreeNode* node, int& value, bool IsChildAdd, bool IsAdd) {
    if (nullptr == node) return;
    if (IsAdd) value += node->val;
    bool childAdd = false;
    if (!(node->val & 1)) {
	childAdd = true;
    }
    evenSum(node->left, value, childAdd, IsChildAdd);
    evenSum(node->right, value, childAdd, IsChildAdd);
}

int Solution::sumEvenGrandparent(TreeNode* root) {
    int ret = 0;
    evenSum(root, ret, false, false);
    return ret;
}
