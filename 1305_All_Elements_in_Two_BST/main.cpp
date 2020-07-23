#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    TreeNode* root1 = new TreeNode(2);
    TreeNode* root2 = new TreeNode(1);
    TreeNode* root1left = new TreeNode(1);
    TreeNode* root1right = new TreeNode(4);
    TreeNode* root2left = new TreeNode(0);
    TreeNode* root2right = new TreeNode(3);
    root1->left = root1left;
    root1->right = root1right;
    root2->left = root2left;
    root2->right = root2right;
    vector<int> ret = test->getAllElements(root1, root2);

    for (const auto iter : ret) {
	cout << iter << endl;
    }

    return 0;
}

