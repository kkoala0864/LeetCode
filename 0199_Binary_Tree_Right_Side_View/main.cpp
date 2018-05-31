#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    TreeNode* first = new TreeNode(1);
    TreeNode* second = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    first->left = second;
    first->right = third;
    second->right = four;
    third->right = five;

    vector<int> ret = test->rightSideViewRecur(first);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;
    return 0;
}

