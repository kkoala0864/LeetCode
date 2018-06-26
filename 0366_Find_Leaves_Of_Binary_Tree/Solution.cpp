#include <Solution.h>
#include <iostream>

using namespace std;

void removeLeafAndPushToVec(TreeNode*& root, vector<int>& leaveVec) {
    if (!root) return;
    if (!root->left && !root->right) {
	leaveVec.emplace_back(root->val);
	root = nullptr;
	return;
    }

    if (root->left)
	removeLeafAndPushToVec(root->left, leaveVec);
    if (root->right)
	removeLeafAndPushToVec(root->right, leaveVec);
}

vector<vector<int>> Solution::findLeaves(TreeNode* root) {
    vector<vector<int>> ret;
    while (root) {
	vector<int> locVec;
	removeLeafAndPushToVec(root, locVec);
	ret.emplace_back(locVec);
    }
    return ret;
}
