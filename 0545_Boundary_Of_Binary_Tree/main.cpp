#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    TreeNode* node = new TreeNode(1);
    Solution* test = new Solution();
    vector<int> ret = test->boundaryOfBinaryTree(node);
    for (const auto& val : ret) {
	cout << val << " ";
    }
    cout << endl;
    return 0;
}

