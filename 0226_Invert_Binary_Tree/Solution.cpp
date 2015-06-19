#include <iostream>
#include <Solution.h>

using namespace std;

Solution::Solution() {};

Solution::~Solution() {};

TreeNode* Solution::invertTree(TreeNode* root) {
	if ( root ) {
		if (!root->left && !root->right)
			return root;
		if ( root->left ) {
			if ( root->left->left || root->left->right )
				invertTree(root->left);
		}
		if ( root->right ) {
			if ( root->right->left || root->right->right )
				invertTree(root->right);
		}
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
	return root;
}

void Solution::DebugPrint(TreeNode * root) {
	if ( root ) {
		if ( root->left )
			DebugPrint(root->left);
		if ( root->right )
			DebugPrint(root->right);
		cout << root->val << endl;
	}
}
