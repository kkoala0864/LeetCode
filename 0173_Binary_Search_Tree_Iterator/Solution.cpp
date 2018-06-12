#include <Solution.h>
#include <iostream>

using namespace std;
BSTIterator::BSTIterator(TreeNode *root) {
    TreeNode* iter = root;
    while (iter) {
	smallStack.emplace(iter);
	iter = iter->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !smallStack.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *Top = smallStack.top();
    smallStack.pop();
    TreeNode *iter = Top->right;
    while (iter) {
	smallStack.emplace(iter);
	iter = iter->left;
    }
    return Top->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
