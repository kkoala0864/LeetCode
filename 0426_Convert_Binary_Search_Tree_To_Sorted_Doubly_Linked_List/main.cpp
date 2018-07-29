#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    Node* five = new Node(5, nullptr, nullptr);
    Node* eight = new Node(8, nullptr, nullptr);
    Node* thirteen = new Node(13, nullptr, nullptr);
    Node* nineteen = new Node(19, nullptr, nullptr);
    Node* seven = new Node(7, five, eight);
    Node* fifteen = new Node(15, thirteen, nineteen);
    Node* ten = new Node(10, seven, fifteen);
    Solution* test = new Solution();
    Node* head = test->treeToDoublyListLL(ten);
    Node* iter = head;
    Node* rIter = head;
    int Cnt(7);
    while (Cnt-- > 0) {
	cout << iter->val << " ";
	iter = iter->right;
    }
    cout << endl;

    Cnt = 7;
    while (Cnt-- > 0) {
	cout << rIter->val << " ";
	rIter = rIter->left;
    }
    cout << endl;
    return 0;
}

