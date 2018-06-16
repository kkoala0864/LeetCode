#include <Solution.h>

using namespace std;
int main(void) {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution* test = new Solution();
    test->buildTree(inorder, postorder);

    return 0;
}

