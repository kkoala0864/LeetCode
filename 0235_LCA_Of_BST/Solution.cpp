#include <Solution.h>

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;

    TreeNode* iter = root;
    TreeNode* big = p->val >= q->val ? p : q;
    TreeNode* small = big == p ? q : p;
    while (iter) {
	if ((iter == big) || (iter == small)) return iter;
	if ((iter->val > small->val) && (iter->val < big->val)) return iter;
	if (iter->val > big->val) {
	    iter = iter->left;
	} else if (iter->val < small->val) {
	    iter = iter->right;
	}
    }
    return nullptr;
}
