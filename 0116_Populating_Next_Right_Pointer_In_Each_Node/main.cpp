#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    TreeLinkNode* first = new TreeLinkNode(1);
    TreeLinkNode* second = new TreeLinkNode(2);
    TreeLinkNode* third = new TreeLinkNode(3);
    TreeLinkNode* four = new TreeLinkNode(4);
    TreeLinkNode* five = new TreeLinkNode(5);
    TreeLinkNode* six = new TreeLinkNode(6);
    TreeLinkNode* seven = new TreeLinkNode(7);
    first->left = second;
    first->right = third;
    second->left = four;
    second->right = five;
    third->left = six;
    third->right = seven;
    Solution* test = new Solution();
    test->connect(first);
    TreeLinkNode* iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;
    iter = second;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;
    iter = four;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

