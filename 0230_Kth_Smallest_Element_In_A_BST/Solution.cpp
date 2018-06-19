#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

void inorder(TreeNode* root, vector<int>& record, int k) {
    if (!root || record.size() >= k)
	return;
    inorder(root->left, record, k);
    if (record.size() >= k)
	return;
    record.emplace_back(root->val);
    inorder(root->right, record, k);
}

int Solution::kthSmallest(TreeNode* root, int k) {
    if (!root) return -1;
    vector<int> record;
    inorder(root, record, k);
    return record.back();
}
