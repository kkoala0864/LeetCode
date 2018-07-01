#include <Solution.h>
#include <iostream>
using namespace std;

int traverse(TreeNode* node, int& minVal, int& maxVal, int& maxBSTCnt) {
    if (!node->left && !node->right) {
	minVal = node->val;
	maxVal = node->val;
	maxBSTCnt = max(maxBSTCnt, 1);
	return 1;
    }

    int leftMin(0), leftMax(0), rightMin(0), rightMax(0), leftBSTCnt(0), rightBSTCnt(0);
    if (node->left) {
	leftBSTCnt = traverse(node->left, leftMin, leftMax, maxBSTCnt);
    } else {
	leftMin = leftMax = node->val;
    }
    if (node->right) {
	rightBSTCnt = traverse(node->right, rightMin, rightMax, maxBSTCnt);
    } else {
	rightMin = rightMax = node->val;
    }

    bool leftCheck(false), rightCheck(false);
    if (!node->left || (leftMax < node->val)) {
	leftCheck = true;
    }
    if (!node->right || (rightMin > node->val)) {
	rightCheck = true;
    }

    minVal = min(node->val, min(leftMin, rightMin));
    maxVal = max(node->val, max(leftMax, rightMax));

    int cnt(0);
    if (leftCheck && rightCheck) {
	if ((!node->left || leftBSTCnt > 0) && (!node->right || rightBSTCnt > 0)) {
	    cnt = leftBSTCnt + rightBSTCnt + 1;
	}
    } else {
	cnt = 0;
    }

    maxBSTCnt = max(maxBSTCnt, cnt);
    return cnt;
}

int Solution::largestBSTSubtree(TreeNode* root) {
    if (!root) return 0;
    int minVal(0), maxVal(0), ret(0), maxBSTCnt(0);
    traverse(root, minVal, maxVal, maxBSTCnt);
    return maxBSTCnt;
}
