#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    one->left = two;
    one->right = three;
    three->left = four;
    three->right = five;
    Solution test;
    cout << test.serialize(one) << endl;

    return 0;
}

