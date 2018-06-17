#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    TreeLinkNode* first = new TreeLinkNode(1);
    TreeLinkNode* second = new TreeLinkNode(2);
    TreeLinkNode* third = new TreeLinkNode(3);
    TreeLinkNode* four = new TreeLinkNode(4);
    TreeLinkNode* five = new TreeLinkNode(5);
    first->left = second;
    first->right = third;
    second->left = four;
    second->right = five;
    Solution* test = new Solution();
    test->connect(first);

    TreeLinkNode* rootIter = first;
    while (rootIter) {
	TreeLinkNode* iter = rootIter;
	while (iter) {
	    cout << iter->val << " ";
	    iter = iter->next;
	}
	cout << endl;
	rootIter = rootIter->left;
    }
    return 0;
}

