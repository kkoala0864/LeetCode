#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

int dfs(TreeNode* root, int& maxSum) {
    if (nullptr == root) return 0;
    if (nullptr == root->left && nullptr == root->right) {
	maxSum = max(maxSum, root->val);
	return root->val;
    }
    int sum(root->val);
    int leftSum = dfs(root->left, maxSum);
    int rightSum = dfs(root->right, maxSum);

    if (leftSum > 0)
	sum += leftSum;
    if (rightSum > 0)
	sum += rightSum;

    maxSum = max(maxSum, sum);
    int childMax = max(leftSum, rightSum);
    return childMax > 0 ? childMax + root->val : root->val;
}

int Solution::maxPathSum(TreeNode* root) {
    if (nullptr == root) return 0;
    int ret(INT_MIN);
    dfs(root, ret);
    return ret;
}


