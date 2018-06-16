#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr || p == nullptr)
	return nullptr;

    stack<TreeNode*> record;
    TreeNode* iter = root;
    while (iter != nullptr) {
	if (iter->val == p->val) {
	    if (iter->right == nullptr) {
		if (record.size() > 0) {
		    return record.top();
		} else {
		    return nullptr;
		}
	    } else {
		TreeNode* MostLeftChild = iter->right;
		while (MostLeftChild->left)
		    MostLeftChild = MostLeftChild->left;
		return MostLeftChild;
	    }
	} else if (iter->val > p->val) {
	    record.push(iter);
	    iter = iter->left;
	} else {
	    iter = iter->right;
	}
    }
    return nullptr;
}
