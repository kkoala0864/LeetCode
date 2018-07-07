#include <Solution.h>
#include <iostream>

using namespace std;


int Solution::closestValue(TreeNode* root, double target) {
    if (root == nullptr) return 0;
    int CloestNode(root->val);
    TreeNode* iter = root;
    while (iter) {
	if (abs((double)(CloestNode - target)) > abs((double)(iter->val - target))) {
	    CloestNode = iter->val;
	}
	if (iter->val < target) {
	    iter = iter->right;
	} else {
	    iter = iter->left;
	}
    }

    return CloestNode;
}
