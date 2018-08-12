#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

TreeNode* Solution::upsideDownBinaryTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    stack<TreeNode*> st;
    TreeNode* iter = root;
    while (iter) {
	st.emplace(iter);
	iter = iter->left;
    }

    root = st.top();
    iter = st.top(); st.pop();
    while (!st.empty()) {
	iter->right = st.top();
	iter->left = st.top()->right;
	iter = st.top(); st.pop();
    }
    iter->left = nullptr;
    iter->right = nullptr;
    return root;
}
