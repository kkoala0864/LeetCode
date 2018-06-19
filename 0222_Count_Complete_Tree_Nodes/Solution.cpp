#include <Solution.h>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int Solution::countNodes3(TreeNode* root) {
    if (!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int Solution::countNodes2(TreeNode* root) {
    if (!root) return 0;
    int ret(0);
    queue<TreeNode*> Que;
    Que.emplace(root);
    queue<TreeNode*> nextLV;
    while (!Que.empty()) {
	TreeNode* node = Que.front(); Que.pop();
	++ret;
	if (node->left)
	    nextLV.emplace(node->left);
	if (node->right)
	    nextLV.emplace(node->right);
	if (Que.empty())
	    Que = move(nextLV);
    }
    return ret;
}

int Solution::countNodes(TreeNode* root) {
    if (!root) return 0;
    int height(-1);
    int lh = 0;
    int rh = 0;
    TreeNode* lIter = root;
    TreeNode* rIter = root;
    while (lIter) {
	lIter = lIter->left;
	++lh;
    }
    while (rIter) {
	rIter = rIter->right;
	++rh;
    }
    if (lh == rh)
	return pow(2, lh) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
