#include <Solution.h>

void check(TreeNode* node, TreeNode* child, int& CurStep, int ChildStep, int& TotalCnt) {
    if (!child) return;
    if (1 == child->val) {
	TotalCnt += ChildStep;
	return;
    }
    if (1 != child->val) {
	CurStep += abs(child->val - 1) + ChildStep;
	node->val += (child->val - 1);
	child->val = 1;
	return;
    }
}

int distribute(TreeNode* node, int& TotalCnt) {
    if (!node) return 0;
    int step = 0;
    int leftStep = distribute(node->left, TotalCnt);
    int rightStep = distribute(node->right, TotalCnt);
    check(node, node->left, step, leftStep, TotalCnt);
    check(node, node->right, step, rightStep, TotalCnt);
    return step;
}

int Solution::distributeCoins(TreeNode* root) {
    int TotalCnt = 0;
    TotalCnt += distribute(root, TotalCnt);
    return TotalCnt;
}

int dfs(TreeNode* node, int& cnt) {
    if (!node) return 0;
    int left = dfs(node->left, cnt);
    int right = dfs(node->right, cnt);
    cnt += abs(left) + abs(right);
    return (node->val - 1) + left + right;
}

int Solution::distributeCoinsII(TreeNode* root) {
    int TotalCnt = 0;
    dfs(root, TotalCnt);
    return TotalCnt;
}

