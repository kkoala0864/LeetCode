#include <Solution.h>

using namespace std;
int main(void) {
    vector<int> inorder = {9, 3, 15, 20 ,7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    Solution* test = new Solution();
    test->buildTree(preorder, inorder);

    return 0;
}

