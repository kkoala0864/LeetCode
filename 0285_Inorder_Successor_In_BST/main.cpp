#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

int main(void) {
    TreeNode* first = new TreeNode(2);
    TreeNode* second = new TreeNode(1);
    first->left = second;
    Solution* test = new Solution();
    TreeNode* look = new TreeNode(1);
    TreeNode* ret = test->inorderSuccessor(first, look);
    if (ret)
    cout << ret->val << endl;
    else
	cout << "null" << endl;

    return 0;
}

