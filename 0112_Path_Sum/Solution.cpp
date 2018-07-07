#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr && sum == root->val) return true;
    if (root->left) {
	if (hasPathSum(root->left, sum-root->val))
	    return true;
    }
    if (root->right) {
	if (hasPathSum(root->right, sum-root->val))
	    return true;
    }
    return false;
}
