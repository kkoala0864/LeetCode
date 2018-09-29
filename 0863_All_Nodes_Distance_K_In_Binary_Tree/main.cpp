#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    TreeNode* one = new TreeNode(3);
    TreeNode* two = new TreeNode(5);
    TreeNode* three = new TreeNode(1);
    TreeNode* four = new TreeNode(6);
    TreeNode* five = new TreeNode(2);
    TreeNode* six = new TreeNode(0);
    TreeNode* seven = new TreeNode(8);
    TreeNode* eight = new TreeNode(7);
    TreeNode* nine = new TreeNode(4);
    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    three->left = six;
    three->right = seven;
    five->left = eight;
    five->right = nine;
    Solution* test = new Solution();
    vector<int> ret = test->distanceK(one, two, 2);
    for (const auto& val : ret) {
	cout << val << endl;
    }
    return 0;
}

