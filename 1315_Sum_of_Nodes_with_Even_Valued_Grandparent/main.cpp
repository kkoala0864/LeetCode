#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* seven_2 = new TreeNode(7);
    TreeNode* eight = new TreeNode(8);
    TreeNode* nine = new TreeNode(9);
    six->left = seven;
    six->right = eight;
    seven->left = two;
    seven->right = seven_2;
    eight->left = one;
    eight->right = three;
    three->right = five;
    two->left = nine;
    seven_2->left = one;
    seven_2->right = four;
    cout << test->sumEvenGrandparent(six) << endl;
    return 0;
}

