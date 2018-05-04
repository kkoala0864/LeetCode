#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	TreeNode *root = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	root->right = right;
	Solution* test = new Solution();
	TreeNode *ret = test->lowestCommonAncestor(root, nullptr, right);
	if (ret)
		cout << ret->val << endl;
	else
		cout << "empty" << endl;

	return 0;
}

