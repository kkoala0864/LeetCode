#include <Solution.h>
#include <iostream>

using namespace std;

bool countTree(TreeNode* node, int& count) {
    if (node == nullptr) return true;
    if (node->left == nullptr && node->right == nullptr) {
	++count;
	return true;
    }

    bool leftCnt = countTree(node->left, count);
    bool rightCnt = countTree(node->right, count);

    if (leftCnt && rightCnt) {
	bool leftNode = node->left ? node->val == node->left->val : true;
	bool rightNode = node->right ? node->val == node->right->val : true;
	if (leftNode && rightNode) {
	    ++count;
	    return true;
	} else {
	    return false;
	}
    } else {
	return false;
    }
}

int Solution::countUnivalSubtrees(TreeNode* root) {
    if (root == nullptr) return 0;
    int count(0);
    countTree(root, count);
    return count;
}
