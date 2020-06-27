#include <Solution.h>
#include <iostream>

TreeNode* recurCheck(TreeNode *ori, TreeNode *clone, TreeNode* target) {
    if (ori == nullptr) return nullptr;

    if (ori == target) {
	return clone;
    }

    TreeNode* leftRet = recurCheck(ori->left, clone->left, target);
    if (nullptr == leftRet) return recurCheck(ori->right, clone->right, target);
    else return leftRet;

}

TreeNode* Solution::getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (nullptr == original || nullptr == target) return nullptr;
    return recurCheck(original, cloned, target);
}
