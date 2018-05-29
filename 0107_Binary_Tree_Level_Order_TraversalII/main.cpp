#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    TreeNode* first = new TreeNode(3);
    TreeNode* second = new TreeNode(9);
    TreeNode* third = new TreeNode(20);
    TreeNode* four = new TreeNode(15);
    TreeNode* five = new TreeNode(17);
    first->left = second;
    first->right = third;
    third->left = four;
    third->right = five;
    auto ret = test->levelOrderBottom(first);
    for (const auto& first : ret) {
	for (const auto& second : first) {
	    cout << second << " ";
	}
	cout << endl;
    }

    return 0;
}

