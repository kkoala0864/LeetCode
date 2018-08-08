#include <Solution.h>
#include <iostream>

using namespace std;

bool valid(TreeNode* root, TreeNode*& prev) {
    if (root == nullptr) return true;
    if (!valid(root->left, prev)) return false;
    if (prev != nullptr && prev->val >= root->val) return false;
    prev = root;
    return valid(root->right, prev);
}

bool Solution::isValidBST(TreeNode* root) {
    if (nullptr == root) return true;
    TreeNode* prev = nullptr;
    return valid(root, prev);
}
