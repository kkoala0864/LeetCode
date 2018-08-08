#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    TreeNode* root = new TreeNode(-2147483648);
    root->right = new TreeNode(2147483647);
    Solution* test = new Solution();
    cout << test->isValidBST(root) << endl;

    return 0;
}

