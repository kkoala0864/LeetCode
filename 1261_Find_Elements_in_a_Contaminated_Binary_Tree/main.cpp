#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    TreeNode* root = new TreeNode(-1);
    TreeNode* right = new TreeNode(-1);
    root->right = right;
    test->FindElements(root);
    cout << test->find(1) << endl;
    return 0;
}

