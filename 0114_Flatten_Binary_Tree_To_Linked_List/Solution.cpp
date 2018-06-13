#include <Solution.h>
#include <iostream>

using namespace std;

void transfer(TreeNode* cur_root) {
    if (nullptr == cur_root) {
	return;
    }

    if (nullptr != cur_root->right) {
	transfer(cur_root->right);
    }

    if (nullptr != cur_root->left) {
	transfer(cur_root->left);
	TreeNode *rightestNode = cur_root->left;
	while (nullptr != rightestNode->right) {
	    rightestNode = rightestNode->right;
	}
	rightestNode->right = cur_root->right;
	cur_root->right = cur_root->left;
	cur_root = nullptr;
    }
}

void Solution::flatten(TreeNode* root) {
    if (nullptr == root) {
	return;
    }
    transfer(root);
}
