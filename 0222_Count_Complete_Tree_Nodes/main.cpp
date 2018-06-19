#include <Solution.h>
#include <iostream>
using namespace std;

int main(void) {
    TreeNode* first = new TreeNode(1);
    TreeNode* second = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    first->left = second;
    first->right = third;
    second->left = four;
    second->right = five;
    third->left = six;
    Solution* test = new Solution();
    cout << test->countNodes(first) << endl;

    return 0;
}

