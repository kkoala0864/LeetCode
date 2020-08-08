#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    TreeNode *six = new TreeNode(6);
    TreeNode *seven = new TreeNode(7);
    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    three->left = six;
    three->right = seven;
    vector<int> delete_list = {3,5};
    auto ret = test->delNodes(one, delete_list);
    cout << endl;
    for (auto iter : ret) {
	cout << iter->val << " ";
    }
    cout << endl;
    return 0;
}

