#include <iostream>
#include <Solution.h>

using namespace std;

int Solution::maxDepth(TreeNode* root) {
	if ( root ) {
		int left_Depth = maxDepth(root->left);
		int right_Depth = maxDepth(root->right);
		return (left_Depth > right_Depth ? left_Depth : right_Depth ) + 1;
	} else {
		return 0;
	}
}

void Solution::DebugPrint() {
	cout << "This is maxDepth Binary Tree Debug Print" << endl;
}
