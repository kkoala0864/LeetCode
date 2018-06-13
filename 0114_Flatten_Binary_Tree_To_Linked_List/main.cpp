#include <Solution.h>

using namespace std;
int main(void) {
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    TreeNode *six = new TreeNode(6);
    first->left = second;
    first->right = five;
    second->left = three;
    second->right = four;
    five->right = six;
    Solution* test = new Solution();
    test->flatten(first);

    return 0;
}

