#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

TreeNode* combine(TreeNode* leftPart, TreeNode* rightPart) {
    if (rightPart == nullptr) {
	return leftPart;
    } else if (leftPart == nullptr) {
	return rightPart;
    } else {
	TreeNode* iter = rightPart;
	while (iter->left) {
	    iter = iter->left;
	}
	iter->left = leftPart;
	return rightPart;
    }
}

TreeNode* Solution::deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    TreeNode* iter = root;
    stack<TreeNode*> st;
    while (iter) {
	if (iter->val == key) {
	    TreeNode* concanate = combine(iter->left, iter->right);
	    if (st.empty()) {
		return concanate;
	    } else {
		if (iter->val < st.top()->val) {
		    st.top()->left = concanate;
		} else {
		    st.top()->right = concanate;
		}
	    }
	    break;
	}
	st.emplace(iter);
	if (key < iter->val) {
	    iter = iter->left;
	} else {
	    iter = iter->right;
	}
    }
    return root;
}

