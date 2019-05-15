#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void debug(TreeNode* node) {
    if (!node) return;
    debug(node->left);
    cout << node->val << " ";
    debug(node->right);
}

int main(void) {
    Solution* test = new Solution();
    vector<int> pre = {6,10,8,5,4,2,9,3,1,7}, post = {2,3,9,4,7,1,5,8,10,6};
    TreeNode* ret = test->constructFromPrePost(pre, post);
    debug(ret);
    cout << endl;
    return 0;
}

