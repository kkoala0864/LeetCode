#include <Solution.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void leftBound(TreeNode* node, vector<int>& record) {
    if (node == nullptr) return;
    if (node->left || node->right) record.emplace_back(node->val);
    if (node->left) leftBound(node->left, record);
    else leftBound(node->right, record);
}

void leaf(TreeNode* node, vector<int>& record) {
    if (nullptr == node) return;
    if (node->left == nullptr && node->right == nullptr) {
	record.emplace_back(node->val);
	return;
    }
    leaf(node->left, record);
    leaf(node->right, record);
}

void rightBound(TreeNode* node, vector<int>& record) {
    if (nullptr == node) return;
    if (node->right) rightBound(node->right, record);
    else rightBound(node->left, record);
    if (node->left || node->right) record.emplace_back(node->val);
}

vector<int> Solution::boundaryOfBinaryTree(TreeNode* root) {
    vector<int> ret;
    if (root == nullptr) return ret;
    ret.emplace_back(root->val);
    leftBound(root->left, ret);
    leaf(root->left, ret);
    leaf(root->right, ret);
    rightBound(root->right, ret);
    return ret;
}
