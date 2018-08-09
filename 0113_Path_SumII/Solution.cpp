#include <Solution.h>
#include <iostream>

using namespace std;

void traverse(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& ret) {
    if (node == nullptr) return;
    path.emplace_back(node->val);
    if (node->val == sum && node->left == nullptr && node->right == nullptr) {
	ret.emplace_back(path);
    } else {
	traverse(node->left, sum - node->val, path, ret);
	traverse(node->right, sum - node->val, path, ret);
    }
    path.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    vector<int> path;
    if (root == nullptr) return ret;
    traverse(root, sum, path, ret);
    return ret;
}
