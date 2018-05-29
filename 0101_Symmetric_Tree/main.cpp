#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    TreeNode* first = new TreeNode(1);
    TreeNode* second = new TreeNode(2);
    TreeNode* third = new TreeNode(2);
    TreeNode* four = new TreeNode(3);
    TreeNode* five = new TreeNode(4);
    TreeNode* six = new TreeNode(4);
    TreeNode* seven = new TreeNode(3);
    first->left = second;
    first->right = third;
    second->left = four;
    second->right = five;
    third->left = six;
    third->right = seven;
    cout << test->isSymmetric(first) << endl;
    cout << test->isSymmetricRecur(first) << endl;

    return 0;
}

