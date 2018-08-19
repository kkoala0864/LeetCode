#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

void traverse(TreeNode* node, vector<vector<int>>& paths, vector<int>& st) {
    if (node == nullptr) return;
    st.emplace_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
	paths.emplace_back(st);
    } else {
	traverse(node->left, paths, st);
	traverse(node->right, paths, st);
    }
    st.pop_back();
}

int Solution::sumNumbers(TreeNode* root) {
    vector<vector<int>> paths;
    vector<int> st;
    traverse(root, paths, st);
    int ret(0);

    for (const auto& path : paths) {
	int pathSum(0);
	for (const auto& val : path) {
	    pathSum = pathSum * 10 + val;
	}
	ret += pathSum;
    }
    return ret;
}
