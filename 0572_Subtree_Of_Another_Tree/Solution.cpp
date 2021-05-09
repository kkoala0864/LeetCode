#include <Solution.h>
#include <iostream>

bool recur(TreeNode* root, TreeNode* subRoot) {
	if (nullptr == root || nullptr == subRoot) return subRoot == root;
	if (root->val != subRoot->val) return false;
	else return recur(root->left, subRoot->left) && recur(root->right, subRoot->right);
}

bool Solution::isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (nullptr == subRoot) return true;
	if (nullptr == root) return false;
	if (recur(root, subRoot)) return true;
	else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
